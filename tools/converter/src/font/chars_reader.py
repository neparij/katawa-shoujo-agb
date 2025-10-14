import os.path
import subprocess
from typing import List

from src.lz77_decompress import gba_lz77_decompress
from src.utils import remove_bytecode_functions


class CharsReader:
    def __init__(self, ksagb_path: str, gbfs_path: str, translation_keys: List[str], definitions_masks: List[str]):
        self.ksagb_path = ksagb_path
        self.gbfs_path = os.path.join(ksagb_path, gbfs_path)
        self.translation_keys = translation_keys
        self.definitions_masks = definitions_masks
        self.common = [' ', '!', '"', '#', '$', '%', '&', "'", '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~']
        self.additional = []

    def add_char(self, char: str):
        if len(char.strip()) == 0:
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

    def read_tl_files(self):
        for tl_key in self.translation_keys:
            for filename in os.listdir(self.gbfs_path):
                if filename.startswith("tl_") and filename.endswith(f".{tl_key}"):
                    tl_file_path = os.path.join(self.gbfs_path, filename)
                    with open(tl_file_path, 'rb') as f:
                        translation_file_lz77 = f.read()

                    translation_file = gba_lz77_decompress(translation_file_lz77)
                    offset_table_size = int.from_bytes(translation_file[0:2], byteorder='little')
                    text_entries = translation_file[2 + offset_table_size * 2:].split(b'\x00')
                    for entry in text_entries:
                        entry_without_commands = remove_bytecode_functions(entry)
                        entry_text = entry_without_commands.decode('utf-8')
                        for char in entry_text:
                            self.add_char(char)
