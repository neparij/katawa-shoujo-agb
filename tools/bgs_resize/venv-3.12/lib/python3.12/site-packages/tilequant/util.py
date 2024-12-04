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


Color = tuple[int, int, int]


# noinspection PyTypeChecker
def convert_hex_str_color_to_tuple(h: str) -> Color:
    if h is None:
        return None
    return tuple(int(h[i : i + 2], 16) for i in (0, 2, 4))  # type: ignore


def get_package_dir():
    return os.path.abspath(os.path.dirname(__file__))
