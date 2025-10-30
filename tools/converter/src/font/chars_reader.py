import os.path
import subprocess
from typing import List

from src.utils import collect_scenario_sentences, sanitize_ingame_text


class CharsReader:
    def __init__(self, ksagb_path: str, gbfs_path: str, translation_keys: List[str], definitions_masks: List[str]):
        self.ksagb_path = ksagb_path
        self.gbfs_path = os.path.join(ksagb_path, gbfs_path)
        self.translation_keys = translation_keys
        self.definitions_masks = definitions_masks
        self.common = [' ', '!', '"', '#', '$', '%', '&', "'", '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~']
        self.additional = []

    def add_char(self, char: str):
        # if len(char.strip()) == 0:
        if char == " " or char == "\n" or char == "\r" or char == "\t":
            return
        if char not in self.common and char not in self.additional:
            self.additional.append(char)

    def sort_char_tables(self):
        self.common = sorted(self.common, key=lambda c: ord(c))
        self.additional = sorted(self.additional, key=lambda c: ord(c))

    def get_common(self) -> List[str]:
        return self.common

    def get_additional(self) -> List[str]:
        return self.additional

    def read_definitions(self):
        for mask in self.definitions_masks:
            for tl_key in self.translation_keys:
                filename = os.path.join(self.ksagb_path, mask.format(tl_key))
                text = subprocess.check_output(
                    [os.environ['DEVKITARM'] + '/bin/arm-none-eabi-cpp', '-fpreprocessed', filename]).decode('utf-8')
                for char in text:
                    self.add_char(char)

        self.sort_char_tables()

    def read_scenario(self, scenario, locale):
        text_entries: List[str] = []
        collect_scenario_sentences(scenario, locale, text_entries)
        for entry in text_entries:
            for char in sanitize_ingame_text(entry):
                self.add_char(char)
