# Copyright 2022  Michael Davidsaver
# SPDX-License-Identifier: BSD
# See LICENSE

from __future__ import print_function

from collections import OrderedDict
from itertools import chain
import re
import os
import shutil
import logging as log

import tempfile
try:
    from tempfile import TemporaryDirectory
except ImportError:
    class TemporaryDirectory(object):
        def __init__(self):
            self.name = tempfile.mkdtemp()
        def __del__(self):
            self.cleanup()
        def __enter__(self):
            return self.name
        def __exit__(self,A,B,C):
            self.cleanup()
        def cleanup(self):
            if self.name is not None:
                shutil.rmtree(self.name, ignore_errors=True)
                self.name = None

try:
    from setuptools.errors import ExecError, CompileError
except ImportError:
    from distutils.errors import DistutilsExecError as ExecError
    from distutils.errors import CompileError

from .compiler import new_compiler

__all__ = (
    'ProbeToolchain',
)

class ProbeToolchain(object):
    """Inspection of compiler

    :param bool verbose: If True, enable additional prints
    :param str compiler: If not None, select non-default compiler toolchain
    :param list headers: List of headers to include during all test compilations
    :param list define_macros: List of (macro, value) tuples to define during all test compilations
    """
    def __init__(self, verbose=False,
                 compiler=None,
                 headers=None, define_macros=None):
        self.verbose = verbose
        self.headers = list(headers or [])
        self.define_macros = list(define_macros or [])
        self._info = None

        self.compiler = new_compiler(compiler=compiler,
                                     verbose=self.verbose,
                                     dry_run=False,
                                     force=True)
        # TODO: quiet compile errors?

        # clang '-flto' produces LLVM bytecode instead of ELF object files.
        # LLVM has a funny encoding for string constants which is hard to
        # parse for sizeof() detecton.  So we omit '-flto' for test compiles
        for name in ('compiler', 'compiler_so', 'compiler_cxx') + ('compile_options', 'compile_options_debug'):
            ccmd = getattr(self.compiler, name, None)
            if ccmd is not None:
                ccmd = [arg for arg in ccmd if arg!='-flto']
                setattr(self.compiler, name, ccmd)

        self._tdir = TemporaryDirectory()
        self.tempdir = self._tdir.name

    def _source_name(self, basename, language='c', **kws):
        for ext, lang in self.compiler.language_map.items():
            if lang==language:
                return basename + ext
        else:
            raise ValueError('unknown language '+language)

    def compile(self, src, language='c', define_macros=None, **kws):
        """Compile provided source code and return path to resulting object file

        :returns: Path string to object file in temporary location.
        :param str src: Source code string
        :param str language: Source code language: 'c' or 'c++'
        :param list define_macros: Extra macro definitions.
        :param list include_dirs: Extra directories to search for headers
        :param list extra_preargs: Extra arguments to pass to the compiler
        :param list extra_postargs: Extra arguments to pass to the compiler
        """
        define_macros = self.define_macros + list(define_macros or [])
        srcname = os.path.join(self.tempdir, self._source_name('try_compile', language=language))

        log.debug('/* test compile */\n'+src)
        with open(srcname, 'w') as F:
            F.write(src)

        objs = self.compiler.compile([srcname],
                                    output_dir=self.tempdir,
                                    macros=define_macros,
                                    **kws
                                    )
        assert len(objs)==1, (srcname, objs)

        return objs[0]

    def try_compile(self, src, **kws):
        """Return True if provided source code compiles

        :param str src: Source code string
        :param str language: Source code language: 'c' or 'c++'
        :param list define_macros: Extra macro definitions.
        :param list include_dirs: Extra directories to search for headers
        :param list extra_preargs: Extra arguments to pass to the compiler
        :param list extra_postargs: Extra arguments to pass to the compiler
        """
        try:
            self.compile(src, **kws)
            return True
        except (ExecError, CompileError):
            return False

    def check_includes(self, headers, **kws):
        """Return true if all of the headers may be included (in order)

        :param list headers: List of header file names
        :param str language: Source code language: 'c' or 'c++'
        :param list define_macros: Extra macro definitions.
        :param list include_dirs: Extra directories to search for headers
        :param list extra_preargs: Extra arguments to pass to the compiler
        :param list extra_postargs: Extra arguments to pass to the compiler
        """
        src = ['#include <%s>'%h for h in self.headers+list(headers)]

        ret = self.try_compile('\n'.join(src), **kws)
        log.info('Probe includes %s -> %s', headers, 'Present' if ret else 'Absent')
        return ret

    def check_include(self, header, **kws):
        """Return true if the header may be included

        :param str header: Header file name
        :param str language: Source code language: 'c' or 'c++'
        :param list define_macros: Extra macro definitions.
        :param list include_dirs: Extra directories to search for headers
        :param list extra_preargs: Extra arguments to pass to the compiler
        :param list extra_postargs: Extra arguments to pass to the compiler
        """
        return self.check_includes([header], **kws)

    def sizeof(self, typename, headers=None, **kws):
        """Return size in bytes of provided typename

        :param str typename: Header file name
        :param list headers: List of headers to include during all test compilations
        :param str language: Source code language: 'c' or 'c++'
        :param list define_macros: Extra macro definitions.
        :param list include_dirs: Extra directories to search for headers
        :param list extra_preargs: Extra arguments to pass to the compiler
        :param list extra_postargs: Extra arguments to pass to the compiler
        """
        # borrow a trick from CMake.  see Modules/CheckTypeSize.c.in
        src = ['#include <%s>'%h for h in self.headers+list(headers or ())]
        src += [
            '#define PROBESIZE (sizeof(%s))'%typename,
            "char probe_info[] = {'P','R','O','B','E','I','N','F','O','[',"
            "  ('0'+((PROBESIZE/10000)%10)),"
            "  ('0'+((PROBESIZE/1000)%10)),"
            "  ('0'+((PROBESIZE/100)%10)),"
            "  ('0'+((PROBESIZE/10)%10)),"
            "  ('0'+((PROBESIZE/1)%10)),"
            "']'};",
            ""
        ]

        obj = self.compile('\n'.join(src), **kws)

        with open(obj, 'rb') as F:
            raw = F.read()

        if raw.find(b'\x01\x01\x01P\x01\x01\x01R\x01\x01\x01O\x01\x01\x01B\x01\x01\x01E\x01\x01\x01I\x01\x01\x01N\x01\x01\x01F\x01\x01\x01O')!=-1:
            # MSVC
            raw = raw.replace(b'\x01\x01\x01', b'')

        M = re.match(b'.*PROBEINFO\\[(\\d+)\\].*', raw, re.DOTALL)
        if M is None:
            print(repr(raw))
            raise RuntimeError('Unable to find PROBEINFO for %s'%typename)

        size = int(M.group(1))
        log.info('Probe sizeof(%s) = %d', typename, size)

        return size

    def check_symbol(self, symname, headers=None, **kws):
        """Return True if symbol name (macro, variable, or function) is defined/delcared

        :param str symname: Symbol name
        :param list headers: List of headers to include during all test compilations
        :param str language: Source code language: 'c' or 'c++'
        :param list define_macros: Extra macro definitions.
        :param list include_dirs: Extra directories to search for headers
        :param list extra_preargs: Extra arguments to pass to the compiler
        :param list extra_postargs: Extra arguments to pass to the compiler
        """
        src = ['#include <%s>'%h for h in self.headers+list(headers or ())]
        src += [
            'void* probe_symbol(void) {',
            '#if defined(%s)'%symname,
            '  return 0;',
            '#else',
            '  return (void*)&%s;'%symname,
            '#endif',
            '}',
            ''
        ]

        ret = self.try_compile('\n'.join(src), **kws)
        log.info('Probe Symbol %s -> %s', symname, 'Present' if ret else 'Absent')
        return ret

    def check_member(self, struct, member, headers=None, **kws):
        """Return True if the given structure has the named member

        :param str struct: Structure name
        :param str member: Member name
        :param list headers: List of headers to include during all test compilations
        :param str language: Source code language: 'c' or 'c++'
        :param list define_macros: Extra macro definitions.
        :param list include_dirs: Extra directories to search for headers
        :param list extra_preargs: Extra arguments to pass to the compiler
        :param list extra_postargs: Extra arguments to pass to the compiler
        """
        src = ['#include <%s>'%h for h in self.headers+list(headers or ())]
        src += [
            'int probe_member(void) {',
            '  return (int)sizeof( ((%s *)0)->%s); '%(struct, member),
            '}',
            ''
        ]

        ret = self.try_compile('\n'.join(src), **kws)
        log.info('Probe Member %s::%s -> %s', struct, member, 'Present' if ret else 'Absent')
        return ret

    def eval_macros(self, macros, headers=None, define_macros=None, language='c', **kws):
        """Expand C/C++ preprocessor macros.

        For undefined macros, None is returned.
        For defined macros a string is returned.
        When evaluating multiple macros, the order of the macros argument is preserved
        in the OrderedDict which is returned.

        :returns: An OrderedDict mapping to string (if defined) or None (if not defined)
        :param str|list macros: A macro name string, or a list of such strings
        :param list headers: List of headers to include during all test compilations
        :param list define_macros: Extra macro definitions.
        :param str language: Source code language: 'c' or 'c++'  (Added in 2.9)
        :param list include_dirs: Extra directories to search for headers
        :param list extra_preargs: Extra arguments to pass to the compiler
        :param list extra_postargs: Extra arguments to pass to the compiler
        """
        if isinstance(macros, str):
            macros = [macros]

        srcname = os.path.join(self.tempdir, self._source_name('eval_macros_in', language=language, **kws))
        outname = os.path.join(self.tempdir, self._source_name('eval_macros_out', language=language, **kws))

        define_macros = self.define_macros + list(define_macros or [])
        src = ['#include <%s>'%h for h in self.headers+list(headers or ())]

        for macro in macros:
            src.append('''
#if defined({macro})
void D_{macro} = |||{macro}|||; void X_{macro};
#else
void U_{macro} = ||||||; void X_{macro};
#endif /* {macro} */
'''.format(macro=macro))

        src = '\n'.join(src)

        with open(srcname, 'w') as F:
            F.write(src)

        self.compiler.preprocess(srcname, outname, macros=define_macros, **kws)

        with open(outname, 'r') as F:
            out = F.read()

        # Various pre-processor implementations are inconsistent about
        # what "debris" is emitted in the output.
        # eg. GCC strips C/C++ comments, while MSVC leaves them in.

        # remove pre-processor directive lines
        out = re.sub(r'^\s*#[^\n\r]*$', '', out, 0, re.MULTILINE)
        # remove c++ line comments
        out = re.sub(r'^//[^\n\r]*$', '', out, 0, re.MULTILINE)
        # remove C comments
        out = re.sub(r'/\*.*?\*/', '', out, 0, re.MULTILINE|re.DOTALL)

        defs = OrderedDict()

        for name in macros:
            pat = r'.*void ([DU])_%(name)s = \|\|\|(.*?)\|\|\|; void X_%(name)s;.*'%{'name':name}
            M = re.match(pat, out, re.MULTILINE|re.DOTALL)
            if M is None:
                raise RuntimeError("In %r\nFailed to find match for %r using %r"%(out, name, pat))
            du, val = M.groups()
            if du=='D':
                defs[name] = val.strip()
            elif du=='U':
                defs[name] = None
            else:
                raise ValueError("Logic error {0!r} : {1!r}".format(M, M.groups()) )

        return defs

    @property
    def info(self):
        """Inspect toolchain

        :returns: A :py:class:`probe.ToolchainInfo`
        """
        if self._info is None:
            self._info = ToolchainInfo(self)

        return self._info

class ToolchainInfo(object):
    """Information about a compiler toolchain
    """

    compiler_type = None
    """Directly copied from :py:class:`distutils.ccompiler.CCompiler.compiler_type`

    Known values include: 'bcpp', 'cygwin', 'mingw', 'msvc', 'unix'
    """

    compiler = None
    """Compiler implementation name

    Possible values; 'clang', 'gcc', 'msvc'
    """

    compiler_version = None
    """Compiler release version as a tuple of integers suitible for comparison

    eg. for GCC: (4,9,2), clang: (11,0,1), msvc: (19,0,24245)
    """

    gnuish = False
    """True when compiler is clang or gcc
    """

    target_os = None
    """Target OS runtime environment

    Known values: "cygwin", "linux", "osx", "windows"
    """

    target_arch = None
    """Target CPU architecture

    Known values: "aarch64", "arm32", "amd64", "i386"
    """

    address_width = 0
    """Width in bits of a virtual address.  aka. 8*sizeof(void*)

    Known values: 32, 64
    """

    endian = None
    """Target byte order for multi-byte values

    Known values: "little", "big"
    """

    # cf.
    #  https://sourceforge.net/p/predef/wiki/Home/
    #  https://docs.microsoft.com/en-us/cpp/preprocessor/predefined-macros

    __macros = [
        # compiler ID
        '__clang__',
        '__clang_major__',
        '__clang_minor__',
        '__clang_patchlevel__',
        '__GNUC__',
        '__GNUC_MINOR__',
        '__GNUC_PATCHLEVEL__',
        '_MSC_VER',
        '_MSC_FULL_VER',
    ]

    __info = {
        'target_os':[
            ('__APPLE__', 'osx'),
            ('__CYGWIN__', 'cygwin'),
            ('__linux__', 'linux'),
            ('_WIN32', 'windows'),
        ],
        'target_arch':[
            # GCC/clang
            ('__aarch64__', 'aarch64'),
            ('__arm__', 'arm32'),
            ('__x86_64__', 'amd64'),
            ('__i386__', 'i386'),
            # MSVC
            ('_M_ARM', 'arm32'),
            ('_M_ARM64','arm64'),
            ('_M_AMD64','amd64'),
            ('_M_X64','amd64'),
            ('_M_IX86','i386'),
        ],
        'endian':[
            ('_WIN32','little'),
            ('__x86_64__', 'little'),
            ('__i386__', 'little'),
            ('__ARMEB__', 'big'),
            ('__ARMEL__', 'little'),
            ('__AARCH64EB__', 'big'),
            ('__AARCH64EL__', 'little'),
        ],
    }

    def __init__(self, TC):
        self.compiler_type = TC.compiler.compiler_type

        macros = self.__macros + [macro for macro,_value in chain(*[x for x in self.__info.values()])]

        self._raw_macros = D = TC.eval_macros(macros)

        # special handler for compiler version
        if D['__clang__'] is not None:
            self.compiler = 'clang'
            self.compiler_version = tuple(int(D[comp]) for comp in ('__clang_major__',
                '__clang_minor__',
                '__clang_patchlevel__'))
            self.gnuish = True

        elif D['__GNUC__'] is not None:
            self.compiler = 'gcc'
            self.compiler_version = tuple(int(D[comp]) for comp in ('__GNUC__',
                '__GNUC_MINOR__',
                '__GNUC_PATCHLEVEL__'))
            self.gnuish = True

        elif D['_MSC_VER'] is not None:
            self.compiler = 'msvc'
            # eg. "190024245" -> (19, 00, 24245)
            FV = D['_MSC_FULL_VER']
            self.compiler_version = tuple(int(p) for p in (FV[:2], FV[2:4], FV[4:]))

        else:
            log.warning("Warning: unable to classify compiler")

        for attr, info in self.__info.items():
            for macro, val in info:
                if D.get(macro) is not None:
                    setattr(self, attr, val)

            if getattr(self, attr) is None:
                log.warning("Warning: unable to classify "+attr)

        self.address_width = 8*TC.sizeof('void*')

    def __repr__(self):
        S = []
        for name in dir(self):
            if name.startswith('_'):
                continue
            V = getattr(self, name)
            if callable(V):
                continue
            S.append('{0}={1!r}'.format(name, V))
        return 'ToolchainInfo({})'.format(', '.join(S))
    __str__ = __repr__

if __name__=='__main__':
    print(ProbeToolchain().info)
