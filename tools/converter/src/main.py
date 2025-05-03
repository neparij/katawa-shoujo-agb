import argparse
import os
from typing import List

from src.definitions_reader import DefinitionsReader
from src.definitions_writer import DefinitionsWriter
from src.scenario_reader import ScenarioReader
from src.scenario_writer import ScenarioWriter
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
        "--translation",
        required=False,
        help="Translation key (de, es, fr, ru, zh_hans)"
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
    character_sprites_parser.add_argument(
        "--character",
        required=False,
        help="Character sprites directory name (i.e. \"rinpan\")",
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
        "--translation",
        required=False,
        help="Translation key (de, es, fr, ru, zh_hans)"
    )

    args = parser.parse_args()

    if args.command == "script":
        ksre_path = args.source
        ksagb_path = args.outdir
        script_name = args.script
        locale = args.translation

        rpy_scenario_file = os.path.join(ksre_path, "game", f"{script_name}.rpy")
        rpy_translation_file = os.path.join(ksre_path, "game", "tl", locale, f"{script_name}.rpy") if locale else None
        gba_scripts_path = os.path.join(ksagb_path, "src", "scripts")
        gbfs_path = os.path.join(ksagb_path, "gbfs_files")
        output_file = script_name.replace("-", "_")

        tl = None
        if rpy_translation_file:
            print(f"Processing translation file: {rpy_translation_file}")
            reader = TranslationReader(locale, rpy_translation_file)
            tl = reader.read()

        print(f"Processing scenario file: {rpy_scenario_file}")
        reader = ScenarioReader(rpy_scenario_file, tl)
        scenario = reader.read()

        print(f"Writing scenario to {output_file}")
        writer = ScenarioWriter(output_file, gba_scripts_path, gbfs_path, scenario, locale)
        # writer.clean()
        writer.write()
        exit(0)

    if args.command == "character-sprites":
        ksre_path = args.source
        ksagb_path = args.outdir

        ksre_character_sprites_path = os.path.join(ksre_path, "game", "sprites")

        print(f"Processing character sprites: {ksre_character_sprites_path}")
        reader = CharacterSpritesReader(ksre_character_sprites_path)
        character_sprites_groups: List[CharacterSpritesGroup] = []
        if not args.character:
            character_sprites_groups = reader.process_all()
        elif args.character == "shizu":
            character_sprites_groups = reader.process_shizu()

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
        locale = args.translation

        rpy_translation_file = os.path.join(ksre_path, "game", "tl", locale, "definitions.rpy") if locale else None

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
        definitions_writer.write_scripts_definitions(routes)
        definitions_writer.write_labels_definitions(routes)
        if locale:
            definitions_writer.write_labels_translations(routes, locale)
        else:
            definitions_writer.write_labels_translations(routes, "en")


if __name__ == "__main__":
    main()
