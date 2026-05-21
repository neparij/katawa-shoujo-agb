import copy
import hashlib
import os
import re
import tempfile
from time import sleep
from typing import List, cast, Dict

from src.dto.assignment_item import AssignmentItem
from src.dto.background_item import BackgroundItem, BgShowPosition, BgTransition
from src.dto.background_transform_item import BackgroundTransformItem
from src.dto.background_transition_item import BackgroundTransitionItem
from src.dto.condition_item import ConditionItem
from src.dto.custom_event_item import CustomEventItem
from src.dto.custom_event_state_item import CustomEventStateItem
from src.dto.dialog_item import DialogItem
from src.dto.doublespeak_item import DoubleSpeakItem
from src.dto.hide_item import HideEvent, HideItem
from src.dto.menu_item import MenuItem
from src.dto.music_item import MusicItem, MusicAction, MusicEffect
from src.dto.novel_clear_item import NovelClearItem
from src.dto.novel_hide_item import NovelHideItem
from src.dto.pause_item import PauseItem
from src.dto.return_item import ReturnItem
from src.dto.run_label_item import RunLabelItem
from src.dto.sequence_item import SequenceType, SequenceItem
from src.dto.show_item import ShowEvent, ShowItem, ShowPosition
from src.dto.show_displayable_item import ShowDisplayableItem
from src.displayable_utils import is_displayable_sprite, split_displayable_sprite, displayable_palette_variant
from src.dto.show_transform_item import ShowTransformItem
from src.dto.show_video_item import ShowVideoItem
from src.dto.sound_item import SoundItem, SoundAction, SoundEffect, SoundChannel
from src.dto.update_visuals_item import UpdateVisualsItem
from src.scenario.scenario_script_stack import ScenarioScriptStack
from src.scenario.sequence_group import SequenceGroup, SequenceGroupType
from src.translation.translation_container import TranslationContainer
from src.utils import sanitize_function_name, starts_with_filled_bg, \
    sanitize_ingame_text, get_sprite_paletted_variant, get_bg_paletted_variant

DEFAULT_LOCALE = "en"

class ScenarioReader:
    def __init__(self, scenario_file, translations: Dict[str, TranslationContainer]):
        self.scenario_file = scenario_file
        self.translations = translations
        self.scenario: List[SequenceGroup] = []
        self.stack: ScenarioScriptStack = ScenarioScriptStack()
        self.initial_name = None
        self._hack_nvl_cleared = False
        self._hack_latest_label_name = None
        self._hack_latest_sprite_name = None
        self.linepack_events : List[SequenceItem] = []
        self.bgs_images_cache : List[str] = []

    def set_bgs_images_cache(self, bgs_images_cache):
        self.bgs_images_cache = bgs_images_cache

    def read(self) -> List[SequenceGroup]:
        """Reads the scenario file and returns a list of sequence groups."""

        with tempfile.TemporaryFile(mode='w+t', encoding="utf-8") as f:
            with open(self.scenario_file, 'r', encoding="utf-8") as source_file:
                content = source_file.read()
            content = scenario_rewrites(self.scenario_file, content)
            f.write(content)
            f.seek(0)
            lines = f.readlines()

        line_pack = []
        for line in lines:
            if line.strip():
                current_indent = get_line_indent(line)
                line_pack.append((line, current_indent))
            else:
                self.process_line_pack(line_pack)

        if line_pack:
            self.process_line_pack(line_pack)

        self.pop_stack_if_unindented(0, "")

        if self.stack.size() > 0:
            raise Exception("Scenario ended, but stack is not empty")

        return self.scenario.copy()

    def calculate_tl_hash(self, line, nointeract=False):
        md5 = hashlib.md5()
        md5.update((f"{line}{" nointeract" if nointeract else ""}" + "\r\n").encode("utf-8"))
        label = self.stack.current_label()
        if label:
            tl_fixed_name = label.name
            base = f"{tl_fixed_name}_{md5.hexdigest()[:8]}"
        else:
            base = md5.hexdigest()[:8]
        result = base

        i = 0
        while result in label.translation_identifiers:
            i += 1
            result = f"{base}_{i}"

        label.translation_identifiers.append(result)
        return result

    # TODO: Check that
    def close_conditions(self, current_indent, next_line):
        """Closes conditions until reaching the target indentation."""
        has_next_condition = next_line.startswith("elif ") or next_line.startswith("else:")
        if self.stack.size() > 0 and self.stack.current().type == SequenceGroupType.CONDITION and self.stack.current_indent() >= current_indent and not (has_next_condition and self.stack.current_indent() < get_line_indent(next_line)):
        # while self.stack.size() > 0 and self.stack.current().type == SequenceGroupType.CONDITION and self.stack.current_indent() >= current_indent and not has_conditional_operator:
            condition = self.stack.pop()
            self.scenario.append(condition)

    # def close_conditions(self, current_indent, next_line):
    #     """Closes conditions until reaching the target indentation."""
    #     while self.stack.size() > 0 and self.stack.current().type == SequenceGroupType.CONDITION and self.stack.current_indent() >= current_indent:
    #         print(f"      - pop condition (current stack indent: {self.stack.current_indent()}, current line indent: {current_indent})")
    #         condition = self.stack.pop()
    #         self.scenario.append(condition)

    def close_menus(self, current_indent):
        """Closes menu blocks until reaching the target indentation."""
        while self.stack.size() > 0 and self.stack.current().type == SequenceGroupType.MENU and self.stack.current_indent() >= current_indent:
            menu = self.stack.pop()
            self.scenario.append(menu)

    def close_labels(self, current_indent):
        """Closes label blocks until reaching the target indentation."""
        while self.stack.size() > 0 and self.stack.current().type == SequenceGroupType.LABEL and self.stack.current_indent() >= current_indent:
            label = self.stack.pop()
            self.scenario.append(label)

    def pop_stack_if_unindented(self, current_indent, next_line):
        """Close blocks based on the current indentation level."""
        has_condition = next_line.startswith("elif ") or next_line.startswith("else:")
        stack_size = self.stack.size()

        while self.stack.size() > 0:
            stack_indent = self.stack.current_indent()

            # Ensure we do not close a parent `if` block if there's an `elif` or `else`
            if stack_indent < current_indent or (has_condition and stack_indent == current_indent):
                break

            current_group = self.stack.current()
            if current_group.type == SequenceGroupType.CONDITION:
                self.close_conditions(current_indent, next_line)
            elif current_group.type == SequenceGroupType.MENU:
                self.close_menus(current_indent)
            elif current_group.type == SequenceGroupType.LABEL:
                self.close_labels(current_indent)
            else:
                raise Exception(f"Unknown stack type: {current_group.type}")

    def process_line_pack(self, line_pack):
        with_clause = None
        self.linepack_events : List[SequenceItem] = []
        for line, current_indent in line_pack:
           self.process_line(line, current_indent)
        line_pack.clear()
        # TODO: process show sequence with "at" clause here!

        if (has_sequence_item_with_type(self.linepack_events, SequenceType.SHOW) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.SHOW_DISPLAYABLE) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.HIDE) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.SHOW_TRANSFORM) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.BACKGROUND_TRANSITION) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.BACKGROUND_TRANSFORM) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.BACKGROUND) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.CUSTOM_EVENT)):
            self.stack.current().add_sequence_item(self.linepack_events, UpdateVisualsItem())

    def process_line(self, line, current_indent):
        stripped_line = line.strip()

        if stripped_line.startswith("#"):
            return

        self.pop_stack_if_unindented(current_indent, stripped_line)

        _hack_prepend_dialog_nvl_clear = self._hack_nvl_cleared
        self._hack_nvl_cleared = False

        # TODO: REMOVE THIS WORKAROUND:
        if stripped_line.startswith("show misha behind shizu at"):
            return

        if stripped_line.startswith("label "):
            label_name = stripped_line.split("label ", 1)[1].strip(":")
            self._hack_latest_label_name = label_name
            if label_name.startswith("."):
                label_name = label_name[1:]
                print(f" >> Relative label detected: {label_name}")
                if self.stack.size() == 0 and not self._hack_latest_label_name:
                    raise Exception("Initial label cannot be a relative label")
                elif self.stack.size() == 0:
                    # label_name = f"{self._hack_latest_label_name}_{label_name}"
                    label_name = f"{label_name}"
            name = sanitize_function_name(label_name)

            if self.stack.size() > 0:
                name = f"{self.stack.parent_label().name}_{name}"
                self.stack.current().add_sequence_item(self.linepack_events, RunLabelItem(name, self.initial_name and name.startswith(self.initial_name), label_name=self.stack.current_label().name))
            else:
                name = name

            if not self.initial_name:
                self.initial_name = name
                self.stack.push(SequenceGroup(current_indent, name, SequenceGroupType.LABEL, True, True), current_indent)
            else:
                self.stack.push(SequenceGroup(current_indent, name, SequenceGroupType.LABEL, name.startswith(self.initial_name)), current_indent)
            return

        elif stripped_line == "return":
            self.stack.current().add_sequence_item(self.linepack_events, ReturnItem())
            return

        elif stripped_line.startswith("if "):
            condition = stripped_line.split("if ", 1)[1].strip(":")
            print(f" >> If condition before rewrite: {condition}")
            print(f"    current indent: {self.stack.current_indent()}")
            print(f"    current label: {self.stack.current_label().name}")
            condition = rewrite_condition(condition)

            # TODO: custom condition definition for _in_replay
            #     Example in rpy scenario:
            #     if _in_replay:
            #         return

            if self.stack:
                name = f"{self.stack.current().name}__condition_{sum(1 for item in self.stack.current().sequence if isinstance(item, ConditionItem))}"
            else:
                raise Exception("Condition block outside of label stack")

            self.stack.current().add_sequence_item(self.linepack_events, ConditionItem(name))

            condition_stack = SequenceGroup(current_indent, name, SequenceGroupType.CONDITION)
            condition_stack.add_condition(self.stack.current_label().name, condition=condition)
            self.stack.push(condition_stack, current_indent)
            print(f" >> Current condition indent: {current_indent}")
            return

        elif stripped_line.startswith("elif "):
            condition = stripped_line.split("elif ", 1)[1].strip(":")
            print(f" >> Elif condition before rewrite: {condition}")
            print(f"    current indent: {self.stack.current_indent()}")
            print(f"    current label: {self.stack.current_label().name}")
            condition = rewrite_condition(condition)
            if self.stack.current().type != SequenceGroupType.CONDITION:
                raise Exception("Elif block outside of condition block")
            self.stack.current().add_condition(self.stack.current_label().name, condition=condition)
            return

        elif stripped_line.startswith("else:"):
            print(f" >> Else condition")
            print(f"    current indent: {self.stack.current_indent()}")
            print(f"    current label:    current label: {self.stack.current_label().name}")
            if self.stack.current().type != SequenceGroupType.CONDITION:
                raise Exception("Else block outside of condition block")
            self.stack.current().add_condition(self.stack.current_label().name)
            return

        elif stripped_line.startswith("menu:"):
            if self.stack:
                name = f"{self.stack.current().name}__menu_question_{sum(1 for item in self.stack.current().sequence if isinstance(item, MenuItem))}"
            else:
                raise Exception("Menu block outside of label stack")

            self.stack.current().add_sequence_item(self.linepack_events, MenuItem(name))
            self.stack.push(SequenceGroup(current_indent, name, SequenceGroupType.MENU), current_indent)
            return

        elif self.stack.current().type == SequenceGroupType.MENU and stripped_line.startswith("\"") and current_indent == self.stack.current().indentation_level + 1:
            # Parse menu choice
            match = re.match(r"\"(.*)\"(?:| if (.*)):$", stripped_line)
            if match:
                choice_text = {
                    DEFAULT_LOCALE: match.group(1)
                }
                condition_block = match.group(2)
                print(f" >> Choice_text: {choice_text[DEFAULT_LOCALE]}, condition: {condition_block}")
                for locale, translation in self.translations.items():
                    if locale == DEFAULT_LOCALE:
                        continue
                    if choice_text[DEFAULT_LOCALE] in translation.strings:
                        translated = translation.strings[choice_text[DEFAULT_LOCALE]]
                        choice_text[locale] = sanitize_ingame_text(translated)
                    else:
                        raise Exception(f"Missing translation for key: {choice_text[DEFAULT_LOCALE]} in locale {locale}")
                        # choice_text[locale] = choice_text[DEFAULT_LOCALE]
                    print(f"    - {locale}: {choice_text[locale]}")

                condition = condition_block if condition_block else None
                print(f"Adding menu answers inside label [[[{self.stack.current_label().name}]]]")
                self.stack.current().add_answer(
                    self.stack.current_label().name,
                    answer = choice_text,
                    condition = condition,
                    callback = f"{self.stack.current().name}_{sanitize_function_name(choice_text[DEFAULT_LOCALE])}"
                )
            return

        elif stripped_line.startswith("$ "):
            # Inline assignments in menu blocks
            command = stripped_line[2:].strip()
            self.stack.current().add_sequence_item(self.linepack_events, AssignmentItem(command))
            return

        elif re.match(r'^([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*(.+)$', stripped_line):
            # General assignment
            command = stripped_line
            self.stack.current().add_sequence_item(self.linepack_events, AssignmentItem(command))
            return

        elif stripped_line.startswith("call screen doublespeak("):
            doublespeak_match = re.match(r"^call screen doublespeak\((.*)\)$", stripped_line)
            if not doublespeak_match:
                raise Exception(f"Invalid doublespeak syntax: {stripped_line}")
            # params = doublespeak_match.group(1).split(",")
            # TODO: Check for consistency
            params = re.findall(r'(?:[^,"]|"(?:\\.|[^"])*")+', doublespeak_match.group(1))
            params = [p.strip() for p in params]
            if len(params) != 4:
                raise Exception(f"Invalid doublespeak parameters count ({len(params)}): {stripped_line}")

            hashing_contents = stripped_line
            original_dialog_hash = self.calculate_tl_hash(hashing_contents)

            actor_left_ref = params[0].strip()
            actor_right_ref = params[2].strip()
            dialogs = [params[1].strip(), params[3].strip()]

            print(f' >> DoubleSpeak actors: left="{actor_left_ref}", right="{actor_right_ref}"')
            print(f' >> DoubleSpeak dialogs: left="{dialogs[0]}", right="{dialogs[1]}"')

            dialog_left: Dict[str, str] = {
                DEFAULT_LOCALE: re.search(r'\"(.*)\"', dialogs[0]).group(1)
            }
            dialog_right: Dict[str, str] = {
                DEFAULT_LOCALE: re.search(r'\"(.*)\"', dialogs[1]).group(1)
            }

            for locale, translation in self.translations.items():
                def resolve_dialog(dialog_expr: str) -> str:
                    if dialog_expr.startswith("_(") and dialog_expr.endswith(")"):
                        key = re.match(r"^_\(\"(.*)\"\)$", dialog_expr).group(1)
                        if key not in translation.strings:
                            raise Exception(f"Missing translation for key: {key} in locale {locale}")
                        return translation.strings[key]

                    literal_match = re.match(r'^"(.*)"$', dialog_expr)
                    if literal_match:
                        literal_text = literal_match.group(1)
                        if literal_text in ["…"]:
                            # For plain literals (for example "…"), keep source text
                            # if the string table does not contain a translation entry.
                            print(f"[38;5;208m Warning: Literal text \"{literal_text}\" not found in translation table for locale {locale}?[33;0m")
                            return translation.strings.get(literal_text, literal_text)

                    raise Exception(f"Unsupported doublespeak dialog expression: {dialog_expr}")

                dialog_left[locale] = resolve_dialog(dialogs[0])
                dialog_right[locale] = resolve_dialog(dialogs[1])

            self.stack.current().add_sequence_item(self.linepack_events,
                                                   DoubleSpeakItem(original_dialog_hash[-8:],
                                                                   actor_left_ref, actor_right_ref,
                                                                   dialog_left, dialog_right,
                                                                   label_name=self.stack.current_label().name))

        elif stripped_line.startswith("call act_op("):
            video_name = stripped_line.split("act_op(\"", 1)[1].strip("\")")
            video_without_extension = video_name.split(".")[0]
            self.stack.current().add_sequence_item(self.linepack_events, ShowVideoItem(video_without_extension,
                                                                                       label_name=self.stack.current_label().name))
            return

        elif stripped_line.startswith("call "):
            if "act_op(" in stripped_line or "call screen " in stripped_line:
                pass
            elif "call timeskip" in stripped_line:
                self.stack.current().add_sequence_item(self.linepack_events, RunLabelItem("ks::SceneManager::timeskip", True))
            else:
                # Inline calls in menu blocks
                function_name = stripped_line.split("call ", 1)[1].strip()
                if function_name == "a1c4o1":
                    self.stack.current().add_sequence_item(self.linepack_events, AssignmentItem("im_new_here = True"))
                self.stack.current().add_sequence_item(self.linepack_events, RunLabelItem(sanitize_function_name(function_name), False, label_name=self.stack.current_label().name))
            return

        elif stripped_line.startswith("scene bg"):
            parts = stripped_line.split()
            scene_bg_name = parts[2].removesuffix(":")
            scene_bg_name, palette_variant = get_bg_name_and_palette(scene_bg_name, self.bgs_images_cache)

            if "at bgleft" in stripped_line or "at left" in stripped_line:
                position = BgShowPosition.BGLEFT
            elif "at bgright" in stripped_line or "at right" in stripped_line:
                position = BgShowPosition.BGRIGHT
            elif "at center" in stripped_line:
                position = BgShowPosition.CENTER
            else:
                position = BgShowPosition.DEFAULT

            self.stack.current().add_sequence_item(self.linepack_events, BackgroundItem(scene_bg_name, position=position, palette_variant=palette_variant))
            self._hack_latest_sprite_name = None  # TODO: Remove after "Friday"-hack
            return

        elif starts_with_filled_bg(stripped_line):
            color = stripped_line.split()[1].removesuffix(":")
            self.stack.current().add_sequence_item(self.linepack_events, BackgroundItem(color))
            self._hack_latest_sprite_name = None  # TODO: Remove after "Friday"-hack
            return

        elif stripped_line.startswith("scene ev") or stripped_line.startswith("show ev"):
            parts = stripped_line.split()
            print(f" >> Scene ev: {parts}")
            event_bg_name = parts[2].removesuffix(":")
            # REMOVES TEMP
            # TODO: use specs
            event_bg_name = rewrite_motion_background(event_bg_name)
            custom_event_bg, custom_event = get_custom_event(event_bg_name)
            if custom_event_bg is not None and custom_event is not None:
                event_bg_name = custom_event_bg
                event = custom_event
                self.stack.current().add_sequence_item(self.linepack_events, CustomEventItem(event_bg_name, event))
            else:
                self.stack.current().add_sequence_item(self.linepack_events, BackgroundItem(event_bg_name))

            self._hack_latest_sprite_name = None # TODO: Remove after "Friday"-hack
            return

        elif stripped_line.startswith("state ev"):
            match = re.match(r'state ev\s+(\d+)$', stripped_line)
            if not match:
                raise Exception(f"Invalid state ev syntax: {stripped_line}")
            event_state = int(match.group(1))
            self.stack.current().add_sequence_item(self.linepack_events, CustomEventStateItem(event_state))

        elif stripped_line.startswith("show passoutOP1"):
            self.stack.current().add_sequence_item(self.linepack_events, BackgroundTransitionItem(BgTransition.PASSOUTOP1))
            return

        elif stripped_line.startswith("pause"):
            value_match = re.search(r"pause (\d+\.\d+)", stripped_line)
            value = float(value_match.group(1)) if value_match else 0
            if value > 0:
                self.stack.current().add_sequence_item(self.linepack_events, PauseItem(value))
            else:
                raise Exception(f"Invalid pause value: {stripped_line}")
            return

        elif stripped_line.startswith("play music"):
            parts = stripped_line.split()
            music_name = parts[2]
            fadein_match = re.search(r"fadein (\d+\.\d+)", stripped_line)
            fadein_time = float(fadein_match.group(1)) if fadein_match else 0
            self.stack.current().add_sequence_item(self.linepack_events, 
                MusicItem(MusicAction.PLAY, music_name, MusicEffect.FADEIN if fadein_match else MusicEffect.NONE,
                          fadein_time))
            return

        elif stripped_line.startswith("stop music"):
            fadeout_match = re.search(r"fadeout (\d+\.\d+)", stripped_line)
            fadeout_time = float(fadeout_match.group(1)) if fadeout_match else 0
            self.stack.current().add_sequence_item(self.linepack_events, 
                MusicItem(MusicAction.STOP, "", MusicEffect.FADEOUT if fadeout_match else MusicEffect.NONE,
                          fadeout_time))
            return

        elif stripped_line.startswith("play sound"):
            parts = stripped_line.split()
            music_name = parts[2]
            fadein_match = re.search(r"fadein (\d+\.\d+)", stripped_line)
            fadein_time = float(fadein_match.group(1)) if fadein_match else 0
            self.stack.current().add_sequence_item(self.linepack_events, 
                SoundItem(SoundAction.PLAY, music_name, SoundChannel.SOUND, SoundEffect.FADEIN if fadein_match else SoundEffect.NONE,
                          fadein_time))
            return

        elif stripped_line.startswith("play ambient"):
            parts = stripped_line.split()
            music_name = parts[2]
            fadein_match = re.search(r"fadein (\d+\.\d+)", stripped_line)
            fadein_time = float(fadein_match.group(1)) if fadein_match else 0
            self.stack.current().add_sequence_item(self.linepack_events,
                SoundItem(SoundAction.PLAY, music_name, SoundChannel.AMBIENT, SoundEffect.FADEIN if fadein_match else SoundEffect.NONE,
                          fadein_time))
            return

        elif stripped_line.startswith("stop sound"):
            fadeout_match = re.search(r"fadeout (\d+\.\d+)", stripped_line)
            fadeout_time = float(fadeout_match.group(1)) if fadeout_match else 0
            self.stack.current().add_sequence_item(self.linepack_events, 
                SoundItem(SoundAction.STOP, "", SoundChannel.SOUND, SoundEffect.FADEOUT if fadeout_match else SoundEffect.NONE,
                          fadeout_time))
            return

        elif stripped_line.startswith("stop ambient"):
            fadeout_match = re.search(r"fadeout (\d+\.\d+)", stripped_line)
            fadeout_time = float(fadeout_match.group(1)) if fadeout_match else 0
            self.stack.current().add_sequence_item(self.linepack_events,
                SoundItem(SoundAction.STOP, "", SoundChannel.AMBIENT, SoundEffect.FADEOUT if fadeout_match else SoundEffect.NONE,
                          fadeout_time))
            return

        elif stripped_line.startswith("show bg at"):
            # TODO: review for lines as ""
            if "at bgleft" in stripped_line or "at left" in stripped_line:
                position = BgShowPosition.BGLEFT
            elif "at bgright" in stripped_line or "at right" in stripped_line:
                position = BgShowPosition.BGRIGHT
            elif "at center" in stripped_line:
                position = BgShowPosition.CENTER
            else:
                position = BgShowPosition.DEFAULT
                raise(Exception(f"Unknown background position: {stripped_line}"))

            self.stack.current().add_sequence_item(self.linepack_events,
                                                   BackgroundTransformItem(position))
            self._hack_latest_sprite_name = None # TODO: Remove after "Friday"-hack
            return

        elif stripped_line.startswith("show "):
            parts = stripped_line.split()
            sprite_name = parts[1].removesuffix(":")
            variant_name = parts[2].removesuffix(":") if len(parts) > 2 and parts[2] not in ["at", "with"] else None

            event_type = ShowEvent.CHARACTER_CHANGE if "with charachange" in stripped_line else ShowEvent.NONE

            if "at twoleft" in stripped_line:
                position = ShowPosition.TWOLEFT
            elif "at tworight" in stripped_line:
                position = ShowPosition.TWORIGHT
            elif "at closeleft" in stripped_line:
                position = ShowPosition.CLOSELEFT
            elif "at closeright" in stripped_line:
                position = ShowPosition.CLOSERIGHT
            elif "at offscreenleft" in stripped_line:
                position = ShowPosition.OFFSCREENLEFT
            elif "at offscreenright" in stripped_line:
                position = ShowPosition.OFFSCREENRIGHT
            elif "at left" in stripped_line:
                position = ShowPosition.LEFT
            elif "at right" in stripped_line:
                position = ShowPosition.RIGHT
            elif "at center" in stripped_line:
                position = ShowPosition.CENTER
            else:
                position = ShowPosition.DEFAULT

            if is_displayable_sprite(sprite_name):
                base_name, subvariant = split_displayable_sprite(sprite_name)
                palette_variant = displayable_palette_variant(subvariant)
                self.stack.current().add_sequence_item(
                    self.linepack_events,
                    ShowDisplayableItem(base_name, subvariant, event_type, position, palette_variant))
                self._hack_latest_sprite_name = base_name
                return

            variant_name, palette_variant = get_sprite_paletted_variant(variant_name)
            self.stack.current().add_sequence_item(self.linepack_events, ShowItem(sprite_name, variant_name, event_type, position, palette_variant))
            self._hack_latest_sprite_name = sprite_name
            return

        elif stripped_line.startswith("hide "):
            parts = stripped_line.split()
            sprite_name = parts[1]

            event_type = HideEvent.CHARACTER_EXIT if "with charaexit" in stripped_line else HideEvent.NONE
            self.stack.current().add_sequence_item(self.linepack_events, HideItem(sprite_name, event_type))
            return

        elif "xalign " in stripped_line:
            # TODO: The background sequences also can be aligned!!!!!! It brokes the Friday now!!!!
            #                     scene bg misc_sky_ni:
            #                         xalign 0.0
            #                         warp acdc_warp 15.0 xalign 1.0
            #                     with locationchange

            if self._hack_latest_sprite_name is not None:
                # `xalign V` is shorthand for `xpos V xanchor V` per
                # Ren'Py docs: the normalised pixel-resolution happens at
                # runtime against each variant's actual body width, see
                # `ShowTransformItem` doc.
                value = float(stripped_line.split("xalign ")[1].split()[0])
                self.stack.current().add_sequence_item(
                    self.linepack_events,
                    ShowTransformItem(self._hack_latest_sprite_name, None,
                                      xpos=value, xanchor=value))

        elif "xpos " in stripped_line:
            # TODO: See above. Same shit...
            # TODO: As an above - needs to be processed as a block-sequence...

            if self._hack_latest_sprite_name is not None:
                xpos_value = float(stripped_line.split("xpos ")[1].split()[0])
                xanchor_value = 0.5
                if "xanchor " in stripped_line:
                    xanchor_value = float(stripped_line.split("xanchor ")[1].split()[0])
                self.stack.current().add_sequence_item(
                    self.linepack_events,
                    ShowTransformItem(self._hack_latest_sprite_name, None,
                                      xpos=xpos_value, xanchor=xanchor_value))

        elif stripped_line.startswith("nvl "):
            parts = stripped_line.split()
            action_name = parts[1]
            if action_name == "clear":
                self._hack_nvl_cleared = True
                self.stack.current().add_sequence_item(self.linepack_events, NovelClearItem())
            elif action_name == "hide":
                self.stack.current().add_sequence_item(self.linepack_events, NovelHideItem())
            return

        elif stripped_line.startswith("with "):
            transition_match = re.match(r"^with ([\w_]+)$", stripped_line)
            if transition_match:
                transition_name = transition_match.group(1)
                if transition_name in [t.name.lower() for t in BgTransition] and transition_name != "none":
                    transition = cast(BgTransition, BgTransition[transition_name.upper()])
                    for sequence in self.linepack_events:
                        if sequence.type == SequenceType.BACKGROUND:
                            sequence = cast(BackgroundItem, sequence)
                            sequence.transition = transition
                            return
                        elif sequence.type == SequenceType.CUSTOM_EVENT:
                            sequence = cast(CustomEventItem, sequence)
                            sequence.transition = transition
                            return
                    self.stack.current().add_sequence_item(self.linepack_events, BackgroundTransitionItem(transition))
                    return
            displayable_dissolve_match = re.match(r"^with Dissolve\s*\(([\d.]+)\)$", stripped_line)
            if displayable_dissolve_match:
                dissolve_time = float(displayable_dissolve_match.group(1))
                for sequence in self.linepack_events:
                    if sequence.type == SequenceType.BACKGROUND:
                        sequence = cast(BackgroundItem, sequence)
                        sequence.dissolve_time = dissolve_time
                    elif sequence.type == SequenceType.CUSTOM_EVENT:
                        sequence = cast(CustomEventItem, sequence)
                        sequence.dissolve_time = dissolve_time
            if (stripped_line.startswith("with dissolve")
                    or stripped_line.startswith("with fade")
                    or stripped_line.startswith("with locationchange")
                    or stripped_line.startswith("with charachangealways")
                    or stripped_line.startswith("with charachangeev")
                    or stripped_line.startswith("with charaenter")
                    or stripped_line.startswith("with charaexit")
                    or stripped_line.startswith("with characlose")
                    or stripped_line.startswith("with charadistant")):
                dissolve_time = float(1)
                for sequence in self.linepack_events:
                    if sequence.type == SequenceType.BACKGROUND:
                        sequence = cast(BackgroundItem, sequence)
                        sequence.dissolve_time = dissolve_time
                    elif sequence.type == SequenceType.CUSTOM_EVENT:
                        sequence = cast(CustomEventItem, sequence)
                        sequence.dissolve_time = dissolve_time
            elif stripped_line.startswith("with locationskip"):
                dissolve_time = float(0.5)
                for sequence in self.linepack_events:
                    if sequence.type == SequenceType.BACKGROUND:
                        sequence = cast(BackgroundItem, sequence)
                        sequence.dissolve_time = dissolve_time
                    elif sequence.type == SequenceType.CUSTOM_EVENT:
                        sequence = cast(CustomEventItem, sequence)
                        sequence.dissolve_time = dissolve_time


        else:
            hashing_contents = stripped_line
            if _hack_prepend_dialog_nvl_clear:
                # If novel mode was cleared just before dialog - we need to add this to hashing contents
                # See translations, for example:
                # - /tl/de/script-a3-emi.rpy@12642
                # - /tl/es/script-a3-rin.rpy@3892
                # - /tl/ru/script-a4-shizune.rpy@90

                hashing_contents = f"nvl clear\r\n{hashing_contents}"

            dialog_match_str = re.match(r"^\"(.+?)\"\s+\"(.*)\"(?:| nointeract)$", stripped_line)
            dialog_match_ref = re.match(r"^(\w+)\s+\"(.*)\"(?:| nointeract)$", stripped_line)
            # narration_match = re.match(r"^\"(.*)\"(?:| nointeract)$", stripped_line)
            # TODO: Fix translation in KS:RE project: "tl/ru/script-a1-sunday.rpy:943"
            narration_match = re.match(r"^\"(.*)\"(?:| nointeract| with vpunch)$", stripped_line)

            original_dialog_hash = self.calculate_tl_hash(hashing_contents)
            original_dialog_hash_nointeract = self.calculate_tl_hash(hashing_contents, nointeract=True)

            matches : Dict[str, re.Match] = {}
            if dialog_match_str or dialog_match_ref or narration_match:
                if dialog_match_str:
                    matches[DEFAULT_LOCALE] = dialog_match_str
                elif dialog_match_ref:
                    matches[DEFAULT_LOCALE] = dialog_match_ref
                elif narration_match:
                    matches[DEFAULT_LOCALE] = narration_match

                for locale, translation in self.translations.items():
                    if locale == DEFAULT_LOCALE:
                        continue
                    dialog_hash = original_dialog_hash
                    if dialog_hash not in translation.translations:
                        dialog_hash = original_dialog_hash_nointeract
                    if dialog_hash not in translation.translations:
                        # Hack: translation labels can differ in prefix, but keep the same 8-char hash suffix.
                        # Also check both normal and explicit `nointeract` hash variants.
                        short_hash_candidates = (
                            original_dialog_hash[-8:],
                            original_dialog_hash_nointeract[-8:],
                        )
                        for key in translation.translations:
                            if any(key.endswith(short_hash) for short_hash in short_hash_candidates):
                                dialog_hash = key
                                break
                    if dialog_hash not in translation.translations:
                        for key, value in translation.translations.items():
                            print(f"    - {key}: {value}")
                        raise Exception(f"Missing translation for hash {dialog_hash} in locale {locale} for line: {stripped_line}")
                    translated_stripped_line = translation.translations[dialog_hash]

                    if dialog_match_str:
                        matches[locale] = re.match(r"^\"(.+?)\"\s+\"(.*)\"(?:| nointeract)$", translated_stripped_line)
                    elif dialog_match_ref:
                        matches[locale] = re.match(r"^(\w+)\s+\"(.*)\"(?:| nointeract)$", translated_stripped_line)
                    else:
                        # matches[locale] = re.match(r"^\"(.*)\"(?:| nointeract)$", translated_stripped_line)
                        # TODO: Fix translation in KS:RE project: "tl/ru/script-a1-sunday.rpy:943"
                        matches[locale] = re.match(r"^\"(.*)\"(?:| nointeract| with vpunch)$", translated_stripped_line)

            actor: Dict[str, str] = {}
            dialog: Dict[str, str] = {}
            if dialog_match_str:
                for locale, match in matches.items():
                    if match:
                        actor_locale, dialog_locale = match.groups()
                        actor[locale] = actor_locale
                        dialog[locale] = dialog_locale.strip().replace("\\n", "\n")
                    else:
                        raise Exception(f"Translation regex mismatch for hash {original_dialog_hash} in locale {locale} for line: {stripped_line}")

                self.stack.current().add_sequence_item(self.linepack_events,
                    DialogItem(original_dialog_hash[-8:], actor, dialog, label_name=self.stack.current_label().name))
            elif dialog_match_ref:
                dialog_extended = None

                if dialog_match_ref.group(1) == "extend":
                    previous_dialog = self.stack.current().get_last_item_with_type(SequenceType.DIALOG)
                    if previous_dialog is None:
                        raise Exception(
                            f"Extend dialog found, but there is no previous dialog to extend: {stripped_line}")
                    previous_dialog = cast(DialogItem, previous_dialog)
                    dialog_extended = copy.deepcopy(previous_dialog)
                    dialog_extended.id = original_dialog_hash[-8:]
                    for locale, match in matches.items():
                        if match:
                            actor_locale, dialog_locale = match.groups()
                            actor[locale] = actor_locale
                            dialog[locale] = dialog_locale.replace("\\n", "\n")
                            if actor[locale] != "extend":
                                raise Exception(f"Extend dialog found, but actor is not 'extend' for locale {locale}: {stripped_line}")

                            if locale in dialog_extended.message:
                                new_message = previous_dialog.message[locale]
                                new_message = new_message.replace("{fast}", "")
                                new_message = new_message.replace("{w}", "")
                                new_message = re.sub(r"\{w=(\d*\.*\d+)\}", "", new_message)
                                new_message = new_message.removesuffix("{nw}")
                                new_message = new_message + "{fast}" + dialog[locale].replace("{vspace=30}", "\n")
                                dialog_extended.message[locale] = new_message
                                print(f"[38;5;83m Extended: \"{dialog[locale]}\"?[33;0m")
                                # sleep(0.5)
                            else:
                                raise Exception(
                                    f"Extend dialog found, but there is no previous dialog to extend for locale {locale}: {stripped_line}")
                        else:
                            raise Exception(f"Translation regex mismatch for hash {original_dialog_hash} in locale {locale} for line: {stripped_line}")
                else:
                    for locale, match in matches.items():
                        if match:
                            actor_locale, dialog_locale = match.groups()
                            actor[locale] = actor_locale
                            dialog[locale] = dialog_locale.strip().replace("\\n", "\n")
                        else:
                            # TODO: Fix the translation in KS:RE project: "tl/ru/script-a1-sunday.rpy" a1_sunday_movement is completely broken
                            # raise Exception(f"Translation regex mismatch for hash {original_dialog_hash} in locale {locale} for line: {stripped_line}")
                            print(f"[38;5;197m Translation regex mismatch for hash {original_dialog_hash} in locale {locale} for line: {stripped_line}?[33;0m")
                            # sleep(0.05)
                            actor[locale] = actor[DEFAULT_LOCALE]
                            dialog[locale] = dialog[DEFAULT_LOCALE]

                if dialog_extended is not None:
                    self.stack.current().add_sequence_item(self.linepack_events, dialog_extended)
                else:
                    self.stack.current().add_sequence_item(self.linepack_events,
                                                           DialogItem(original_dialog_hash[-8:], None, dialog,
                                                                      actor[DEFAULT_LOCALE],
                                                                      label_name=self.stack.current_label().name))

            elif narration_match:
                for locale, match in matches.items():
                    if match:
                        narration_locale = match.group(1)
                        dialog[locale] = narration_locale.strip().replace("\\n", "\n")
                    else:
                        # TODO: Fix the translation in KS:RE project: "tl/ru/script-a1-sunday.rpy" a1_sunday_movement is completely broken
                        # raise Exception(f"Translation regex mismatch for hash {original_dialog_hash} in locale {locale} for line: {stripped_line}")
                        print(f"[38;5;197m Translation regex mismatch for hash {original_dialog_hash} in locale {locale} for line: {stripped_line}?[33;0m")
                        # sleep(0.25)
                        dialog[locale] = dialog[DEFAULT_LOCALE]
                self.stack.current().add_sequence_item(self.linepack_events,
                    DialogItem(original_dialog_hash[-8:], None, dialog,
                               label_name=self.stack.current_label().name))
            return

def get_line_indent(line: str) -> int:
    return (len(line) - len(line.lstrip())) // 4

def rewrite_condition(condition: str) -> str:
    return (condition
            .replace('"Hi! I\'m new here. Hisao Nakai. We\'re in the same class." in choices', 'im_new_here == True')
            .replace("persistent.disable_disturbing_content", "settings___disable_disturbing_content")
            )

def get_custom_bg(bg_name: str) -> (str, str):
    bgs = {
        "school_track_fb": ("school_track", "PALETTE_VARIANT_PAST"),
        # "watchhallway_blur": ("vfx/watchhallway_blur", "PALETTE_VARIANT_DEFAULT"),
        # "worrytree": ("vfx/worrytree", "PALETTE_VARIANT_DEFAULT"),
        # "worrytree_ss": ("vfx/worrytree", "PALETTE_VARIANT_SUNSET"),
        # "gallery_atelier_close": ("vfx/gallery_atelier_close", "PALETTE_VARIANT_DEFAULT"),
        # "misc_sky_rays": ("bgs/misc_sky_rays.jpg", "PALETTE_VARIANT_DEFAULT"),
        "school_dormhisao_ni_fb": ("school_dormhisao_blurred_ni", "PALETTE_VARIANT_PAST"),
        "shizu_houseext_lights_fb": ("shizu_houseext_lights", "PALETTE_VARIANT_PAST"),
        "hosp_ext_fb": ("hosp_ext", "PALETTE_VARIANT_PAST_NIGHT"),
        # "tearoom_lillyhisao_noon": ("event/Lilly_supercg/tearoom_lillyhisao_noon.png", "PALETTE_VARIANT_DEFAULT"),
        # "tearoom_lillyhisao_sunset": ("event/Lilly_supercg/tearoom_lillyhisao_sunset.png", "PALETTE_VARIANT_DEFAULT"),
        # "tearoom_everyone_noon": ("event/Lilly_supercg/tearoom_everyone_noon.png", "PALETTE_VARIANT_DEFAULT"),
        # TODO: image bg school_roof_ni_crop = Transform("bgs/school_roof_ni.jpg", crop=(200, 0, 1920, 1080)),
        # TODO: mural_start = "vfx/mural_start.jpg"
        # TODO: mural_unfinished = "vfx/mural_unfinished.jpg"
        # TODO: mural_part = "vfx/mural.jpg"
        # TODO: mural = "vfx/mural.jpg"
        # TODO: mural_ss = sunset("vfx/mural.jpg")
        "mural_start": ("mural", "PALETTE_VARIANT_DEFAULT"),
        "mural_unfinished": ("mural_unfinished", "PALETTE_VARIANT_DEFAULT"),
        "mural_part": ("mural", "PALETTE_VARIANT_DEFAULT"),
        "mural_ss": ("mural", "PALETTE_VARIANT_SUNSET"),
        "gallery_atelier_bw": ("gallery_atelier", "PALETTE_VARIANT_BLACK_AND_WHITE"),
        "school_scienceroom_bw": ("school_scienceroom", "PALETTE_VARIANT_BLACK_AND_WHITE"),
        "school_library_bw": ("school_library", "PALETTE_VARIANT_BLACK_AND_WHITE"),
        "city_street4_bw": ("city_street4", "PALETTE_VARIANT_BLACK_AND_WHITE"),
        "city_street3_bw": ("city_street3", "PALETTE_VARIANT_BLACK_AND_WHITE"),
        "school_council_bw": ("school_council", "PALETTE_VARIANT_BLACK_AND_WHITE"),
        "school_dormhisao_bw": ("school_dormhisao", "PALETTE_VARIANT_BLACK_AND_WHITE"),
        # TODO: school_library_yuuko_blurred = "vfx/school_library_yuuko_blurred.jpg",
    }
    if bg_name in bgs.keys():
        return bgs[bg_name]
    else:
        return None, None

def get_bg_name_and_palette(bg_name: str, bg_names : None|List[str] = None) -> (str, str):
    custom_bg_name, palette_variant = get_custom_bg(bg_name)
    if custom_bg_name is not None:
        return custom_bg_name, palette_variant
    return get_bg_paletted_variant(bg_name, bg_names)

def rewrite_motion_background(bg_name: str) -> str:
    # TODO: remove this method and allow motion backgrounds
    return (bg_name
            .replace("hana_library_read_std", "hana_library_read")
            .replace("hana_library_std", "hana_library")
            .replace("hana_library_gasp_std", "hana_library_gasp")
            .replace("hana_library_smile_std", "hana_library_smile")
            .replace("lilly_airport_end_fb", "lilly_airport_end") # TODO: Paletted variants for backgrounds

            .replace("kenji_rooftop_kenji", "kenji_rooftop") # TODO: Kenji alcotrip event
            .replace("kenji_rooftop_large", "kenji_rooftop") # TODO: Kenji alcotrip event
            .replace("kenji_rooftop", "kenji_rooftop") # TODO: Kenji alcotrip event

            .replace("shizu_roof2_towardsnormal", "shizu_roof_towardsnormal") # TODO: Shizu roof event
            .replace("shizu_roof2_towardsangry", "shizu_roof_towardsangry") # TODO: Shizu roof event
            .replace("shizu_roof2", "shizu_roof_hisao2") # TODO: Shizu roof event
            .replace("shizu_roof2_smile", "shizu_roof_smile") # TODO: Shizu roof event

            .replace("shizu_goodend_pan", "shizu_goodend") # TODO: Shizu goodend event

            .replace("emi_run_face_ss", "emi_run_face") # TODO: Emi run face paletted variant

            .replace("hanako_cry_closed_fb", "hanako_cry_closed") # TODO: Hanako cry paletted variant

            .replace("hanako_billiards_distant_med", "hanako_billiards_distant") # TODO: Hanako billiard event
            .replace("hanako_billiards_serious_med", "hanako_billiards_serious") # TODO: Hanako billiard event
            .replace("hanako_billiards_smile_med", "hanako_billiards_smile") # TODO: Hanako billiard event
            .replace("hanako_billiards_timid_med", "hanako_billiards_timid") # TODO: Hanako billiard event

            .replace("rin_nap_total_awind_tears", "rin_nap_total_wind") # TODO: Rin nap event
            .replace("rin_nap_close_awind_tears", "rin_nap_close_wind") # TODO: Rin nap event
            .replace("rin_nap_total_awind", "rin_nap_total_wind") # TODO: Rin nap event
            .replace("rin_nap_close_awind", "rin_nap_close_wind") # TODO: Rin nap event
            .replace("rin_nap_total_tears", "rin_nap_total") # TODO: Rin nap event
            .replace("rin_nap_close_tears", "rin_nap_close") # TODO: Rin nap event

            .replace("rin_doodle_all", "rin_doodle") # TODO: Rin doodle event

            .replace("rin_h2_pan_surprise", "rin_h2_l_pan") # TODO: Rin cunnilingus event
            .replace("rin_h2_pan_away", "rin_h2_l_pan") # TODO: Rin cunnilingus event
            .replace("rin_h2_pan_closed", "rin_h2_l_pan") # TODO: Rin cunnilingus event
            .replace("rin_h2_nopan_closed", "rin_h2_l_nopan") # TODO: Rin cunnilingus event
            .replace("rin_h2_hisao_closed", "rin_h2_l_hisao") # TODO: Rin cunnilingus event
            .replace("rin_h2_hisao_away", "rin_h2_l_hisao") # TODO: Rin cunnilingus event
            .replace("rin_h2_hisao_surprise", "rin_h2_l_hisao") # TODO: Rin cunnilingus event

            .replace("hisaobird_", "bird_")
            .replace("hisao_mirror_800", "hisao_mirror")

            # .replace("_start", "")
            # .replace("_move", "")
            # .replace("_end", "")
            .replace("_zoomout", "")
            # .replace("emi_knockeddown_facepullout", "emi_knockeddown")
            # .replace("emi_knockeddown_largepullout", "emi_knockeddown")
            # .replace("emi_knockeddown_legs", "emi_knockeddown")
            )

def scenario_rewrites(scenario_file, content):

    # TODO: Dialog Window auto-management (see: https://www.renpy.org/doc/html/dialogue.html#dialogue-window-management)
    content = (
        content
        .replace("$ _window = False\n", "")
        .replace("window auto True\n", "")
        .replace("window auto False\n", "")
    )

    scenario_name = os.path.splitext(os.path.basename(scenario_file))[0]
    if scenario_name == "script-a1-monday":
        return content.replace(
            "        show drugs:\n"
            "            xpos 0 ypos 0\n"
            "            easein 25.0 xanchor 0.5",
            # WITH
            "        scene ev drugs_event"
        ).replace(
            "        scene ev other_iwanako_start\n"
            "        show snow",
            # WITH
            # TODO: Other Iwanako Start event (Affine background scaling down)
            "        scene ev other_iwanako"
        ).replace(
            "        scene ev other_iwanako\n"
            "        show snow",
            # WITH
            "        scene ev other_iwanako"
        ).replace(
            "        scene bg op_snowywoods\n"
            "        show snow",
            # WITH
            "        scene ev op_snowywoods"
        ).replace(
            "        scene bg hosp_room\n"
            "        show sakura\n"
            "        show hospitalmask",
            # WITH
            "        scene ev hosp_room"
        )

    if scenario_name == "script-a1-wednesday":
        return content.replace(
            "            show shizu behind_smile:\n"
            "                xalign 1.03\n"
            "            show misha hips_grin at tworight\n"
            "            with charaenter\n",
            # WITH
            "            show shizu behind_smile:\n"
            "                xalign 1.2\n"
            "            show misha hips_grin at tworight\n"
            "            with charaenter\n"
        )

    if scenario_name == "script-a1-thursday":
        return content.replace(
            "        show showdown_lilly_slice:\n"
            "            xpos 1.0\n"
            "        show showdown_shizu_slice:\n"
            "            xanchor 1.0 yalign 1.0\n"
            "\n"
            "        play sound sfx_draw\n"
            "        show showdown_lilly_slice:\n"
            "            easein 0.2 xalign 0.0 yalign 0.0\n"
            "\n"
            "        pause 0.4\n"
            "\n"
            "        play sound sfx_draw\n"
            "        show showdown_shizu_slice:\n"
            "            easein 0.2 xalign 1.0 yalign 1.0\n"
            "\n"
            "        pause 0.4\n",
            # WITH
            "        scene ev showdown_slices\n"
        ).replace(
            "        scene ev showdown\n"
            "        with Fade(0.2, 0.0, 3.0, color=\"#FFF\")\n",
            # WITH
            "        scene ev lilly_shizu_showdown\n"
            "        with showdown_thunder_long\n"
        ).replace(
            "        scene ev showdown\n"
            "        with Fade(0.2, 0.0, 1.5, color=\"#FFF\")\n",
            # WITH
            "        scene ev lilly_shizu_showdown\n"
            "        with showdown_thunder_short\n"
        ).replace(
            "        show ev showdown_large:\n"
            "            xysize (1920, 1080) crop (0, 0, 5760, 3240)\n"
            "            easeout 0.2 crop (912, 240, 1920, 1080)\n",
            # WITH
            "        show ev showdown_lilly\n"
        ).replace(
            "        show ev showdown_large:\n"
            "            ease 0.2 crop (912, 240, 1920, 1080)\n",
            # WITH
            "        show ev showdown_lilly\n"
        ).replace(
            "        show ev showdown_large:\n"
            "            ease 0.2 crop (3120, 384, 1920, 1080)\n",
            # WITH
            "        show ev showdown_shizu\n"
        ).replace(
            "        $ _window = False\n\n",
            # WITH
            ""
        )

    if scenario_name == "script-a1-sunday":
        return content.replace(
            "            show shizu epictransition at epictransform\n"
            "            show cityscape zoom behind shizu\n"
            "            show hill enter behind shizu\n",
            # WITH
            "\n" # TODO: Shizune Epic Transition
        ).replace(
            "play music sfx_crowd_outdoors",
            # WITH
            "play ambient sfx_crowd_outdoors"
        ).replace(
            "            hide ev\n"
            "            show bg school_roof_ni:",
            # WITH
            "            scene bg school_roof_ni:"
        ).replace(
            "            show nightsky rotation",
            # WITH
            "            scene bg misc_sky_ni" # TODO: Rotation Nightsky scene
        ).replace(
            "            show black behind bg\n"
            "\n"
            "            show n_vignette:\n"
            "                xalign 0.5 yalign 0.5 zoom 4.0\n"
            "                linear 0.2 zoom 1.2\n"
            "\n"
            "            pause 0.2\n"
            "\n"
            "            show n_vignette:\n"
            "                zoom 1.2\n"
            "                linear 8.0 zoom 0.001\n"
            "            show kenji happy_close_ni:\n"
            "                xalign 0.5 yalign 0.5\n"
            "                linear 8.0 zoom 0.001\n"
            "            show bg school_roof_ni_crop:\n"
            "                xalign 0.5 yalign 0.5\n"
            "                linear 8.0 zoom 0.001\n",
            # WITH
            "            hide kenji\n" # TODO: Rotation Nightsky scene
            "            scene black\n"
            "            with Dissolve(1.0)\n"
            "\n"
            "            pause 0.2\n"
        ).replace(
            "            show hanako_fw behind bg:\n"
            "                zoom 1.05 truecenter\n"
            "                ease 22.0 zoom 1.0\n"
            "            show ev hanako_shanghaiwindow behind hanako_fw:\n"
            "                zoom 1.05 truecenter\n"
            "                ease 22.0 zoom 1.0",
            # WITH
            ""
        ).replace(
            "            hide fireshine\n"
            "            hide bg\n"
            "            hide hanako\n"
            "            hide lilly\n"
            "            hide yuukoshang\n"
            "            with locationskip",
            # WITH
            "            scene ev hanako_fw\n"
            "            with locationskip"
        ).replace(
            "            hide fireshine\n"
            "            show bg misc_sky_ni as front\n"
            "            show fireworks\n"
            "            with locationchange",
            # WITH
            "            scene ev nightsky_fw"
        ).replace(
            "            hide fireworks\n"
            "            hide front\n"
            "            show fireshine\n"
            "            show yuukoshang happy_down\n"
            "            with locationchange",
            # WITH
            "            scene bg suburb_shanghaiint\n"
            "            show lilly basic_weaksmile\n"
            "            show hanako emb_timid\n"
            "            show yuukoshang happy_down\n"
            "            with locationchange"
        ).replace(
            "            hide hanako_fw\n"
            "            with Dissolve(1.0)",
            # WITH
            "            state ev 1"
        )

    if scenario_name == "script-a2-emi":
        return content.replace(
            "        show emi gymbounce_once\n"
            "        with Dissolve(0.1)\n",
            # WITH TODO: Emi bouncing animation
            ""
        ).replace(
            "        show emi gymbounce\n"
            "        with Dissolve(0.05)\n",
            # WITH TODO: Emi bouncing animation
            ""
        ).replace(
            "        show emi blur at offscreenright\n"
            "        with None",
            # WITH TODO: Emi blur VFX
            "        show emi at offscreenright\n"
            "        with None",
        ).replace(
            "        scene ev emi_bed_full:\n"
            "            xalign 0.5 yalign 1.0\n"
            "            easein 15.0 yalign 0.0\n"
            "        with Dissolve(1.0)",
            # WITH TODO: Emi bed event
            "        scene ev emi_bed_normal_f:\n"
            "        with Dissolve(1.0)",
        )

    if scenario_name == "script-a3-emi":
        return content.replace(
            "        show emi rin_roof\n"
            "        with charaenter",
            # WITH TODO: Emi roof (shadow on Rin)
            "\n"
        ).replace(
            "        scene bg school_library_yuuko_blurred\n"
            "        show phone mobile:\n"
            "            xalign 0.5 yanchor 0.5 ypos 0.7 alpha 0.0\n"
            "            easein 1.0 yalign 0.5 alpha 1.0\n"
            "        with locationchange",
            # WITH TODO: mobile phone on scene in library
            "\n"
        ).replace(
            "        scene evh emi_shed_base1\n"
            "        show emi emi_shed_grin\n"
            "        show hisao emi_shed_neutral\n"
            "        show evh_l emi_shed_up\n"
            "        show evh_r emi_shed_down\n"
            "        with shorttimeskip",
            # WITH TODO: Lemon
            "        scene evh emi_shed_base1\n"
            "        with shorttimeskip"
        ).replace(
            "        show emi emi_shed_hesitant\n"
            "        with persistent.charachange",
            # WITH TODO: Lemon
            "\n"
        ).replace(
            "        show evh emi_shed_base2\n"
            "        show hisao emi_shed_closed\n"
            "        with charachangeev",
            # WTIH TODO: Lemon
            "        scene evh emi_shed_base2"
        ).replace(
            "        show emi emi_shed_shock\n"
            "        with hpunch",
            # WITH TODO: Lemon
            "\n"
        ).replace(
            "        show hisao emi_shed_neutral\n"
            "        with charachangeev",
            # WITH TODO: Lemon
            "\n"
        ).replace(
            "        show emi emi_shed_closed\n"
            "        with charachangeev",
            # WITH TODO: Lemon
            "\n"
        ).replace(
            "        show hisao emi_shed_closed\n"
            "        with charachangeev",
            # WITH TODO: Lemon
            "\n"
        ).replace(
            "        show evh emi_shed_base3\n"
            "        show emi emi_shed_hesitant\n"
            "        with charachangeev",
            # WITH TODO: Lemon
            "        scene evh emi_shed_base3"
        ).replace(
            "        show emi emi_shed_grin\n"
            "        with charachangeev",
            # WITH TODO: Lemon
            "\n"
        ).replace(
            "        show emi emi_shed_hesitant\n"
            "        with charachangeev",
            # WITH TODO: Lemon
            "\n"
        ).replace(
            "        show evh_r emi_shed_up\n"
            "        show emi emi_shed_shock\n"
            "        with charachangeev",
            # WITH TODO: Lemon
            "\n"
        ).replace(
            "        show hisao emi_shed_sweat\n"
            "        with charachangeev",
            # WITH TODO: Lemon
            "\n"
        ).replace(
            "        show evh emi_shed_base4\n"
            "        show hisao emi_shed_neutral\n"
            "        show emi emi_shed_closed\n"
            "        show evh_l emi_shed_down\n"
            "        with charachangeev",
            # WITH TODO: Lemon
            "        scene evh emi_shed_base4"
        ).replace(
            "        show evh_l emi_shed_up\n"
            "        show evh_r emi_shed_down\n"
            "        with charachangeev",
            # WITH TODO: Lemon
            "\n"
        )

    if scenario_name == "script-a4-emi":
        return content.replace(
            "        show emi gymconcentratebounce\n",
            # WITH TODO: Emi concentrate bounce animation
            "\n"
        )

    if scenario_name == "script-a2-rin":
        return content.replace(
            "        show ev hisaobird_0:\n"
            "            center\n"
            "            ypos 1.5 alpha 0.0\n"
            "            easein 0.5 center alpha 1.0\n"
            "\n"
            "        pause 0.5\n"
            "\n"
            "        show ev at center:\n"
            "            alpha 1.0",
            # WITH TODO: Hisaobird event?
            "        show ev hisaobird_0:\n"
            "        with charachangeev",
        ).replace(
            "        show ev:\n"
            "            easeout 0.5 alpha 0.0 ypos 1.5\n"
            "        show bg:\n"
            "            yalign 0.0\n"
            "            ease 20.0 zoom 1.1\n"
            "\n"
            "        pause 0.5\n"
            "\n"
            "        hide ev",
            # WITH TODO: Hisaobird event?
            "        scene bg school_scienceroom:\n"
            "        with charachangeev"
        ).replace(
            "        show ev hisaobird_1:\n"
            "            center\n"
            "            ypos 1.5 alpha 0.0\n"
            "            easein 0.5 center alpha 1.0\n"
            "\n"
            "        pause 0.5\n"
            "\n"
            "        show ev hisaobird_2 at center:\n"
            "            alpha 1.0\n"
            "            with charachangeev",
            # WITH TODO: Hisaobird event?
            "        show ev hisaobird_1:\n"
            "        with charachangeev\n"
            "\n"
            "        pause 0.5\n"
            "\n"
            "        show ev hisaobird_2:\n"
            "        with charachangeev"
        ).replace(
            "        show bg behind ev at center\n"
            "        show shizu behind_blank_close behind ev at closeright\n"
            "        show misha cross_smile_close behind ev at closeleft\n"
            "\n"
            "        show ev hisaobird_9:\n"
            "            center\n"
            "            easeout 0.5 alpha 0.0 ypos 1.5\n"
            "\n"
            "        pause 0.5\n"
            "\n"
            "        hide ev",
            # WITH (fix) TODO: Hisaobird event?
            "        scene ev hisaobird_9:\n"
            "        with charachangeev\n"
            "\n"
            "        pause 0.5\n"
            "\n"
            "        scene bg school_scienceroom:\n"
            "        with charachangeev\n"
            "        show shizu behind_blank_close at closeright\n"
            "        show misha cross_smile_close at closeleft"
        ).replace(
            "        scene bg watchhallway_blur\n"
            "        show ev watch_worn at truecenter\n"
            "        with locationchange",
            # WITH TODO: Watch worn event?
            "        scene bg school_hallway3\n"
            "        with locationchange"
        ).replace(
            "        show ev:\n"
            "            easeout 0.5 ypos 1.0 alpha 0.0",
            # WITH
            "\n"
        )

    if scenario_name == "script-a3-rin":
        return content.replace(
            "        show ev:\n"
            "            acdc_warp 40.0 zoom 1.0",
            # WITH
            "\n"
        ).replace(
            "            show ev:\n"
            "                easeout 1.0 ypos 0.7 alpha 0.0\n"
            "            with None",
            # WITH
            "\n"
        ).replace(
            "        show emi happybounce\n"
            "\n"
            "        pause 0.5",
            # WITH TODO: Emi bouncing animation
            "\n"
        ).replace(
            "            show ev watch_worn_330:\n"
            "                truecenter\n"
            "                ypos 0.7\n"
            "                easein 1.0 truecenter\n"
            "            show bg school_dormhisao_blurred_ni\n"
            "            with Dissolve(1.0)",
            # WITH TODO: Watch worn event?
            "\n"
        ).replace(
            "            hide ev watch_worn_330\n"
            "            with None",
            # WITH TODO: Watch worn event?
            "\n"
        )

    if scenario_name == "script-a4-rin":
        return content.replace(
            "            show ev:\n"
            "                \"ev rin_trueend_gone_ni\" with Dissolve(10.0)",
            # WITH
            "\n"
        ).replace(
            "            show evh:\n"
            "                acdc_warp 8.0 yalign 0.8",
            # WITH
            "\n"
        ).replace(
            "            show evbg:\n"
            "                acdc_warp 12.0 zoom 1.15\n"
            "            show rin goodend_2_hires:\n"
            "                zoom 0.769\n"
            "                acdc_warp 12.0 yalign 0.0 zoom 1.0\n"
            "            show evfg:\n"
            "                acdc_warp 12.0 yalign 0.0 zoom 1.45\n"
            "            with None",
            # WITH
            "\n"
        ).replace(
            "            show evbg rin_goodend_base zorder -1:\n"
            "                xalign 0.0\n"
            "                1.0\n"
            "                easein 20.0 xalign 1.0\n"
            "            show rin goodend_1:\n"
            "                xalign -0.5\n"
            "                1.0\n"
            "                easein 20.0 xalign 1.0\n"
            "            show evfg rin_goodend:\n"
            "                xalign -1.0\n"
            "                1.0\n"
            "                easein 20.0 xalign 1.0\n"
            "            hide bg\n"
            "            with whiteout",
            # WITH TODO: Rin Good End Event.
            "            show ev rin_goodend_1\n"
            "            with whiteout",
        ).replace(
            "            show evbg at right\n"
            "            show rin goodend_1b at right\n"
            "            show evfg at right\n"
            "            with charachangealways",
            # WITH TODO: Rin Good End Event.
            "            show ev rin_goodend_1b\n"
            "            with charachangealways"
        ).replace(
            "            show rin goodend_2\n"
            "            with charachangeev",
            # WITH TODO: Rin Good End Event.
            "            show ev rin_goodend_2\n"
            "            with charachangeev"
        ).replace(
            "            show evbg:\n"
            "                acdc_warp 12.0 zoom 1.15\n"
            "            show rin goodend_2_hires:\n"
            "                zoom 0.769\n"
            "                acdc_warp 12.0 yalign 0.0 zoom 1.0\n"
            "            show evfg:\n"
            "                acdc_warp 12.0 yalign 0.0 zoom 1.45\n"
            "            with None",
            # WITH TODO: Rin Good End Event.
            "\n"
        ).replace(
            "            scene ev rin_pair_base_clothes\n"
            "            show rp_hisao normal at truecenter\n"
            "            show rp_rin normal at truecenter\n"
            "            with whiteout",
            # WITH TODO: Rin-Hisao pair Event
            "            scene ev rin_pair_base\n"
            "            with whiteout"
        ).replace(
            "            show rp_hisao frown\n"
            "            with charachangeev",
            # WITH TODO: Rin-Hisao pair Event,
            "\n"
        ).replace(
            "            show rp_rin talk\n"            
            "            with charachangeev",
            # WITH TODO: Rin-Hisao pair Event,
            "\n"
        ).replace(
            "            show rp_hisao smile\n"
            "            with charachangeev",
            # WITH TODO: Rin-Hisao pair Event,
            "\n"
        ).replace(
            "            show rp_rin smile\n"
            "            with charachangeev",
            # WITH TODO: Rin-Hisao pair Event,
            "\n"
        ).replace(
            "            show rp_rin frown\n"
            "            with charachangeev",
            # WITH TODO: Rin-Hisao pair Event,
            "\n"
        ).replace(
            "            show rp_hisao normal\n"
            "            with charachangeev",
            # WITH TODO: Rin-Hisao pair Event,
            "\n"
        ).replace(
            "            show rp_rin normal\n"
            "            with charachangeev",
            # WITH TODO: Rin-Hisao pair Event,
            "\n"
        ).replace(
            "            show rp_rin closed\n"
            "            with charachangeev",
            # WITH TODO: Rin-Hisao pair Event,
            "\n"
        ).replace(
            "            nvl clear\n"
            "\n"
            "            show bg:\n"
            "                \"bg school_nomiya_ss\" with Dissolve(8.0)\n"
            "            show rin:\n"
            "                \"rin negative_crying_superclose_ss\" with Dissolve(8.0)",
            # WITH (fix) TODO: bg change to Sunset during novel!
            "            nvl clear\n"
        )

    if scenario_name == "script-a2-lilly":
        return content.replace(
            "        scene evbg lilly_sunsetwalk:\n"
            "            truecenter zoom 0.9\n"
            "            acdc_warp 20.0 zoom 1.0\n"
            "        show evfg lilly_sunsetwalk:\n"
            "            truecenter zoom 0.85\n"
            "            acdc_warp 20.0 zoom 1.0\n"
            "        with locationskip",
            # WITH TODO: Lilly sunset walk, check if we can reuse Lilly's superclose sprites!
            "        scene ev lilly_sunsetwalk_bg\n"
            "        with locationskip",
        )

    if scenario_name == "script-a3-lilly":
        return content.replace(
            "        scene evhunlock lilly_handjob_chest_normal_small\n"
            "        show evh lilly_handjob_chest_normal:\n"
            "            xalign 0.7 yalign 1.0\n"
            "            ease 8.0 xalign 0.4 yalign 0.2\n"
            "        with whiteout",
            # WITH:
            "        scene ev lilly_hcg_handjob_chest_normal\n"
            "        with whiteout"
        ).replace(
            "        show evhunlock lilly_handjob_chest_frown_small\n"
            "        show evh lilly_handjob_chest_frown:\n"
            "            xalign 0.4 yalign 0.2\n"
            "        with charachangeev",
            # WITH:
            "        scene ev lilly_hcg_handjob_chest_frown\n"
            "        with charachangeev"
        ).replace(
            "        show evh lilly_handjob_chest_normal\n"
            "        with charachangeev",
            # WITH
            "        scene ev lilly_hcg_handjob_chest_normal\n"
            "        with charachangeev"
        ).replace(
            "        show evh:\n"
            "            zoom 1.0 xalign 0.4 yalign 0.2\n"
            "            ease 4.0 xalign 0.5 yalign 0.5\n"
            "        with None",
            # WITH
            "\n"
        ).replace(
            "        show evh lilly_handjob_stroke_normopen:\n"
            "            zoom 1.0 xalign 0.4 yalign 0.2\n"
            "            ease 4.0 xalign 0.5 yalign 0.5\n"
            "        with charachangeev",
            # WITH
            "        scene ev lilly_hcg_handjob_stroke_normopen\n"
            "        with charachangeev"
        ).replace(
            "        show evh lilly_handjob_stroke_normshut_small:\n"
            "            truecenter\n"
            "            zoom 1.0\n"
            "        with charachangeev",
            # WITH
            "        scene ev lilly_hcg_handjob_stroke_normshut_small\n"
            "        with charachangeev"
        ).replace(
            "show evh lilly_handjob_stroke_flustopen_small", "scene ev lilly_hcg_handjob_stroke_flustopen_small"
        ).replace(
            "show evh lilly_handjob_stroke_normopen_small", "scene ev lilly_hcg_handjob_stroke_normopen_small"
        ).replace(
            "show evh lilly_cowgirl_smile_small", "scene ev lilly_hcg_cowgirl_smile_small"
        ).replace(
            "show evh lilly_cowgirl_weaksmile_small", "scene ev lilly_hcg_cowgirl_weaksmile_small"
        ).replace(
            "scene evh lilly_cowgirl_strain_small", "scene ev lilly_hcg_cowgirl_strain_small"
        ).replace(
            "scene evh lilly_cowgirl_frown_small", "scene ev lilly_hcg_cowgirl_frown_small"
        ).replace(
            "scene evh lilly_cowgirl_cry_small", "scene ev lilly_hcg_cowgirl_cry_small"
        ).replace(
            "scene evh lilly_cowgirl_weaksmile_small", "scene ev lilly_hcg_cowgirl_weaksmile_small"
        ).replace(
            "scene evh lilly_cowgirl_smile_small", "scene ev lilly_hcg_cowgirl_smile_small"
        ).replace(
            "scene evh lilly_bath_smile_small", "scene ev lilly_hcg_bath_smile_small"
        ).replace(
            "show evh lilly_bath_emb_small", "scene ev lilly_hcg_bath_emb_small"
        ).replace(
            "show evh lilly_bath_smile_small", "scene ev lilly_hcg_bath_smile_small"
        ).replace(
            "show evh lilly_bath_open_small", "scene ev lilly_hcg_bath_open_small"
        ).replace(
            "show evh lilly_bath_grab_small", "scene ev lilly_hcg_bath_grab_small"
        ).replace(
            "show evh lilly_bath_moan_small", "scene ev lilly_hcg_bath_moan_small"
        ).replace(
            "show evh lilly_bath_smile_small", "scene ev lilly_hcg_bath_smile_small"
        ).replace(
            "scene evh lilly_afterbath_open_small", "scene ev lilly_hcg_afterbath_open_small"
        ).replace(
            "scene evh lilly_afterbath_shut_small", "scene ev lilly_hcg_afterbath_shut_small"
        )

    if scenario_name == "script-a2-shizune":
        return content.replace(
            "        scene evbg kenji_glasses:\n"
            "            truecenter\n"
            "            zoom 0.82\n"
            "            acdc_warp 20.0 zoom 0.8\n"
            "        show evmg kenji_glasses_closed at kenji_mg_out\n"
            "        show evfg kenji_glasses:\n"
            "            truecenter\n"
            "            zoom 1.0\n"
            "            acdc_warp 20.0 zoom 0.8\n"
            "        with whiteout",
            # WITH
            "        scene ev kenji_glasses_bg\n"
            "        with whiteout"
        ).replace(
            "        show evmg kenji_glasses_frown at kenji_mg_out\n"
            "        with charachangeev",
            # WITH
            "        scene ev kenji_glasses_bg\n"
            "        with charachangeev"
        ).replace(
            "        show evmg kenji_glasses_normal at kenji_mg_out\n"
            "        with charachangeev",
            # WITH
            "        scene ev kenji_glasses_bg\n"
            "        with charachangeev"
        ).replace(
            "        show evmg kenji_glasses_closed at kenji_mg_out\n"
            "        with charachangeev",
            # WITH
            "        scene ev kenji_glasses_bg\n"
            "        with charachangeev"
        ).replace(
            "        show ev:\n"
            "            ease 1.0 xpos 400 xanchor 2870 yanchor 650 ypos 300\n"
            "            acdc_warp 10.0 xanchor 2670",
            # WITH
            "\n"
        ).replace(
            "        show ev:\n"
            "            ease 0.5 xanchor 1600 yanchor 560\n"
            "            easein 10.0 xanchor 1400 yanchor 560",
            # WITH
            "\n"
        )

    if scenario_name == "script-a3-shizune":
        return content.replace(
            "        scene evh shizune_hcg_tied_stare:\n"
            "            yalign 0.0 xalign 1.0 zoom 2.0\n"
            "            easein 6.0 xalign 0.7 zoom 1.0 yalign 0.345\n"
            "            truecenter\n"
            "            zoom 1.0\n"
            "            \"evh shizune_hcg_tied_stare_small\"\n"
            "        with whiteout",
            # WITH
            "        scene evh shizune_hcg_tied_smile_small\n"
            "        with whiteout"
        )

    if scenario_name == "script-a2-hanako":
        return content.replace(
            "        show hanagown:\n"
            "            easeout 0.5 xpos 0.7 alpha 0.0\n"
            "\n"
            "        pause 0.5\n"
            "\n"
            "        hide hanako",
            # WITH (fix)
            "        show hanagown:\n"
            "            easeout 0.5 xpos 0.7 alpha 0.0\n"
            "\n"
            "        pause 0.5\n"
            "\n"
            "        hide hanagown",
        )

    if scenario_name == "script-a3-hanako":
        return content.replace(
            "        scene evbg hanako_breakdown:\n"
            "            truecenter\n"
            "            1.0\n"
            "            zoom 1.05\n"
            "            easein 8.0 zoom 1.0\n"
            "        show evfg hanako_breakdown_down:\n"
            "            truecenter\n"
            "            1.0\n"
            "            zoom 1.1\n"
            "            easein 8.0 zoom 1.0\n"
            "        with silentwhiteout",
            # WITH TODO: Hanako breakdown event
            "        scene ev hanako_breakdown_down:\n"
            "        with silentwhiteout",
        ).replace(
            "        scene evbg hanako_breakdown:\n"
            "            truecenter\n"
            "        show evfg hanako_breakdown_up:\n"
            "            truecenter\n"
            "        with charachangeev\n",
            # WITH TODO: Hanako breakdown event
            "\n"
        ).replace(
            "        show evfg hanako_breakdown_closed\n"
            "        with charachangeev\n",
            # WITH TODO: Hanako breakdown event
            "\n"
        ).replace(
            "        show hanako emb_downsad_close:\n"
            "            function partial(tremble_general, 1.0, 0.5, 1.09, 0.5, 1.0)\n"
            "        with charachangealways",
            # WITH TODO: Hanako breakdown event
            "        show hanako emb_downsad_close"
        )

    if scenario_name == "script-a4-hanako":
        return content.replace(
            "        scene evbg hanako_emptyclassroom:\n"
            "            truecenter\n"
            "            zoom 0.9\n"
            "            easein 20.0 zoom 1.0\n"
            "        show evfg hanako_emptyclassroom:\n"
            "            truecenter\n"
            "            zoom 0.8\n"
            "            easein 20.0 zoom 1.0\n"
            "        with whiteout",
            # WITH TODO: Hanako empty classroom event
            "        scene ev hanako_emptyclassroom_bg\n"
            "        with whiteout"
        ).replace(
            "        show hanako:\n"
            "            linear 1.0 alpha 0.0\n"
            "        with shorttimeskip\n"
            "\n"
            "        hide hanako",
            # WITH (fix)
            "        hide hanako\n"
            "\n"
            "        scene bg city_karaokeint\n"
            "        with shorttimeskip"
        )

    return content

def get_custom_event(bg_name: str) -> tuple[str, str] | tuple[None, None]:

    # OP_SNOWYWOODS
    if bg_name == "op_snowywoods":
        return "op_snowywoods", "OpSnowywoodsEvent"

    # OTHER_IWANAKO
    # TODO: Other Iwanako Start event (Affine background scaling down)
    if bg_name == "other_iwanako":
        return "other_iwanako", "OtherIwanakoEvent"

    # HOSP_ROOM
    if bg_name == "hosp_room":
        return "hosp_room", "HospRoomEvent"

    # HISAO CLASS
    if bg_name == "hisao_class_start":
        return "hisao_class", "HisaoClassStartEvent"
    elif bg_name == "hisao_class_move":
        return "hisao_class", "HisaoClassMoveEvent"
    elif bg_name == "hisao_class_end":
        return "hisao_class", "HisaoClassEndEvent"

    # EMI KNOCKEDDOWN
    if bg_name == "emi_knockeddown_facepullout":
        return "emi_knockeddown_facepullout", "EmiKnockeddownFacepulloutEvent"
    elif bg_name == "emi_knockeddown_largepullout":
        return "emi_knockeddown_largepullout", "EmiKnockeddownLargepulloutEvent"
    elif bg_name == "emi_knockeddown_legs":
        return "emi_knockeddown_legs", "EmiKnockeddownLegsEvent"
    elif bg_name == "emi_knockeddown":
        return "emi_knockeddown_largepullout", "EmiKnockeddownEvent"

    # LILLY SHIZU SHOWDOWN
    if bg_name == "showdown_slices":
        return "lilly_shizu_showdown_slices_lilly", "LillyShizuShowdownSlicesEvent"
    elif bg_name == "showdown_lilly":
        return "lilly_shizu_showdown_both", "LillyShizuShowdownLillyEvent"
    elif bg_name == "showdown_shizu":
        return "lilly_shizu_showdown_both", "LillyShizuShowdownShizuEvent"

    # DRUGS EVENT
    if bg_name == "drugs_event":
        return "event_drugs", "DrugsEvent"

    # NIGHTSKY FIREWORKS
    if bg_name == "nightsky_fw":
        return "misc_sky_ni", "NightskyFireworksEvent"

    # HANAKO FIREWORKS
    if bg_name == "hanako_fw":
        return "hanako_fw_base", "HanakoFireworksEvent"

    return None, None

def has_sequence_item_with_type(linepack: List[SequenceItem], sequence_type: SequenceType) -> bool:
    for item in linepack:
        if item.get_type() == sequence_type:
            return True
    return False