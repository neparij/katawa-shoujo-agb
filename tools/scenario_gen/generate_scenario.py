import re
import os

def parse_renpy_to_cpp(input_file, output_file):
    with open(input_file, "r", encoding="utf-8") as infile:
        lines = infile.readlines()

    cpp_code = []
    scenario = []  # Main scenario code
    menu_callbacks = []  # Store menu callback functions to append later
    label_callbacks = []
    condition_callbacks = []
    callback_signatures = []
    condition_signatures = []
    condition_stack = []  # Stack to manage nested conditions
    menu_stack = []  # Stack to manage nested menu blocks
    label_stack = []  # Stack for nested function handling
    callable_labels = []
    line_pack = []
    current_function = None
    previous_indent = 0
    question_index = 0
    condition_index = 0
    current_label_id = 0

    # Imports:
    import_backgrounds = []
    import_events = []
    import_sequences = [
        '#include "sequence/assignmentitem.h"',
        '#include "sequence/backgrounditem.h"',
        '#include "sequence/dialogitem.h"',
        '#include "sequence/menuitem.h"',
        '#include "sequence/musicitem.h"',
        '#include "sequence/runlabelfinishitem.h"',
        '#include "sequence/runlabelitem.h"',
        '#include "sequence/spriteitem.h"',
    ]
    import_stuff = [
        '#include "bn_music_items.h"',
        '#include "scenemanager.h"',
    ]

    def add_line(line, indent_level):
        """Adds a line with proper indentation."""
        if menu_stack:
            menu_stack[-1]["body"].append("    " * (indent_level - menu_stack[-1]["indent"]) + line)
        elif condition_stack:
            condition_stack[-1]["conditions"][-1]["body"].append("    " * (indent_level - condition_stack[-1]["indent"]) + line)
        elif label_stack:
            label_stack[-1]["body"].append("    " * (indent_level - label_stack[-1]["indent"]) + line)
        else:
            scenario.append("    " * indent_level + line)
            print(f"Error: Label stack is empty. Skip the scenario code: [{line}]")

    def close_conditions(current_indent, next_line):
        """Closes conditions until reaching the target indentation."""
        has_conditional_operator = next_line.startswith("if ") or next_line.startswith("elif ") or next_line.startswith("else:")
        while condition_stack and condition_stack[-1]["indent"] >= current_indent and not has_conditional_operator:
            # print(f"Close condition by line: [{next_line}]")
            condition = condition_stack.pop()
            add_line(f"// bn::vector<ks::ConditionItem, 2> {condition["function"]};", current_indent + 1)
            cnum = 0
            for condition_item in condition["conditions"]:
                add_line(f"// {condition["function"]}.push_back(ks::ConditionItem(\"{condition_item["condition"]}\", &{condition["function"]}_{cnum}));", current_indent + 1)
                cnum += 1
            add_line(f"// scene.add_condition({condition["function"]});", current_indent + 1)
            generate_condition_callback(condition["function"], condition["conditions"])
            # add_line(f"scene.add_condition")
            # add_line("}", condition_stack.pop()["indent"])

    def close_menus(current_indent):
        """Closes menu blocks until reaching the target indentation."""
        while menu_stack and menu_stack[-1]["indent"] >= current_indent:
            menu = menu_stack.pop()
            generate_menu_callback(menu["function"], menu["body"], menu["answers_count"])

    def close_labels(current_indent):
        """Closes label blocks until reaching the target indentation."""
        nonlocal current_label_id
        while label_stack and label_stack[-1]["indent"] >= current_indent:
            label = label_stack.pop()
            # current_label_id += 1
            # print("Close label - pop from stack")
            generate_label_callback(label["function"], label["body"], label["id"])

    def generate_menu_callback(menu_name, menu_body, menu_answers_count):
        """Generates a callback function for a menu question."""
        signature = f"void {menu_name}(ks::SceneManager& scene)"
        callback_signatures.append(f"{signature};")
        callback_function = [f"{signature} {{"] + menu_body + ["    return;", "}"]
        if (menu_answers_count > 0):
            answers_vector = f"    // bn::vector<ks::AnswerItem, {menu_answers_count}> answers;"
            choices_item = "    // scene.add_sequence(ks::ChoicesItem(answers, ks::ChoicesEventType::MenuEffect));"
            callback_function = [f"{signature} {{", answers_vector] + menu_body + [choices_item, "    return;", "}"]
        menu_callbacks.extend(callback_function)

    def generate_condition_callback(condition_name, conditions):
        num = 0
        for condition in conditions:
            signature = f"void {condition_name}_{num}(ks::SceneManager& scene)"
            condition_signatures.append(f"{signature};")
            callback_function = [f"{signature} {{"] + condition["body"] + [ "}" ]
            condition_callbacks.extend(callback_function)
            num += 1

    def generate_label_callback(label_name, label_body, label_id):
        """Generates a callback function for a label."""
        signature = f"void {label_name}()"
        if label_name in callable_labels:
            signature = f"void {label_name}(ks::SceneManager& scene)"

        callback_signatures.append(f"{signature};")

        scene_init = [
        	f"    bn::optional<bn::regular_bg_ptr> main_bg;",
        	f"    ks::SceneManager scene(main_bg);",
        	f"",
        ] if label_name not in callable_labels and label_id > 0 else []

        scene_handle = [
            f"    scene.start();",
        	f"",
            f"    while (!scene.is_finished()) {{",
            f"        scene.update();",
            f"        bn::core::update();",
            f"    }}",
        ] if label_name not in callable_labels and label_id > 0 else []

        callback_function = [f"{signature} {{"] + scene_init + label_body + scene_handle + ["}"]
        label_callbacks.extend(callback_function)

    def sanitize_function_name(text):
        """Sanitizes text for valid C++ function names."""
        return re.sub(r"[^a-zA-Z0-9_]", "", text.replace(" ", "_").lower())

    def process_line(line, current_indent):
        nonlocal previous_indent, current_function, question_index, condition_index, current_label_id
        stripped_line = line.strip()

        # Close conditions, menus, and labels if indentation decreases
        close_conditions(current_indent, stripped_line)
        close_menus(current_indent)
        close_labels(current_indent)

        if stripped_line.startswith("label "):
            # Handle nested labels like menu processing
            label_name = stripped_line.split("label ", 1)[1].strip(":")
            function_name = sanitize_function_name(label_name)

            # Nest the function if it's a child label
            if label_stack:
                function_name = f"{label_stack[-1]['function']}__{function_name}"
                # add_line(f"scene.add_sequence(ks::RunLabelItem(&{function_name}));", current_indent)
                add_line(f"{function_name}();", current_indent)
                add_line("bn::core::update();", current_indent)
            else:
                function_name = f"scene__{function_name}"

            label_stack.append({
            	"id": current_label_id,
                "indent": current_indent,
                "function": function_name, 
                "body": []
            })
            # print("Label stack append")
            current_function = function_name
            current_label_id += 1
        elif stripped_line == "return":
            # add_line("return;", current_indent)
            if label_stack and label_stack[-1]["id"] != 0:
                # print("")
                # print(f"Current label ID: {current_label_id}")
                # print(f"Last label stack ID: {label_stack[-1]["id"]}")
                # print(f"Label stack size: {len(label_stack)}")
                # add_line("scene.finish();", current_indent)
                add_line("return;", current_indent)
        elif stripped_line.startswith("if "):
            # print(stripped_line)
            condition = stripped_line.split("if ", 1)[1].strip(":")
            condition.replace("and", "&&")
            condition.replace("or", "||")
            condition_stack.append({
                "indent": current_indent,
                "function": f"{current_function}__condition_{condition_index}",
                "conditions": [
                    {
                        "condition": condition,
                        "body": []
                    }
                ]
            })
            condition_index += 1
        elif stripped_line.startswith("elif "):
            # print(stripped_line)
            condition = stripped_line.split("elif ", 1)[1].strip(":")
            condition.replace("and", "&&")
            condition.replace("or", "||")
            condition_stack[-1]["conditions"].append({
                "condition": condition,
                "body": []
            })
        elif stripped_line.startswith("else:"):
            # add_line("else {", current_indent)
            # print(stripped_line)
            condition_stack[-1]["conditions"].append({
                "condition": None,
                "body": []
            })
        elif stripped_line.startswith("menu:"):
            question_function = f"{current_function}__menu_question_{question_index}"
            question_index += 1
            add_line(f"scene.add_sequence(ks::MenuItem(&{question_function}));", current_indent)
            menu_stack.append({
                "indent": current_indent,
                "function": question_function,
                "body": [],
                "answers_count": 0
            })
        elif menu_stack and stripped_line.startswith("\""):
            # Parse menu choice
            match = re.match(r"\"(.*)\":", stripped_line)
            if match:
                choice_text = match.group(1)
                choice_function = f"{menu_stack[-1]['function']}__{sanitize_function_name(choice_text)}"
                menu_stack[-1]['answers_count'] += 1
                add_line(f'// answers.push_back(ks::AnswerItem("{choice_text}", &{choice_function}));', current_indent)
                menu_stack.append({
                    "indent": current_indent,
                    "function": choice_function,
                    "body": [],
                    "answers_count": 0
                })
        elif stripped_line.startswith("$ "):
            # Inline assignments in menu blocks
            command = stripped_line[2:].strip()
            add_line(f'// scene.add_sequence(ks::AssignmentItem("{command}"));', current_indent)
        elif stripped_line.startswith("call "):
            skip = False
            if "act_op(" in stripped_line or "call screen " in stripped_line:
                skip = True
            if not skip:
                # Inline calls in menu blocks
                function_name = stripped_line.split("call ", 1)[1].strip()
                callable_labels.append(f"scene__{sanitize_function_name(function_name)}")
                add_line(f'scene.add_sequence(ks::RunLabelItem(&scene__{sanitize_function_name(function_name)}));', current_indent)
                # add_line(f'scene.add_sequence(ks::CallFunctionItem(scene_{sanitize_function_name(function_name)}));', current_indent)
        elif stripped_line.startswith("scene bg"):  
            parts = stripped_line.split()
            scene_bg_name = parts[2]
            import_statement = f'#include "bn_regular_bg_items_{scene_bg_name}.h"'
            if import_statement not in import_backgrounds:
            	import_backgrounds.append(import_statement)
            add_line(f'scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::{scene_bg_name}));', current_indent)
        elif stripped_line.startswith("scene ev"):  
            parts = stripped_line.split()
            event_bg_name = parts[2]
            print(event_bg_name)
            # REMOVES TEMP
            # TODO: use specs
            event_bg_name = event_bg_name.replace("_start", "").replace("_move", "").replace("_end", "")
            import_statement = f'#include "bn_regular_bg_items_{event_bg_name}.h"'
            if import_statement not in import_events:
            	import_events.append(import_statement)
            add_line(f'scene.add_sequence(ks::BackgroundItem(bn::regular_bg_items::{event_bg_name}));', current_indent)
        elif stripped_line.startswith("play music"):
            parts = stripped_line.split()
            music_name = parts[2]
            fadein_match = re.search(r"fadein (\d+\.\d+)", stripped_line)
            fadein_time = fadein_match.group(1) if fadein_match else "0"
            add_line(f'scene.add_sequence(ks::MusicItem(bn::music_items::{music_name}, {fadein_time}));', current_indent)
        elif stripped_line.startswith("stop music"):
            fadeout_match = re.search(r"fadeout (\d+\.\d+)", stripped_line)
            if fadeout_match:
                fadeout_time = fadeout_match.group(1)
                add_line(f'scene.add_sequence(ks::MusicStopItem("fadeout", {fadeout_time}));', current_indent)
            else:
                add_line("scene.add_sequence(ks::MusicStopItem());", current_indent)
        elif stripped_line.startswith("show "):
            parts = stripped_line.split()
            sprite_name = parts[1]

            event_type = "CharaChange" if "with charachange" in stripped_line else "Show"
            add_line(f'// scene.add_sequence(ks::SpriteItem(bn::sprite_items::{sprite_name}, ks::SpriteEventType::{event_type}));', current_indent)
        else:
            dialog_match_str = re.match(r"\"(\w+)\"\s+\"(.*)\"", stripped_line)
            dialog_match_ref = re.match(r"(\w+)\s+\"(.*)\"", stripped_line)
            narration_match = re.match(r"\"(.*)\"", stripped_line)
            if dialog_match_str:
                actor, dialog = dialog_match_str.groups()
                add_line(f'scene.add_sequence(ks::DialogItem("{actor}", "{dialog.strip()}"));', current_indent)
            elif dialog_match_ref:
                actor, dialog = dialog_match_ref.groups()
                add_line(f'scene.add_sequence(ks::DialogItem("{actor}", "{dialog.strip()}"));', current_indent)
            elif narration_match:
                narration = narration_match.group(1)
                add_line(f'scene.add_sequence(ks::DialogItem("", "{narration.strip()}"));', current_indent)

    def process_line_pack(line_pack):
        # print(f'Processing pack of {line_pack} lines')
        with_clause = None
        for line, current_indent in line_pack:
            process_line(line, current_indent)
        line_pack.clear()

    for line in lines:
        if line.strip():
            current_indent = (len(line) - len(line.lstrip())) // 4
            line_pack.append((line, current_indent))
        else:
            process_line_pack(line_pack)

    if line_pack:
        process_line_pack(line_pack)

    # Close any remaining open conditions or menus
    close_conditions(0, "")
    close_menus(0)
    close_labels(0)

    # # Close the last function
    # if current_function:
    #     add_line("}", 0)

    script_out = []
    script_out += ["// Signatures"] + callback_signatures + [""]
    script_out += ["// Scenario - NOT USED"] + scenario + [""]

    # Prepend declarations, append callbacks
    # scenario = import_backgrounds + [""] + import_events + [""] + callback_signatures + scenario
    script_out += ["// Labels"] + label_callbacks + [""]
    script_out += ["// Menu"] + menu_callbacks + [""]
    script_out += ["// Conditions"] + condition_callbacks + [""]

    define_name = output_file.split(".")[0].upper().replace("-", "_")
    output = []
    output += [f"#ifndef KS_{define_name}"] + [f"#define KS_{define_name}"] + [""]
    output += import_sequences + import_stuff
    output += ["// Backgrounds"] + import_backgrounds + [""]
    output += ["// Events"] + import_events + [""]
    output += ["namespace"] + ["{"]
    for line in script_out:
        output += [f"    {line}"]
    output += ["}", "", f"#endif // KS_{define_name}", ""]

    with open(output_file, "w", encoding="utf-8") as outfile:
        outfile.write("\n".join(output))

# Usage
input_file = "/Users/n.laptev/development/ksre/game/script-a1-tuesday.rpy"
output_file = os.path.basename(input_file).split('.')[0] + ".cpp"
print(output_file)

parse_renpy_to_cpp(input_file, output_file)
