import os
import json
from PIL import Image, ImageOps

PINK_COLOR = (255, 0, 255)  # Pink background color
# OUTPUT_DIR = "evout"  # Output directory


def resize_images_in_directory(input_dir):
    """Resize all images in the input directory and save them in the output directory."""
    image_files = [f for f in os.listdir(input_dir) if f.lower().endswith(('.png', '.jpg', '.jpeg', '.bmp', '.gif'))]

    if not image_files:
        print("No image files found in the specified directory.")
        return

    os.makedirs(OUTPUT_DIR, exist_ok=True)  # Create output directory if it doesn't exist

    for image_file in image_files:
        input_path = os.path.join(input_dir, image_file)
        output_file_name = f"{os.path.splitext(image_file)[0]}.bmp"  # Save as BMP
        output_path = os.path.join(OUTPUT_DIR, output_file_name)

        try:
            process_image(input_path, output_path)
            create_json_metadata(output_path)
        except Exception as e:
            print(f"Error processing {image_file}: {e}")


def process_image(input_path, output_path):
    """Process an image: resize, add pink background, remap palette, and save as BMP."""
    # Create a 256x256 image filled with pink
    pink_background = Image.new("RGB", (256, 256), PINK_COLOR)

    # Open the source image
    source_image = Image.open(input_path).convert("RGB")

    # Resize the source image to fit within 240x160 while maintaining aspect ratio
    source_resized = ImageOps.fit(source_image, (240, 160), method=Image.LANCZOS, centering=(0.5, 0.5))

    # Paste the resized image onto the pink background, centered
    pink_background.paste(source_resized, (8, 48))  # Center 240x160 on 256x256

    # Convert to 255-color palette
    palette_image = pink_background.convert("P", palette=Image.ADAPTIVE, colors=255)

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

    # Save the result as BMP
    img_remapped.save(output_path, format="BMP")
    print(f"Resized and saved: {output_path}")


def create_json_metadata(image_path):
    """Create a JSON metadata file for the image."""
    json_path = f"{os.path.splitext(image_path)[0]}.json"
    metadata = {
        "type": "regular_bg"
    }

    with open(json_path, "w", encoding="utf-8") as json_file:
        json.dump(metadata, json_file, indent=4)

    print(f"Metadata saved: {json_path}")


if __name__ == "__main__":
    OUTPUT_DIR = "evout"
    input_directory = "/Users/n.laptev/development/ksre/game/event/Lilly_supercg"
    resize_images_in_directory(input_directory)
    input_directory = "/Users/n.laptev/development/ksre/game/event"
    resize_images_in_directory(input_directory)
    OUTPUT_DIR = "out"
    input_directory = "/Users/n.laptev/development/ksre/game/bgs"
    resize_images_in_directory(input_directory)
