# type: ignore
"""Converts any image to an image using the color restrictions of PMD2 tiled images"""
#  Copyright 2020-2021 Parakoopa and the SkyTemple Contributors
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

try:
    from PIL import Image
    from PIL.Image import NONE
except ImportError:
    from pil import Image
    from pil.Image import NONE

from tilequant.util import Color
from tilequant.legacy.run import ConversionRun
from tilequant.transparency_handler import TransparencyHandler


class ImageConverter:
    """
    Converts any image into a indexed image containing a number of smaller sub-palettes, each with a fixed
    color length. The conversion will assign each tile in the image one of these sub-palettes
    to use (single-palette-per-tile constraint).
    To meet this constraint the converter will continue to reduce the overall image colors using color
    quantization until each tile can be assigned a palette.
    """

    def __init__(
        self,
        img: Image.Image,
        tile_width=8,
        tile_height=8,
        transparent_color: Color = None,
    ):
        """
        Init.
        :param img:                 Input image. Is converted to RGB, alpha channel ist removed.
        :param tile_width:          The width of each tile in img. img must be divisible by this.
        :param tile_height:         The height of each tile in img. img must be divisible by this.
        :param transparent_color:   A single color value that should be treated as transparent, when doing
                                    the conversion with transparency enabled.
        """
        assert (
            img.width % tile_width == 0
        ), f"The image width must be divisible by {tile_width}"
        assert (
            img.height % tile_height == 0
        ), f"The image height must be divisible by {tile_height}"
        self._img = img.convert("RGB")
        self._tile_width = tile_width
        self._tile_height = tile_height
        self._transparent_color = transparent_color
        self._reset(0, 0, 0, NONE, 0, False, False)

    # noinspection PyAttributeOutsideInit
    def _reset(
        self,
        num_palettes,
        colors_per_palette,
        color_steps,
        dither,
        color_limit_per_tile,
        mosaic_limiting,
        transparency,
    ):
        # Number of colors per palette. Minimum is 1, the first color is always transparency.
        self._colors_per_palette = colors_per_palette
        # Maximum number of palettes to generate
        self._num_palettes = num_palettes
        # How many colors to subtract with each attempt of quantization
        # If it is -1, the tool will not try to subtract colors. It will just try one run with the maximum (or minimum,
        # based on the setting of direction) amount of colors and throw an error if not possible.
        self._color_steps = color_steps
        # Which dithering algorithm to use
        self._dither = dither
        # The number of colors the tiles are initially limited to by the first simple tile quanting:
        self._color_limit_per_tile = color_limit_per_tile
        # See doc of convert for description of this flag
        self._mosaic_limiting = mosaic_limiting
        # Transparency handler object or None if transparency is disabled
        self._transparency = (
            TransparencyHandler(self._transparent_color) if transparency else None
        )
        # Whether or not self._check_num_palette_constraint needs to perform a deep/hard merge check
        self._deep_merge_check_needed_for_run = False
        # For debugging:
        self._dbg_last_tile_quantized_img = None
        # The indices of this map are the real final palette indices and the entries themselves
        # reference an entry in self._palette which may contain fair more palettes due to the way things
        # may be merged.
        self._real_palette_indices = list(range(0, self._num_palettes))
        # The last color count after convert
        self._final_color_count = 0

    def convert(
        self,
        num_palettes=16,
        colors_per_palette=16,
        color_steps=4,
        max_colors=None,
        dither=NONE,
        color_limit_per_tile=None,
        mosaic_limiting=True,
        low_to_high=True,
        transparency=True,
    ) -> Image.Image:
        """
        Perform the conversion, returns the converted indexed image.

        It's highly recommended you pre-quantize the input image (=reduce the colors), because PIL (the used
        library) isn't very good at it. Use num_palettes*colors_per_palette colors for this.

        :param dither:                  Which dithering mechanism to use. Possible values: NONE, FLOYDSTEINBERG.
        :param num_palettes:            Number of palettes in the output
        :param colors_per_palette:      Number of colors per palette. If transparency is enabled, the first color in
                                        each palette is reserved for it.
        :param color_steps:             Step interval for reducing the color count on conversion failures.
                                        If it is -1, the tool will not try to subtract colors.
                                        It will just try one run with the maximum (or minimum,
                                        based on the setting of direction) amount of colors and throw an error if
                                        not possible.
                                        The original image will not be pre-processed if this is set to -1.
        :param max_colors:              Maximum overall colors to test, None means num_palettes*colors_per_palette
        :param low_to_high:             If True: Start with the lowest number of colors and go up until
                                        not possible anymore.
                                        If False: Start with highest number of colors and go down until possible.
                                        What's faster depends on the image, for most general images low_to_high is
                                        better.
                                        There is a chance for some images, especially once already in a format close to
                                        the one the converter creates, that low_to_high will not return the best result,
                                        because some color counts in-between may not be convertible, while higher ones
                                        are. This has to do with the color quantization algorithms used.
        :param color_limit_per_tile:    Limit the tiles to a specific amount of colors they should use. Setting this
                                        lower than colors_per_palette may help increase the number of
                                        total colors in the image.
        :param mosaic_limiting:         Enables or disables "mosaic limiting": If enabled, not only limit tiles like
                                        described in color_limit_per_tile, but also apply those limitations to larger
                                        areas of the image.
                                        Example for 8x8 tiles:
                                        [Always]:
                                            All 8x8 blocks   are limited to color_limit_per_tile      colors
                                        [If mosaic_limiting]:
                                            All 16x16 blocks are limited to color_limit_per_tile * 2  colors
                                            All 32x32 blocks are limited to color_limit_per_tile * 4  colors
                                            ... until the block size is the entire image
        :param transparency:            Toggle transparency. If on, reserve the first color of each palette for
                                        transparency and import pixels with the color code specified by
                                        transparent_color as transparency (if given).

        :return: The converted image. It will contain a palette that consists of all generated sub-palettes, one
                 after the other.
        """
        if max_colors is None:
            max_colors = num_palettes * colors_per_palette
            if transparency:
                max_colors -= num_palettes
        if color_limit_per_tile is None:
            color_limit_per_tile = colors_per_palette
            if transparency:
                color_limit_per_tile -= 1
        self._reset(
            num_palettes,
            colors_per_palette,
            color_steps,
            dither,
            color_limit_per_tile,
            mosaic_limiting,
            transparency,
        )

        if self._transparency:
            # If transparency, collect transparent tiles
            self._transparency.collect_and_remove_transparency(
                self._img, tile_w=self._tile_width, tile_h=self._tile_height
            )

        if max_colors <= 1:
            raise ValueError("The requested palette specs don't contain any colors.")

        # First do a tiled quantize: Reduce the colors of all tiles to their best self._color_limit_per_tile colors.
        # This will hopefully lead to better results.
        if not self._color_steps == -1:
            img = self._tiled_quantize(
                self._img.copy(),
                self._tile_width,
                self._tile_height,
                self._color_limit_per_tile,
            )
            # If mosaic limiting is enabled, also apply these rules to larger portions of the image, see docstring:
            if mosaic_limiting:
                block_width = self._tile_width * 2
                block_height = self._tile_height * 2
                block_colors = self._color_limit_per_tile * 2
                while (
                    block_width < self._img.width
                    and block_height < self._img.height
                    and block_colors <= 256
                ):
                    img = self._tiled_quantize(
                        img, block_width, block_height, block_colors
                    )
                    block_width *= 2
                    block_height *= 2
                    block_colors *= 2
        else:
            img = self._img.copy()

        # Prepare all full image color quantization
        prepare_color_count = max_colors
        quant_images: list[tuple[int, Image, list[Color]]] = []
        while prepare_color_count > 0:
            q_result = self._quantize(img, prepare_color_count)
            quant_images.append((prepare_color_count, q_result[0], q_result[1]))
            if self._color_steps == -1:
                break
            prepare_color_count -= self._color_steps

        # Go up instead flag set
        if low_to_high:
            # noinspection PyTypeChecker
            quant_images = reversed(quant_images)

        colors_per_palette = self._colors_per_palette
        # If transparency is enabled, run the runs with one color less,
        # the first one is reserved for transparency
        if transparency:
            colors_per_palette -= 1

        last_working_run = None
        for color_count, quant_image, current_colors in quant_images:
            run = ConversionRun(
                color_count,
                quant_image,
                current_colors,
                self._tile_width,
                self._tile_height,
                self._num_palettes,
                colors_per_palette,
                id(self),
                self._transparency.transparency_map,
            )
            if not low_to_high:
                # If big -> small:
                # Go through the list and stop when first found
                if run.run():
                    last_working_run = run
                    break
            else:
                # If small -> big:
                # Go through the list and stop until no longer found
                if not run.run():
                    break
                else:
                    last_working_run = run
            if self._color_steps == -1:
                raise ValueError(
                    "Was unable to re-organize the colors in the image without removing colors."
                )

        if last_working_run is None:
            raise RuntimeError("Was unable to quantize image: Had no colors left.")

        self._final_color_count = last_working_run.color_count

        # If the palette count is > num_palettes, we need to merge palettes
        if len(last_working_run.palettes) > num_palettes:
            self._merge_palettes(last_working_run)

        # If transparency is enabled, update the palettes to include the transparent colors
        if self._transparency:
            last_working_run.palettes = self._transparency.update_palettes(
                last_working_run.palettes
            )

        indexed_pixels = self._index_pixels(last_working_run)

        # If transparency is enabled, set the transparent pixels of the image back to transparency
        if self._transparency:
            last_working_run.palettes = (
                self._transparency.set_transparent_color_in_palettes(
                    last_working_run.palettes
                )
            )
            self._transparency.update_pixels(
                self._img.width,
                int(self._img.width / self._tile_width),
                int(self._img.height / self._tile_height),
                self._colors_per_palette,
                self._tile_width,
                self._tile_height,
                indexed_pixels,
            )

        # Iterate one last time and assign the final pixel colors and then build the image from it
        return self._build_image(indexed_pixels, last_working_run.palettes)

    def color_count(self):
        """The count of colors in the last converted image"""
        return self._final_color_count

    def _tiled_quantize(self, img, block_width, block_height, color_limit):
        """
        Reduces the colors in each block of the image down to color_limit.
        """
        for tx in range(0, int(self._img.width / block_width)):
            for ty in range(0, int(self._img.height / block_height)):
                box = (
                    tx * block_width,
                    ty * block_height,
                    (tx + 1) * block_width,
                    (ty + 1) * block_height,
                )
                img_tile = img.crop(box).convert(
                    "P", palette=Image.ADAPTIVE, colors=color_limit, dither=self._dither
                )
                img.paste(img_tile, box)
        self._dbg_last_tile_quantized_img = img.copy()
        return img

    def _quantize(self, img, color_count) -> tuple[Image.Image, list[Color]]:
        """
        Reduces the colors in the entire image down to self._current_color_count
        :return:
        """
        # PIL is a bit broken, so convert to RGB again first.
        img = img.convert("RGB").convert(
            "P", palette=Image.ADAPTIVE, colors=color_count, dither=self._dither
        )
        it = iter(img.getpalette()[: color_count * 3])
        # zip converts the palette into rgb tuples: [(r,g,b),(r,g,b)...]
        return img, list(zip(it, it, it))

    def _merge_palettes(self, run: ConversionRun):
        """
        Merges the palettes and updates self._palette_for_tiles and self._real_palette_indices.
        self._real_palette_indices will contain a list of maximum self._number_palettes entries,
        that contains indices for the list run.palettes.
        Fills all palette slots removed during the merge in run.palettes with None, these are then skipped
        later for self._build_image.
        """
        # We can just re-use the information from last merger we used, if we already had to use one.
        if not run.merger.was_run:
            assert run.merger.try_to_merge()

        for merge_step in run.merger.get_merge_operations():
            run.palettes[merge_step[0]] = run.palettes[merge_step[0]].union(
                run.palettes[merge_step[1]]
            )
            # Set the other palette at this place to None
            run.palettes[merge_step[1]] = None
            assert len(run.palettes[merge_step[0]]) <= self._colors_per_palette
            for tile in run.palettes_for_tiles:
                try:
                    tile.remove(merge_step[1])
                    if merge_step[0] not in tile:
                        tile.append(merge_step[0])
                except ValueError:
                    pass  # Faster this way, than to check if in list first.

        # Now assign the real final indices (between 0 and num_palettes) of the palettes
        self._real_palette_indices = []
        for p_idx, p in enumerate(run.palettes):
            if p is not None:
                self._real_palette_indices.append(p_idx)
        assert len(self._real_palette_indices) <= self._num_palettes

    def _iterate_tiles_x(self):
        return range(0, int(self._img.width / self._tile_width))

    def _iterate_tiles_y(self):
        return range(0, int(self._img.height / self._tile_height))

    def _tile_coord(self, tx, ty):
        return int(self._img.width / self._tile_width) * ty + tx

    def _index_pixels(self, run: ConversionRun):
        """
        Find the color value for the final palettes for each tile, with the single-palette-per-tile constraint
        in mind.
        """

        pxs = [0 for _ in range(0, self._img.width * self._img.height)]
        for tx in self._iterate_tiles_x():
            for ty in self._iterate_tiles_y():
                palette_for_tile = run.palettes_for_tiles[self._tile_coord(tx, ty)][0]
                real_final_index = self._real_palette_indices.index(palette_for_tile)
                index_first_col = real_final_index * self._colors_per_palette
                for x in range(tx * self._tile_width, (tx + 1) * self._tile_width):
                    for y in range(
                        ty * self._tile_height, (ty + 1) * self._tile_height
                    ):
                        col = run.colors[run.img.getpixel((x, y))]
                        try:
                            col_val_index = index_first_col + run.palettes[
                                palette_for_tile
                            ].index(col)
                            pxs[y * self._img.width + x] = col_val_index
                        except KeyError:
                            # This can be none if the pixel was originally ignored, for transparency.
                            pxs[y * self._img.width + x] = index_first_col
        return pxs

    def _build_image(self, indexed_pixels, palettes):
        """
        Build the final image from the provided pixel data and the palettes in palettes. None entries
        in palettes are skipped.
        """

        im = Image.frombuffer(
            "P",
            (self._img.width, self._img.height),
            bytearray(indexed_pixels),
            "raw",
            "P",
            0,
            1,
        )
        cols = []
        processed_palette_count = 0
        for p in palettes:
            if p is None:
                continue
            processed_palette_count += 1
            # Fill rest of palette
            p = list(p)
            p.extend([(0, 0, 0)] * (self._colors_per_palette - len(p)))
            for r, g, b in p:
                cols.append(r)
                cols.append(g)
                cols.append(b)
        for i in range(processed_palette_count, self._num_palettes):
            cols += [0] * 3 * self._colors_per_palette
        im.putpalette(cols)
        return im
