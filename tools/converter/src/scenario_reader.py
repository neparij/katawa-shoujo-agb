import hashlib
import re
from typing import List

from src.dto.assignment_item import AssignmentItem
from src.dto.background_item import BackgroundItem
from src.dto.condition_item import ConditionItem
from src.dto.dialog_item import DialogItem
from src.dto.menu_item import MenuItem
from src.dto.music_item import MusicItem, MusicAction, MusicEffect
from src.dto.return_item import ReturnItem
from src.dto.run_label_item import RunLabelItem
from src.dto.show_item import ShowEvent, ShowItem
from src.scenario.scenario_script_stack import ScenarioScriptStack
from src.scenario.sequence_group import SequenceGroup, SequenceGroupType
from src.utils import sanitize_function_name


class ScenarioReader:
    def __init__(self, scenario_file):
        self.scenario_file = scenario_file
        self.scenario: List[SequenceGroup] = []
        self.stack: ScenarioScriptStack = ScenarioScriptStack()

    def read(self) -> List[SequenceGroup]:
        with open(self.scenario_file, 'r', encoding="utf-8") as f:
            lines = f.readlines()

        line_pack = []
        for line in lines:
            if line.strip():
                current_indent = (len(line) - len(line.lstrip())) // 4
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
            result = f"{label.name}__{md5.hexdigest()[:8]}"
        else:
            result = md5.hexdigest()[:8]

        i = 0
        while result in label.translation_identifiers:
            i += 1
            result = f"{result}_{i}"

        label.translation_identifiers.append(result)
        return result

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
        has_conditional_operator = next_line.startswith("if ") or next_line.startswith("elif ") or next_line.startswith(
            "else:")
        if has_conditional_operator:
            print(f"Has conditional operator: {next_line}")
        while self.stack.size() > 0 and self.stack.current_indent() >= current_indent and not has_conditional_operator:
            stack_type = self.stack.current().type
            if stack_type == SequenceGroupType.CONDITION:
                self.close_conditions(current_indent, next_line)
            elif stack_type == SequenceGroupType.MENU:
                self.close_menus(current_indent)
            elif stack_type == SequenceGroupType.LABEL:
                self.close_labels(current_indent)
            else:
                raise Exception(f"Unknown stack type: {stack_type}")

    def process_line_pack(self, line_pack):
        with_clause = None
        for line, current_indent in line_pack:
           self.process_line(line, current_indent)
        line_pack.clear()

    def process_line(self, line, current_indent):
        stripped_line = line.strip()

        if stripped_line.startswith("#"):
            return

        self.pop_stack_if_unindented(current_indent, stripped_line)

        if stripped_line.startswith("label "):
            label_name = stripped_line.split("label ", 1)[1].strip(":")
            name = sanitize_function_name(label_name)

            if self.stack.size() > 0:
                name = f"{self.stack.current_label().name}__{name}"
                self.stack.current().add_sequence_item(RunLabelItem(name, True))
            else:
                name = f"scene__{name}"

            print("Label: ", name)

            self.stack.push(SequenceGroup(name, SequenceGroupType.LABEL, True), current_indent)
        elif stripped_line == "return":
            self.stack.current().add_sequence_item(ReturnItem())
        elif stripped_line.startswith("if "):
            condition = stripped_line.split("if ", 1)[1].strip(":")
            if self.stack:
                name = f"{self.stack.current().name}__condition_{sum(1 for item in self.stack.current().sequence if isinstance(item, ConditionItem))}"
            else:
                raise Exception("Condition block outside of label stack")

            self.stack.current().add_sequence_item(ConditionItem(name))

            condition_stack = SequenceGroup(name, SequenceGroupType.CONDITION)
            condition_stack.add_condition(condition)
            self.stack.push(condition_stack, current_indent)

        elif stripped_line.startswith("elif "):
            condition = stripped_line.split("elif ", 1)[1].strip(":")
            if self.stack.current().type != SequenceGroupType.CONDITION:
                raise Exception("Elif block outside of condition block")
            self.stack.current().add_condition(condition)

        elif stripped_line.startswith("else:"):
            if self.stack.current().type != SequenceGroupType.CONDITION:
                raise Exception("Else block outside of condition block")
            self.stack.current().add_condition()

        elif stripped_line.startswith("menu:"):
            if self.stack:
                name = f"{self.stack.current().name}__menu_question_{sum(1 for item in self.stack.current().sequence if isinstance(item, MenuItem))}"
            else:
                raise Exception("Menu block outside of label stack")

            self.stack.current().add_sequence_item(MenuItem(name))
            self.stack.push(SequenceGroup(name, SequenceGroupType.MENU), current_indent)
        elif self.stack.current().type == SequenceGroupType.MENU and stripped_line.startswith("\""):
            # Parse menu choice
            match = re.match(r"\"(.*)\":", stripped_line)
            if match:
                choice_text = match.group(1)
                self.stack.current().add_condition(choice_text, f"{self.stack.current().name}_{sanitize_function_name(choice_text)}")
                # self.stack.push(SequenceGroup(f"{self.stack.current().name}_{sanitize_function_name(choice_text)}", SequenceGroupType.MENU), current_indent)

        elif stripped_line.startswith("$ "):
            # Inline assignments in menu blocks
            command = stripped_line[2:].strip()
            self.stack.current().add_sequence_item(AssignmentItem(command))

        elif stripped_line.startswith("call "):
            skip = False
            if "act_op(" in stripped_line or "call screen " in stripped_line:
                skip = True
            if not skip:
                # Inline calls in menu blocks
                function_name = stripped_line.split("call ", 1)[1].strip()
                self.stack.current().add_sequence_item(RunLabelItem(sanitize_function_name(function_name)))

        elif stripped_line.startswith("scene bg"):
            parts = stripped_line.split()
            scene_bg_name = parts[2]
            self.stack.current().add_sequence_item(BackgroundItem(scene_bg_name))

        elif stripped_line.startswith("scene ev"):
            parts = stripped_line.split()
            event_bg_name = parts[2]
            print(event_bg_name)
            # REMOVES TEMP
            # TODO: use specs
            event_bg_name = event_bg_name.replace("_start", "").replace("_move", "").replace("_end", "")
            self.stack.current().add_sequence_item(BackgroundItem(event_bg_name))

        elif stripped_line.startswith("play music"):
            parts = stripped_line.split()
            music_name = parts[2]
            fadein_match = re.search(r"fadein (\d+\.\d+)", stripped_line)
            fadein_time = float(fadein_match.group(1)) if fadein_match else 0
            self.stack.current().add_sequence_item(
                MusicItem(MusicAction.PLAY, music_name, MusicEffect.FADEIN if fadein_match else MusicEffect.NONE,
                          fadein_time))

        elif stripped_line.startswith("stop music"):
            fadeout_match = re.search(r"fadeout (\d+\.\d+)", stripped_line)
            fadeout_time = float(fadeout_match.group(1)) if fadeout_match else 0
            self.stack.current().add_sequence_item(
                MusicItem(MusicAction.STOP, "", MusicEffect.FADEOUT if fadeout_match else MusicEffect.NONE,
                          fadeout_time))

        elif stripped_line.startswith("show "):
            parts = stripped_line.split()
            sprite_name = parts[1]

            event_type = ShowEvent.CHARACTER_CHANGE if "with charachange" in stripped_line else ShowEvent.NONE
            self.stack.current().add_sequence_item(ShowItem(sprite_name, event_type))

        else:
            dialog_match_str = re.match(r"\"(\w+)\"\s+\"(.*)\"", stripped_line)
            dialog_match_ref = re.match(r"(\w+)\s+\"(.*)\"", stripped_line)
            narration_match = re.match(r"\"(.*)\"", stripped_line)
            if dialog_match_str:
                actor, dialog = dialog_match_str.groups()
                self.stack.current().add_sequence_item(
                    DialogItem(self.calculate_tl_hash(stripped_line), actor, dialog.strip()))
            elif dialog_match_ref:
                actor, dialog = dialog_match_ref.groups()
                self.stack.current().add_sequence_item(
                    DialogItem(self.calculate_tl_hash(stripped_line), "", dialog.strip(), actor))
            elif narration_match:
                narration = narration_match.group(1)
                self.stack.current().add_sequence_item(
                    DialogItem(self.calculate_tl_hash(stripped_line), "", narration.strip()))