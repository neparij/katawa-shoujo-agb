import argparse
import os
from typing import Dict

from src.definitions_reader import DefinitionsReader
from src.definitions_writer import DefinitionsWriter
from src.font.chars_reader import CharsReader
from src.fonts_writer import FontsWriter
from src.scenario_reader import ScenarioReader
from src.scenario_writer import ScenarioWriter
from src.spm_packer import SPMPacker
from src.spm_writer import SPMWriter
from src.translation.translation_container import TranslationContainer
from src.translation_reader import TranslationReader


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
        "--spm-assets-path",
        required=True,
        help="Path to SentencePiece models for TextDB"
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
        "--scripts",
        required=True,
        help="Script names, comma separated. Example: script-a1-monday,script-a1-tuesday (etc.)"
    )
    fonts_parser.add_argument(
        "--locales",
        required=True,
        help="Locale keys, comma separated. Example: en,de,es,fr,ru,zh_hans"
    )

    spm_train_parser = subparsers.add_parser("train-spm", help="Train SentencePiece models for TextDB")
    spm_train_parser.add_argument(
        "--source",
        required=True,
        help="Path to KS:RE sources"
    )
    spm_train_parser.add_argument(
        "--outdir",
        required=True,
        help="Path to output directory for SPM models"
    )
    spm_train_parser.add_argument(
        "--scripts",
        required=True,
        help="Script names, comma separated. Example: script-a1-monday,script-a1-tuesday (etc.)"
    )
    spm_train_parser.add_argument(
        "--locales",
        required=True,
        help="Locale keys, comma separated. Example: en,de,es,fr,ru,zh_hans"
    )

    spm_pack_parser = subparsers.add_parser("pack-spm", help="Pack SentencePiece models into GBFS")
    spm_pack_parser.add_argument(
        "--source",
        required=True,
        help="Path to SPM models"
    )
    spm_pack_parser.add_argument(
        "--outdir",
        required=True,
        help="Path to KS GBA sources"
    )
    spm_pack_parser.add_argument(
        "--locales",
        required=True,
        help="Locale keys, comma separated. Example: en,de,es,fr,ru,zh_hans"
    )

    args = parser.parse_args()

    if args.command == "script":
        ksre_path = args.source
        ksagb_path = args.outdir
        spm_assets_path = args.spm_assets_path
        script_name = args.script
        locales = args.translations.split(",") if args.translations else []

        rpy_scenario_file = os.path.join(ksre_path, "game", f"{script_name}.rpy")
        gba_scripts_path = os.path.join(ksagb_path, "src", "scripts")
        tl_path = os.path.join(ksagb_path, "tl")
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
        writer = ScenarioWriter(output_file, gba_scripts_path, tl_path, spm_assets_path, scenario)
        # writer.clean()
        writer.write()
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
        scripts = args.scripts.split(",") if args.scripts else []
        locales = args.locales.split(",") if args.locales else []

        if not os.environ.get('DEVKITARM'):
            raise EnvironmentError("DEVKITARM environment variable is not set. Please set up devkitARM.")

        chars_reader = CharsReader(ksagb_path,
                                   "gbfs_files",
                                   locales,
                                   [
                                       "src/tl/{}/translation.cpp",
                                       "src/tl/{}/definitions_commons.inc",
                                       "src/tl/{}/definitions_labels.h"
                                   ])
        chars_reader.read_definitions()

        translations: Dict[str, TranslationContainer] = {}
        for locale in locales:
            if locale != "en":
                print(f"Processing translation files for locale: {locale}")
                rpy_translation_dir = os.path.join(ksre_path, "game", "tl", locale)
                reader = TranslationReader(locale, rpy_translation_dir)
                translations[locale] = reader.read()

        for script_name in scripts:
            print(f"Processing script: {script_name}")
            rpy_scenario_file = os.path.join(ksre_path, "game", f"{script_name}.rpy")
            reader = ScenarioReader(rpy_scenario_file, translations)
            scenario = reader.read()
            for locale in locales:
                chars_reader.read_scenario(scenario, locale)

        chars_reader.sort_char_tables()

        writer = FontsWriter(ksre_path, ksagb_path, "common",
                             chars_reader.get_common(),
                             chars_reader.get_additional())
        writer.generate_fonts()
        writer.generate_palettes()

    if args.command == "train-spm":
        ksre_path = args.source
        outdir = args.outdir
        scripts = args.scripts.split(",") if args.scripts else []
        locales = args.locales.split(",") if args.locales else []

        for locale in locales:
            translations: Dict[str, TranslationContainer] = {}
            if locale != "en":
                print(f"Processing translation files for locale: {locale}")
                rpy_translation_dir = os.path.join(ksre_path, "game", "tl", locale)
                reader = TranslationReader(locale, rpy_translation_dir)
                translations[locale] = reader.read()

            spm_writer = SPMWriter(outdir, locale)
            for script_name in scripts:
                print(f"Processing script: {script_name}")
                rpy_scenario_file = os.path.join(ksre_path, "game", f"{script_name}.rpy")
                reader = ScenarioReader(rpy_scenario_file, translations)
                scenario = reader.read()
                spm_writer.process_scenario(scenario)

            spm_writer.write_model()

    if args.command == "pack-spm":
        spm_path = args.source
        ksagb_path = args.outdir
        tl_path = os.path.join(ksagb_path, "tl")
        locales = args.locales.split(",") if args.locales else []

        for locale in locales:
            spm_packer = SPMPacker(spm_path, tl_path, locale)
            spm_packer.pack()


if __name__ == "__main__":
    main()
