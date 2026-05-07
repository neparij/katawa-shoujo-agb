from setuptools import setup, find_packages, Extension

pyfastgbalz77_module = Extension(
    'pyfastgbalz77',
    sources=['src/pyfastgbalz77.c'],
)

setup(
    name="ksre_converter",
    version="0.1.0",
    packages=find_packages(),
    ext_modules=[pyfastgbalz77_module],
    install_requires=[
        "sentencepiece",
        "Pillow",
        "pyyaml"
    ],
    entry_points={
        "console_scripts": [
            "ksre_converter=src.main:main",
        ],
    },
)