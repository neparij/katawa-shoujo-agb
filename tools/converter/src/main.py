import argparse
import os
from typing import List, Dict

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
        "--locale-pairs",
        required=False,
        help="Locale pairs (lang:group), comma separated. Example: en:latin,de:latin,es:latin,fr:latin,ru:cyrillic,jp:j,zh_hans:c"
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
            rpy_translation_file = os.path.join(ksre_path, "game", "tl", locale, f"{script_name}.rpy")
            print(f"Processing translation file: {rpy_translation_file}")
            reader = TranslationReader(locale, rpy_translation_file)
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
            rpy_translation_file = os.path.join(ksre_path, "game", "tl", locale, "definitions.rpy") if locale != "en" else None

            tl = None
            if rpy_translation_file:
                print(f"Processing translation file: {rpy_translation_file}")
                reader = TranslationReader(locale, rpy_translation_file)
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

            definitions_writer.write_scripts_definitions(routes)
            definitions_writer.write_labels_definitions(routes)
            definitions_writer.write_labels_translations(routes, locale)
            definitions_writer.write_seen_bitmask_definitions(gallery_images)

    if args.command == "fonts":
        ksre_path = args.source
        ksagb_path = args.outdir
        locale_pairs = args.locale_pairs.split(",") if args.locale_pairs else []
        groups = {}

        if not os.environ.get('DEVKITARM'):
            raise EnvironmentError("DEVKITARM environment variable is not set. Please set up devkitARM.")

        for locale_pair in locale_pairs:
            lang, group = locale_pair.split(":")
            if not (lang and group):
                raise ValueError(f"Invalid locale pair: {locale_pair}")
            if group not in groups:
                groups[group] = []
            groups[group].append(lang)

        for group, languages in groups.items():
            print(f"Processing font group: {group} for languages: {', '.join(languages)}")
            chars_reader = CharsReader(ksagb_path,
                                       "gbfs_files",
                                       languages,
                                       [
                                           "src/translations/{}.cpp",
                                           "src/translations/{}_definitions_labels.h"
                                       ])
            chars_reader.read_definitions()
            chars_reader.read_tl_files()
            chars_reader.sort_char_tables()

            writer = FontsWriter(ksre_path, ksagb_path, group,
                                 chars_reader.get_common(),
                                 chars_reader.get_additional())
            writer.generate_fonts()

        writer = FontsWriter(ksre_path, ksagb_path, "default", [], [])
        writer.generate_palettes()


if __name__ == "__main__":
    main()
