import hashlib
import os
import json
import subprocess

from PIL import Image, ImageOps
from tilequant import Tilequant
from tilequant.image_converter import DitheringMode

PINK_COLOR = (255, 0, 255)  # Pink background color

QUALETIZE = "/Users/n.laptev/development/gba/qualetize/release/qualetize"
IMAGEMAGICK = "magick"

# Game Boy Advance (GBA) settings - default
QUALETIZE_COLOURSPACE = "ycbcr-psy"
QUALETIZE_DITHER_METHOD = "floyd"
QUALETIZE_DITHER_LEVEL = 1.0
QUALETIZE_PALETTES_COUNT = 8
QUALETIZE_PALETTE_COLORS = 16
QUALETIZE_BITS_PER_COLOR = 5
QUALETIZE_COLOR_0_IS_CLEAR = True

QUALETIZE_PASSES_COLOUR = (2 ** 10) * QUALETIZE_PALETTES_COUNT
QUALETIZE_PASSES_TILES = (2 ** 10) * QUALETIZE_PALETTES_COUNT

PAGES = [
    [
        "event/other_iwanako",
        "event/hisao_class",
        "event/kenji_rooftop",
        "event/hisao_teacup",
        "event/hisao_letter_closed",
        "event/akira_park",
        "event/emi_knockeddown",
        "event/emi_run_face",
        "event/emitrack_blocks",
        "event/emitrack_running",
        "event/emitrack_finishtop",
        "event/emitrack_finish",
    ],
    [
        "event/picnic_normal",
        "event/emi_sleep_unsure",
        "event/emi_sleepy",
        "event/emi_firstkiss",
        "event/emi_bed_normal",
        "event/emi_forehead",
        "event/emi_grinding/emi_grinding_victory",
        "event/emi_shed/emi_shed_base1",
        "event/emi_grave",
        "event/emi_cry_down",
        "event/emi_miss_closed",
        "event/emi_ending_smile",
    ],
    [
        "event/hana_library",
        "event/hanako_fw",
        "event/hanako_presents1",
        "event/hanako_crayon1",
        "event/hanako_breakdown/hanako_breakdown_bg", # TODO: wrong thumbnail used
        "event/hanako_cry_closed",
        "event/hanako_billiards_break",
        "event/hanako_emptyclassroom_bg",
        "event/hanako_rage",
        "event/hisao_scar",
        "event/hanako_scars",
        "event/hanako_bed_boobs_blush",
    ],
    [
        "event/hanako_missionary_underwear",
        "event/hanako_after_worry",
        "event/hanako_park_alone",
        "event/hanako_goodend",
        "event/lilly_tearoom",
        "event/lilly_touch_uni",
        "event/lilly_crane",
        "event/lilly_bedroom",
        "event/lilly_hanako_hug",
        "event/lilly_sleeping",
        "event/lilly_train/lilly_trainride_smiles",
        "event/lilly_wheat_small",
    ],
    [
        "event/lilly_handjob/lilly_hcg_handjob_chest_frown",
        "event/lilly_cowgirl/lilly_hcg_cowgirl_cry_small",
        "event/lilly_bath/lilly_hcg_bath_emb_small",
        "event/lilly_afterbath/lilly_hcg_afterbath_open_small",
        "event/lilly_kissing",
        "event/lilly_masturbate",
        "event/lilly_restaurant_listen",
        "event/lilly_sheets",
        "event/lilly_airport",
        "event/lilly_hospitalwindow",
        "event/lilly_hospitalclosed",
        "event/lilly_goodend",
    ],
    [
        "event/rin_eating",
        "event/rin_artclass1",
        "event/hisao_mirror",
        "event/rin_painting_base",
        "event/rin_rain_away",
        "event/rin_high_frown",
        "event/rin_kiss",
        "event/rin_nap_total",
        "event/rin_wisp1",
        "event/rin_galleryskylight",
        "event/rin_orange",
        "event/rin_masturbate_away",
    ],
    [
        "event/rin_relief_down",
        "event/rin_gallery",
        "event/rin_trueend/rin_trueend_normal",
        "event/rin_wet/rin_wet_pan_down",
        "event/rin_h2/rin_h2_l_pan",
        "event/rin_pair/rin_pair_base",
        "event/rin_h/rin_h_closed",
        "event/rin_goodend/rin_goodend_base",
        "event/shizu_shanghai",
        "event/lilly_shizu_showdown",
        "event/shizu_supercg/shizu_chess_base",
        "event/kenji_glasses/kenji_glasses_bg",
    ],
    [
        "event/shizu_yukata/shizutanabata",
        "event/shizu_yukata/shizuconfess_normal",
        "event/shizu_hands",
        "event/shizu_couch",
        "event/shizune_car",
        "event/shizu_fishing_ah",
        "event/shizune_hcg_tied/shizune_hcg_tied_blush",
        "event/misha_sad",
        "event/misha_naked",
        "event/misha_sex_aside",
        "event/misha_roof_closed",
        "event/shizu_roof/shizu_roof",
    ],
    [
        "event/shizu_flashback",
        "event/shizu_undressing/shizu_undressing_clothed_stare",
        "event/shizu_pushdown",
        "event/shizu_straddle_open",
        "event/shizu_table_smile",
        "event/misha_nightclass",
        "event/shizu_badend",
        "event/shizu_goodend",
        "event/event_missing",
        "event/completionbonus",
    ]
]

def create_json_metadata(image_path):
    json_path = f"{os.path.splitext(image_path)[0]}.json"
    metadata = {
        "type": "regular_bg",
        "bpp_mode": "bpp_4_manual",
        "colors_count": 32,
        "compression": "auto_no_huffman",
    }

    with open(json_path, "w", encoding="utf-8") as json_file:
        json.dump(metadata, json_file, indent=4)

    print(f"Metadata saved: {json_path}")

def create_pages():
    output_directory = "/Users/n.laptev/development/gba/katawa/graphics"
    input_directory = "/Users/n.laptev/development/ksre-2/game"

    page_num = 0
    for page in PAGES:
        image_files = []
        image_files += [f"{input_directory}/{f}.png" for f in page]
        output_path = f"{output_directory}/ui_bg_menu_extras_gallery_page_{page_num}.bmp"
        xx = 0
        yy = 0

        print(f"Processing page {page_num + 1} with {len(image_files)} images.")
        canvas = Image.new("RGBA", (256, 256), PINK_COLOR)
        for image_file in image_files:
            source_image = Image.open(image_file).convert("RGBA")
            grayscale_image = ImageOps.grayscale(source_image).convert("RGBA")
            grayscale_resized = ImageOps.fit(grayscale_image, (48, 32), method=Image.Resampling.LANCZOS, centering=(0.5, 0.5))
            canvas.paste(grayscale_resized, (20 + 56 * xx, 73 + 38 * yy))

            xx += 1
            if xx == 4:
                xx = 0
                yy += 1

        converter = Tilequant(
            canvas, PINK_COLOR,
            tile_width=8,
            tile_height=8,
        )
        quantized = converter.convert(num_palettes=2, colors_per_palette=16,
                                      dithering_mode=DitheringMode.FLOYDSTEINBERG, dithering_level=0.5,
                                      num_color_cluster_passes=0, num_tile_cluster_passes=0)
        quantized.save(output_path, format="BMP")
        create_json_metadata(output_path)
        print(f"Resized, quantized and saved: {output_path}")
        page_num += 1


def main():
    create_pages()

if __name__ == "__main__":
    main()
