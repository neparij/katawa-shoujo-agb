# Copyright 2022  Michael Davidsaver
# SPDX-License-Identifier: BSD
# See LICENSE
import os
import unittest

from .. import probe

class TryCompile(unittest.TestCase):
    def setUp(self):
        import logging
        log = logging.Logger(name="test", level=logging.DEBUG)
        self.probe = probe.ProbeToolchain(verbose=True)

    def test_try_compile(self):
        self.assertTrue(self.probe.try_compile('#include <stdlib.h>'))
        self.assertFalse(self.probe.try_compile('intentionally invalid syntax'))

        self.assertTrue(self.probe.check_include('stdlib.h'))
        self.assertFalse(self.probe.check_include('no-such-header.h'))
        self.assertEqual(self.probe.sizeof('short'), 2)
        self.assertTrue(self.probe.check_symbol('RAND_MAX', headers=['stdlib.h']))
        self.assertTrue(self.probe.check_symbol('abort', headers=['stdlib.h']))
        self.assertFalse(self.probe.check_symbol('intentionally_undeclared_symbol', headers=['stdlib.h']))

    def test_macros(self):
        inp = os.path.join(self.probe.tempdir, 'defs.h')
        with open(inp, 'w') as F:
            F.write('''
/* not defined UNDEF */
#define NOVAL
#define MAGIC 42
#define HELLO "hello world"
#define MULTILINE this \
is a test
''')

        defs = self.probe.eval_macros(['UNDEF', 'NOVAL', 'MAGIC', 'HELLO', 'MULTILINE'], headers=[inp])

        # GCC/clang == ' ', msvc == ''
        if defs['NOVAL']=='':
            defs['NOVAL'] = ' '

        self.assertListEqual(list(defs.items()), [
            ('UNDEF', None),
            ('NOVAL', ' '),
            ('MAGIC', '42'),
            ('HELLO', '"hello world"'),
            ('MULTILINE', 'this is a test'),
        ])

    def test_predef(self):
        # self ID for supported compilers
        defs = self.probe.eval_macros(['__GNUC__', '__clang__', '_MSC_VER'])
        self.assertTrue(any(defs.values()), str(defs))

    def test_cxx(self):
        defs = self.probe.eval_macros([
            # ID for known C++ stdlib implementations
            '__GLIBCXX__',     # g++
            '_CPPLIB_VER',     # Dinkumware (aka. MSVC)
            '_LIBCPP_VERSION', # clang
        ], headers=['string'], language='c++')
        self.assertTrue(any(defs.values()), str(defs))

    def test_info(self):
        info = self.probe.info
        print("Raw Macros", info._raw_macros)
        print("Info", info)

        self.assertIn(info.compiler, ('clang', 'gcc', 'msvc'))
        self.assertGreater(info.compiler_version, (0,))
        self.assertIn(info.target_os, ("cygwin", "linux", "osx", "windows"))
        self.assertIn(info.target_arch, ("aarch64", "arm32", "amd64", "i386"))
        self.assertIn(info.address_width, (32, 64))
        self.assertIn(info.endian, ("little", "big"))
