import argparse
import os

from src.scenario_reader import ScenarioReader
from src.scenario_writer import ScenarioWriter


def main():
    parser = argparse.ArgumentParser(description="Katawa Shoujo GBA: Converter toolset")
    subparsers = parser.add_subparsers(dest="command", required=True, help="Available commands")

    scenario_parser = subparsers.add_parser("scenario", help="Scenario converter")
    scenario_parser.add_argument(
        "--input",
        required=True,
        help="Path to rpy scenario file"
    )

    args = parser.parse_args()

    if args.command == "scenario":
        input_file = args.input
        output_file = os.path.basename(input_file).split('.')[0].replace("-", "_")

        print(f"Processing scenario file: {input_file}")
        reader = ScenarioReader(input_file)
        scenario = reader.read()

        print(f"Writing scenario to {output_file}")
        writer = ScenarioWriter(output_file, "../../../src/scripts", scenario)
        writer.write()
        pass

if __name__ == "__main__":
    main()
