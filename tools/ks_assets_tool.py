import argparse
import sys
import traceback

from ks_graphics_tool import process_graphics


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Katawa Shoujo GBA assets tool.')
    parser.add_argument('--grit', required=True, help='grit executable path')
    parser.add_argument('--graphics', required=True, help='graphics folder and file paths')
    parser.add_argument('--build', required=True, help='build folder path')

    try:
        args = parser.parse_args()
        print(f'Using grit: {args.grit}')
        print(f'Using graphics: {args.graphics}')
        print(f'Using build: {args.build}')
        process_graphics(args.grit, args.graphics, args.build)
    except Exception as ex:
        sys.stderr.write('Error: ' + str(ex) + '\n')
        traceback.print_exc()
        exit(-1)
