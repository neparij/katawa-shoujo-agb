import hashlib
import os
import re
from typing import List, cast, Dict

from src.character_sprite.character_sprite import CharacterDisplayableReplacements
from src.dto.assignment_item import AssignmentItem
from src.dto.background_item import BackgroundItem
from src.dto.condition_item import ConditionItem
from src.dto.dialog_item import DialogItem
from src.dto.hide_item import HideItem
from src.dto.menu_item import MenuItem
from src.dto.music_item import MusicItem, MusicAction
from src.dto.return_item import ReturnItem
from src.dto.run_label_item import RunLabelItem
from src.dto.sequence_item import SequenceItem, SequenceType
from src.dto.show_item import ShowItem, ShowEvent, ShowPosition
from src.scenario.sequence_group import SequenceGroup, SequenceGroupType, ConditionWrapper
from src.utils import sanitize_function_name, sanitize_comment_text

DEFAULT_LOCALE = "en"


class ScenarioWriter:
    def __init__(self, filename: str, output_dir: str, gbfs_dir: str, scenario: List[SequenceGroup],
                 locale: str = DEFAULT_LOCALE):
        self.filename = filename
        self.output_dir = output_dir
        self.gbfs_dir = gbfs_dir
        self.scenario = scenario
        self.tl_indexes: Dict[str, int] = {}
        self.tl_list: List[str] = []
        self.locale = locale if locale else DEFAULT_LOCALE

        self.backgrounds = []
        self.events = []
        self.music = []
        self.sprites = []
        self.sprite_metas = []
        self.characters: Dict[str, int] = {}

    def clean(self):
        self.clean_output_dir()
        self.clean_gbfs_dir_translations()

    def clean_output_dir(self):
        # delete all files in output_dir
        for root, dirs, files in os.walk(self.output_dir):
            for file in files:
                os.remove(os.path.join(root, file))

    def clean_gbfs_dir_translations(self):
        # delete all files in gbfs_dir with mask tl_*.locale
        for root, dirs, files in os.walk(self.gbfs_dir):
            for file in files:
                if file.startswith("tl_") and file.endswith(f".{self.locale}"):
                    os.remove(os.path.join(root, file))

    def write(self):
        os.makedirs(os.path.dirname(os.path.join(self.output_dir, self.filename)), exist_ok=True)
        self.write_source()
        if self.locale == DEFAULT_LOCALE:
            self.write_header()
        self.write_scenario_tl()

    def write_header(self):
        define_name = f"{self.filename.split(".")[0].upper().replace("-", "_")}"
        h_code = [
            # Include SequenceItem headers
            include_header("../sequence/assignmentitem"),
            include_header("../sequence/backgrounditem"),
            include_header("../sequence/dialogitem"),
            include_header("../sequence/menuitem"),
            include_header("../sequence/musicitem"),
            include_header("../sequence/runlabelfinishitem"),
            include_header("../sequence/runlabelitem"),
            include_header("../sequence/spriteitem"),
            # Include common stuff
            include_header("../scenemanager"),
            # Include common BN stuff
            # include_header("bn_music_items"),
        ]

        for background in self.backgrounds:
            h_code.append(include_header(background, "bn_regular_bg_items_"))

        for sprite in self.sprites:
            h_code.append(include_header(sprite, "bn_sprite_items_"))

        for sprite_meta in self.sprite_metas:
            h_code.append(include_header(sprite_meta))

        function_declarations = [
            f'virtual ~{self.get_interface_name()}() = default;',
        ]

        function_declarations.append(comment("Labels"))
        for label in self.get_labels():
            function_declarations.append(f"static {label_signature(label)};")

        function_declarations.append(comment("Choice functions"))
        for menu in self.get_menus():
            function_declarations.append(f"static {menu_signature(menu)};")
            for answer in menu.conditions:
                function_declarations.append(f"static {answer_signature(menu, answer)};")

        function_declarations.append(comment("Conditions"))
        for condition in self.get_conditions():
            cnum = 0
            for variant in condition.conditions:
                function_declarations.append(f"static {condition_signature(condition, cnum)};")
                cnum += 1

        public_functions = as_public("\n".join(function_declarations))
        class_code = as_class(public_functions, self.get_interface_name())

        h_code.append(namespace(class_code, "ks"))

        with open(f"{os.path.join(self.output_dir, self.filename)}.h", "w") as h_file:
            h_file.write(defined("\n".join(h_code), define_name, "KS"))

    def write_source(self):
        cpp_code = [
            include_header(f"{self.filename}"),
            include_header(f"{self.filename}_{self.locale}_tl_index"),
        ]
        functions = []

        for label in self.get_labels():
            sequences = []
            if label.is_called_inline and not label.is_initial:
                sequences.append(f'ks::SceneManager::free_resources();')
            elif label.is_initial:
                sequences.append(
                    f'ks::SceneManager::set(ks::SceneManager("{self.filename}", "{self.locale}", {sanitize_function_name(self.filename)}_{self.locale}_intl));\n')
            for sequence in label.sequence:
                sequence_code = self.process_sequence(label, sequence)
                if sequence_code:
                    sequences.extend(sequence_code)
            # if label.is_called_inline and not label.is_initial:
            #     sequences.append("scene.start();\n")
            #     sequences.extend([
            #         "while(!scene.is_finished()) {",
            #         "    scene.update();",
            #         "}"
            #     ])
            functions.append(f"static {label_signature(label)} {{\n{indented_l(sequences)}\n}}")

        for menu in self.get_menus():
            sequences = []
            for sequence in menu.sequence:
                sequence_code = self.process_sequence(menu, sequence)
                if sequence_code:
                    sequences.extend(sequence_code)
            answers_indexes = []

            sequences.append(f'bn::vector<int, 5> answers;')
            for answer in menu.conditions:
                tl_index = self.tl_indexes.get(answer.answer)

                if tl_index is None:  # Only process if the id is not already in the index
                    for i, tl in enumerate(self.tl_list):
                        if answer.answer == tl:  # Check for duplicate message
                            tl_index = i
                            break
                    else:  # If no duplicate is found
                        tl_index = len(self.tl_list)
                        self.tl_list.append(answer.answer)  # Add the message to the list

                    self.tl_indexes[answer.answer] = tl_index  # Store the index for the id
                answers_indexes.append(str(tl_index))
                sequences.append(f'answers.push_back({tl_index});') if not answer.condition else sequences.append(
                    f'if ({to_ks_progress_variables(to_cpp_condition(answer.condition))}) answers.push_back({tl_index});')

            sequences.append(f'ks::SceneManager::show_dialog_question(answers);')
            sequences.append(f'int answer = ks::SceneManager::get_dialog_question_answer();')

            answer_callbacks = []
            for answer in menu.conditions:
                answer_callbacks.append(f'if (answer == {len(answer_callbacks)}) {{\n'
                                        f'    {self.get_class_name()}::{answer.function_callback}();\n'
                                        f'}}')

            sequences.extend(" else ".join(answer_callbacks).split("\n"))

            functions.append(f"static {menu_signature(menu)} {{\n{indented_l(sequences)}\n}}")

            for answer in menu.conditions:
                sequences = []
                for seq in answer.sequence:
                    sequences.extend(self.process_sequence(menu, seq))
                functions.append(f"static {answer_signature(menu, answer)} {{\n{indented_l(sequences)}\n}}")

        for condition in self.get_conditions():
            cnum = 0
            for variant in condition.conditions:
                sequences = []
                for seq in variant.sequence:
                    sequence_code = self.process_sequence(condition, seq)
                    if sequence_code:
                        sequences.extend(sequence_code)
                functions.append(f"static {condition_signature(condition, cnum)} {{\n{indented_l(sequences)}\n}}")
                cnum += 1

        functions = as_public("\n".join(functions))
        class_code = as_class(functions, self.get_class_name(), self.get_interface_name())

        cpp_code.append(namespace(class_code, "ks"))

        with open(f"{os.path.join(self.output_dir, self.filename)}{self.locale_suffix()}.cpp", "w") as cpp_file:
            cpp_file.write("\n".join(cpp_code))

    def write_scenario_tl(self):
        current_offset = 0
        define_name = f"{self.filename.split(".")[0].upper().replace("-", "_")}"
        h_code = [include_header("bn_vector"),
                  # f'inline void init_tl_index(bn::vector<unsigned int, {len(self.tl_list)}>& offset_index) {{',
                  # TODO: Decrease mem consuption
                  f'constexpr unsigned int {sanitize_function_name(self.filename)}_{self.locale}_intl[] = {{',
                  ]

        for tl in self.tl_list:
            h_code.append(f'    0x{current_offset:04X}, // {sanitize_comment_text(tl)}')
            current_offset += len(tl.encode("utf-8")) + 1  # +1 for null terminator

        h_code.append("};")

        with open(f"{os.path.join(self.output_dir, self.filename)}_{self.locale}_tl_index.h", "w") as h_file:
            h_file.write(defined("\n".join(h_code), define_name, "KS", f"{self.locale.upper()}_TL_INDEX"))

        tl_filename = f"tl_{self.filename}.{self.locale}"
        os.makedirs(os.path.dirname(os.path.join(self.gbfs_dir, tl_filename)), exist_ok=True)
        with open(f"{os.path.join(self.gbfs_dir, self.filename)}.{self.locale}", "wb") as tl_file:
            for value in self.tl_list:
                tl_file.write(value.encode("utf-8") + b'\0')

    def get_labels(self) -> List[SequenceGroup]:
        return [group for group in self.scenario if group.type == SequenceGroupType.LABEL]

    def get_menus(self) -> List[SequenceGroup]:
        return [group for group in self.scenario if group.type == SequenceGroupType.MENU]

    def get_conditions(self) -> List[SequenceGroup]:
        return [group for group in self.scenario if group.type == SequenceGroupType.CONDITION]

    def process_sequence(self, group: SequenceGroup, sequence: SequenceItem) -> List[str]:
        if sequence.type == SequenceType.ASSIGNMENT:
            return self.process_sequence_assignment(group, cast(AssignmentItem, sequence))
        elif sequence.type == SequenceType.BACKGROUND:
            return self.process_sequence_background(group, cast(BackgroundItem, sequence))
        elif sequence.type == SequenceType.CONDITION:
            return self.process_sequence_condition(group, cast(ConditionItem, sequence))
        elif sequence.type == SequenceType.DIALOG:
            return self.precess_sequence_dialogue(group, cast(DialogItem, sequence))
        elif sequence.type == SequenceType.MENU:
            return self.process_sequence_menu(group, cast(MenuItem, sequence))
        elif sequence.type == SequenceType.MUSIC:
            return self.process_sequence_music(group, cast(MusicItem, sequence))
        elif sequence.type == SequenceType.RETURN:
            return self.process_sequence_return(group, cast(ReturnItem, sequence))
        elif sequence.type == SequenceType.RUN_LABEL:
            return self.process_sequence_run_label(group, cast(RunLabelItem, sequence))
        elif sequence.type == SequenceType.SHOW:
            return self.process_sequence_show(group, cast(ShowItem, sequence))
        elif sequence.type == SequenceType.HIDE:
            return self.process_sequence_hide(group, cast(HideItem, sequence))
        return []

    def process_sequence_assignment(self, group: SequenceGroup, assignment: AssignmentItem) -> List[str]:
        assignment_regex = r'^[a-zA-Z_][a-zA-Z0-9_]*\s*(=|\+=|-=|\*=|/=)\s*.*$'

        if re.match(assignment_regex, assignment.content):
            return [f'{to_ks_progress_variables(to_cpp_condition(assignment.content))};']
        else:
            print(f"Unknown assignment: {assignment.content}")
            return [f'// {assignment.content}; TODO: unknown assignment']
        # return [f'// scene.add_sequence(ks::AssignmentItem("{assignment.content}"));']

    def process_sequence_background(self, group: SequenceGroup, bg: BackgroundItem) -> List[str]:
        if not bg.background in self.backgrounds:
            self.backgrounds.append(bg.background)
        return [f'ks::SceneManager::set_background(bn::regular_bg_items::{bg.background});']

    def process_sequence_condition(self, group: SequenceGroup, condition: ConditionItem) -> List[str]:
        matching_scenario_item = next((item for item in self.scenario if item.name == condition.function_callback),
                                      None)
        code = []
        cnum = 0
        for variant in matching_scenario_item.conditions:
            if variant.condition:
                condition_variant = f"if ({to_ks_progress_variables(to_cpp_condition(variant.condition))})"
            elif variant.condition and cnum > 0:
                condition_variant = f"else if ({to_ks_progress_variables(to_cpp_condition(variant.condition))})"
            elif cnum == len(matching_scenario_item.conditions) - 1 and not variant.condition:
                condition_variant = "else"
            else:
                raise TypeError("Unknown Condition type")
            code.extend([f'{condition_variant} {{',
                         f'    {self.get_class_name()}::{condition.function_callback}_{cnum}();',
                         f'}} '])
            cnum += 1

        code.append("\n")
        return code

    def precess_sequence_dialogue(self, group: SequenceGroup, dialog: DialogItem) -> List[str]:
        tl_index = self.tl_indexes.get(dialog.id)

        if tl_index is None:  # Only process if the id is not already in the index
            for i, tl in enumerate(self.tl_list):
                if dialog.message == tl:  # Check for duplicate message
                    tl_index = i
                    break
            else:  # If no duplicate is found
                tl_index = len(self.tl_list)
                self.tl_list.append(dialog.message)  # Add the message to the list

            self.tl_indexes[dialog.id] = tl_index  # Store the index for the id

        if dialog.actor_ref:
            return [f'ks::SceneManager::show_dialog("{dialog.actor_ref}", {tl_index});']
            # return [f'scene.add_dialog("{dialog.actor_ref}", \"{resulted_hash}\");']
        elif dialog.actor:
            return [f'ks::SceneManager::show_dialog("{dialog.actor}", {tl_index});']
        else:
            return [f'ks::SceneManager::show_dialog("", {tl_index});']

    def process_sequence_menu(self, group: SequenceGroup, menu: MenuItem) -> List[str]:
        return [
            f'{self.get_class_name()}::{menu.function_callback}();']
        # f'{menu.function_callback}();']
        # return [
        #     f'// scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){{{self.get_class_name()}::{menu.function_callback}(scene);}}));']

    def process_sequence_music(self, group: SequenceGroup, music: MusicItem) -> List[str]:
        if music.action == MusicAction.PLAY:
            return [f'ks::SceneManager::music_play("{music.music}.gsm");']
        elif music.action == MusicAction.STOP:
            return [f'ks::SceneManager::music_stop();']
        return []

    def process_sequence_return(self, group, ret: ReturnItem) -> List[str]:
        if group.is_called_inline:
            return []
        return [f'return;']

    def process_sequence_run_label(self, group: SequenceGroup, run_label: RunLabelItem) -> List[str]:
        if run_label.inline_call:
            return [
                f'{run_label.function_callback}();',
            ]
        else:
            # return [f'scene.add_sequence(ks::RunLabelItem(&{self.get_class_name()}::{run_label.function_callback}));']
            # return [f'scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){{{self.get_class_name()}::{menu.function_callback}();}}));']
            return [f'{self.get_class_name()}::{run_label.function_callback}();']
            # return [f'{run_label.function_callback}();']
            # return [
            #     f'// scene.add_sequence(ks::RunLabelItem([](ks::SceneManager& scene){{{self.get_class_name()}::{run_label.function_callback}(scene);}}));']

    def process_sequence_show(self, group: SequenceGroup, show: ShowItem) -> List[str]:
        # if not show.sprite in self.sprites:
        #     self.sprites.append(show.sprite)

        # TODO: rework, that's for test purposes only for the moment
        if show.sprite in ["shizu", "misha", "rin", "lilly"]:
            character_index = self.characters.get(show.sprite)
            if show.position == ShowPosition.TWOLEFT:
                position = (-48, 0)
            elif show.position == ShowPosition.TWORIGHT:
                position = (48, 0)
            elif show.position == ShowPosition.CLOSELEFT:
                position = (-60, 0)
            elif show.position == ShowPosition.CLOSERIGHT:
                position = (60, 0)
            elif show.position == ShowPosition.OFFSCREENLEFT:
                # TODO: Calculate bsed on sprite width
                position = (-120 - 0, 0)
            elif show.position == ShowPosition.OFFSCREENRIGHT:
                # TODO: Calculate bsed on sprite width
                position = (120 + 0, 0)
            elif show.position == ShowPosition.LEFT:
                # TODO: Calculate bsed on sprite width
                position = (-120 + 40, 0)
            elif show.position == ShowPosition.RIGHT:
                # TODO: Calculate bsed on sprite width
                position = (120 - 40, 0)
            elif show.position == ShowPosition.DEFAULT:
                position = (0, 0)
            else:
                raise TypeError("Unknown ShowPosition type")

            result = []

            if character_index is None:
                character_index = len(self.characters)
                self.characters[show.sprite] = character_index
            if show.variant:
                if show.sprite == "lilly":
                    # Fix for Lilly's custom poses
                    show.variant = CharacterDisplayableReplacements.lilly(show.variant)

                # character_bg_name = f'{show.sprite}_bg_{show.variant.split("_")[0]}'
                # TODO: support _close notation
                character_bg_name = f'{show.sprite}_bg_{show.variant.split("_")[0]}'.removesuffix("_close")
                if not character_bg_name in self.backgrounds:
                    self.backgrounds.append(character_bg_name)
                # character_spr_name = f'{show.sprite}_spr_{"_".join(show.variant.split("_")[0:])}'
                # TODO: support _close notation
                character_spr_name = f'{show.sprite}_spr_{"_".join(show.variant.split("_")[0:])}'.removesuffix("_close").removesuffix("_ss")
                if not character_spr_name in self.sprites:
                    self.sprites.append(character_spr_name)
                # character_sprite_meta_name = f'{show.sprite}_{show.variant.split("_")[0]}'
                # TODO: support _close notation
                character_sprite_meta_name = f'{show.sprite}_{show.variant.split("_")[0]}'.removesuffix("_close").removesuffix("_ss")
                if not character_sprite_meta_name in self.sprite_metas:
                    self.sprite_metas.append(character_sprite_meta_name)

                if show.position == ShowPosition.DEFAULT:
                    result.append(
                        f'ks::SceneManager::show_character({character_index}, bn::regular_bg_items::{character_bg_name}, bn::sprite_items::{character_spr_name}, ks::sprite_metas::{character_sprite_meta_name});')
                else:
                    result.append(
                        f'ks::SceneManager::show_character({character_index}, bn::regular_bg_items::{character_bg_name}, bn::sprite_items::{character_spr_name}, ks::sprite_metas::{character_sprite_meta_name}, {position[0]}, {position[1]});')
                return result
            if show.position != ShowPosition.DEFAULT:
                result.append(
                    f'ks::SceneManager::set_character_position({character_index}, {position[0]}, {position[1]});')

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
        if hide.sprite in ["shizu", "misha", "rin", "lilly"]:
            character_index = self.characters.get(hide.sprite)
            if character_index is None:
                raise f'"{hide.sprite}" is not in character index. Attempt to hide not shown character?'
            return [f'ks::SceneManager::hide_character({character_index});']

    def locale_suffix(self):
        return f"_{self.locale}" if self.locale else ""

    def get_class_name(self):
        return to_pascal_case(f'{self.filename}{self.locale_suffix()}')

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


def label_signature(group: SequenceGroup):
    if group.is_called_inline:
        return f"void {group.name}()"
    else:
        return f"void {group.name}()"


def menu_signature(group: SequenceGroup):
    return f"void {group.name}()"


def answer_signature(group: SequenceGroup, answer: ConditionWrapper):
    return f"void {answer.function_callback}()"


def condition_signature(group: SequenceGroup, num: int):
    return f"void {group.name}_{num}()"


def to_pascal_case(s: str) -> str:
    return ''.join(word.capitalize() for word in s.split('_'))


def to_cpp_condition(s: str) -> str:
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
        return f"ks::progress.{variable}"

    # Regex to match variable names (assumes they are composed of letters, numbers, and underscores)
    return re.sub(r'\b[a-zA-Z_][a-zA-Z0-9_]*\b', replacer, s)
