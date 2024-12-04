"""Converts any image to an image using the color restrictions of PMD2 tiled images"""
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
from __future__ import annotations

import os
from ctypes import cdll, c_int, POINTER, c_uint8, c_int32, memmove, byref, c_float
from enum import Enum
import platform

from tilequant.legacy import do_simple_convert

try:
    from PIL import Image
except ImportError:
    from pil import Image  # type: ignore

from tilequant.util import Color
from tilequant.transparency_handler import TransparencyHandler


class TilequantError(RuntimeError):
    def __init__(self, message: str, error_out: str, error_err: str):
        self.message = message
        self.error_out = error_out
        self.error_err = error_err

    def __str__(self):
        return self.message + "\n" + self.error_out + "\n" + self.error_err


class DitheringMode(Enum):
    NONE = 0
    ORDERED = 3
    FLOYDSTEINBERG = -1


class Tilequant:
    """
    Converts any image into a indexed image containing a number of smaller sub-palettes,
    each with a fixed color length.
    """

    def __init__(
        self,
        img: Image.Image,
        transparent_color: Color | None = None,
        tile_width=8,
        tile_height=8,
        dl_name=None,
    ):
        """
        Init.
        :param img:                 Input image. Is converted to RGB, alpha channel ist removed.
        :param transparent_color:   A single RGB color value that should be treated as transparent, when doing
                                    the conversion with transparency enabled.
        :param tile_width:          Width of a tile
        :param tile_height:         Height of a tile
        :param dl_name:             Path to the DLL or SO file for Tilequant, if not given, will auto-detect.
        """
        assert (
            img.width % tile_width == 0
        ), f"The image width must be divisible by {tile_width}"
        assert (
            img.height % tile_height == 0
        ), f"The image height must be divisible by {tile_height}"
        self._img = img.convert("RGBA").convert("RGBa")
        self._transparent_color: tuple[int, int, int, int] | None = None
        if transparent_color is not None:
            self._transparent_color = (
                transparent_color[0],
                transparent_color[1],
                transparent_color[2],
                255,
            )
        self.tile_width = tile_width
        self.tile_height = tile_height
        # The created image
        self._out_img: Image.Image | None = None

        # Init the library
        if dl_name is None:
            # Try setuptools_dso
            try:
                import setuptools_dso

                fname = setuptools_dso.find_dso("tilequant")
                self.lib = cdll.LoadLibrary(fname)
            except OSError:
                # Try autodetect / CWD
                try:
                    if platform.system().lower().startswith("windows"):
                        dl_name = "libtilequant.dll"
                        os.add_dll_directory(os.getcwd())  # type: ignore
                    elif platform.system().lower().startswith("linux"):
                        dl_name = "libtilequant.so"
                    elif platform.system().lower().startswith("darwin"):
                        dl_name = "libtilequant.so"
                    else:
                        RuntimeError(
                            f"Unknown platform {platform.system()}, can't autodetect DLL to load."
                        )

                    self.lib = cdll.LoadLibrary(dl_name)
                except OSError:
                    # Okay now try the package directory
                    dl_name = os.path.dirname(os.path.realpath(__file__))
                    if platform.system().lower().startswith("windows"):
                        os.add_dll_directory(dl_name)  # type: ignore
                        dl_name = os.path.join(dl_name, "libtilequant.dll")
                    elif platform.system().lower().startswith("linux"):
                        dl_name = os.path.join(dl_name, "libtilequant.so")
                    elif platform.system().lower().startswith("darwin"):
                        dl_name = os.path.join(dl_name, "libtilequant.so")

                    self.lib = cdll.LoadLibrary(dl_name)
        else:
            if platform.system().lower().startswith("windows"):
                os.add_dll_directory(os.path.dirname(dl_name))  # type: ignore
                dl_name = os.path.basename(dl_name)

            self.lib = cdll.LoadLibrary(dl_name)

        self.lib.QualetizeFromRawImage.argtypes = (
            c_int,  # int ImgWidth,
            c_int,  # int ImgHeight,
            POINTER(c_uint8),  # const uint8_t *SrcPxData,
            POINTER(c_uint8),  # const uint8_t *SrcPxPal,
            POINTER(c_uint8),  # uint8_t *DstPxIdx,
            POINTER(c_uint8),  # uint8_t *DstPal,
            c_int,  # int nUnusedColoursPerPalette,
            c_int,  # int OutputPaletteIs24bitRGB,
            c_int,  # int nPalettes,
            c_int,  # int nColoursPerPalette,
            c_int,  # int TileW,
            c_int,  # int TileH,
            POINTER(c_int32),  # int32_t *TilePalIdx,
            c_int,  # int nTileClusterPasses,
            c_int,  # int nColourClusterPasses,
            c_uint8 * 4,  # const uint8_t BitRange[4],
            c_int,  # int DitherMode,
            c_float,  # float DitherLevel
        )
        self.lib.QualetizeFromRawImage.restype = c_int

    def simple_convert(self, num_palettes=16, colors_per_palette=16) -> Image.Image:
        """
        This does a simple conversion by simply trying to re-order the existing colors in the image
        so that one tile can get one color.
        Returns the converted indexed image on success, raises a ValueError if not possible.

        It's highly recommended you pre-quantize the input image (=reduce the colors), because PIL (the used
        library) isn't very good at it. Use num_palettes*colors_per_palette colors for this.

        :param num_palettes:            Number of palettes in the output
        :param colors_per_palette:      Number of colors per palette. If transparency is enabled, the first color in
                                        each palette is reserved for it.

        :return: The converted image. It will contain a palette that consists of all generated sub-palettes, one
                 after the other.
        """
        return do_simple_convert(
            self._img,
            num_palettes,
            colors_per_palette,
            self.tile_width,
            self.tile_height,
            self._transparent_color,  # type: ignore # this is ok, we just ignore the 4th channel.
        )

    def convert(
        self,
        num_palettes=16,
        colors_per_palette=16,
        dithering_mode: DitheringMode = DitheringMode.ORDERED,
        dithering_level=1.0,
        num_tile_cluster_passes=0,
        num_color_cluster_passes=0,
    ) -> Image.Image:
        """
        Perform the conversion, returns the converted indexed image.

        It's highly recommended you pre-quantize the input image (=reduce the colors), because PIL (the used
        library) isn't very good at it. Use num_palettes*colors_per_palette colors for this.

        :param num_palettes:                Number of palettes in the output
        :param colors_per_palette:          Number of colors per palette. If transparency is enabled, the first color in
                                            each palette is reserved for it.
        :param dithering_mode:              Dithering mode to use.
        :param dithering_level:             Scale of the dither (0.0 = No dither, 1.0 = Full dither).
        :param num_tile_cluster_passes:     Manually control the number of tile clustering passes,
                                            0 uses reasonable defaults.
        :param num_color_cluster_passes:    Manually control the number of color clustering passes,
                                            0 uses reasonable defaults.

        :return: The converted image. It will contain a palette that consists of all generated sub-palettes, one
                 after the other.
        """
        # Collect transparent tiles
        transparency = TransparencyHandler(self._transparent_color)
        transparency.collect_and_remove_transparency(self._img, True)

        # Execute Aikku's Tilequant
        self._out_img = self._execute_tilequant(
            num_palettes,
            colors_per_palette,
            dithering_mode,
            dithering_level,
            num_tile_cluster_passes,
            num_color_cluster_passes,
        )

        # Iterate one last time and assign the final pixel colors and then build the image from it
        return self._out_img

    def _execute_tilequant(
        self,
        num_palettes: int,
        colors_per_palette: int,
        dithering_mode: DitheringMode,
        dithering_level: float,
        num_tile_cluster_passes: int,
        num_color_cluster_passes: int,
    ) -> Image.Image:
        dst_px_idx = (c_uint8 * (self._img.width * self._img.height))()
        dst_pal = (c_uint8 * (num_palettes * colors_per_palette * 4 * 4))()

        img_data_bytes = self._img.tobytes("raw", "BGRa")
        img_data = (c_uint8 * len(img_data_bytes))()
        memmove(byref(img_data), img_data_bytes, len(img_data_bytes))

        self.lib.QualetizeFromRawImage(
            self._img.width,
            self._img.height,
            img_data,
            None,
            dst_px_idx,
            dst_pal,
            1,
            True,
            num_palettes,
            colors_per_palette,
            self.tile_width,
            self.tile_height,
            None,
            num_tile_cluster_passes,
            num_color_cluster_passes,
            (c_uint8 * 4)(*[31, 31, 31, 1]),
            dithering_mode.value,
            dithering_level,
        )

        out = Image.frombuffer(
            "P", (self._img.width, self._img.height), dst_px_idx, "raw", "P", 0, 1
        )
        out.putpalette(dst_pal[: 3 * 256])

        return out
