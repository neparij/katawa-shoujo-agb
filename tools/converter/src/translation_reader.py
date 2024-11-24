import re
from enum import Enum
from typing import List

from src.translation.translation_container import TranslationContainer


class TranslationReaderMode(Enum):
    KEY = "key"
    STRINGS = "strings"
    NONE = "none"

class TranslationReader:
    def __init__(self, language, translation_file):
        self.translation_file = translation_file
        self.current_indent = 0
        self.current_mode = TranslationReaderMode.NONE
        self.language = language
        self.pack: TranslationContainer = TranslationContainer(language)
        self._key = None

    def read(self) -> TranslationContainer:
        with open(self.translation_file, 'r', encoding="utf-8-sig") as f:
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
        return self.pack

    def process_line_pack(self, line_pack):
        for line, current_indent in line_pack:
            self.process_line(line, current_indent)
        line_pack.clear()

    def process_line(self, line, current_indent):
        stripped_line = line.strip()

        if stripped_line.startswith("#"):
            return

        if stripped_line == "nvl clear":
            return

        if current_indent == 0:
            self.current_mode = TranslationReaderMode.NONE

        if self.current_mode == TranslationReaderMode.NONE:
            match = re.match(r"translate (\S+) ([^\s:]+):", stripped_line)
            if match:
                language = match.group(1)
                if language != self.language:
                    raise Exception(f"Language mismatch: {language} != {self.language}")
                self._key = match.group(2)
                if self._key == "strings":
                    self.current_mode = TranslationReaderMode.STRINGS
                else:
                    self.current_mode = TranslationReaderMode.KEY
            else:
                raise Exception(f"Invalid line: {stripped_line}")
        elif self.current_mode == TranslationReaderMode.KEY:
            if not self._key:
                raise Exception("Key is not set")
            self.pack.translations[self._key] = stripped_line
            self._key = None
        elif self.current_mode == TranslationReaderMode.STRINGS:
            old_match = re.match(r"old \"(.*)\"", stripped_line)
            new_match = re.match(r"new \"(.*)\"", stripped_line)
            if old_match:
                self._key = old_match.group(1)
            elif new_match:
                self.pack.strings[self._key] = new_match.group(1)
                self._key = None
            else:
                raise Exception(f"Invalid line: {stripped_line}")
