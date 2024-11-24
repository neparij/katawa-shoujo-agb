from typing import List, Dict


class TranslationContainer:
    def __init__(self, language):
        self.language = language
        self.translations: Dict[str, str] = {}
        self.strings: Dict[str, str] = {}

    def add_translation(self, key, translation):
        if key in self.translations:
            raise Exception(f"Key {key} already exists in translations")
        self.translations[key] = translation

    def add_string(self, key, translation):
        if key in self.strings:
            raise Exception(f"Key {key} already exists in strings")
        self.strings[key] = translation
