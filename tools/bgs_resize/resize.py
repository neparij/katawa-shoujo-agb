import os
import json
from PIL import Image, ImageOps
from tilequant import Tilequant
from tilequant.image_converter import DitheringMode

PINK_COLOR = (255, 0, 255)  # Pink background color
QUANTIZE = True

def resize_images_in_directory(input_dir, quantize=True, quantize_palettes=8, unquant_colors : int = 256):
    """Resize all images in the input directory and save them in the output directory."""
    image_files = [f for f in os.listdir(input_dir) if f.lower().endswith(('.png', '.jpg', '.jpeg', '.bmp', '.gif'))]

    if not image_files:
        print("No image files found in the specified directory.")
        return

    os.makedirs(OUTPUT_DIR, exist_ok=True)  # Create output directory if it doesn't exist

    for image_file in image_files:
        # if not image_file.startswith("school_dormext"):
        #     continue
        input_path = os.path.join(input_dir, image_file)
        output_file_name = f"{os.path.splitext(image_file)[0]}.bmp"  # Save as BMP
        output_path = os.path.join(OUTPUT_DIR, output_file_name)

        try:
            if quantize:
                process_image_quantized(input_path, output_path, quantize_palettes)
            else:
                process_image(input_path, output_path, unquant_colors)
            create_json_metadata(output_path, quantize, unquant_colors)
        except Exception as e:
            print(f"Error processing {image_file}: {e}")

def process_image_quantized(input_path, output_path, quantize_palettes: int):
    canvas = Image.new("RGB", (256, 256), PINK_COLOR)
    # canvas = Image.new("RGB", (128, 128), PINK_COLOR)
    source_image = Image.open(input_path).convert("RGB")

    # source_resized = ImageOps.fit(source_image, (256, 160), method=Image.Resampling.LANCZOS, centering=(0.5, 0.5))
    # # canvas.paste(source_resized, (8, 48))  # Center 240x160 on 256x256
    # canvas.paste(source_resized, (0, 48))  # Center 256x160 on 256x256

    original_ratio = 1920 / 1080
    gba_ratio = 240 / 160

    gba_resize_factor = 160 / 1080

    # source_fhd_resized = ImageOps.scale(source_image, 1080 / source_image.height, resample=Image.Resampling.LANCZOS)
    #
    # extra_width = source_fhd_resized.width - 1920
    # extra_width_percentage = extra_width / 1920

    # source_fhd_resized = ImageOps.scale(source_image, 1080 / source_image.height, resample=Image.Resampling.LANCZOS)

    extra_width = source_image.width - 1920
    extra_height = source_image.height - 1080
    extra_width_percentage = extra_width / 1920
    extra_height_percentage = extra_height / 1080


    print("Extra size percentage:", extra_width_percentage, extra_height_percentage)
    gba_extra_width = int(240 * extra_width_percentage)
    gba_extra_height = int(160 * extra_height_percentage)
    print("GBA extra width:", gba_extra_width)
    print("GBA extra height:", gba_extra_height)

    if extra_width < 0:
        raise Exception(f"Extra width is negative: {extra_width}")

    source_height_resized = ImageOps.scale(source_image, gba_resize_factor, resample=Image.Resampling.LANCZOS)

    crop_x = source_height_resized.width - (240 + gba_extra_width)
    crop_y = source_height_resized.height - (160 + gba_extra_height)

    source_cropped = ImageOps.crop(source_height_resized, (crop_x // 2, crop_y // 2, crop_x // 2, crop_y // 2))
    canvas.paste(source_cropped, ((256 - source_cropped.width) // 2, (256 - source_cropped.height) // 2))


    converter = Tilequant(
        canvas, PINK_COLOR,
        tile_width=8,
        tile_height=8,
    )
    quantized = converter.convert(num_palettes=quantize_palettes, colors_per_palette=16,
                                  dithering_mode=DitheringMode.FLOYDSTEINBERG, dithering_level=0.5,
                                  num_color_cluster_passes=0, num_tile_cluster_passes=0)
    quantized.save(output_path, format="BMP")
    print(f"Resized, Quantized and saved: {output_path}")

def process_image(input_path, output_path, colors : int = 256):
    """Process an image: resize, add pink background, remap palette, and save as BMP."""
    # Create a 256x256 image filled with pink
    pink_background = Image.new("RGB", (256, 256), PINK_COLOR)

    # Open the source image
    source_image = Image.open(input_path).convert("RGB")

    # Resize the source image to fit within 240x160 while maintaining aspect ratio
    source_resized = ImageOps.fit(source_image, (256, 160), method=Image.Resampling.LANCZOS, centering=(0.5, 0.5))
    # pink_background.paste(source_resized, (8, 48))  # Center 240x160 on 256x256
    pink_background.paste(source_resized, (0, 48))  # Center 256x160 on 256x256

    # Convert to 255-color palette
    palette_image = pink_background.convert("P", palette=Image.Palette.ADAPTIVE, colors=colors)

    # # Convert to 63-color palette
    # palette_image = pink_background.convert("P", palette=Image.ADAPTIVE, colors=63)

    # Get the current palette data
    palette = palette_image.getpalette()
    palette_colors = [tuple(palette[i:i + 3]) for i in range(0, len(palette), 3)]

    # Ensure pink is explicitly the first color in the palette
    if PINK_COLOR not in palette_colors:
        print(f"Warning: Pink color {PINK_COLOR} is not in the palette!")
        return

    first_color_index = palette_colors.index(PINK_COLOR)
    remap = list(range(len(palette_colors)))
    if first_color_index != 0:
        # Swap pink with the first palette color
        remap[0], remap[first_color_index] = remap[first_color_index], remap[0]

    # Remap the palette to make pink the first color
    img_remapped = palette_image.remap_palette(remap)
    # img_remapped = palette_image

    # Save the result as BMP
    img_remapped.save(output_path, format="BMP")
    print(f"Resized and saved: {output_path}")


def create_json_metadata(image_path, quantize, unquant_colors: int):
    """Create a JSON metadata file for the image."""
    json_path = f"{os.path.splitext(image_path)[0]}.json"
    metadata = {
        "type": "regular_bg",
        # "type": "affine_bg",
    }

    if quantize:
        metadata["bpp_mode"] = "bpp_4_manual"
        metadata["compression"] = "auto_no_huffman"
    else:
        metadata["compression"] = "auto_no_huffman"
        metadata["colors"] = unquant_colors

    #  * * `"compression"`: optional field which specifies the compression of the tiles, the colors and the map data:
    #  *   * `"none"`: uncompressed data (this is the default option).
    #  *   * `"lz77"`: LZ77 compressed data.
    #  *   * `"run_length"`: run-length compressed data.
    #  *   * `"huffman"`: Huffman compressed data.
    #  *   * `"auto"`: uses the option which gives the smallest data size.
    #  *   * `"auto_no_huffman"`: uses the option which gives the smallest data size, excluding "huffman".

    with open(json_path, "w", encoding="utf-8") as json_file:
        json.dump(metadata, json_file, indent=4)

    print(f"Metadata saved: {json_path}")


if __name__ == "__main__":
    ### HERE AND AFTER EVENTS (LILLY)
    OUTPUT_DIR = "/Users/n.laptev/development/gba/katawa/graphics/event"
    input_directory = "/Users/n.laptev/development/ksre/game/event/Lilly_supercg"
    resize_images_in_directory(input_directory, quantize_palettes=8)
    # # resize_images_in_directory(input_directory, quantize=True, quantize_palettes=14)
    # resize_images_in_directory(input_directory, quantize=False, unquant_colors = 16*14)
    # resize_images_in_directory(input_directory, quantize=False, unquant_colors = 16*8)


    ### HERE AND AFTER EVENTS
    OUTPUT_DIR = "/Users/n.laptev/development/gba/katawa/graphics/event"
    input_directory = "/Users/n.laptev/development/ksre/game/event"
    resize_images_in_directory(input_directory, quantize_palettes=8)
    # # resize_images_in_directory(input_directory, quantize=True, quantize_palettes=14)
    # resize_images_in_directory(input_directory, quantize=False, unquant_colors = 16*14)
    # resize_images_in_directory(input_directory, quantize=False, unquant_colors = 16*8)


    # ## HERE AND AFTER BACKGROUNDS
    # OUTPUT_DIR = "/Users/n.laptev/development/gba/katawa/graphics/bgs"
    # input_directory = "/Users/n.laptev/development/ksre/game/bgs"
    # resize_images_in_directory(input_directory, quantize_palettes=8)
    # # resize_images_in_directory(input_directory, quantize=False, unquant_colors=16 * 8)
    # # resize_images_in_directory(input_directory)



    # ## HERE AND AFTER TEST MURAL IMAGES
    # OUTPUT_DIR = "/Users/n.laptev/development/gba/katawa/graphics/bgs"
    # input_directory = "/Users/n.laptev/development/ksre/game/vfx"
    # process_image_quantized(
    #     os.path.join(input_directory, "mural_start.jpg"),
    #     os.path.join(OUTPUT_DIR, "mural_start.bmp"),
    #     8
    # )
    # create_json_metadata(os.path.join(OUTPUT_DIR, "mural_start.bmp"), True, -1)
    #
    # process_image_quantized(
    #     os.path.join(input_directory, "mural_unfinished.jpg"),
    #     os.path.join(OUTPUT_DIR, "mural_unfinished.bmp"),
    #     8
    # )
    # create_json_metadata(os.path.join(OUTPUT_DIR, "mural_unfinished.bmp"), True, -1)
