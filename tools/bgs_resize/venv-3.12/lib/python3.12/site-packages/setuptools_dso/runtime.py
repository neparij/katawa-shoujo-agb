# Copyright 2022  Michael Davidsaver
# SPDX-License-Identifier: BSD
# See LICENSE

# Tools for interacting with packages containing DSOs w/ dsoinfo modules
# as built with setuptools_dso >= 2 

from __future__ import print_function

import os
import sys
import logging
import inspect
from importlib import import_module
from collections import OrderedDict

__all__ = (
    'dylink_prepare_dso',
    'find_dso',
    'import_dsoinfo',
)

_log = logging.getLogger(__name__)

# shadow DSO runtime search path to avoid duplication.
# Only effective on windows.
_dso_dirs = set()

def add_dso_directory(path):
    path = os.path.normpath(path)

    # strictly speaking, only needed on windows.
    # we enforce on all targets for consistency.
    if not os.path.isabs(path):
        raise ValueError('DSO search pathes must be absolute: {0!r}'.format(path))

    elif path in _dso_dirs:
        return

    elif hasattr(os, 'add_dll_directory'): # py >= 3.8
        os.add_dll_directory(path)

    elif sys.platform == "win32":
        paths = os.environ.get('PATH', '').split(os.pathsep)
        paths.append(path)
        os.environ['PATH'] = os.pathsep.join(paths)

    _log.debug('Extend DSO search path to {0!r}'.format(path))
    _dso_dirs.add(path)

def _dso2info(dso):
    """Return mangled name of DSO info module.
    
    eg. 'my.pkg.libs.adso' -> 'my.pkg.libs.adso_dsoinfo'
    """
    parts = dso.split('.')
    parts[-1] = '{}_dsoinfo'.format(parts[-1])
    return '.'.join(parts)

def _auto_pkg():
    # look 2 frames down in the call stack
    caller_frame = inspect.stack()[2][0]
    caller_mod = inspect.getmodule(caller_frame)
    return caller_mod.__name__

def import_dsoinfo(dso, package=None):
    """Import and return "info" module for the named DSO.

    :param str dso: DSO name string (eg. 'my.pkg.libs.adso').
    :param str package: Package name to resolve relative imports.  cf. importlib.import_module
    :returns: Info module

    For example, on a ELF target the "info" module for a DSO "mypkg.lib.thelib" would contain the attributes:

    - `.dsoname`    eg. "mypkg.lib.thelib"
    - `.libname`    eg. "thelib.so"
    - `.soname`     eg. "thelib.so.0"
    - `.filename`   eg. "/full/path/to/thelib.so"
    - `.sofilename` eg. "/full/path/to/thelib.so.0"
    """
    if package is None:
        package = _auto_pkg()
    return import_module(_dso2info(dso), package=package)

def dylink_prepare_dso(dso, package=None):
    """Take steps necessary to allow the named DSO to be loaded implicitly.

    eg. On Windows, call `os.add_dll_directory()` as neeeded.

    :param str dso: DSO name string (eg. 'my.pkg.libs.adso').
    :param str package: Package name to resolve relative imports.  cf. importlib.import_module
    :returns: Info module for the named DSO
    """
    if package is None:
        package = _auto_pkg()
    todo, found = [dso], OrderedDict()

    # recursively walk dependencies
    while todo:
        working = todo.pop(0)
        info = import_dsoinfo(working, package=package)
        found[working] = info
        # libdir must be absolute, but __file__ may be relative if imported via $PWD
        libdir = os.path.join(os.getcwd(), os.path.dirname(info.__file__))
        add_dso_directory(libdir)
        todo.extend([t for t in info.depends if t not in found])

    return next(iter(found.values())) # first value

def find_dso(dso, package=None, so=True):
    """Lookup DSO file name.  eg. for use with ctypes

    :param str dso: DSO name string (eg. 'my.pkg.libs.adso').
    :param str package: Package name to resolve relative imports.  cf. importlib.import_module
    :param bool so: When True (default) return SO qualified name.
                    eg. "libblah.so.0" vs. "libblah.so".
                    No effect on Windows.
    :returns: Absolute path string of DSO file.

    eg. ::

        fname = setuptools_dso.find_dso('my.pkg.libs.adso')
        lib = ctypes.CDLL(fname, ctypes.RTLD_GLOBAL)
    """
    if package is None:
        package = _auto_pkg()
    mod = dylink_prepare_dso(dso, package=package)
    return mod.sofilename if so else mod.filename



def _cli_info(args):
    mod = import_dsoinfo(args.dso)
    if args.var:
        print(getattr(mod, args.var))
    else:
        for var in dir(mod):
            if not var.startswith('_'):
                print('{} = {!r}'.format(var, getattr(mod, var)))

def getargs():
    from argparse import ArgumentParser
    P = ArgumentParser()
    P.add_argument('-v', '--debug', dest='level', default=logging.INFO,
                    action='store_const', const=logging.DEBUG)
    SP = P.add_subparsers()
    S = SP.add_parser('info')
    S.add_argument('dso')
    S.add_argument('var', nargs='?')
    S.set_defaults(func=_cli_info)

    return P

def main():
    args = getargs().parse_args()
    logging.basicConfig(level=args.level)
    logging.debug('PYTHONPATH=')
    for ent in sys.path:
        logging.debug('  '+ent)
    args.func(args)

if __name__=='__main__':
    main()
