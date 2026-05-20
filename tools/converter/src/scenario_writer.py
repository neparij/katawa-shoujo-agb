import hashlib
import os
import re
import tempfile
from collections import namedtuple
from typing import List, cast, Dict, Optional, Tuple

import pyfastgbalz77
import sentencepiece as spm
import yaml

from src.gba_huffman import gba_huff_compress_8bit
from src.character_sprite.character_sprite import CharacterDisplayableReplacements, CharacterSprite, CharacterRegex, \
    CharacterNudeIf
from src.dto.assignment_item import AssignmentItem
from src.dto.background_item import BackgroundItem, BgShowPosition
from src.dto.background_transform_item import BackgroundTransformItem
from src.dto.background_transition_item import BackgroundTransitionItem
from src.dto.condition_item import ConditionItem
from src.dto.custom_event_item import CustomEventItem
from src.dto.custom_event_state_item import CustomEventStateItem
from src.dto.dialog_item import DialogItem
from src.dto.doublespeak_item import DoubleSpeakItem
from src.dto.hide_item import HideItem
from src.dto.menu_item import MenuItem
from src.dto.music_item import MusicItem, MusicAction, MusicEffect
from src.dto.novel_clear_item import NovelClearItem
from src.dto.novel_hide_item import NovelHideItem
from src.dto.pause_item import PauseItem
from src.dto.return_item import ReturnItem
from src.dto.run_label_item import RunLabelItem
from src.dto.sequence_item import SequenceItem, SequenceType
from src.dto.show_item import ShowItem, ShowPosition
from src.dto.show_transform_item import ShowTransformItem
from src.dto.show_video_item import ShowVideoItem
from src.dto.sound_item import SoundItem, SoundAction, SoundEffect
from src.dto.update_visuals_item import UpdateVisualsItem
from src.scenario.sequence_group import SequenceGroup, SequenceGroupType, ConditionWrapper
from src.utils import is_color_filled_bg, add_translations_optional, \
    get_textdb_name, sanitize_ingame_text, spm_with_bytecode_encode, fixed_literal

LABEL_EXIT_CHECK = 'if (ks::globals::exit_scenario) return;'

CHARACTERS = [
    "akira",
    "emi",
    "emicas",
    "eminude",
    "emiwheel",
    "hanagown",
    "hanako",
    "hideaki",
    "jigoro",
    "kenji",
    "lilly",
    "meiko",
    "miki",
    "misha",
    "mishashort",
    "muto",
    "nomiya",
    "nurse",
    "rin",
    "rinpan",
    "sae",
    "shizu",
    "shizuyu",
    "shopkeep",
    "yuuko",
    "yuukoshang"
]


# ---------------------------------------------------------------------------
# Smart-characters YAML resolver
# ---------------------------------------------------------------------------
# The ScenarioWriter no longer emits separate (background, sprite, sprite_meta)
# triplets per show — it emits a single `ks::smart_characters::<tileset>::<sym>`
# variant reference. The tileset bucket and the YAML-defined `group_key` for a
# given (character × pose × outfit × close) tuple live in the same YAML the
# converter consumes, so the writer reads it directly to keep both sides in
# lock-step.

_SMART_CHARACTERS_YAML = os.path.join(
    os.path.dirname(__file__), "character_sprite", "character_sprites.yaml"
)

_smart_yaml_cache: Optional[dict] = None


def _load_smart_yaml() -> dict:
    """Load and memoize the smart-characters YAML once per process."""
    global _smart_yaml_cache
    if _smart_yaml_cache is None:
        with open(_SMART_CHARACTERS_YAML, "r", encoding="utf-8") as f:
            _smart_yaml_cache = yaml.safe_load(f) or {}
    return _smart_yaml_cache


def _smart_character_data(character_name: str) -> dict:
    data = _load_smart_yaml()
    sprites = data.get("sprites") or {}
    if character_name not in sprites:
        raise KeyError(
            f"Character {character_name!r} is not defined in {_SMART_CHARACTERS_YAML}"
        )
    return sprites[character_name]


def smart_character_tileset(character_name: str) -> str:
    """Tileset bucket the character belongs to (e.g. 'emicas' -> 'emi')."""
    char_data = _smart_character_data(character_name)
    return char_data.get("tileset", character_name)


def smart_character_resolve(character: CharacterSprite) -> Tuple[str, str, str]:
    """Resolve (tileset_key, group_key, variant_symbol) for a CharacterSprite.

    The YAML is the source of truth for `group_key`: the converter and the
    scenario writer both reference groups by that exact YAML key, so we must
    not reconstruct it from (pose, outfit, close) — characters like `nurse`
    or `yuuko` use bespoke keys (`default`, `close`, …) that don't follow
    the `pose_outfit_close` schema.
    """
    char_data = _smart_character_data(character.character_name)
    tileset_key = char_data.get("tileset", character.character_name)
    groups = char_data.get("groups") or {}

    target_pose   = character.pose
    target_outfit = character.outfit
    target_close  = bool(character.close)

    matched_key: Optional[str] = None
    for group_key, group_data in groups.items():
        if (group_data.get("pose")   == target_pose
                and group_data.get("outfit") == target_outfit
                and bool(group_data.get("close", False)) == target_close):
            matched_key = group_key
            break

    if matched_key is None:
        raise KeyError(
            f"No group in {character.character_name!r} matches "
            f"pose={target_pose!r}, outfit={target_outfit!r}, close={target_close} "
            f"(emotion={character.emotion!r})"
        )

    if character.emotion not in (groups[matched_key].get("sprites") or {}):
        raise KeyError(
            f"Group {character.character_name}/{matched_key} has no sprite "
            f"for emotion {character.emotion!r}"
        )

    variant_symbol = f"{character.character_name}_{matched_key}_{character.emotion}"
    return tileset_key, matched_key, variant_symbol


class ScenarioWriter:
    def __init__(self, filename: str, output_dir: str, tl_dir: str, spm_dir: str, scenario: List[SequenceGroup]):
        self.filename = filename
        self.output_dir = output_dir
        self.tl_dir = tl_dir
        self.spm_dir = spm_dir
        self.scenario = scenario
        self.tl_dict: List[Dict[str, str]] = []

        self.backgrounds = []
        # Tileset buckets used by smart_characters in this script. Each entry
        # corresponds to one `#include "smart_characters/<tileset>.h"` and
        # contains every (character × pose × outfit × close) group + emotion
        # used by this script that maps to that tileset.
        self.smart_character_tilesets: List[str] = []
        self.events = []
        self.music = []
        self.videos = []
        self.characters: Dict[str, int] = {}

    def write(self):
        os.makedirs(os.path.dirname(os.path.join(self.output_dir, self.filename)), exist_ok=True)
        self.write_source()
        self.write_header()
        self.write_scenario_tl()

    def collect_implementation_includes(self) -> List[str]:
        includes = [
            include_header(self.filename),
            include_header(f"{get_textdb_name(self.filename)}_tl"),
            include_header("../scenemanager"),
            include_header("../character"),
        ]
        for tileset in self.smart_character_tilesets:
            includes.append(include_header(tileset, "smart_characters/"))
        for background in self.backgrounds:
            includes.append(include_header(background, "background_metas/"))
        for event in self.events:
            includes.append(include_header(f"{to_snake_case(event).removesuffix("_event")}.cpp", "../events/"))
        for video in self.videos:
            includes.append(include_header(video, "video_", "_dxtv"))
        return includes

    def write_header(self):
        define_name = f"{self.filename.split(".")[0].upper().replace("-", "_")}"
        h_code: List[str] = []

        function_declarations = [
            f'virtual ~{self.get_interface_name()}() = default;',
        ]

        function_declarations.append(comment("Labels"))
        for label in self.get_labels():
            function_declarations.append(f"static {label_signature(label)};")

        public_functions = as_public("\n".join(function_declarations))
        class_code = as_class(public_functions, self.get_interface_name())

        h_code.append(namespace(class_code, "ks"))

        with open(f"{os.path.join(self.output_dir, self.filename)}.h", "w") as h_file:
            h_file.write(defined("\n".join(h_code), define_name, "KS"))

    def write_source(self):
        functions = []

        for label in self.get_labels():
            sequences = [LABEL_EXIT_CHECK]
            if label.is_called_inline and not label.is_initial:
                sequences.append(f'ks::SceneManager::set_label(LABEL_{label.name.upper()});')
                sequences.append(f'ks::SceneManager::set_textdb({get_textdb_name(self.filename)}_tl);')
                # sequences.append(f'if (!ks::in_replay) {{')
                # sequences.append(f'    ks::SceneManager::autosave();')
                # sequences.append(f'}}')
            elif label.is_initial:
                sequences.append(f'SKIP_IF_LOAD_ANOTHER_SCENE(SCRIPT_{label.name.upper()});')
                sequences.append(f'ks::SceneManager::set_script(SCRIPT_{label.name.upper()});')
                sequences.append(f'ks::SceneManager::init_savedata(ks::progress);')
                sequences.append(
                    f'ks::SceneManager::set(ks::SceneManager("{self.filename}"));\n')
            if self.sequence_contains_menu(label.sequence):
                sequences.append('bn::vector<ks::answer_ptr, 5> answers;')
                sequences.append('int answer;')
            for sequence in label.sequence:
                sequence_code = self.process_sequence(label, sequence)
                if sequence_code:
                    for seq in sequence_code:
                        sequences.append(seq)
            # if label.is_called_inline and not label.is_initial:
            #     sequences.append("scene.start();\n")
            #     sequences.extend([
            #         "while(!scene.is_finished()) {",
            #         "    scene.update();",
            #         "}"
            #     ])
            if label.is_initial:
                functions.append(f"{label_signature(label, ns = self.get_class_name())} {{\n{indented_l(sequences)}\n}}")
            else:
                functions.append(f"{label_signature(label, ns = self.get_class_name())} {{\n{indented_l(sequences)}\n}}")

        class_code = indented("\n".join(functions))

        cpp_code = self.collect_implementation_includes() + [namespace(class_code, "ks")]

        with open(f"{os.path.join(self.output_dir, self.filename)}.cpp", "w") as cpp_file:
            cpp_file.write("\n".join(cpp_code))

    def write_scenario_tl(self):
        locales = self.tl_dict[0].keys()
        tl_entry = namedtuple('TranslationEntry', ['offset', 'translation'])
        translations : Dict[str, List[tl_entry]] = {}

        for locale in locales:
            spp = spm.SentencePieceProcessor()
            try:
                spp.Load(model_file=os.path.join(self.spm_dir, f'spm-{locale}.model'))
            except Exception as e:
                raise Exception(f"Failed to load SPM model for locale '{locale}': {e}")

            translations[locale] = []
            offset = 0
            for tl in self.tl_dict:
                if locale not in tl:
                    raise Exception(f"Locale '{locale}' not found in translation entry {tl}")
                if offset >= 0xFFFFFF:
                    raise Exception(f"Entry offset: {offset} (0x{offset:06X}) too large for locale '{locale}'")
                translation = spm_with_bytecode_encode(tl[locale], spp)
                translations[locale].append(tl_entry(offset=offset, translation=translation))
                offset += len(translation)

        for locale in translations:
            filename_base = f"{get_textdb_name(self.filename)}.tl"
            spp = spm.SentencePieceProcessor()

            try:
                spp.Load(model_file=os.path.join(self.spm_dir, f'spm-{locale}.model'))
            except Exception as e:
                raise Exception(f"Failed to load SPM model for locale '{locale}': {e}")

            uncompressed_file = tempfile.mktemp(suffix=f"_tl_{locale}.u")
            with open(uncompressed_file, "wb") as tl_file:
                # Offset table length
                tl_file.write(len(translations[locale]).to_bytes(2, byteorder='little'))
                # Offset table
                for entry in translations[locale]:
                    tl_file.write(entry.offset.to_bytes(3, byteorder='little'))
                # Translations itself
                for entry in translations[locale]:
                    tl_file.write(entry.translation)

            with open(uncompressed_file, "rb") as f:
                uncompressed_bytes = f.read()

            # BIOS-compatible Huffman compression (SWI 0x13, 8-bit symbols)
            compressed_bytes = gba_huff_compress_8bit(uncompressed_bytes)
            if len(compressed_bytes) % 4:
                compressed_bytes += b"\x00" * (4 - (len(compressed_bytes) % 4))

            # Write Huffman compressed translation file
            with open(os.path.join(self.tl_dir, locale, filename_base), "wb") as f:
                f.write(compressed_bytes)

    def get_labels(self) -> List[SequenceGroup]:
        return [group for group in self.scenario if group.type == SequenceGroupType.LABEL]

    def get_menus(self) -> List[SequenceGroup]:
        return [group for group in self.scenario if group.type == SequenceGroupType.MENU]

    def get_conditions(self) -> List[SequenceGroup]:
        return [group for group in self.scenario if group.type == SequenceGroupType.CONDITION]

    def find_group_by_name(self, name: str, group_type: SequenceGroupType) -> SequenceGroup:
        for group in self.scenario:
            if group.type == group_type and group.name == name:
                return group
        raise KeyError(f"No {group_type.value} group named {name!r} in {self.filename}")

    def sequence_contains_menu(self, items: List[SequenceItem]) -> bool:
        for item in items:
            if item.type == SequenceType.MENU:
                return True
            if item.type == SequenceType.CONDITION:
                condition = cast(ConditionItem, item)
                matching = self.find_group_by_name(
                    condition.function_callback, SequenceGroupType.CONDITION
                )
                for variant in matching.conditions:
                    if self.sequence_contains_menu(variant.sequence):
                        return True
        return False

    def emit_sequence_lines(self, ctx_group: SequenceGroup, items: List[SequenceItem], indent: int) -> List[str]:
        lines: List[str] = []
        pad = ' ' * indent
        for item in items:
            for line in self.process_sequence(ctx_group, item) or []:
                lines.append(f'{pad}{line}')
        return lines

    def emit_condition_block(self, ctx_group: SequenceGroup, condition: ConditionItem, indent: int) -> List[str]:
        matching = self.find_group_by_name(condition.function_callback, SequenceGroupType.CONDITION)
        code: List[str] = []
        pad = ' ' * indent
        body_indent = indent + 4
        variants = matching.conditions
        for cnum, variant in enumerate(variants):
            if variant.condition and cnum == 0:
                head = f'if ({to_ks_progress_variables(to_cpp_condition(variant.condition))}) {{'
            elif variant.condition and cnum > 0:
                head = f'}} else if ({to_ks_progress_variables(to_cpp_condition(variant.condition))}) {{'
            elif cnum == len(variants) - 1 and not variant.condition:
                head = '} else {'
            else:
                raise TypeError("Unknown Condition type")
            code.append(f'{pad}{head}')
            code.extend(self.emit_sequence_lines(matching, variant.sequence, body_indent))
        if variants:
            code.append(f'{pad}}}')
        return code

    def emit_menu_block(self, ctx_group: SequenceGroup, menu: MenuItem, indent: int) -> List[str]:
        matching = self.find_group_by_name(menu.function_callback, SequenceGroupType.MENU)
        code: List[str] = []
        pad = ' ' * indent
        branch_pad = ' ' * (indent + 4)

        code.extend(self.emit_sequence_lines(matching, matching.sequence, indent))
        code.append(f'{pad}answers.clear();')
        answer_index = 0
        for choice in matching.conditions:
            tl_index = add_translations_optional(self.tl_dict, choice.answer)
            if not choice.condition:
                code.append(f'{pad}answers.push_back(ks::answer_ptr{{{answer_index}, {tl_index}}});')
            else:
                code.append(
                    f'{pad}if ({to_ks_progress_variables(to_cpp_condition(choice.condition))}) '
                    f'answers.push_back(ks::answer_ptr{{{answer_index}, {tl_index}}});'
                )
            answer_index += 1

        code.append(f'{pad}ks::SceneManager::show_dialog_question(answers);')
        code.append(f'{pad}answer = answers[ks::SceneManager::get_dialog_question_answer()].index;')

        branch_index = 0
        for choice in matching.conditions:
            branch_lines = self.emit_sequence_lines(matching, choice.sequence, indent + 8)
            if branch_index == 0:
                code.append(f'{branch_pad}if (answer == {branch_index}) {{')
            else:
                code.append(f'{branch_pad}}} else if (answer == {branch_index}) {{')
            code.extend(branch_lines)
            branch_index += 1
        if matching.conditions:
            code.append(f'{branch_pad}}}')

        return code

    def process_sequence(self, group: SequenceGroup, sequence: SequenceItem) -> List[str]:
        if sequence.type == SequenceType.ASSIGNMENT:
            return self.process_sequence_assignment(group, cast(AssignmentItem, sequence))
        elif sequence.type == SequenceType.BACKGROUND:
            return self.process_sequence_background(group, cast(BackgroundItem, sequence))
        elif sequence.type == SequenceType.CUSTOM_EVENT:
            return self.process_sequence_custom_event(group, cast(CustomEventItem, sequence))
        elif sequence.type == SequenceType.CUSTOM_EVENT_STATE:
            return self.process_sequence_custom_event_state(group, cast(CustomEventStateItem, sequence))
        elif sequence.type == SequenceType.CONDITION:
            return self.process_sequence_condition(group, cast(ConditionItem, sequence))
        elif sequence.type == SequenceType.DIALOG:
            return self.process_sequence_dialogue(group, cast(DialogItem, sequence))
        elif sequence.type == SequenceType.DOUBLESPEAK:
            return self.process_sequence_doublespeak(group, cast(DoubleSpeakItem, sequence))
        elif sequence.type == SequenceType.NVL_CLEAR:
            return self.process_sequence_nvl_clear(group, cast(NovelClearItem, sequence))
        elif sequence.type == SequenceType.NVL_HIDE:
            return self.process_sequence_nvl_hide(group, cast(NovelHideItem, sequence))
        elif sequence.type == SequenceType.MENU:
            return self.process_sequence_menu(group, cast(MenuItem, sequence))
        elif sequence.type == SequenceType.MUSIC:
            return self.process_sequence_music(group, cast(MusicItem, sequence))
        elif sequence.type == SequenceType.SOUND:
            return self.process_sequence_sound(group, cast(SoundItem, sequence))
        elif sequence.type == SequenceType.RETURN:
            return self.process_sequence_return(group, cast(ReturnItem, sequence))
        elif sequence.type == SequenceType.RUN_LABEL:
            return self.process_sequence_run_label(group, cast(RunLabelItem, sequence))
        elif sequence.type == SequenceType.SHOW:
            return self.process_sequence_show(group, cast(ShowItem, sequence))
        elif sequence.type == SequenceType.HIDE:
            return self.process_sequence_hide(group, cast(HideItem, sequence))
        elif sequence.type == SequenceType.BACKGROUND_TRANSFORM:
            return self.process_sequence_bg_transform(group, cast(BackgroundTransformItem, sequence))
        elif sequence.type == SequenceType.BACKGROUND_TRANSITION:
            return self.process_sequence_bg_transition(group, cast(BackgroundTransitionItem, sequence))
        elif sequence.type == SequenceType.SHOW_TRANSFORM:
            return self.process_sequence_show_transform(group, cast(ShowTransformItem, sequence))
        elif sequence.type == SequenceType.PAUSE:
            return self.process_sequence_pause(group, cast(PauseItem, sequence))
        elif sequence.type == SequenceType.UPDATE_VISUALS:
            return self.process_sequence_update_visuals(group, cast(UpdateVisualsItem, sequence))
        elif sequence.type == SequenceType.SHOW_VIDEO:
            return self.process_sequence_show_video(group, cast(ShowVideoItem, sequence))
        else:
            raise TypeError("Unknown Sequence type")

    def process_sequence_assignment(self, group: SequenceGroup, assignment: AssignmentItem) -> List[str]:
        assignment_regex = r'^[a-zA-Z_][a-zA-Z0-9_]*\s*(=|\+=|-=|\*=|/=)\s*.*$'

        if re.match(assignment_regex, assignment.content):
            return [f'{to_ks_progress_variables(to_cpp_condition(assignment.content))};']
        else:
            print(f"Unknown assignment: {assignment.content}")
            return [f'// {assignment.content}; TODO: unknown assignment']
        # return [f'// scene.add_sequence(ks::AssignmentItem("{assignment.content}"));']

    def process_sequence_custom_event(self, group: SequenceGroup, ev: CustomEventItem) -> List[str]:
        # if not ev.background in self.backgrounds:
        #     self.backgrounds.append(ev.background)
        if not ev.event in self.events:
            self.events.append(ev.event)
        return [
            f'ks::SceneManager::set_event(ks::background_metas::{ev.background}, {ev.event}(), {ev.transition.value}, {int(ev.dissolve_time * 30)});']
            # f'ks::SceneManager::set_event(bn::regular_bg_items::{ev.background}, {ev.event}(), {ev.transition.value}, {int(ev.dissolve_time * 30)});']

    def process_sequence_custom_event_state(self, group: SequenceGroup, ev: CustomEventStateItem) -> List[str]:
        return [f'ks::SceneManager::set_event_state({ev.state});']

    def process_sequence_background(self, group: SequenceGroup, bg: BackgroundItem) -> List[str]:
        if not bg.background in self.backgrounds and not is_color_filled_bg(bg.background):
            self.backgrounds.append(bg.background)

        if bg.position == BgShowPosition.BGLEFT:
            position = (8, 0)
        elif bg.position == BgShowPosition.BGRIGHT:
            position = (-8, 0)
        elif bg.position == BgShowPosition.CENTER:
            position = (0, 0)
        elif bg.position == BgShowPosition.DEFAULT:
            position = (0, 0)
        else:
            raise TypeError("Unknown BgShowPosition type")

        if is_color_filled_bg(bg.background):
            return [
                f'ks::SceneManager::hide_background({bg.transition.value}, {int(bg.dissolve_time * 30)});',
                f'ks::SceneManager::enable_fill(ks::globals::colors::{bg.background.upper()});'
            ]
        else:
            return [f'ks::SceneManager::set_background(ks::background_metas::{bg.background}, {position[0]}, {position[1]}, {bg.transition.value}, {int(bg.dissolve_time * 30)}, {bg.palette_variant});']

    def process_sequence_condition(self, group: SequenceGroup, condition: ConditionItem) -> List[str]:
        return self.emit_condition_block(group, condition, indent=0)

    def process_sequence_dialogue(self, group: SequenceGroup, dialog: DialogItem) -> List[str]:
        # TODO: add character symbol to font
        for locale, text in dialog.message.items():
            dialog.message[locale] = sanitize_ingame_text(text)
        tl_index = add_translations_optional(self.tl_dict, dialog.message)

        hashed_id = hashlib.md5(dialog.id.encode()).hexdigest()[:8].upper()
        if dialog.actor_ref:
            if dialog.actor_ref == "n" or dialog.actor_ref == "nb" or dialog.actor_ref == "rinbabble":
                # TODO: fix the Rinbabble dialogs
                # TODO: NVL bold/Black? (nb)
                for locale, text in dialog.message.items():
                    fixed_text = text
                    # Remove vspace from the beginning of the line
                    fixed_text = re.sub(r'^\{vspace=\d+\}', '', fixed_text)
                    # Remove \n sequences from the beginning of the line
                    fixed_text = re.sub(r'^\n+', '', fixed_text)
                    dialog.message[locale] = fixed_text
                return [f'ks::SceneManager::nvl_show(0x{hashed_id}, {tl_index});']
            else:
                return [f'ks::SceneManager::show_dialog(0x{hashed_id}, ks::definitions::{dialog.actor_ref}, {tl_index});']
        elif dialog.actor:
            actor_tl_index = add_translations_optional(self.tl_dict, dialog.actor)
            return [f'ks::SceneManager::show_dialog(0x{hashed_id}, {actor_tl_index}, {tl_index});']
        else:
            return [f'ks::SceneManager::show_dialog(0x{hashed_id}, ks::definitions::no_char, {tl_index});']

    def process_sequence_doublespeak(self, group: SequenceGroup, ds: DoubleSpeakItem) -> List[str]:
        for locale, text in ds.message_left.items():
            ds.message_left[locale] = sanitize_ingame_text(text)
        for locale, text in ds.message_right.items():
            ds.message_right[locale] = sanitize_ingame_text(text)
        tl_index_left = add_translations_optional(self.tl_dict, ds.message_left)
        tl_index_right = add_translations_optional(self.tl_dict, ds.message_right)

        hashed_id = hashlib.md5(ds.id.encode()).hexdigest()[:8].upper()
        return [
            f'ks::SceneManager::show_doublespeak(0x{hashed_id}, ks::definitions::{ds.actor_left_ref}, {tl_index_left}, ks::definitions::{ds.actor_right_ref}, {tl_index_right});'
        ]

    def process_sequence_nvl_clear(self, group: SequenceGroup, nvl_clear: NovelClearItem) -> List[str]:
        return [f'ks::SceneManager::nvl_clear();']

    def process_sequence_nvl_hide(self, group: SequenceGroup, nvl_hide: NovelHideItem) -> List[str]:
        return [f'ks::SceneManager::nvl_hide();']

    def process_sequence_menu(self, group: SequenceGroup, menu: MenuItem) -> List[str]:
        return self.emit_menu_block(group, menu, indent=0)

    def process_sequence_music(self, group: SequenceGroup, music: MusicItem) -> List[str]:
        if music.action == MusicAction.PLAY:
            if music.effect == MusicEffect.FADEIN:
                return [f'ks::SceneManager::music_play({music.music.upper()}, {int(music.value * 60)});']
            else:
                return [f'ks::SceneManager::music_play({music.music.upper()});']
        elif music.action == MusicAction.STOP:
            if music.effect == MusicEffect.FADEOUT:
                return [f'ks::SceneManager::music_stop({int(music.value * 60)});']
            else:
                return [f'ks::SceneManager::music_stop();']
        return []

    def process_sequence_sound(self, group: SequenceGroup, sound: SoundItem) -> List[str]:
        if sound.action == SoundAction.PLAY:
            if sound.effect == SoundEffect.FADEIN:
                return [f'ks::SceneManager::sfx_play("{sound.sound}.8ad", {sound.channel.value}, {int(sound.value * 60)});']
            else:
                return [f'ks::SceneManager::sfx_play("{sound.sound}.8ad", {sound.channel.value});']
        elif sound.action == SoundAction.STOP:
            if sound.effect == SoundEffect.FADEOUT:
                return [f'ks::SceneManager::sfx_stop({sound.channel.value}, {int(sound.value * 60)});']
            else:
                return [f'ks::SceneManager::sfx_stop({sound.channel.value});']
        return []

    def process_sequence_return(self, group, ret: ReturnItem) -> List[str]:
        if group.is_called_inline:
            return []
        return [f'return;']

    def process_sequence_run_label(self, group: SequenceGroup, run_label: RunLabelItem) -> List[str]:
        class_name = self.get_class_name()
        callback = run_label.function_callback
        # e.g. ks::SceneManager::timeskip — already fully qualified
        if '::' in callback and not callback.startswith(f'{class_name}::'):
            return [f'{callback}();']
        if run_label.inline_call:
            print(f"{group.name} >>> Run Label (inline) {callback}")
            return [f'{class_name}::{callback}(); // INLINE CALL']
        print(f"{group.name} ({group.type}) >>> Run Label (direct) {callback}")
        return [f'{class_name}::{callback}(); // DIRECT CALL']

    def process_sequence_show(self, group: SequenceGroup, show: ShowItem) -> List[str]:
        # if not show.sprite in self.sprites:
        #     self.sprites.append(show.sprite)
        # TODO: rework, that's for test purposes only for the moment
        # if show.sprite == "black":
        if is_color_filled_bg(show.sprite):
            # TODO: show black behind bg
            return [f'ks::SceneManager::enable_fill(ks::globals::colors::{show.sprite.upper()});']
        elif show.sprite not in CHARACTERS:
            return [f'// TODO: Show {show.sprite}']
        elif show.variant == "behind":
            # TODO: behind keyword is not implemented yet
            return ["// TODO: behind keyword is not implemented yet"]
        else:
            # Predefined transforms — verbatim from KS's `script-transforms.rpy`:
            #   transform twoleft:    xpos 0.3  xanchor 0.5 ypos 1.0 yanchor 1.0
            #   transform tworight:   xpos 0.7  xanchor 0.5 ypos 1.0 yanchor 1.0
            #   transform closeleft:  xpos 0.25 xanchor 0.5 ypos 1.0 yanchor 1.0
            #   transform closeright: xpos 0.75 xanchor 0.5 ypos 1.0 yanchor 1.0
            #
            # Off-screen / left / right and center are KS-specific
            # nudges — values picked to match the legacy pixel-baked
            # output (e.g. previous `OFFSCREENLEFT = -184 px` ≈ xpos
            # -0.27 with xanchor 0.5 once you back out the
            # screen-mapping). All resolution to actual pixels happens
            # in `SceneManager::_resolve_pixel_position` against the
            # variant's body width — see scenemanager.cpp comments.
            renpy_pos: Tuple[float, float, float, float] | None = None
            if show.position == ShowPosition.TWOLEFT:
                renpy_pos = (0.3, 0.5, 1.0, 1.0)
            elif show.position == ShowPosition.TWORIGHT:
                renpy_pos = (0.7, 0.5, 1.0, 1.0)
            elif show.position == ShowPosition.CLOSELEFT:
                renpy_pos = (0.25, 0.5, 1.0, 1.0)
            elif show.position == ShowPosition.CLOSERIGHT:
                renpy_pos = (0.75, 0.5, 1.0, 1.0)
            elif show.position == ShowPosition.OFFSCREENLEFT:
                # Far off the left edge: anchor at right edge of body
                # so the whole body is offscreen.
                renpy_pos = (-0.25, 1.0, 1.0, 1.0)
            elif show.position == ShowPosition.OFFSCREENRIGHT:
                renpy_pos = (1.25, 0.0, 1.0, 1.0)
            elif show.position == ShowPosition.LEFT:
                # Inside the screen, anchored at left edge of body.
                renpy_pos = (0.0, 0.0, 1.0, 1.0)
            elif show.position == ShowPosition.RIGHT:
                renpy_pos = (1.0, 1.0, 1.0, 1.0)
            elif show.position == ShowPosition.CENTER:
                renpy_pos = (0.5, 0.5, 1.0, 1.0)
            elif show.position == ShowPosition.DEFAULT:
                renpy_pos = None  # keep slot's current transform
            else:
                raise TypeError("Unknown ShowPosition type")

            result = []

            if show.variant:
                displayable = f"{show.sprite}_{show.variant}"
                if show.sprite == "akira":
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "emi":
                    # TODO: remove this. That is WORKAROUND for Thursday script
                    displayable = CharacterDisplayableReplacements.emi(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "emicas":
                    displayable = CharacterDisplayableReplacements.emicas(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "eminude":
                    displayable = CharacterDisplayableReplacements.eminude(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.eminude(displayable))
                elif show.sprite == "emiwheel":
                    displayable = CharacterDisplayableReplacements.emiwheel(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "hanagown":
                    displayable = CharacterDisplayableReplacements.hanagown(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.hanagown(displayable))
                elif show.sprite == "hanako":
                    displayable = CharacterDisplayableReplacements.hanako(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "hideaki":
                    displayable = CharacterDisplayableReplacements.hideaki(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "jigoro":
                    displayable = CharacterDisplayableReplacements.jigoro(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "kenji":
                    displayable = CharacterDisplayableReplacements.kenji(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.kenji(displayable))
                elif show.sprite == "lilly":
                    displayable = CharacterDisplayableReplacements.lilly(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.lilly(displayable))
                elif show.sprite == "meiko":
                    displayable = CharacterDisplayableReplacements.meiko(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "miki":
                    displayable = CharacterDisplayableReplacements.miki(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "misha":
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "mishashort":
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "muto":
                    displayable = CharacterDisplayableReplacements.muto(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "nomiya":
                    displayable = CharacterDisplayableReplacements.nomiya(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "nurse":
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.nurse(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "rin":
                    displayable = CharacterDisplayableReplacements.rin(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "rinpan":
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "sae":
                    displayable = CharacterDisplayableReplacements.sae(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "shizu":
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.shizu(displayable))
                elif show.sprite == "shizuyu":
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "shopkeep":
                    displayable = CharacterDisplayableReplacements.shopkeep(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.default(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "yuuko":
                    displayable = CharacterDisplayableReplacements.yuuko(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.yuuko(),
                                                                 CharacterNudeIf.default(displayable))
                elif show.sprite == "yuukoshang":
                    displayable = CharacterDisplayableReplacements.yuukoshang(displayable)
                    character = CharacterSprite.from_displayable(displayable, CharacterRegex.yuukoshang(),
                                                                 CharacterNudeIf.default(displayable))
                else:
                    raise TypeError("Unknown character: " + show.sprite)

                tileset_key, _group_key, variant_symbol = smart_character_resolve(character)

                if tileset_key not in self.smart_character_tilesets:
                    self.smart_character_tilesets.append(tileset_key)

                variant_ref = f"ks::smart_characters::{tileset_key}::{variant_symbol}"

                if renpy_pos is None:
                    result.append(
                        f'ks::SceneManager::show_character('
                        f'CHARACTER_{show.sprite.upper()}, {variant_ref}, '
                        f'{show.palette_variant});')
                else:
                    xpos, xanchor, ypos, yanchor = renpy_pos
                    result.append(
                        f'ks::SceneManager::show_character('
                        f'CHARACTER_{show.sprite.upper()}, {variant_ref}, '
                        f'{show.palette_variant}, '
                        f'{fixed_literal(xpos)}, {fixed_literal(xanchor)}, '
                        f'{fixed_literal(ypos)}, {fixed_literal(yanchor)});')
                return result
            # Move if not default position and variant is not provided
            if renpy_pos is not None:
                xpos, xanchor, ypos, yanchor = renpy_pos
                result.append(
                    f'ks::SceneManager::set_character_position('
                    f'CHARACTER_{show.sprite.upper()}, '
                    f'{fixed_literal(xpos)}, {fixed_literal(xanchor)}, '
                    f'{fixed_literal(ypos)}, {fixed_literal(yanchor)});')

            return result

        # if show.event == ShowEvent.CHARACTER_CHANGE:
        #     return [
        #         f'// scene.add_sequence(ks::SpriteItem(bn::sprite_items::{show.sprite}, ks::SpriteEventType::CharacterChange));']
        # elif show.event == ShowEvent.NONE:
        #     return [
        #         f'// scene.add_sequence(ks::SpriteItem(bn::sprite_items::{show.sprite}, ks::SpriteEventType::None));']
        # else:
        #     raise TypeError("Unknown ShowEvent type")

    def process_sequence_hide(self, group: SequenceGroup, hide: HideItem) -> List[str]:
        # if hide.sprite == "black":
        if is_color_filled_bg(hide.sprite):
            return [f'ks::SceneManager::disable_fill();']
        elif hide.sprite not in CHARACTERS:
            return [f'// TODO: Hide {hide.sprite}']
        else:
            return [f'ks::SceneManager::hide_character(CHARACTER_{hide.sprite.upper()});']

    def process_sequence_bg_transform(self, group: SequenceGroup, bg_transform: BackgroundTransformItem) -> List[str]:
        # TODO: remove deuplicated positions code!!!!!!
        print(bg_transform.position)
        if bg_transform.position == BgShowPosition.BGLEFT:
            position = (8, 0)
        elif bg_transform.position == BgShowPosition.BGRIGHT:
            position = (-8, 0)
        elif bg_transform.position == BgShowPosition.CENTER:
            position = (0, 0)
        else:
            raise TypeError("Unknown BgShowPosition type")
        return [
            f'ks::SceneManager::set_background_position({position[0]}, {position[1]});']

    def process_sequence_bg_transition(self, group: SequenceGroup, bg_transition: BackgroundTransitionItem) -> List[str]:
        return [
            f'ks::SceneManager::set_background_transition({bg_transition.transition.value});'
        ]

    def process_sequence_show_transform(self, group: SequenceGroup, show_transform: ShowTransformItem) -> List[str]:
        print(show_transform)
        if show_transform.sprite not in CHARACTERS:
            return [
                f'// TODO: Show transform {show_transform.sprite} '
                f'xpos={show_transform.xpos} xanchor={show_transform.xanchor} '
                f'ypos={show_transform.ypos} yanchor={show_transform.yanchor}'
            ]
        return [
            f'ks::SceneManager::set_character_position('
            f'CHARACTER_{show_transform.sprite.upper()}, '
            f'{fixed_literal(show_transform.xpos)}, {fixed_literal(show_transform.xanchor)}, '
            f'{fixed_literal(show_transform.ypos)}, {fixed_literal(show_transform.yanchor)});'
        ]

    def process_sequence_pause(self, group: SequenceGroup, pause: PauseItem) -> List[str]:
        return [f'ks::SceneManager::pause({int(pause.value * 60)});']

    def process_sequence_update_visuals(self, group: SequenceGroup, update_visuals: UpdateVisualsItem) -> List[str]:
        return [f'ks::SceneManager::update_visuals();']

    def process_sequence_show_video(self, group: SequenceGroup, show_video: ShowVideoItem) -> List[str]:
        if show_video.video.startswith("tc_"):
            return [
                f'ks::SceneManager::show_title({show_video.video.upper()});',
                f'ks::SceneManager::set(ks::SceneManager("{self.filename}"));',
            ]

        if show_video.video == "op_1":
            return [
                f'ks::SceneManager::show_op1();',
                f'ks::SceneManager::set(ks::SceneManager("{self.filename}"));',
            ]

        if not show_video.video in self.videos:
            self.videos.append(show_video.video)
        return [
            f'ks::SceneManager::show_video(video_{show_video.video}_dxtv, "video_{show_video.video}.ulc");',
            f'ks::SceneManager::set(ks::SceneManager("{self.filename}"));',
        ]

    def get_class_name(self):
        return to_pascal_case(f'{self.filename}')

    def get_interface_name(self):
        return to_pascal_case(self.filename)


def defined(code, define_name, prefix="", suffix=""):
    define_name = f"{f"{prefix}_" if prefix else ""}{define_name}{f"_{suffix}" if suffix else ""}"
    return f"#ifndef {define_name}\n#define {define_name}\n\n{code}\n\n#endif // {define_name}"


def namespace(code, name=""):
    return f"namespace {name} {{\n{indented(code)}\n}}"


def as_class(code, class_name="", extends_name=""):
    return f"class {class_name}{f" : public {extends_name}" if extends_name else ""} {{\n{indented(code)}\n}};"

def as_public(code):
    return f"public:\n{indented(code)}"


def include_header(header, prefix="", suffix=""):
    return f"#include \"{prefix}{header}{suffix}.h\""


def comment(text):
    return f"// {text}"


def indented(code: str, indent=4):
    return "\n".join(f"{' ' * indent}{line}" for line in code.splitlines())


def indented_l(code: List[str], indent=4):
    return "\n".join(f"{' ' * indent}{line}" for line in code)


def label_signature(group: SequenceGroup, ns: str | None = None):
    print(f"   >>> Label: {f"{ns}::" if ns else ""}{group.name}, is_called_inline: {group.is_called_inline}")
    return f"void {f"{ns}::" if ns else ""}{group.name}()"


def menu_signature(group: SequenceGroup, ns: str | None = None):
    return f"void {f"{ns}::" if ns else ""}{group.name}()"


def answer_signature(group: SequenceGroup, answer: ConditionWrapper, ns: str | None = None):
    return f"void {f"{ns}::" if ns else ""}{answer.function_callback}()"


def condition_signature(group: SequenceGroup, num: int, ns: str | None = None):
    return f"void {f"{ns}::" if ns else ""}{group.name}_{num}()"


def to_pascal_case(s: str) -> str:
    return ''.join(word.capitalize() for word in s.split('_'))

def to_snake_case(name):
    name = re.sub('(.)([A-Z][a-z]+)', r'\1_\2', name)
    name = re.sub('__([A-Z])', r'_\1', name)
    name = re.sub('([a-z0-9])([A-Z])', r'\1_\2', name)
    return name.lower()

def to_cpp_condition(s: str) -> str:
    # "in" statement
    # var in (A, B, C, D): -> (var == A || var == B || var == C || var == D)
    in_pattern = re.compile(r'(\b[a-zA-Z_][a-zA-Z0-9_]*\b)\s+in\s+\(([^)]+)\)')
    s = in_pattern.sub(lambda m: '(' + ' || '.join(f'{m.group(1)} == {item.strip()}' for item in m.group(2).split(',')) + ')', s)

    # Replace logical operators and boolean literals
    return (s.replace("not ", "!")
            .replace(" and ", " && ")
            .replace(" or ", " || ")
            .replace("True", "true")
            .replace("False", "false"))


def to_ks_progress_variables(s: str) -> str:
    def replacer(match):
        variable = match.group(0)
        if variable == "_in_replay":
            return "ks::in_replay"
        elif variable in ["true", "false"]:
            return variable
        elif variable in ["FR_NONE", "FR_EMI", "FR_HANAKO", "FR_LILLY", "FR_RIN", "FR_SHIZU", "FR_KENJI"]:
            return variable
        elif variable.startswith("settings___"):
            return f"ks::globals::settings.{variable.removeprefix("settings___")}"
        return f"ks::progress.{variable}"

    # Regex to match variable names (assumes they are composed of letters, numbers, and underscores)
    return re.sub(r'\b[a-zA-Z_][a-zA-Z0-9_]*\b', replacer, s)
