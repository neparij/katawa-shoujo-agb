import os
from tokenize import group
from typing import List, cast

from src.dto.assignment_item import AssignmentItem
from src.dto.background_item import BackgroundItem
from src.dto.condition_item import ConditionItem
from src.dto.dialog_item import DialogItem
from src.dto.menu_item import MenuItem
from src.dto.music_item import MusicItem, MusicAction
from src.dto.return_item import ReturnItem
from src.dto.run_label_item import RunLabelItem
from src.dto.sequence_item import SequenceItem, SequenceType
from src.dto.show_item import ShowItem, ShowEvent
from src.scenario.sequence_group import SequenceGroup, SequenceGroupType, ConditionWrapper
from src.utils import sanitize_function_name


class ScenarioWriter:
    def __init__(self, filename: str, output_dir: str, scenario: List[SequenceGroup]):
        self.filename = filename
        self.output_dir = output_dir
        self.scenario = scenario

        # TODO: refactor this
        self.unprocessed_music = [
            "music_another",
            "music_comedy",
            "music_daily",
            "music_emi",
            "music_kenji",
            "music_nurse",
            "music_pearly",
            "music_rain",
            "music_running",
            "music_serene",
            "music_soothing",
            "music_tension"
        ]

        self.backgrounds = []
        self.events = []
        self.music = []
        self.sprites = []

    def write(self):
        os.makedirs(os.path.dirname(os.path.join(self.output_dir, self.filename)), exist_ok=True)
        self.write_source()
        self.write_header()

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
            include_header("bn_music_items")
        ]

        for background in self.backgrounds:
            h_code.append(include_header(background, "bn_regular_bg_items_"))

        function_declarations = []

        function_declarations.append(comment("Labels"))
        for label in self.get_labels():
            function_declarations.append(f"{label_signature(label)};")

        function_declarations.append(comment("Choice functions"))
        for menu in self.get_menus():
            function_declarations.append(f"{menu_signature(menu)};")
            for answer in menu.conditions:
                function_declarations.append(f"{answer_signature(menu, answer)};")

        function_declarations.append(comment("Conditions"))
        for condition in self.get_conditions():
            cnum = 0
            for variant in condition.conditions:
                function_declarations.append(f"{condition_signature(condition, cnum)};")
                cnum += 1

        h_code.append(namespace("\n".join(function_declarations), "ks"))

        with open(f"{os.path.join(self.output_dir, self.filename)}.h", "w") as h_file:
            h_file.write(defined("\n".join(h_code), define_name, "KS"))

    def write_source(self):
        cpp_code = [
            include_header(f"{self.filename}"),
        ]
        functions = []

        for label in self.get_labels():
            sequences = []
            if label.is_called_inline and not label.is_initial:
                sequences.append(comment("POTENTIAL MEMLEAK!!!! better to provide it globally."))
                sequences.append("bn::optional<bn::regular_bg_ptr> main_bg;")
                sequences.append("ks::SceneManager scene(main_bg);\n")
            for sequence in label.sequence:
                sequences.extend(self.process_sequence(label, sequence))
            if label.is_called_inline and not label.is_initial:
                sequences.append("scene.start();\n")
                sequences.extend([
                    "while(!scene.is_finished()) {",
                    "    scene.update();",
                    "    bn::core::update();",
                    "}"
                ])
            functions.append(f"{label_signature(label)} {{\n{indented_l(sequences)}\n}}")

        for menu in self.get_menus():
            sequences = []
            for sequence in menu.sequence:
                sequences.extend(self.process_sequence(menu, sequence))
            sequences.append(f'// bn::vector<ks::AnswerItem, {len(menu.conditions)}> answers;')
            for answer in menu.conditions:
                sequences.append(
                    f'// answers.push_back(ks::AnswerItem("{answer.condition}", &{answer.function_callback}));')
            sequences.append(f'// scene.add_sequence(ks::MenuItem(answers);')
            functions.append(f"{menu_signature(menu)} {{\n{indented_l(sequences)}\n}}")

            for answer in menu.conditions:
                sequences = []
                for seq in answer.sequence:
                    sequences.extend(self.process_sequence(menu, seq))
                functions.append(f"{answer_signature(menu, answer)} {{\n{indented_l(sequences)}\n}}")

        for condition in self.get_conditions():
            cnum = 0
            for variant in condition.conditions:
                sequences = []
                for seq in variant.sequence:
                    sequences.extend(self.process_sequence(condition, seq))
                functions.append(f"{condition_signature(condition, cnum)} {{\n{indented_l(sequences)}\n}}")
                cnum += 1

        cpp_code.append(namespace("\n".join(functions), "ks"))

        with open(f"{os.path.join(self.output_dir, self.filename)}.cpp", "w") as cpp_file:
            cpp_file.write("\n".join(cpp_code))

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
        return []

    def process_sequence_assignment(self, group: SequenceGroup, assignment: AssignmentItem) -> List[str]:
        return [f'// scene.add_sequence(ks::AssignmentItem("{assignment.content}"));']

    def process_sequence_background(self, group: SequenceGroup, bg: BackgroundItem) -> List[str]:
        if not bg.background in self.backgrounds:
            self.backgrounds.append(bg.background)
        return [f'scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::{bg.background}));']

    def process_sequence_condition(self, group: SequenceGroup, condition: ConditionItem) -> List[str]:
        matching_scenario_item = next((item for item in self.scenario if item.name == condition.function_callback),
                                      None)
        code = [
            f'// bn::vector<ks::ConditionItem, {len(matching_scenario_item.conditions)}> {condition.function_callback};']
        cnum = 0
        for variant in matching_scenario_item.conditions:
            code.append(
                f'// {condition.function_callback}.push_back(ks::ConditionItem(\"{variant.condition}\", &{condition.function_callback}_{cnum}));')
            cnum += 1
        code.append(f'// scene.add_condition({condition.function_callback});')
        return code

    def precess_sequence_dialogue(self, group: SequenceGroup, dialog: DialogItem) -> List[str]:
        if dialog.actor_ref:
            return [f'scene.add_sequence(ks::DialogItem("{dialog.actor_ref}", \"{dialog.message}\"));']
        elif dialog.actor:
            return [f'scene.add_sequence(ks::DialogItem("{dialog.actor}", \"{dialog.message}\"));']
        else:
            return [f'scene.add_sequence(ks::DialogItem("", \"{dialog.message}\"));']

    def process_sequence_menu(self, group: SequenceGroup, menu: MenuItem) -> List[str]:
        return [f'scene.add_sequence(ks::RunLabelItem(&{menu.function_callback}));']

    def process_sequence_music(self, group: SequenceGroup, music: MusicItem) -> List[str]:
        if music.action == MusicAction.PLAY:
            if music.music and not music.music in self.music and music.music not in self.unprocessed_music:
                self.music.append(music.music)
            if music.music in self.unprocessed_music:
                return [f'scene.add_sequence(ks::MusicNotFoundItem());']
            return [f'scene.add_sequence(ks::MusicItem(bn::music_items::{music.music}));']
        elif music.action == MusicAction.STOP:
            return [f'scene.add_sequence(ks::MusicStopItem());']
        return []

    def process_sequence_return(self, group, ret: ReturnItem) -> List[str]:
        if group.is_called_inline:
            return []
        return [f'return;']

    def process_sequence_run_label(self, group: SequenceGroup, run_label: RunLabelItem) -> List[str]:
        if run_label.inline_call:
            return [
                f'{run_label.function_callback}();',
                'bn::core::update();'
            ]
        else:
            return [f'scene.add_sequence(ks::RunLabelItem(&{run_label.function_callback}));']

    def process_sequence_show(self, group: SequenceGroup, show: ShowItem) -> List[str]:
        if not show.sprite in self.sprites:
            self.sprites.append(show.sprite)
        if show.event == ShowEvent.CHARACTER_CHANGE:
            return [
                f'// scene.add_sequence(ks::SpriteItem(bn::sprite_items::{show.sprite}, ks::SpriteEventType::CharacterChange));']
        elif show.event == ShowEvent.NONE:
            return [
                f'// scene.add_sequence(ks::SpriteItem(bn::sprite_items::{show.sprite}, ks::SpriteEventType::None));']
        else:
            raise TypeError("Unknown ShowEvent type")


def defined(code, define_name, prefix="", suffix=""):
    define_name = f"{f"{prefix}_" if prefix else ""}{define_name}{f"_{suffix}" if suffix else ""}"
    return f"#ifndef {define_name}\n#define {define_name}\n\n{code}\n\n#endif // {define_name}"


def namespace(code, name=""):
    return f"namespace {name} {{\n{indented(code)}\n}}"


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
        return f"void {group.name}(ks::SceneManager& scene)"


def menu_signature(group: SequenceGroup):
    return f"void {group.name}(ks::SceneManager& scene)"


def answer_signature(group: SequenceGroup, answer: ConditionWrapper):
    return f"void {group.name}_{sanitize_function_name(answer.condition)}(ks::SceneManager& scene)"


def condition_signature(group: SequenceGroup, num: int):
    return f"void {group.name}_{num}(ks::SceneManager& scene)"
