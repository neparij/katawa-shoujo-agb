# Copyright 2022  Michael Davidsaver
# SPDX-License-Identifier: BSD
# See LICENSE
import sys
import os
import re

from collections import defaultdict
from importlib import import_module # say that three times fast...
from multiprocessing import Pool
import multiprocessing as MP
import logging as log

try:
    from wheel.bdist_wheel import bdist_wheel as _bdist_wheel
except ImportError:
    _bdist_wheel = None

from setuptools import Command, Distribution, Extension as _Extension
from setuptools.command.build_ext import build_ext as _build_ext
from setuptools.command.install import install as _install
from setuptools.command.bdist_egg import bdist_egg as _bdist_egg

try:
    # Allows for 3.12 support
    from setuptools.command.build import build as _build
    from setuptools.modified import newer_group
except ImportError:
    from distutils.command.build import build as _build
    from distutils.dep_util import newer_group

from .compiler import new_compiler

__all__ = (
    'DSO',
    'Extension',
    'build_dso',
    'build_ext',
    'bdist_egg',
    'install',
)

Distribution.x_dsos = None

if sys.version_info<(3,4) or MP.get_start_method()!='fork':
    # bypass multiprocessing optimization (parallel compile)
    # for older py (can't pickle the necessary pieces)
    # freeze_support() is a pain, and is needed by methods other than 'fork'.
    # Contrary to documentation, this is not limited to Windows.
    # https://bugs.python.org/issue32146
    # https://bugs.python.org/issue33725
    class Pool(object):
        def __init__(self, N):
            pass
        def __enter__(self):
            return self
        def __exit__(self,A,B,C):
            pass
        class DummyJob(object):
            def __init__(self, fn, args, kws):
                self._F = fn, args, kws
            def get(self):
                fn, args, kws = self._F
                return fn(*args, **kws)
        def apply_async(self, fn, args, kws):
            return self.DummyJob(fn, args, kws)

def _system_concurrency():
    if 'NUM_JOBS' in os.environ: # because it is so very cumbersome to pass extra build args through pip and setuptools ...
        # we trust that our user knows what is being requested...
        return int(os.environ['NUM_JOBS'])

    # from this point, fail softly

    # find available CPU concurrency
    if hasattr(os, 'cpu_count'): # py3
        njobs = os.cpu_count()
    else:
        njobs = 2 # why not?

    # estimate available memory concurrency.  (lots of swapping erases any benefit of parallel compile)
    nmem = njobs
    if os.path.isfile('/proc/meminfo'): # Linux
        meminfo={}
        units = {
            'kB': 1024,
            None: 1,
        }
        # lines like:
        #   MemTotal:       15951564 kB
        #   HugePages_Total:       0
        pat = re.compile(r'([^:]+):\s*([0-9]+)\s*(\S+)?')
        with open('/proc/meminfo', 'r') as F:
            for L in F:
                M = pat.match(L)
                if M is not None:
                    name, val, unit = M.groups()
                    meminfo[name] = float(val)*units[unit]
                # else: # ignore unknown lines

        avail_phy = meminfo.get('MemAvailable') # physical unused and disk cache
        if avail_phy:
            # Estimated peak physical RAM usage for a single GCC run.
            # Measured max RSS for a single GCC run when compiling epics-base circa 7.0.7 is ~130 MB.
            job_max_mem = 128 * 2**20
            # Arbitrarily multiply because I don't have confidence in the generality of this measurement.
            job_max_mem *= 4

            nmem = int(avail_phy / job_max_mem)

    njobs = max(1, min(njobs, nmem))

    return njobs


def system_concurrency():
    """Estimate the number of concurrent compile jobs this system can perform.
    
    Tries to use both available CPU and memory resource information.
    """
    try:
        return _system_concurrency()
    except Exception as e: # fail softly with a pessimistic estimate
        log.warning('Warning: Unable to estimate system concurrency, default to sequential build: %r'%e)
        return 1

def massage_dir_list(bdirs, indirs):
    """Process a list of directories for use with -I or -L
    For relative paths, also include paths relative to a build directory
    """
    indirs = indirs or []
    dirs = indirs[:]

    for bdir in bdirs:
        dirs.extend([os.path.join(bdir, D) for D in indirs if not os.path.isabs(D)])
        if os.name == 'nt':
            bdir = os.path.dirname(bdir) # strip /Release or /Debug
            dirs.extend([os.path.join(bdir, D) for D in indirs if not os.path.isabs(D)])

    return list(filter(os.path.isdir, dirs))

def expand_sources(cmd, sources):
    for i,src in enumerate(sources):
        if os.path.exists(src):
            continue
        cand = os.path.join(cmd.build_temp, src)
        if os.path.exists(cand):
            sources[i] = cand
            continue
        if os.name == 'nt':
            cand = os.path.join(os.path.dirname(cmd.build_temp), src) # strip /Release or /Debug
            if os.path.exists(cand):
                sources[i] = cand
                continue
        raise RuntimeError("Missing source file: %s"%src)

class Extension(_Extension):
    """Extension(name, sources, ..., dsos=[DSO(...)])
    Wrapper around setuptools.Extension which accepts a list of :py:class:`DSO` dependencies.

    :param dsos: A list of :py:class:`DSO` s which this Extension will be linked against.
    """
    def __init__(self, name, sources,
                 dsos=None,
                 **kws):
        _Extension.__init__(self, name, sources, **kws)
        self.dsos = dsos or []

class DSO(_Extension):
    """DSO(name, sources, ..., dsos=[DSO(...)], soversion=None)
    A Dynamic Shared Object to be built.
    Accepts the same options as :py:class:`Extension` with additions:

    :param dsos: A list of :py:class:`DSO` s which this DSO will be linked against.
    :param str soversion: None (default) or a string.  On supported targerts, this string
                          which will be appended to create the SONAME.  eg. ``soversion="0"``
                          will turn ``libfoo.so`` into ``libfoo.so.0``.
    :param dict lang_compile_args: Language specific ("c" or "c++") compiler flags.
                                   eg. ``{'c':['-DMAGIC']}``
    :param str gen_info: Controls generation of "info" module.
                         True (default) uses the conventional filename,
                         False disables generation,
                         or a specific filename string.
    """
    def __init__(self, name, sources,
                 soversion=None,
                 lang_compile_args=None,
                 dsos=None,
                 gen_info=True,
                 **kws):
        _Extension.__init__(self, name, sources, **kws)
        self.lang_compile_args = lang_compile_args or {}
        self.soversion = soversion or None
        self.dsos = dsos or []
        self.gen_info = gen_info

class dso2libmixin:
    def __add_ext_candidates(self, parts, dsosearch):
        parts = parts[:-1] # exclude DSO name
        try:
            # Checking if this DSO lives in an external package.
            # Find full path names of directories which may contain DSO file.
            # To accomidate namespace packages, search for DSO 'foo.bar.baz.mydso'
            # in modules: 'foo', 'foo.bar', then 'foo.bar.baz'
            # eg. if 'foo.bar' is '/some/python/bar/__init__.py'
            #     then look for DSO in '/some/python/bar/baz'
            for i in range(1, len(parts)):
                mparts, fparts = parts[:i], parts[i:]
                # PEP420 states that a namespace module "Does not have a __file__ attribute"
                # However, cpython after 3.6 has __file__=None.
                basepackage = getattr(import_module(".".join(mparts)), "__file__", None)
                if basepackage:
                    # found actual (not namespace) module
                    dsobase = os.path.dirname(basepackage) # exclude __init__.py file
                    dsodir = os.path.join(dsobase, *fparts) # append directories within top package
                    dsosearch.append(dsodir)
                    break
            else:
                log.debug("No external candidates for %s"%parts)
        except ImportError as e:
            log.debug("Error finding external candidates for %s: %s"%(parts, e))

    def dso2lib_pre(self, ext):
        # ext may be our Extension or DSO
        mypath = os.path.join('.', *ext.name.split('.')[:-1])

        soargs = set()
        solibs = []
        sodirs = []

        for dso in getattr(ext, 'dsos', []):
            log.debug("Will link against DSO %s"%dso)

            parts = dso.split('.')
            dsopath = os.path.join('.', *parts[:-1])
            if sys.platform == "win32":
                libname = parts[-1]+'.dll'
            elif sys.platform == 'darwin':
                libname = 'lib%s.dylib'%parts[-1] # find the plain version first.
            else:
                libname = 'lib%s.so'%parts[-1]

            dsosearch = [os.path.join(self.build_lib, *parts[:-1])] # maybe we just built it

            self.__add_ext_candidates(parts, dsosearch)

            for candidate in dsosearch:
                C = os.path.join(candidate, libname)
                if not os.path.isfile(C):
                    log.debug("  Not %s"%C)
                else:
                    log.debug("  Found %s"%C)
                    sodirs.append(candidate)
                    break
            else:
                raise RuntimeError("Unable to find DSO %s needed by extension %s in %s"%(dso, ext.name, dsosearch))

            solibs.append(parts[-1])

            if sys.platform=='win32':
                pass # nothing line -rpath available

            elif sys.platform=='darwin':
                soargs.add('-Wl,-rpath,@loader_path/%s' % os.path.relpath(dsopath, mypath))

            else:
                # Some versions of GCC will expand shell macros _internally_ when
                # passing arguments to 'ld', and need '\$ORIGIN'.  And some versions don't,
                # and fail with '\$ORIGIN'.
                # Presumably this was a bug in gcc-wrapper which was fixed at some point.
                #
                # So what to do?
                # For lack of a better idea, give both versions and hope that the non-functional
                # one is really non-functional.
                soargs.add('-Wl,-rpath,$ORIGIN/%s'%os.path.relpath(dsopath, mypath))
                soargs.add(r'-Wl,-rpath,\$ORIGIN/%s'%os.path.relpath(dsopath, mypath))

        # Do not append to extisting list as it may be shared
        # between multiple extensions
        ext.libraries = ext.libraries + solibs
        ext.library_dirs = ext.library_dirs + sodirs
        ext.extra_link_args = ext.extra_link_args + list(soargs)                
        
    def dso2lib_post(self, ext_path):
        if sys.platform == 'darwin':
            self.spawn(['otool', '-L', ext_path])

class build_dso(dso2libmixin, Command):
    description = "Build Dynamic Shared Object (DSO).  non-python dynamic libraries (.so, .dylib, or .dll)"

    user_options = [
        ('build-lib=', 'b',
         "directory for compiled extension modules"),
        ('build-temp=', 't',
         "directory for temporary files (build by-products)"),
        ('inplace', 'i',
         "ignore build-lib and put libraries into the source " +
         "directory alongside your pure Python modules"),
        ('force', 'f',
         "forcibly build everything (ignore file timestamps)"),
    ]

    boolean_options = ['inplace', 'force']

    # eg. allow injection of extra work (eg. code generation)
    # before DSOs are built
    sub_commands = []

    def initialize_options (self):
        self.dsos = None

        self.build_lib = None
        self.build_temp = None
        self.inplace = None
        self.force = None

    def finalize_options(self):

        self.set_undefined_options('build_ext',
                                   ('build_lib', 'build_lib'),
                                   ('build_temp', 'build_temp'),
                                   ('inplace', 'inplace'),
                                   ('force', 'force'),
                                   )

        self.dsos = self.distribution.x_dsos

    def run(self):
        for cmd_name in self.get_sub_commands():
            self.run_command(cmd_name)

        if self.dsos is None:
            log.debug("No DSOs to build")
            return

        elif callable(self.dsos):
            # allow dynamic/lazy population of the DSOs list
            # pass this Command to allow access to build_* locations and self.distribution
            self.dsos = self.dsos(self)

        log.info("Building DSOs")

        self.compiler = new_compiler(#compiler=self.compiler,
                                     verbose=self.verbose,
                                     dry_run=self.dry_run,
                                     force=self.force)

        # fixup for MAC to build dylib (MH_DYLIB) instead of bundle (MH_BUNDLE)
        if sys.platform == 'darwin':
            for attr in ('linker_so', 'linker_so_cxx'):
                linker_so = getattr(self.compiler, attr, [])
                for i,val in enumerate(linker_so):
                    if val=='-bundle':
                        linker_so[i] = '-dynamiclib'

        for dso in self.dsos:
            self.build_dso(dso)
            self.gen_info_module(dso)

    def _name2file(self, dso, so=False):
        """Translate DSO name (eg. "pkg.mod.mylib" into
        "pkg/mod/mylib.so" or (if so==True) "pkg/mod/mylib.so.0"
        """
        parts = dso.name.split('.')

        parts[-1] = self._name2libname(dso, so)

        return os.path.join(*parts)

    def _name2libname(self, dso, so=False):
        """
        Translate DSO name to library name

        For example, DSO "mylib" on Linux would return "libmylib.so".
        """
        parts = dso.name.split('.')

        if sys.platform == "win32":
            return parts[-1]+'.dll'

        elif sys.platform == 'darwin':
            if so and dso.soversion is not None:
                return 'lib%s.%s.dylib'%(parts[-1], dso.soversion)
            else:
                return 'lib%s.dylib'%(parts[-1],)

        else: # ELF
            if so and dso.soversion is not None:
                return 'lib%s.so.%s'%(parts[-1], dso.soversion)
            else:
                return 'lib%s.so'%(parts[-1],)

    def build_dso(self, dso):
        # dso is an instance of DSO
        self.dso2lib_pre(dso)
        expand_sources(self, dso.sources)
        expand_sources(self, dso.depends)

        baselib = self._name2file(dso)        # eg. "pkg/mod/mylib.so"
        solib = self._name2file(dso, so=True) # eg. "pkg/mod/mylib.so.0"
        # on windows always baselib==solib

        # prepend staging area path
        outbaselib = os.path.join(self.build_lib, baselib)
        outlib = os.path.join(self.build_lib, solib)
        sources = list(dso.sources)

        depends = sources + dso.depends
        if not (self.force or newer_group(depends, outlib, 'newer')):
            log.debug("skipping '%s' DSO (up-to-date)", dso.name)
            return
        else:
            log.info("building '%s' DSO as %s", dso.name, outlib)

        macros = dso.define_macros[:]
        for undef in dso.undef_macros:
            macros.append((undef,))

        extra_args = dso.extra_compile_args or []

        include_dirs = massage_dir_list([self.build_temp, self.build_lib], dso.include_dirs or [])

        SRC = defaultdict(list)

        # sort by language
        for src in sources:
            SRC[self.compiler.language_map[os.path.splitext(src)[-1]]].append(src)

        # do the actual compiling
        objects = []

        nworkers = system_concurrency()
        log.info('effective NUM_JOBS=%d'%nworkers)
        with Pool(nworkers) as P:
            jobs = []
            for lang, srcs in SRC.items():

                # submit jobs
                # allocate every n-th object to the n-th worker.
                # Load not well balanced, but easy to do.
                for inputs in [srcs[n::nworkers] for n in range(nworkers)]:
                    jobs.append(P.apply_async(self.compiler.compile, [inputs], {
                        'output_dir':self.build_temp,
                        'macros':macros,
                        'include_dirs':include_dirs,
                        'extra_postargs':extra_args + (dso.lang_compile_args.get(lang) or []),
                        'depends':dso.depends,
                    }))

            # work for completion
            [objects.extend(job.get()) for job in jobs]

        library_dirs = massage_dir_list([self.build_lib], dso.library_dirs or [])

        # the Darwin linker errors if given non-existant -L directories :(
        [self.mkpath(D) for D in library_dirs]

        if dso.extra_objects:
            objects.extend(dso.extra_objects)

        extra_args = dso.extra_link_args or []
        solibbase = os.path.basename(solib) # eg. "mylib.so.0"

        if sys.platform == 'darwin':
            # we always want to produce relocatable (movable) binaries
            # this install_name will be replaced below (cf. 'install_name_tool')
            extra_args.extend(['-install_name', '@rpath/%s'%solibbase])

        elif sys.platform == "win32":
            # The .lib is considered "temporary" for extensions, but not for us
            # so we pass export_symbols=None and put it along side the .dll
            # eg. "pkg\mod\mylib.dll" and "pkg\mod\mylib.lib"
            outlib_lib = '%s.lib' % os.path.splitext(outlib)[0]
            outlib_exp = '%s.exp' % os.path.splitext(outlib)[0]
            extra_args.append('/IMPLIB:%s'%outlib_lib)

        elif baselib!=solib: # ELF
            extra_args.extend(['-Wl,-h,%s'%solibbase])

        language = dso.language or self.compiler.detect_language(sources)

        self.compiler.link_shared_object(
            objects, outlib,
            libraries=dso.libraries,
            library_dirs=library_dirs,
            runtime_library_dirs=dso.runtime_library_dirs,
            extra_postargs=extra_args,
            export_symbols=None,
            #debug=self.debug,
            build_temp=self.build_temp,
            target_lang=language)

        self.dso2lib_post(outlib)

        if baselib!=solib:
            # we make best effort here, even though zipfiles (.whl or .egg) will contain copies
            log.info("symlink %s <- %s", solibbase, outbaselib)
            if not self.dry_run:
                if os.path.exists(outbaselib):
                    os.unlink(outbaselib)
                os.symlink(solibbase, outbaselib)
            #self.copy_file(outlib, outbaselib) # link="sym" seem to get the target path wrong

        if self.inplace:
            build_py = self.get_finalized_command('build_py')
            pkg = '.'.join(dso.name.split('.')[:-1])    # path.to.dso -> path.to
            pkgdir = build_py.get_package_dir(pkg)      # path.to -> src/path/to

            def inplace_dst(path): # build/.../path/to/dso.so -> src/path/to/dso.so
                return os.path.join(pkgdir, os.path.basename(path))

            self.mkpath(os.path.dirname(inplace_dst(outlib)))
            self.copy_file(outlib, inplace_dst(outlib))
            if baselib!=solib:
                self.copy_file(outbaselib, inplace_dst(outbaselib))
            if sys.platform == "win32":
                # on windows linking to x.dll goes through x.lib and x.exp first
                self.copy_file(outlib_lib, inplace_dst(outlib_lib))
                self.copy_file(outlib_exp, inplace_dst(outlib_exp))

    def gen_info_module(self, dso):
        if not dso.gen_info:
            log.debug("skiping creation of info module")
            return

        parts = dso.name.split(".")
        infoparts = parts[:-1]
        if dso.gen_info is True:
            infoparts.append(parts[-1]+"_dsoinfo.py")
        else:
            infoparts.append(dso.gen_info)

        info_module_filename = os.path.join(self.build_lib, *infoparts)

        log.info(
            "creating info module for {dso_name} at {filename}".format(
                dso_name=dso.name, filename=info_module_filename
            )
        )

        if not self.dry_run:
            import textwrap

            with open(info_module_filename, "w") as file:
                file.write(
                    textwrap.dedent(
                        """
                    # generated by setuptools_dso
                    import os

                    dsoname = {dso.name!r}
                    libname = {libname!r}
                    soname = {soname!r}
                    depends = {dso.dsos!r}
                    dir = os.path.dirname(__file__)
                    filename = os.path.join(dir, libname)
                    sofilename = os.path.join(dir, soname)
                    del dir
                    del os
                    __all__ = ("dsoname", "libname", "soname", "filename", "sofilename")
                    """
                    ).format(dso=dso,
                             libname=self._name2libname(dso),
                             soname=self._name2libname(dso, so=True))
                )

        if self.inplace:
            build_py = self.get_finalized_command("build_py")
            pkg = ".".join(parts[:-1])  # path.to.dso -> path.to
            pkgdir = build_py.get_package_dir(pkg)  # path.to -> src/path/to

            info_module_dest = os.path.join(
                pkgdir, os.path.basename(info_module_filename)
            )

            self.mkpath(os.path.dirname(info_module_dest))
            self.copy_file(info_module_filename, info_module_dest)


class build_ext(dso2libmixin, _build_ext):

    # allow build_ext to depend on other commands
    sub_commands = _build_ext.sub_commands[:]

    def finalize_options(self):
        _build_ext.finalize_options(self)

        self.include_dirs = massage_dir_list([self.build_temp], self.include_dirs or [])
        self.library_dirs = massage_dir_list([self.build_lib]  , self.library_dirs or [])

        self._propagate_inplace()

    def _propagate_inplace(self):
        # Hack inspired from https://github.com/pypa/setuptools/blob/8ad627dfd580ac9cad2fd9c3a51dc173c5a38eca/setuptools/command/editable_wheel.py#L239
        if self.inplace:
            dist = self.distribution
            for cmd_name in self.get_sub_commands():
                cmd = dist.get_command_obj(cmd_name)
                if hasattr(cmd, "inplace"):
                    cmd.inplace = True

    def run(self):
        # original setuptools/distutils don't call sub_commands for build_ext
        for cmd_name in self.get_sub_commands():
            self.run_command(cmd_name)

        # the Darwin linker errors if given non-existant directories :(
        [self.mkpath(D) for D in self.library_dirs]
        _build_ext.run(self)

    def build_extension(self, ext):
        expand_sources(self, ext.sources)
        expand_sources(self, ext.depends)

        ext.include_dirs = massage_dir_list([self.build_temp], ext.include_dirs or [])
        ext.library_dirs = massage_dir_list([self.build_lib]  , ext.library_dirs or [])

        ext.extra_link_args = ext.extra_link_args or []

        self.dso2lib_pre(ext)

        # the Darwin linker errors if given non-existant directories :(
        [self.mkpath(D) for D in ext.library_dirs]

        _build_ext.build_extension(self, ext)

        self.dso2lib_post(self.get_ext_fullpath(ext.name))

# hack...
# setuptools/distutils decides to treat build as a "purelib" vs. "platlib"
# by testing 'dist.ext_modules' (not call 'dist.has_ext_modules()' mind you...)
# So we can't simply patch has_ext_modules() to also check for DSOs.
#
# Otherwise a package contains DSOs, but not Extensions, would incorrectly
# be treated as "purelib".
class build(_build):
    def finalize_options(self):
        _build.finalize_options(self)
        if self.distribution.x_dsos:
            self.build_lib = self.build_platlib

class install(_install):
    def finalize_options(self):
        _install.finalize_options(self)
        if self.distribution.x_dsos:
            self.install_lib = self.install_platlib


if _bdist_wheel:
    class bdist_wheel(_bdist_wheel):
        """Since 'auditwheel' doesn't understand the idea of non-python libraries in the python tree,
           we provide an alternate way to handling changing the platform tag on Linux by environment
           variable.  eg.

           $ SETUPTOOLS_DSO_PLAT_NAME=manylinux2014_x86_64 pip install .
        """

        def finalize_options(self):
            _bdist_wheel.finalize_options(self)
            # wheels with DSO are not "pure" python
            self.root_is_pure &= not has_dsos(self)

        def get_tag(self):
            impl, abi_tag, plat_name = _bdist_wheel.get_tag(self)
            log.info('Original Wheel Tag: %s, %s, %s'%(impl, abi_tag, plat_name))

            # So far PIP doesn't clear the environment for sandbox builds...
            # allow mangling of platform name.  eg. 'linux_x86_64' -> 'manylinux1_x86_64'
            new_plat_name = os.environ.get('SETUPTOOLS_DSO_PLAT_NAME', '')
            if new_plat_name:
                plat_name = new_plat_name

            return (impl, abi_tag, plat_name)

# Rant:
#   Arranging for 'build_dso' to be run is seriously annoying!
#
#   distutils presents such a simple idea.  We just add 'build_dso' to build.sub_commands.
#   'install' will first run 'build', and we're done for everything except 'bdist_egg'.
#
#   Enter setuptools...  setuptools decides to automagically alias 'install' as 'bdist_egg'.
#   Seriously 'magic', it's inspecting the strack frames...
#
#   'bdist_egg' is a special little snowflake (aka. total hack) which doesn't run 'build'
#   or 'install' (fuck!), but does it's own thing by piecemeal calling
#   eg. 'egg_info', 'build_clib' (conditionally), 'install_lib'.
#
# so what to do...
#
# 1. insert 'build_dso' before 'build_clib' in the 'build' sequence.
#    This handles everything except 'bdist_egg' (aka. 'setup.py install')...
#
# 2. override 'bdist_egg' to run 'build_dso' at an appropriate point.

def has_dsos(cmd):
    x_dsos = getattr(cmd.distribution, 'x_dsos', None)
    return callable(x_dsos) or len(x_dsos or [])>0

class bdist_egg(_bdist_egg):
    # An ugly hack on top of an ugly hack...
    #
    # we can't hook into 'egg_info' unconditionally, as other targets like 'sdist'
    # don't want to build things...
    # so instead we hook in and run 'build_dso' just after 'egg_info'.
    def run_command(self, cmd):
        _bdist_egg.run_command(self, cmd)
        if cmd=='egg_info' and has_dsos(self):
            self.run_command('build_dso')

# _needs_builddso marks distutils/setuptools command to depend on build_dso.
#
# if right_before is specified build_dso is injected before that command
# instead of as first dependency.
def _needs_builddso(command, right_before=None):
    assert issubclass(command, Command)
    # copy to avoid changing base class if sub_commands was just inherited
    _ = command.sub_commands[:]
    where = 0
    if right_before is not None:
        for i,(name,_test) in enumerate(_):
            if name == right_before:
                where = i
                break
        else:
            raise AssertionError("command %r does not have %r subcommand" % (command, right_before))
    _.insert(where, ('build_dso', has_dsos))
    command.sub_commands = _

_needs_builddso(_build, right_before='build_clib')


# depend build_ext: build_dso, for DSOs to be automatically built on
# `setup.py develop` (= `pip install -e`).
#
# `setup.py develop` does not call build and instead calls `build_ext -i`
# directly without providing any kind of sub_commands support.
#
# -> so we hook into build_ext to make sure build_dso is also called.
_needs_builddso(build_ext)
