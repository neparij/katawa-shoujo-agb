# Copyright 2022  Michael Davidsaver
# SPDX-License-Identifier: BSD
# See LICENSE

import unittest

from ..dsocmd import _system_concurrency

class TestFindConcur(unittest.TestCase):
    def test_system_concurrency(self):
        njobs = _system_concurrency()
        self.assertGreaterEqual(njobs, 1)
