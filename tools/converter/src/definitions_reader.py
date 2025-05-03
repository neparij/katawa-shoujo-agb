import ast
import re
from typing import List, Dict

from src.dto.definitions import RouteDefinition, ActDefinition, LabelDefinition
from src.translation.translation_container import TranslationContainer


class DefinitionsReader:
    def __init__(self, definitions_file, translation: TranslationContainer):
        self.definitions_file = definitions_file
        self.translation = translation

    @staticmethod
    def sanitize_block(block: str) -> str:
        # Replace Ren'Py-style _() with Python-compatible quotes for AST
        return re.sub(r'_\("([^"]+)"\)', r'"_\1"', block)

    def extract_replays_block(self):
        with open(self.definitions_file, 'r', encoding="utf-8") as f:
            text = f.read()
        pattern = r'define\s+replays\s*=\s*(\[[\s\S]*?\])\s*\n\s*define'
        match = re.search(pattern, text)
        if not match:
            raise ValueError("Could not find replays block.")
        sanitized = self.sanitize_block(match.group(1))
        return ast.literal_eval(sanitized)

    def parse_routes_structure(self, replays_ast) -> List[RouteDefinition]:
        replays = []
        for route_entry in replays_ast:
            route_name = route_entry[0][1:]  # Remove leading underscore
            if self.translation and route_name in self.translation.strings:
                route_name = self.translation.strings[route_name]
            acts = []
            for act_entry in route_entry[1]:
                act_name = act_entry[0][1:]  # Remove leading underscore
                if self.translation and act_name in self.translation.strings:
                    act_name = self.translation.strings[act_name]
                labels = []
                for label in act_entry[1]:
                    label_name = label[0][1:]  # Remove leading underscore
                    label_id = label[1]
                    description = label[2][1:]  # Remove leading underscore
                    if self.translation and label_name in self.translation.strings:
                        label_name = self.translation.strings[label_name]
                    if self.translation and description in self.translation.strings:
                        description = self.translation.strings[description]
                    labels.append(LabelDefinition(label_name, label_id, description))
                acts.append(ActDefinition(act_name, labels))
            replays.append(RouteDefinition(route_name, acts))
        return replays
