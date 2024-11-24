import argparse
import os

from src.scenario_reader import ScenarioReader
from src.scenario_writer import ScenarioWriter
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

    args = parser.parse_args()

    if args.command == "script":
        ksre_path = args.source
        ksagb_path = args.outdir
        script_name = args.script
        locale = args.translation

        rpy_scenario_file = os.path.join(ksre_path, "game", f"{script_name}.rpy")
        rpy_translation_file = os.path.join(ksre_path, "game", "tl", locale, f"{script_name}.rpy") if locale else None
        gba_scripts_path = os.path.join(ksagb_path, "src", "scripts")
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
        writer = ScenarioWriter(output_file, gba_scripts_path, scenario, locale)
        writer.write()
        pass

if __name__ == "__main__":
    main()
