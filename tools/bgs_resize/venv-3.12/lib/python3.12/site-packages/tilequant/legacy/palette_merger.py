# type: ignore
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
import itertools

from ordered_set import OrderedSet
from sortedcollections import ValueSortedDict


class PaletteMerger:
    """
    Class to merge palettes, provides a fast check as class method and a slower check with a higher successrate
    via try_to_merge.
    """

    def __init__(
        self, palettes: list[OrderedSet], num_palettes: int, colors_per_palette: int
    ):
        """
        :param palettes: A list of ordered sets of palettes
        :param palette_relations: A list of lists of possible palettes for tiles
        :param num_palettes: The number of palettes to reduce down to
        :param colors_per_palette: The number of colors per palette
        """
        self.was_run = False
        self._palettes = [p.copy() for p in palettes]
        self._current_number_of_palettes = len(palettes)
        self._num_palettes = num_palettes
        self._colors_per_palette = colors_per_palette
        self._merges_performed: list[tuple[int, int]] = []
        self._count_per_pal = ValueSortedDict(
            {pidx: -len(p) for pidx, p in enumerate(self._palettes)}
        )

    @classmethod
    def try_fast_merge(cls, palettes, colors_per_palette, num_palettes):
        """
        Faster merge check, than regular try_to_merge check,
        that works the list of palettes simply from top to bottom and doesn't check duplicate colors
        """
        full_palettes = 0
        while len(palettes) > 0:
            remove_this_run_indices = []
            p_to_see_if_mergeable = palettes.pop()
            len_this_run = len(p_to_see_if_mergeable)
            for i, p in enumerate(palettes):
                if len(p) + len_this_run <= colors_per_palette:
                    remove_this_run_indices.append(i)
                    len_this_run += len(p)

            palettes = [
                p for i, p in enumerate(palettes) if i not in remove_this_run_indices
            ]
            full_palettes += 1

        return full_palettes < num_palettes

    # PyCharm doesn't really understand the sorted(...) type correctly:
    # noinspection PyTypeChecker, PyUnresolvedReferences
    def try_to_merge(self):
        """
        Perform the merge check by trying to merge palettes combinations that can be used by the most tiles.
        This merge uses unions of the palettes, so merged palettes don't contain duplicate colors, unlike the fast
        check.

        This still doesn't test all possible options, but by sorting by palette color count descending, this
        has a pretty high success rate. And checking all possible cases would just take too much time.

        After calling this method with a return auf True, the method get_merge_operations returns a list of merge
        operations that can be performed to get down to self._num_palettes.
        """
        self.was_run = True
        return self._try_to_merge__recursion()

    def _try_to_merge__recursion(self):
        if self._current_number_of_palettes <= self._num_palettes:
            return True

        # TODO: Creating and iterating a list of all combinations over and over
        #       takes VERY long if no match can be found.
        max_combinations = list(
            itertools.combinations(
                [
                    pal_idx
                    for pal_idx, c in self._count_per_pal.items()
                    if c <= self._colors_per_palette
                ],
                2,
            )
        )

        # Find first combination that can be merged
        for i, pal_pair in enumerate(max_combinations):
            new_colors = self._merge_two_pal(pal_pair)
            len_new_colors = len(new_colors)
            if len_new_colors <= self._colors_per_palette:
                # Merge by merging to pal_pair[0] and setting the reference in 1 to 0.
                self._merges_performed.append(pal_pair)
                self._palettes[pal_pair[0]] = new_colors
                self._count_per_pal[pal_pair[0]] = -len_new_colors
                del self._count_per_pal[pal_pair[1]]
                self._current_number_of_palettes -= 1
                # Recursively start again
                return self._try_to_merge__recursion()
        # Found none, return False
        return False

    def get_merge_operations(self):
        """Can be called after a successful try_to_merge to return a list of palettes to merge (in order)."""
        return self._merges_performed

    def _merge_two_pal(self, pal_pair: tuple[int, int]) -> OrderedSet:
        return self._palettes[pal_pair[0]].union(self._palettes[pal_pair[1]])
