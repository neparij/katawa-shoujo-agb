import hashlib
import os
import re
import tempfile
from typing import List, cast, Tuple

from src.dto.assignment_item import AssignmentItem
from src.dto.background_item import BackgroundItem, BgShowPosition, BgTransition
from src.dto.background_transform_item import BackgroundTransformItem
from src.dto.background_transition_item import BackgroundTransitionItem
from src.dto.condition_item import ConditionItem
from src.dto.custom_event_item import CustomEventItem
from src.dto.dialog_item import DialogItem
from src.dto.hide_item import HideEvent, HideItem
from src.dto.menu_item import MenuItem
from src.dto.music_item import MusicItem, MusicAction, MusicEffect
from src.dto.pause_item import PauseItem
from src.dto.return_item import ReturnItem
from src.dto.run_label_item import RunLabelItem
from src.dto.sequence_item import SequenceType, SequenceItem
from src.dto.show_item import ShowEvent, ShowItem, ShowPosition
from src.dto.show_transform_item import ShowTransformItem
from src.dto.show_video_item import ShowVideoItem
from src.dto.sound_item import SoundItem, SoundAction, SoundEffect, SoundChannel
from src.dto.update_visuals_item import UpdateVisualsItem
from src.scenario.scenario_script_stack import ScenarioScriptStack
from src.scenario.sequence_group import SequenceGroup, SequenceGroupType
from src.translation.translation_container import TranslationContainer
from src.utils import sanitize_function_name, get_xalign_position


class ScenarioReader:
    def __init__(self, scenario_file, translation: TranslationContainer):
        self.scenario_file = scenario_file
        self.translation = translation
        self.scenario: List[SequenceGroup] = []
        self.stack: ScenarioScriptStack = ScenarioScriptStack()
        self.initial_name = None
        self._hack_nvl_cleared = False
        self._hack_latest_label_name = None
        self._hack_latest_sprite_name = None
        self.linepack_events : List[SequenceItem] = []


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

    def calculate_tl_hash(self, line):
        md5 = hashlib.md5()
        md5.update((line + "\r\n").encode("utf-8"))
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

    # def close_conditions(self, current_indent, next_line):
    #     """Closes conditions until reaching the target indentation."""
    #     has_next_condition = next_line.startswith("elif ") or next_line.startswith("else:")
    #     if self.stack.size() > 0 and self.stack.current().type == SequenceGroupType.CONDITION and self.stack.current_indent() >= current_indent and not (has_next_condition and self.stack.current_indent() < get_line_indent(next_line)):
    #     # while self.stack.size() > 0 and self.stack.current().type == SequenceGroupType.CONDITION and self.stack.current_indent() >= current_indent and not has_conditional_operator:
    #         condition = self.stack.pop()
    #         self.scenario.append(condition)
    #
    def close_conditions(self, current_indent, next_line):
        """Closes conditions until reaching the target indentation."""
        while self.stack.size() > 0 and self.stack.current().type == SequenceGroupType.CONDITION and self.stack.current_indent() >= current_indent:
            condition = self.stack.pop()
            self.scenario.append(condition)

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
        print(">>>>>>>>>>>>>>>>>>>>>>")
        with_clause = None
        self.linepack_events : List[SequenceItem] = []
        for line, current_indent in line_pack:
           self.process_line(line, current_indent)
        line_pack.clear()
        # TODO: process show sequence with "at" clause here!

        # if SequenceType.SHOW in self.linepack_events or SequenceType.SHOW_TRANSFORM in self.linepack_events:
        if (has_sequence_item_with_type(self.linepack_events, SequenceType.SHOW) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.HIDE) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.SHOW_TRANSFORM) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.BACKGROUND_TRANSITION) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.BACKGROUND_TRANSFORM) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.BACKGROUND) or
                has_sequence_item_with_type(self.linepack_events, SequenceType.CUSTOM_EVENT)):
            self.stack.current().add_sequence_item(self.linepack_events, UpdateVisualsItem())
        print("<<<<<<<<<<<<<<<<<<<<<<\n")

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
                if self.stack.size() == 0 and not self._hack_latest_label_name:
                    raise Exception("Initial label cannot be a relative label")
                elif self.stack.size() == 0:
                    label_name = f"{self._hack_latest_label_name}_{label_name}"
            name = sanitize_function_name(label_name)

            if self.stack.size() > 0:
                name = f"{self.stack.parent_label().name}_{name}"
                self.stack.current().add_sequence_item(self.linepack_events, RunLabelItem(name, self.initial_name and name.startswith(self.initial_name)))
            else:
                name = name

            if not self.initial_name:
                self.initial_name = name
                self.stack.push(SequenceGroup(name, SequenceGroupType.LABEL, True, True), current_indent)
            else:
                self.stack.push(SequenceGroup(name, SequenceGroupType.LABEL, name.startswith(self.initial_name)), current_indent)
            return

        elif stripped_line == "return":
            self.stack.current().add_sequence_item(self.linepack_events, ReturnItem())
            return

        elif stripped_line.startswith("if "):
            condition = stripped_line.split("if ", 1)[1].strip(":")
            condition = rewrite_condition(condition)

            # TODO: process conditions, also transpose it from py to c++

            # TODO: custom condition definition for _in_replay
            #     Example in rpy scenario:
            #     if _in_replay:
            #         return
            #
            # TODO: custom condition definition for go_through_lilly()
            #     def go_through_lilly():
            #         return talk_with_hanako and side_lilly
            #
            # TODO: custom condition definition for go_through_shizu()
            #     def go_through_shizu():
            #         return wait_for_shizu and not side_lilly
            #
            # TODO: custom condition definition for go_through_rin()
            #     def get_tired():
            #         return promised and go_for_it
            #
            # TODO: custom condition definition for go_through_rin()
            #     def got_kenji():
            #         return kick_shizu or fun_fun_at_office or not_much_talking
            #
            # TODO: custom condition definition for persistent.disable_disturbing_content
            #     Example in rpy scenario:
            #     if persistent.disable_disturbing_content:
            #         "The following scene is disabled based on your accessibility options. By proceeding forward, you'll skip to the next day. "

            if self.stack:
                name = f"{self.stack.current().name}__condition_{sum(1 for item in self.stack.current().sequence if isinstance(item, ConditionItem))}"
            else:
                raise Exception("Condition block outside of label stack")

            self.stack.current().add_sequence_item(self.linepack_events, ConditionItem(name))

            condition_stack = SequenceGroup(name, SequenceGroupType.CONDITION)
            condition_stack.add_condition(condition)
            self.stack.push(condition_stack, current_indent)
            return

        elif stripped_line.startswith("elif "):
            condition = stripped_line.split("elif ", 1)[1].strip(":")
            condition = rewrite_condition(condition)
            if self.stack.current().type != SequenceGroupType.CONDITION:
                raise Exception("Elif block outside of condition block")
            self.stack.current().add_condition(condition)
            return

        elif stripped_line.startswith("else:"):
            if self.stack.current().type != SequenceGroupType.CONDITION:
                raise Exception("Else block outside of condition block")
            self.stack.current().add_condition()
            return

        elif stripped_line.startswith("menu:"):
            if self.stack:
                name = f"{self.stack.current().name}__menu_question_{sum(1 for item in self.stack.current().sequence if isinstance(item, MenuItem))}"
            else:
                raise Exception("Menu block outside of label stack")

            self.stack.current().add_sequence_item(self.linepack_events, MenuItem(name))
            self.stack.push(SequenceGroup(name, SequenceGroupType.MENU), current_indent)
            return

        elif self.stack.current().type == SequenceGroupType.MENU and stripped_line.startswith("\""):
            # Parse menu choice
            match = re.match(r"\"(.*)\"(?:| if (.*)):$", stripped_line)
            if match:
                choice_text = match.group(1)
                condition_block = match.group(2)
                choice_text_translated = None
                if self.translation and choice_text in self.translation.strings:
                    choice_text_translated = self.translation.strings[choice_text]

                condition = condition_block if condition_block else None
                # self.stack.current().add_condition(choice_text_translated if choice_text_translated else choice_text, f"{self.stack.current().name}_{sanitize_function_name(choice_text)}")
                self.stack.current().add_answer(
                    answer = choice_text_translated if choice_text_translated else choice_text,
                    condition = condition,
                    callback = f"{self.stack.current().name}_{sanitize_function_name(choice_text)}"
                )
                # self.stack.push(SequenceGroup(f"{self.stack.current().name}_{sanitize_function_name(choice_text)}", SequenceGroupType.MENU), current_indent)
            return

        elif stripped_line.startswith("$ "):
            # Inline assignments in menu blocks
            command = stripped_line[2:].strip()
            self.stack.current().add_sequence_item(self.linepack_events, AssignmentItem(command))
            return

        elif stripped_line.startswith("call act_op("):
            video_name = stripped_line.split("act_op(\"", 1)[1].strip("\")")
            video_without_extension = video_name.split(".")[0]
            self.stack.current().add_sequence_item(self.linepack_events, ShowVideoItem(video_without_extension))
            return

        elif stripped_line.startswith("call "):
            skip = False
            if "act_op(" in stripped_line or "call screen " in stripped_line or "call timeskip" in stripped_line:
                skip = True
            if not skip:
                # Inline calls in menu blocks
                function_name = stripped_line.split("call ", 1)[1].strip()
                if function_name == "a1c4o1":
                    self.stack.current().add_sequence_item(self.linepack_events, AssignmentItem("im_new_here = True"))
                self.stack.current().add_sequence_item(self.linepack_events, RunLabelItem(sanitize_function_name(function_name), False))
            return

        elif stripped_line.startswith("scene bg"):
            parts = stripped_line.split()
            scene_bg_name = parts[2]

            if "at bgleft" in stripped_line or "at left" in stripped_line:
                position = BgShowPosition.BGLEFT
            elif "at bgright" in stripped_line or "at right" in stripped_line:
                position = BgShowPosition.BGRIGHT
            elif "at center" in stripped_line:
                position = BgShowPosition.CENTER
            else:
                position = BgShowPosition.DEFAULT

            self.stack.current().add_sequence_item(self.linepack_events, BackgroundItem(scene_bg_name, position=position))
            return

        elif stripped_line.startswith("scene ev") or stripped_line.startswith("show ev"):
            parts = stripped_line.split()
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
            return

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
            return

        elif stripped_line.startswith("show "):
            print("Show sequence")
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

            self.stack.current().add_sequence_item(self.linepack_events, ShowItem(sprite_name, variant_name, event_type, position))
            self._hack_latest_sprite_name = sprite_name
            return

        elif stripped_line.startswith("hide "):
            parts = stripped_line.split()
            sprite_name = parts[1]

            event_type = HideEvent.CHARACTER_EXIT if "with charaexit" in stripped_line else HideEvent.NONE
            self.stack.current().add_sequence_item(self.linepack_events, HideItem(sprite_name, event_type))
            return

        elif "xalign " in stripped_line:
            print("Show transform sequence (xalign)")
            # xalign 0.4 blah-blah 1.2 etc should set value to 0.4
            value = float(stripped_line.split("xalign ")[1].split()[0])
            self.stack.current().add_sequence_item(self.linepack_events, ShowTransformItem(self._hack_latest_sprite_name, None, get_xalign_position(value)))

        elif stripped_line.startswith("nvl "):
            parts = stripped_line.split()
            action_name = parts[1]
            if action_name == "clear":
                self._hack_nvl_cleared = True
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
            displayable_dissolve_match = re.match(r"^with Dissolve\(([\d.]+)\)$", stripped_line)
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
                hashing_contents = f"nvl clear\r\n{hashing_contents}"
            # if self.stack.current().type == SequenceGroupType.MENU:
                # hashing_contents = f"{hashing_contents} nointeract"

            dialog_match_str = re.match(r"^\"(.+)\"\s+\"(.*)\"(?:| nointeract)$", stripped_line)
            dialog_match_ref = re.match(r"^(.+)\s+\"(.*)\"(?:| nointeract)$", stripped_line)
            narration_match = re.match(r"^\"(.*)\"(?:| nointeract)$", stripped_line)

            original_dialog_hash = self.calculate_tl_hash(hashing_contents)
            dialog_hash = original_dialog_hash

            if dialog_match_str or dialog_match_ref or narration_match:
                if self.translation:
                    if dialog_hash not in self.translation.translations:
                        dialog_hash = self.calculate_tl_hash(f"{hashing_contents} nointeract")
                    if dialog_hash not in self.translation.translations:
                        # Hack: there is a case where the dialog hash label contains unclosed previous label.
                        # So we need to find a key by remaining part of hash
                        # Example: a1_thursday_things_you_can_do_5abaf868 should be a1_thursday_5abaf868
                        short_hash = original_dialog_hash[-8:]
                        for key in self.translation.translations:
                            if key.endswith(short_hash):
                                dialog_hash = key
                                break
                    if dialog_hash not in self.translation.translations:
                        raise Exception(f"Missing translation for:\n{stripped_line}")
                    stripped_line = self.translation.translations[dialog_hash]
                    dialog_match_str = re.match(r"^\"(\w+)\"\s+\"(.*)\"(?:| nointeract)$", stripped_line)
                    dialog_match_ref = re.match(r"^(\w+)\s+\"(.*)\"(?:| nointeract)$", stripped_line)
                    narration_match = re.match(r"^\"(.*)\"(?:| nointeract)$", stripped_line)

            if dialog_match_str:
                actor, dialog = dialog_match_str.groups()
                self.stack.current().add_sequence_item(self.linepack_events,
                    DialogItem(dialog_hash, actor, dialog.strip().replace("\\n", "\n")))
            elif dialog_match_ref:
                actor, dialog = dialog_match_ref.groups()
                self.stack.current().add_sequence_item(self.linepack_events,
                    DialogItem(dialog_hash, "", dialog.strip().replace("\\n", "\n"), actor))
            elif narration_match:
                narration = narration_match.group(1)
                self.stack.current().add_sequence_item(self.linepack_events,
                    DialogItem(dialog_hash, "", narration.strip().replace("\\n", "\n")))
            return

def get_line_indent(line: str) -> int:
    return (len(line) - len(line.lstrip())) // 4

def rewrite_condition(condition: str) -> str:
    # FROM: "Hi! I'm new here. Hisao Nakai. We're in the same class." in choices
    # TO im_new_here = True
    return condition.replace('"Hi! I\'m new here. Hisao Nakai. We\'re in the same class." in choices', 'im_new_here == True')

def rewrite_background(bg_name: str) -> str:
    return rewrite_motion_background(bg_name)

def rewrite_motion_background(bg_name: str) -> str:
    # TODO: remove this method and allow motion backgrounds
    return (bg_name
            .replace("other_iwanako_start", "other_iwanako")
            # .replace("_start", "")
            # .replace("_move", "")
            # .replace("_end", "")
            .replace("_zoomout", "")
            # .replace("emi_knockeddown_facepullout", "emi_knockeddown")
            # .replace("emi_knockeddown_largepullout", "emi_knockeddown")
            # .replace("emi_knockeddown_legs", "emi_knockeddown")
            )

def scenario_rewrites(scenario_file, content):
    scenario_name = os.path.splitext(os.path.basename(scenario_file))[0]
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
            "        pause 0.2\n"
            "\n"
            "        play sound sfx_draw\n"
            "        show showdown_shizu_slice:\n"
            "            easein 0.2 xalign 1.0 yalign 1.0\n"
            "\n"
            "        pause 0.2\n",
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
            "            size (1920, 1080) crop (0, 0, 5760, 3240)\n"
            "            easeout 0.2 crop (672, 240, 1920, 1080)\n",
            # WITH
            "        show ev showdown_lilly\n"
        ).replace(
            "        show ev showdown_large:\n"
            "            ease 0.2 crop (672, 240, 1920, 1080)\n",
            # WITH
            "        show ev showdown_lilly\n"
        ).replace(
            "        show ev showdown_large:\n"
            "            ease 0.2 crop (3360, 384, 1920, 1080)\n",
            # WITH
            "        show ev showdown_shizu\n"
        )
    return content

def get_custom_event(bg_name: str) -> tuple[str, str] | tuple[None, None]:
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

    return None, None

def has_sequence_item_with_type(linepack: List[SequenceItem], sequence_type: SequenceType) -> bool:
    for item in linepack:
        if item.get_type() == sequence_type:
            return True
    return False