import os
import json
from PIL import Image, ImageOps

PINK_COLOR = (255, 0, 255)  # Pink background color (transparency)

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

    # Open the source image
    source_image = Image.open(input_path).convert("RGB")

    # Apect ratio for GBA 1.5:1
    aspect_cropped = ImageOps.fit(source_image, (1080, 720), method=Image.LANCZOS, centering=(0.5, 0.5))

    # Resize to 128x128 (dont save apect)
    source_resized = aspect_cropped.resize((128, 128), Image.LANCZOS)

    # Convert to 127-color palette (no transparency)
    palette_image = source_resized.convert("P", palette=Image.ADAPTIVE, colors=127)

    palette = palette_image.getpalette()
    num_colors = len(palette) // 3  # Each color is 3 values (R, G, B)
    palette[(num_colors - 1)*3:(num_colors - 1)*3+3] = PINK_COLOR  # Set the last color to pink
    palette_colors = [tuple(palette[i:i + 3]) for i in range(0, len(palette), 3)]
    palette_image.putpalette(palette)

    remap = list(range(len(palette_colors)))
    remap[0], remap[num_colors-1] = remap[num_colors-1], remap[0]

    # Remap the palette to make pink the first color
    img_remapped = palette_image.remap_palette(remap)

    # slice image to 4 64x64 images (top-left, top-right, bottom-left, bottom-right)
    top_left = img_remapped.crop((0, 0, 64, 64))
    top_right = img_remapped.crop((64, 0, 128, 64))
    bottom_left = img_remapped.crop((0, 64, 64, 128))
    bottom_right = img_remapped.crop((64, 64, 128, 128))

    # Save tiles
    top_left.save(f"{os.path.splitext(output_path)[0]}_tl.bmp", format="BMP")
    top_right.save(f"{os.path.splitext(output_path)[0]}_tr.bmp", format="BMP")
    bottom_left.save(f"{os.path.splitext(output_path)[0]}_bl.bmp", format="BMP")
    bottom_right.save(f"{os.path.splitext(output_path)[0]}_br.bmp", format="BMP")

    # # Save the result as BMP
    # palette_image.save(output_path, format="BMP")
    # print(f"Saved: {output_path}")


def create_json_metadata(image_path):
    """Create a JSON metadata file for the image."""
    json_path = f"{os.path.splitext(image_path)[0]}"
    metadata = {
        "type": "sprite",
        "height": 64
    }

    for tile in ["tl", "tr", "bl", "br"]:
        with open(f'{json_path}_{tile}.json', "w", encoding="utf-8") as json_file:
            json.dump(metadata, json_file, indent=4)

    print(f"Metadata saved: {json_path}")


if __name__ == "__main__":
    OUTPUT_DIR = "tiled"
    input_directory = "/Users/n.laptev/development/ksre/game/event/Lilly_supercg"
    resize_images_in_directory(input_directory)

    # OUTPUT_DIR = "/Users/n.laptev/development/gba/katawa/graphics/event"
    # input_directory = "/Users/n.laptev/development/ksre/game/event/Lilly_supercg"
    # resize_images_in_directory(input_directory)
    # input_directory = "/Users/n.laptev/development/ksre/game/event"
    # resize_images_in_directory(input_directory)
    # OUTPUT_DIR = "/Users/n.laptev/development/gba/katawa/graphics/bgs"
    # input_directory = "/Users/n.laptev/development/ksre/game/bgs"
    # resize_images_in_directory(input_directory)
