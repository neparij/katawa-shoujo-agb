from setuptools import setup, find_packages

setup(
    name="ksre_gfx_converter_deprecated",
    version="0.1.0",
    packages=find_packages(),
    install_requires=[
        "Pillow>=9.0.0",
        "tilequant>=0.3.0",
    ],
    entry_points={
        "console_scripts": [
            "ksre_bgs_resize=src.resize:main",
            "ksre_drugs_gen=src.drugs_event_generator:main",
            "ksre_random_fill=src.random_fill_generator:main",
            "ksre_gallery_thumbs=src.gallery_thumbsbg_generator:main",
        ],
    },
)
