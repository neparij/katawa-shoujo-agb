# type: ignore
"""A single run of image conversion"""
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
from typing import Union

try:
    from PIL import Image
except ImportError:
    from pil import Image
from ordered_set import OrderedSet

from tilequant.util import Color
from tilequant.legacy.palette_merger import PaletteMerger


class ConversionRun:
    def __init__(
        self,
        color_count,
        img,
        colors,
        tile_width,
        tile_height,
        num_palettes,
        colors_per_palette,
        conversion_id,
        pixels_to_ignore=None,
    ):
        self.color_count: int = color_count
        # Input image, quantized to max color_count
        self.img: Image.Image = img
        # The colors in img
        self.colors: list[Color] = colors
        # Tiling dimensions
        self._tile_width = tile_width
        self._tile_height = tile_height
        # Info about the palettes
        self._num_palettes = num_palettes
        self._colors_per_palette = colors_per_palette
        # List of all possible palettes
        # In the end this will contain any number of palettes, but they will be merged by self._merge_palettes
        # and only up to self._num_palettes entries in this list will not be None.
        self._palettes: list[Union[None, OrderedSet]] = []
        self.palettes = []
        # A list where each entry is one image tile and the values are lists of possible indices from self.palettes,
        # that the tile could use
        self.palettes_for_tiles = [
            []
            for _ in range(
                0,
                int((img.width * img.height) / (self._tile_width * self._tile_height)),
            )
        ]
        self._deep_merge_check_needed_for_run = False
        # These pixels will be ignored during conversion; use this for pixels that were originally transparent.
        if not pixels_to_ignore:
            self._pixels_to_ignore = [False] * len(img.getdata())
        else:
            self._pixels_to_ignore = pixels_to_ignore
        # The merger instance used for this run, use getter instead.
        self._merger = None
        self._id = conversion_id

    @property
    def merger(self) -> PaletteMerger:
        if not self._merger:
            self._merger = PaletteMerger(
                self.palettes.copy(), self._num_palettes, self._colors_per_palette
            )
        return self._merger

    def run(self):
        """
        Goes over all pixels and builds local tile palettes from the current image colors.

        Fails if more full palettes than num_palettes would be required or if a tile contains more
        colors than colors_per_palette.

        On failure returns False, True otherwise. If no failure occurred, the _palettes
        field contains the palettes and the _palettes_for_tiles field the possible palette idxs the tiles could use

        Please note, that the number of palettes can be bigger than _num_palettes,
        because palettes might be able to be merged. If for example colors_per_palette is 8
        the end result may contain (num_palettes - 1) 8-color palettes and two 4-color
        palettes that could be merged.
        """

        # Iterate tiles:
        for ty in self._iterate_tiles_y():
            for tx in self._iterate_tiles_x():
                success = self._index_tile(tx, ty)
                if not success:
                    return False
        return self._check_num_palette_constraint()

    def _index_tile(self, tx, ty):
        current_local_tile_palette = OrderedSet()

        # Collect all colors and try to fit them in palettes
        for y in range(ty * self._tile_height, (ty + 1) * self._tile_height):
            for x in range(tx * self._tile_width, (tx + 1) * self._tile_width):
                cc_idx = self.img.getpixel((x, y))
                cc = self.colors[cc_idx]
                if not self._pixels_to_ignore[y * self.img.width + x]:
                    current_local_tile_palette.append(cc)

        if len(current_local_tile_palette) > self._colors_per_palette:
            # We don't even have to continue... This single tile already has to many colors
            return False

        # Get possible palettes of the tile
        possible_palettes = self._get_suitable_palettes(current_local_tile_palette)
        if len(possible_palettes) < 1:
            # No palette contains all colors... We need to create a new one
            possible_palettes = [len(self.palettes)]
            self.palettes.append(OrderedSet(current_local_tile_palette))

        self.palettes_for_tiles[self._tile_coord(tx, ty)] = possible_palettes
        return True

    def _iterate_tiles_x(self):
        return range(0, int(self.img.width / self._tile_width))

    def _iterate_tiles_y(self):
        return range(0, int(self.img.height / self._tile_height))

    def _tile_coord(self, tx, ty):
        return int(self.img.width / self._tile_width) * ty + tx

    def _get_suitable_palettes(self, tile_pal: OrderedSet) -> list[int]:
        """
        Check which palettes contain all colors of tile_pal.
        If tile_pal is instead a superset of any of the palettes, those palettes are updated with the colors
        from tile_pal.
        """
        possible = []
        for p_idx, p in enumerate(self.palettes):
            if tile_pal.issubset(p):
                possible.append(p_idx)
            elif tile_pal.issuperset(p):
                self.palettes[p_idx] = p.union(tile_pal)
                possible.append(p_idx)
        return possible

    def _check_num_palette_constraint(self):
        """
        Check if it's still possible with the palettes in self._palettes to get them down to
        a total of self._num_palettes of less, by merging
        :return:
        """

        palette_color_counts = [len(p) for p in self.palettes]

        if not self._deep_merge_check_needed_for_run:
            # Easy case: We still have open slots
            if len(self.palettes) < self._num_palettes:
                return True

            # Slightly harder case:
            # Try and see if we could still easily merge to get under self._num_palettes
            if PaletteMerger.try_fast_merge(
                self.palettes.copy(), self._colors_per_palette, self._num_palettes
            ):
                return True

        self._deep_merge_check_needed_for_run = True

        # Hardest case:
        # Try to find a way to merge by actually trying to find a merge path
        return self.merger.try_to_merge()
