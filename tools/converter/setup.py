from setuptools import setup, find_packages

setup(
    name="ksre_converter",
    version="0.1.0",
    packages=find_packages(),
    entry_points={
        "console_scripts": [
            "ksre_converter=src.main:main",
        ],
    },
)