import argparse
import os
import re
from typing import List, Dict, cast

from src.definitions_reader import DefinitionsReader
from src.definitions_writer import DefinitionsWriter
from src.font.chars_reader import CharsReader
from src.fonts_writer import FontsWriter
from src.scenario_reader import ScenarioReader
from src.scenario_writer import ScenarioWriter
from src.translation.translation_container import TranslationContainer
from src.translation_reader import TranslationReader
from src.character_sprite.character_sprite import CharacterSpritesReader, CharacterSprite, CharacterSpritesGroup, \
    CharacterSpritesWriter, CharacterMetaStorageWriter


def main():
    parser = argparse.ArgumentParser(description="Katawa Shoujo GBA: Converter toolset")
    subparsers = parser.add_subparsers(dest="command", required=True, help="Available commands")

    scenario_parser = subparsers.add_parser("script", help="Script converter")
    scenario_parser.add_argument(
        "--source",
        required=True,
        help="Path to KS:RE sources"
    )
    scenario_parser.add_argument(
        "--script",
        required=True,
        help="Script name (i.e. \"script-a4-rin\")",
    )
    scenario_parser.add_argument(
        "--outdir",
        required=True,
        help="Path to KS GBA sources"
    )
    scenario_parser.add_argument(
        "--translations",
        required=False,
        help="Translation keys, comma separated. Example: de,es,fr,ru,zh_hans"
    )

    character_sprites_parser = subparsers.add_parser("character-sprites", help="Character sprites converter")
    character_sprites_parser.add_argument(
        "--source",
        required=True,
        help="Path to KS:RE sources"
    )
    character_sprites_parser.add_argument(
        "--outdir",
        required=True,
        help="Path to KS GBA sources"
    )

    definitions_parser = subparsers.add_parser("definitions", help="Definitions converter")
    definitions_parser.add_argument(
        "--source",
        required=True,
        help="Path to KS:RE sources"
    )
    definitions_parser.add_argument(
        "--outdir",
        required=True,
        help="Path to KS GBA sources"
    )
    definitions_parser.add_argument(
        "--locales",
        required=False,
        help="Locale keys, comma separated. Example: en,de,es,fr,ru,zh_hans"
    )

    fonts_parser = subparsers.add_parser("fonts", help="Fonts converter")
    fonts_parser.add_argument(
        "--source",
        required=True,
        help="Path to KS:RE sources"
    )
    fonts_parser.add_argument(
        "--outdir",
        required=True,
        help="Path to KS GBA sources"
    )
    fonts_parser.add_argument(
        "--locales",
        required=True,
        help="Locale keys, comma separated. Example: en,de,es,fr,ru,zh_hans"
    )

    # ksre_converter create-dictionary --source="${KSRE_ROOT}" --outdir="${KSGBA_ROOT}" --scripts="$(IFS=,; echo "${SCRIPTS[*]}")" --locale="en"
    create_dict_parser = subparsers.add_parser("create-dictionary", help="Create high-frequency dictionary")
    create_dict_parser.add_argument(
        "--source",
        required=True,
        help="Path to KS:RE sources"
    )
    create_dict_parser.add_argument(
        "--outdir",
        required=True,
        help="Path to output dictionary file"
    )
    create_dict_parser.add_argument(
        "--scripts",
        required=True,
        help="Script names, comma separated. Example: script-a1-monday,script-a1-tuesday (etc.)"
    )
    create_dict_parser.add_argument(
        "--locale",
        required=True,
        help="Locale key. Example: es"
    )

    args = parser.parse_args()

    if args.command == "script":
        ksre_path = args.source
        ksagb_path = args.outdir
        script_name = args.script
        locales = args.translations.split(",") if args.translations else []

        rpy_scenario_file = os.path.join(ksre_path, "game", f"{script_name}.rpy")
        gba_scripts_path = os.path.join(ksagb_path, "src", "scripts")
        gbfs_path = os.path.join(ksagb_path, "gbfs_files")
        output_file = script_name.replace("-", "_")

        translations : Dict[str, TranslationContainer] = {}
        for locale in locales:
            if locale == "en":
                # Skip the default locale
                continue

            print(f"Processing translation files for locale: {locale}")
            rpy_translation_dir = os.path.join(ksre_path, "game", "tl", locale)
            reader = TranslationReader(locale, rpy_translation_dir)
            translations[locale] = reader.read()

        print(f"Processing scenario file: {rpy_scenario_file}")
        reader = ScenarioReader(rpy_scenario_file, translations)
        scenario = reader.read()

        print(f"Writing scenario to {output_file}")
        writer = ScenarioWriter(output_file, gba_scripts_path, gbfs_path, scenario)
        # writer.clean()
        writer.write()
        exit(0)

    if args.command == "character-sprites":
        ksre_path = args.source
        ksagb_path = args.outdir

        ksre_character_sprites_path = os.path.join(ksre_path, "game", "sprites")

        print(f"Processing character sprites: {ksre_character_sprites_path}")
        reader = CharacterSpritesReader(ksre_character_sprites_path)
        character_sprites_groups = reader.process_all()

        group_counter = 1
        for group in character_sprites_groups:
            print(f"{group_counter}/{len(character_sprites_groups)} - Processing character group: {group}")
            writer = CharacterSpritesWriter(os.path.join(ksagb_path, "graphics", "characters", group.character_name),
                                            os.path.join(ksagb_path, "include"))
            writer.write(group)
            group_counter += 1

        meta_writer = CharacterMetaStorageWriter(os.path.join(ksagb_path, "include"))
        meta_writer.write(character_sprites_groups)
        exit(0)

    if args.command == "definitions":
        ksre_path = args.source
        ksagb_path = args.outdir
        locales = args.locales.split(",") if args.locales else []

        for locale in locales:
            print(f"Processing definitions for locale: {locale}")

            tl = None
            if locale != "en":
                print(f"Processing translation files for locale: {locale}")
                rpy_translation_dir = os.path.join(ksre_path, "game", "tl", locale)
                reader = TranslationReader(locale, rpy_translation_dir)
                tl = reader.read()

            definitions_reader = DefinitionsReader(os.path.join(ksre_path, "game", "definitions.rpy"), tl)
            definitions_writer = DefinitionsWriter(
                os.path.join(ksagb_path, "include"),
                os.path.join(ksagb_path, "src")
            )

            replays_ast = definitions_reader.extract_replays_block()
            routes = definitions_reader.parse_routes_structure(replays_ast)

            gallery_images_ast = definitions_reader.extract_gallery_images_block()
            gallery_images = definitions_reader.parse_gallery_images_structure(gallery_images_ast)

            definitions_writer.write_common_definitions(tl)
            definitions_writer.write_scripts_definitions(routes)
            definitions_writer.write_labels_definitions(routes)
            definitions_writer.write_labels_translations(routes, locale)
            definitions_writer.write_seen_bitmask_definitions(gallery_images)

    if args.command == "fonts":
        ksre_path = args.source
        ksagb_path = args.outdir
        locales = args.locales.split(",") if args.locales else []

        if not os.environ.get('DEVKITARM'):
            raise EnvironmentError("DEVKITARM environment variable is not set. Please set up devkitARM.")

        chars_reader = CharsReader(ksagb_path,
                                   "gbfs_files",
                                   locales,
                                   [
                                       "src/translations/{}.cpp",
                                       "src/translations/{}_definitions_commons.inc",
                                       "src/translations/{}_definitions_labels.h"
                                   ])
        chars_reader.read_definitions()
        chars_reader.read_tl_files()
        chars_reader.sort_char_tables()

        writer = FontsWriter(ksre_path, ksagb_path, "common",
                             chars_reader.get_common(),
                             chars_reader.get_additional())
        writer.generate_fonts()
        writer.generate_palettes()

    if args.command == "create-dictionary":
        ksre_path = args.source
        outdir = args.outdir
        scripts = args.scripts.split(",") if args.scripts else []
        locale = args.locale

        translations: Dict[str, TranslationContainer] = {}
        if locale != "en":
            print(f"Processing translation files for locale: {locale}")
            rpy_translation_dir = os.path.join(ksre_path, "game", "tl", locale)
            reader = TranslationReader(locale, rpy_translation_dir)
            translations[locale] = reader.read()


        textdb_strings = []

        def parse_sequence_item(item):
            from src.dto.sequence_item import SequenceType
            from src.dto.dialog_item import DialogItem
            from src.utils import split_by_commands

            if item.type == SequenceType.DIALOG:
                dialog = cast(DialogItem, item)
                if locale not in dialog.message:
                    raise ValueError(f"Missing translation for id {dialog.id} in locale {locale}")
                text_with_commands = dialog.message[locale]
                text_array = split_by_commands(text_with_commands)
                textdb_strings.extend(text_array)


        for script_name in scripts:
            print(f"Processing script: {script_name}")
            rpy_scenario_file = os.path.join(ksre_path, "game", f"{script_name}.rpy")
            reader = ScenarioReader(rpy_scenario_file, translations)
            scenario = reader.read()
            print(f"Creating dictionary for script: {script_name}")
            for sequence_group in scenario:
                for condition in sequence_group.conditions:
                    for item in condition.sequence:
                        parse_sequence_item(item)
                for item in sequence_group.sequence:
                    parse_sequence_item(item)

        print(len(textdb_strings))

        # Replacement cost is the cost of replacing a word with a special token (1F - is control character, FF - is the index of the replacement in the dictionary)
        REPLACEMENT_COST = len(b"\x1F\xFF")

        class CompressionEntry:
            def __init__(self, count: int, savings: int):
                self.count = count
                self.savings = savings
            def __repr__(self):
                return f"CompressionEntry(count={self.count}, savings={self.savings})"
        dictionary : Dict[str, CompressionEntry] = {}

        textdb_words = []
        for text in textdb_strings:
            words = text.split()
            # Remove all punctuation from words
            for i in range(len(words)):
                words[i] = words[i].strip('.,!?;"\'()[]{}<>«»')

            # Remove all capitalized ("Лёгкий" should be "ёгкий", "TEST" should be "")
            for i in range(len(words)):
                words[i] = re.sub(r'^[A-ZА-ЯЁ]+', '', words[i])
                words[i] = re.sub(r'[A-ZА-ЯЁ]+$', '', words[i])

            # Remove empty records
            words = [word for word in words if len(word) > 0]
            textdb_words.extend(words)

        for word in textdb_words:
            word_cost = len(word.encode("utf-8"))
            if word_cost <= REPLACEMENT_COST:
                continue
            if word in dictionary:
                dictionary[word].count += 1
                dictionary[word].savings = (word_cost - REPLACEMENT_COST) * (dictionary[word].count - 1)
            else:
                dictionary[word] = CompressionEntry(1, 0)

        # Filter out entries that do not save space
        dictionary = {k: v for k, v in dictionary.items() if v.savings > 0}
        # Sort by savings descending
        dictionary = dict(sorted(dictionary.items(), key=lambda item: item[1].savings, reverse=True))
        # Limit to 255 entries
        if len(dictionary) > 255:
            dictionary = dict(list(dictionary.items())[:255])

        # Sum of savings
        dict_savings = sum(entry.savings for entry in dictionary.values())
        print(f"Dict potential savings: {dict_savings} bytes")

        dict_size = sum(len(word.encode("utf-8")) + 1 for word in dictionary.keys())
        print(f"Dict size: {dict_size} bytes")

        total_savings = dict_savings - dict_size
        print(f"Total potential savings: {total_savings} bytes")
        print(f"Found {len(dictionary)} unique substrings")

        for i, (word, entry) in enumerate(dictionary.items()):
            print(f"{i+1:3}. {word} - {entry}")

        #Write dict file
        # with open(os.path.join(outdir, "gbfs_files", f"text_dictionary_{locale}.dict"), "wb") as f:
        with open(os.path.join(outdir, "gbfs_files", f"text_dictionary_{locale}.dict"), "w") as f:
            for word in dictionary.keys():
                # f.write(word.encode("utf-8") + b'\x00')
                f.write(f"{word}\n")


if __name__ == "__main__":
    main()
