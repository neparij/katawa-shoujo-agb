#  Copyright 2020-2023 Capypara and the SkyTemple Contributors
#
#  This file is part of SkyTemple.
#
#  SkyTemple is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  SkyTemple is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with SkyTemple.  If not, see <https://www.gnu.org/licenses/>.
import os

import click

from tilequant.image_converter import Tilequant
from tilequant.util import convert_hex_str_color_to_tuple

try:
    from PIL import Image
except ImportError:
    from pil import Image  # type: ignore
from click import echo, ClickException


@click.command()
@click.argument("input_image", required=True)
@click.argument("output_image", required=True)
@click.option(
    "-n",
    "--num-palettes",
    required=False,
    type=int,
    default=16,
    help="[Default: 16] Number of palettes in the output.",
)
@click.option(
    "-c",
    "--colors-per-palette",
    required=False,
    type=int,
    default=16,
    help="[Default: 16] Number of colors per palette. If transparency is enabled, the first color in each "
    "palette is reserved for it.",
)
@click.option(
    "-t",
    "--transparent-color",
    type=str,
    required=False,
    help="A single color value (hex style, eg. 12ab56) that should be treated as transparent, when doing"
    "the conversion with transparency enabled.",
)
@click.option(
    "-v",
    "--loglevel",
    type=click.Choice(["DEBUG", "INFO", "WARNING", "ERROR", "FATAL", "CRITICAL"]),
    default="INFO",
    help="[Default: INFO] Log level.",
)
def main(
    input_image,
    output_image,
    loglevel,
    num_palettes,
    colors_per_palette,
    transparent_color,
):
    """
    Converts any image into a indexed image containing a number of smaller sub-palettes (--num-palettes), each with a
    fixed color length (--colors-per-palette). The conversion will assign each tile in the image one of
    these sub-palettes to use (single-palette-per-tile constraint).

    INPUT_IMAGE is the path of the image to convert and OUTPUT_IMAGE is where to save the converted image. All image
    types supported by PIL (the Python image library) can be used.
    :return:
    """
    echo("Converting...")
    if not os.path.exists(input_image):
        raise ClickException("The input image doesn't exist.")
    with open(input_image, "rb") as input_file:
        try:
            image = Image.open(input_file)
        except OSError:
            raise ClickException("The input image is not a supported image file.")
        try:
            converter = Tilequant(
                image, convert_hex_str_color_to_tuple(transparent_color)
            )
            img = converter.convert(num_palettes, colors_per_palette)
        except RuntimeError as err:
            raise ClickException("The image could not be converted: " + str(err))
    echo(f"Saving image to {output_image}...")
    try:
        img.save(output_image)
    except OSError as err:
        raise ClickException("Error saving the image: " + str(err))


if __name__ == "__main__":
    main()
