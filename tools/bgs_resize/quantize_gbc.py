import os
import json
from PIL import Image, ImageOps
from tilequant import Tilequant
from tilequant.image_converter import DitheringMode

PINK_COLOR = (255, 0, 255)  # Pink background color

def process_image_quantized(input_path, output_path, quantize_palettes: int):
    source = Image.open(input_path)
    converter = Tilequant(
        source, PINK_COLOR, 8, 16
    )
    quantized = converter.convert(num_palettes=8, colors_per_palette=4, dithering_mode=DitheringMode.FLOYDSTEINBERG,
                                  dithering_level=0.5,
                                  num_color_cluster_passes=10000, num_tile_cluster_passes=5000)
    quantized.save(output_path, format="BMP")
    print(f"Quantized and saved: {output_path}")

if __name__ == "__main__":


    INPUT = "/Users/n.laptev/development/gbc/CrossZGB/examples/katawa-cgb/orig/shizu.bmp"
    OUTPUT = "/Users/n.laptev/development/gbc/CrossZGB/examples/katawa-cgb/orig/shizu-quantized.bmp"

    process_image_quantized(INPUT, OUTPUT, 4)
