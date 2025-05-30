import argparse
import os
import platform
import re
import subprocess
from datetime import datetime, UTC
from pathlib import Path
from typing import Tuple

version_file_path = Path("VERSION")
build_info_path = Path("include/build_info.h")


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('--compiler', type=str, default="UNKNOWN", help='Compiler used for the build')
    return parser.parse_args()


def detect_compiler_version(compiler: str) -> str:
    try:
        version_output = subprocess.check_output([compiler, '--version'], text=True, errors='replace')
        first_line = version_output.splitlines()[0]
        return first_line
    except Exception as e:
        return f"{compiler} (unknown version: {e})"


def get_version():
    """Get the version from the VERSION file."""
    if not version_file_path.exists():
        raise FileNotFoundError(f"Version file '{version_file_path}' does not exist.")

    with version_file_path.open(encoding="utf-8") as version_file:
        __version = version_file.read().strip()
    if not __version:
        raise ValueError(f"Version file '{version_file_path}' is empty.")

    return __version


def get_commit_optional():
    """Get the current git commit hash."""
    try:
        __commit = subprocess.check_output(['git', 'rev-parse', '--short', 'HEAD'], text=True).strip()
        # if git have uncommitted changes return "snapshot"
        if subprocess.call(['git', 'diff-index', '--quiet', 'HEAD']) != 0:
            __commit += "-snapshot"
            print(f"Current working branch have changes\nUsing '{__commit}'")
    except (FileNotFoundError, subprocess.CalledProcessError) as e:
        __commit = "snapshot"
        print(f"Failed to get the current commit hash.\nUsing '{__commit}' instead.\n    Reason: {e}")

    return __commit


def get_current_build_info() -> Tuple[str, str]:
    """Get the current build version and commit from the build_info.h file."""
    if not build_info_path.exists():
        raise FileNotFoundError(f"Build info file '{build_info_path}' does not exist.")

    with build_info_path.open(encoding="utf-8") as build_info_file:
        __build_info_text = build_info_file.read()

    __current_build_version_re = re.search(r'#define\s+KS_BUILD_VERSION\s+"([^"]+)"', __build_info_text)
    __current_build_commit_re = re.search(r'#define\s+KS_BUILD_COMMIT\s+"([^"]+)"', __build_info_text)

    return (
        __current_build_version_re.group(1) if __current_build_version_re else None,
        __current_build_commit_re.group(1) if __current_build_commit_re else None
    )


def get_build_environment() -> Tuple[str, str, str]:
    """Get the build environment (OS and compiler)."""
    build_host_os = platform.system()
    if not build_host_os:
        build_host_os = "UNKNOWN"

    if 'GITHUB_ACTIONS' in os.environ:
        build_host_env = "Github Actions"
    elif 'GITLAB_CI' in os.environ:
        build_host_env = "GitLab CI"
    else:
        build_host_env = "Local"

    build_compiler = detect_compiler_version(parse_args().compiler)

    return build_host_os, build_host_env, build_compiler


def update_build_info_file(current_build_info, new_version, new_commit):
    """Update the build_info.h file with the new version and commit."""
    if not build_info_path.exists():
        raise FileNotFoundError(f"Build info file '{build_info_path}' does not exist.")

    with build_info_path.open(encoding="utf-8") as build_info_file:
        build_info_text = build_info_file.read()

    current_build_version, current_build_commit = current_build_info
    if new_version != current_build_version:
        print(f"Updating build version from {current_build_version} to {new_version}")
        build_info_text = re.sub(
            r'#define\s+KS_BUILD_VERSION\s+".*?"',
            fr'#define KS_BUILD_VERSION "{new_version}"',
            build_info_text
        )

    if new_commit != current_build_commit:
        print(f"Updating build commit from {current_build_commit} to {new_commit}")
        build_info_text = re.sub(
            r'#define\s+KS_BUILD_COMMIT\s+".*?"',
            fr'#define KS_BUILD_COMMIT "{new_commit}"',
            build_info_text
        )

    build_time = datetime.now(UTC).isoformat(timespec='seconds')
    print(f"Updating build time to {build_time}")
    build_info_text = re.sub(
        r'#define\s+KS_BUILD_DATE\s+".*?"',
        fr'#define KS_BUILD_DATE "{build_time}"',
        build_info_text
    )

    build_env = get_build_environment()
    print(f"Updating build host environment info")
    build_info_text = re.sub(
        r'#define\s+KS_BUILD_HOST_OS\s+".*?"',
        fr'#define KS_BUILD_HOST_OS "{build_env[0]}"',
        build_info_text
    )
    build_info_text = re.sub(
        r'#define\s+KS_BUILD_HOST_ENV\s+".*?"',
        fr'#define KS_BUILD_HOST_ENV "{build_env[1]}"',
        build_info_text
    )
    build_info_text = re.sub(
        r'#define\s+KS_BUILD_COMPILER\s+".*?"',
        fr'#define KS_BUILD_COMPILER "{build_env[2]}"',
        build_info_text
    )

    with build_info_path.open('w', encoding="utf-8") as build_info_file:
        build_info_file.write(build_info_text)


current = get_current_build_info()
version = get_version()
commit = get_commit_optional()
update_build_info_file(current, version, commit)
