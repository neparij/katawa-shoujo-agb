import json
import os
import re
from src.image_tools.image_tools import ImageTools
from typing import List


class CharacterSprite:
    def __init__(self, character_name: str, pose: str, emotion: str, outfit: str, nude: bool):
        self.character_name = character_name
        self.pose = pose
        self.outfit = outfit
        self.emotion = emotion
        self.nude = nude
        self.original_filename = ""
        self.original_path = ""

    def __str__(self):
        return (f"Name: {self.character_name}\n"
                f"Pose: {self.pose}\n"
                f"Emotion: {self.emotion}\n"
                f"Outfit: {self.outfit}\n"
                f"IsNaked: {self.nude}\n"
                f"OriginalFilename: {self.original_filename}\n")

class CharacterDisplayableReplacements:
    @staticmethod
    def lilly(displayable_name: str) -> str:
        return (displayable_name
                .replace("basic_arablush_paj", "basic1_arablush_paj")  # hands behind
                .replace("basic_ara_paj", "basic1_ara_paj") #hands behind
                .replace("basic_ara", "basic2_ara") #hands joyful
                .replace("basic_emb_paj", "basic1_emb_paj")  # hands behind
                .replace("basic_emb", "basic2_emb")  # hands joyful
                .replace("basic_giggle_paj", "basic1_giggle_paj")  # hands behind
                .replace("basic_giggle", "basic2_giggle")  # hands joyful
                .replace("basic_listen_paj", "basic1_listen_paj")  # hands behind
                .replace("basic_listen", "basic3_listen")  # hands breast
                .replace("basic_oops_paj", "basic1_oops_paj")  # hands behind
                .replace("basic_oops", "basic3_oops")  # hands breast
                .replace("basic_planned_paj", "basic1_planned_paj")  # hands behind
                .replace("basic_planned", "basic2_planned")  # hands joyful
                .replace("basic_pout_paj", "basic1_pout_paj")  # hands behind
                .replace("basic_satisfied_paj", "basic1_satisfied_paj")  # hands behind
                .replace("basic_satisfied", "basic3_satisfied")  # hands breast
                .replace("basic_surprised", "basic3_surprised" if not "_paj" in displayable_name else "basic_surprised")  # hands breast if not in _paj outfit
                )

    @staticmethod
    def yuuko(displayable_name: str) -> str:
        # We should swap last two string
        # Example: "yuuko_first_second" -> "yuuko_second_first"
        parts = displayable_name.split('_')
        if len(parts) > 1:
            return '_'.join(parts[:-2] + [parts[-1], parts[-2]])

    @staticmethod
    def kenji(displayable_name: str) -> str:
        return (displayable_name
                .replace("happy", "basic_happy")
                .replace("neutral", "basic_neutral")
                .replace("tsun", "basic_tsun")
                .replace("rage", "rage_rage")
                )


class CharacterSpritesGroup:
    def __init__(self, character_name: str, pose: str, outfit: str | None, base_emotion: str | None,
                 base_emotion_offset: tuple[int, int], base_emotion_size: tuple[int, int] = (32, 32),
                 base_origin_offset: int = 0):
        self.character_name = character_name
        self.pose = pose
        self.outfit = outfit
        self.sprites: List[CharacterSprite] = []
        self.base_emotion = base_emotion
        self.base_emotion_size = base_emotion_size
        self.base_emotion_offset = base_emotion_offset
        self.base_origin_offset = base_origin_offset

    def __str__(self):
        return (f"Name: {self.character_name}\n"
                f"Pose: {self.pose}\n"
                f"Outfit: {self.outfit}\n"
                f"BaseEmotion: {self.base_emotion}\n"
                f"Sprites: {len(self.sprites)}\n")

    def add_sprite(self, sprite: CharacterSprite):
        self.sprites.append(sprite)


class CharacterSpritesReader:
    def __init__(self, input_dir: str):
        self.input_dir = input_dir
        self.character_groups: List[CharacterSpritesGroup] = []

    def process_all(self) -> List[CharacterSpritesGroup]:
        self.process_shizu()
        self.process_misha()
        self.process_emi()
        self.process_rin()
        self.process_lilly()
        self.process_hanako()
        self.process_kenji()
        self.process_nurse()
        self.process_yuuko()
        return self.character_groups

    def process_shizu(self) -> List[CharacterSpritesGroup]:
        self.character_groups.append(CharacterSpritesGroup("shizu", "behind", "nak", "smile", (104, 80)))
        self.character_groups.append(CharacterSpritesGroup("shizu", "adjust", "cas", "happy", (104, 80)))
        self.character_groups.append(CharacterSpritesGroup("shizu", "basic", "cas", "normal", (128, 80)))
        self.character_groups.append(CharacterSpritesGroup("shizu", "behind", "cas", "smile", (104, 80)))
        self.character_groups.append(CharacterSpritesGroup("shizu", "cross", "cas", "angry", (108, 80)))
        self.character_groups.append(CharacterSpritesGroup("shizu", "adjust", None, "happy", (104, 80)))
        self.character_groups.append(CharacterSpritesGroup("shizu", "basic", None, "normal", (128, 80)))
        self.character_groups.append(CharacterSpritesGroup("shizu", "behind", None, "smile", (104, 80)))
        self.character_groups.append(CharacterSpritesGroup("shizu", "cross", None, "angry", (108, 80)))
        self._process_character("shizu", nude_if=lambda basename: basename.endswith("nak"))
        return self.character_groups

    def process_misha(self) -> List[CharacterSpritesGroup]:
        self.character_groups.append(CharacterSpritesGroup("misha", "hips", "cas", "smile", (112, 76)))
        self.character_groups.append(CharacterSpritesGroup("misha", "cross", "cas", "grin", (112, 76)))
        self.character_groups.append(CharacterSpritesGroup("misha", "perky", "cas", "smile", (112, 76)))
        self.character_groups.append(CharacterSpritesGroup("misha", "sign", "cas", "smile", (112, 76)))
        self.character_groups.append(CharacterSpritesGroup("misha", "perky", "yuk", "smile", (112, 76)))
        self.character_groups.append(CharacterSpritesGroup("misha", "sign", "yuk", "smile", (112, 76)))
        self.character_groups.append(CharacterSpritesGroup("misha", "hips", None, "smile", (112, 76)))
        self.character_groups.append(CharacterSpritesGroup("misha", "cross", None, "smile", (112, 76)))
        self.character_groups.append(CharacterSpritesGroup("misha", "perky", None, "smile", (112, 76)))
        self.character_groups.append(CharacterSpritesGroup("misha", "sign", None, "smile", (112, 76)))
        self._process_character("misha", nude_if=lambda basename: False)
        return self.character_groups

    def process_emi(self) -> List[CharacterSpritesGroup]:
        self.character_groups.append(CharacterSpritesGroup("emi", "basic", "gym", "smile", (110, 88)))
        self.character_groups.append(CharacterSpritesGroup("emi", "basic", None, "smile", (110, 88)))
        self.character_groups.append(CharacterSpritesGroup("emi", "excited", "gym", "smile", (112, 92)))
        self.character_groups.append(CharacterSpritesGroup("emi", "excited", None, "smile", (112, 92)))
        self.character_groups.append(CharacterSpritesGroup("emi", "sad", "gym", "shy", (106, 88)))
        self.character_groups.append(CharacterSpritesGroup("emi", "sad", None, "shy", (106, 88)))

        self._process_character("emi", nude_if=lambda basename: False)
        return self.character_groups

    def process_rin(self) -> List[CharacterSpritesGroup]:
        self.character_groups.append(CharacterSpritesGroup("rin", "basic", "cas", "absent", (108, 68)))
        self.character_groups.append(CharacterSpritesGroup("rin", "negative", "cas", "spaciness", (96, 40), base_emotion_size=(64, 64)))
        self.character_groups.append(CharacterSpritesGroup("rin", "relaxed", "cas", "doubt", (116, 68)))
        self.character_groups.append(CharacterSpritesGroup("rin", "basic", None, "absent", (108, 68)))
        self.character_groups.append(CharacterSpritesGroup("rin", "negative", None, "spaciness", (96, 40), base_emotion_size=(64, 64)))
        self.character_groups.append(CharacterSpritesGroup("rin", "relaxed", None, "doubt", (116, 68)))
        # TODO: Rin back sprite have different naming
        self.character_groups.append(CharacterSpritesGroup("rin", "back", None, None, (108, 68)))
        self._process_character("rin", nude_if=lambda basename: False)
        return self.character_groups

    def process_lilly(self) -> List[CharacterSpritesGroup]:

        # CUSTOM POSES FOR LILLY
        # basic  — hands down (DEFAULT)
        # basic1 — hands behind
        # basic2 — hands joyful
        # basic3 — hands breast

        self.character_groups.append(CharacterSpritesGroup("lilly", "back", "cas", "smileclosed", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "back", None, "smileclosed", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "basic", "cas", "smileclosed", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "basic", "paj", "smileclosed", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "basic", None, "smileclosed", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "basic1", "paj", "ara", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "basic2", "cas", "ara", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "basic2", None, "ara", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "basic3", "cas", "listen", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "basic3", None, "listen", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "behind", "nak", "smileclosed", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "behind", None, "cheerful", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "cane", "cas", "smileclosed", (112, 64), base_origin_offset=-48))
        self.character_groups.append(CharacterSpritesGroup("lilly", "cane", None, "smileclosed", (112, 64), base_origin_offset=-48))

        self._process_character("lilly",
                                filename_replacements=lambda filename: CharacterDisplayableReplacements.lilly(filename),
                                nude_if=lambda basename: basename.endswith("nak"))
        return self.character_groups

    def process_hanako(self) -> List[CharacterSpritesGroup]:
        self.character_groups.append(CharacterSpritesGroup("hanako", "basic", "cas", "normal", (116, 64)))
        self.character_groups.append(CharacterSpritesGroup("hanako", "basic", None, "normal", (116, 64)))
        self.character_groups.append(CharacterSpritesGroup("hanako", "cover", "cas", "distant", (112, 64)))
        self.character_groups.append(CharacterSpritesGroup("hanako", "cover", None, "distant", (112, 64)))
        self.character_groups.append(CharacterSpritesGroup("hanako", "def", "cas", "worry", (112, 64)))
        self.character_groups.append(CharacterSpritesGroup("hanako", "def", None, "worry", (112, 64)))
        self.character_groups.append(CharacterSpritesGroup("hanako", "defarms", "cas", "worry", (112, 64)))
        self.character_groups.append(CharacterSpritesGroup("hanako", "defarms", None, "worry", (112, 64)))
        self.character_groups.append(CharacterSpritesGroup("hanako", "emb", "cas", "timid", (112, 64)))
        self.character_groups.append(CharacterSpritesGroup("hanako", "emb", None, "timid", (112, 64)))

        self._process_character("hanako", nude_if=lambda basename: False)
        return self.character_groups

    def process_kenji(self) -> List[CharacterSpritesGroup]:
        self.character_groups.append(CharacterSpritesGroup("kenji", "basic", None, "tsun", (118, 66)))
        self.character_groups.append(CharacterSpritesGroup("kenji", "basic", "naked", "tsun", (118, 69)))
        self.character_groups.append(CharacterSpritesGroup("kenji", "rage", None, "rage", (128, 80)))

        self._process_character("kenji",
                                filename_replacements=lambda filename: CharacterDisplayableReplacements.kenji(filename),
                                nude_if=lambda basename: basename.endswith("naked"))
        return self.character_groups

    def process_nurse(self) -> List[CharacterSpritesGroup]:
        self.character_groups.append(CharacterSpritesGroup("nurse", None, None, "neutral", (110, 64), base_origin_offset=-48))

        self._process_character("nurse",
                                regex=r'(?P<name>[^_]+)_(?P<emotion>[^_]+)\.png$',
                                nude_if=lambda basename: False)
        return self.character_groups

    def process_yuuko(self) -> List[CharacterSpritesGroup]:
        self.character_groups.append(CharacterSpritesGroup("yuuko", "up", None, "smile", (96, 64), base_emotion_size=(64,32)))
        self.character_groups.append(CharacterSpritesGroup("yuuko", "down", None, "smile", (96, 64), base_emotion_size=(64,32)))

        self._process_character("yuuko",
                                regex=r'(?P<name>[^_]+)_(?P<emotion>[^_]+)(_(?P<pose>[^_]+))?\.png$',
                                nude_if=lambda basename: False)
        return self.character_groups

    def _process_character(self,
                           character_key: str,
                           regex: str = r'(?P<name>[^_]+)_(?P<pose>[^_]+)_(?P<emotion>[^_]+)(_(?P<outfit>[^_]+))?\.png$',
                           filename_replacements=None,
                           nude_if=None):
        character_dir = os.path.join(self.input_dir, character_key)
        image_files = [f for f in os.listdir(character_dir) if f.lower().endswith('.png')]
        for filename in image_files:
            resulted_filename = filename
            if filename_replacements:
                resulted_filename = filename_replacements(filename)
            character = _from_filename(resulted_filename, regex, nude_if)
            character.original_filename = filename
            character.original_path = os.path.join(character_dir, filename)
            character_group = next(
                (group for group in self.character_groups if
                 group.character_name == character.character_name and group.pose == character.pose and group.outfit == character.outfit),
                None)

            if not character_group:
                raise Exception(f"Character group not found for"
                                f" \"{character.character_name}"
                                f" {character.pose}"
                                f" {character.outfit}\" for emotion \"{character.emotion}\"")
            character_group.add_sprite(character)


class CharacterSpritesWriter:
    def __init__(self, sprite_output_dir: str, sprite_headers_output_dir: str):
        self.sprite_output_dir = sprite_output_dir
        self.sprite_headers_dir = sprite_headers_output_dir

    def write(self, group: CharacterSpritesGroup):
        default_sprite = next((sprite for sprite in group.sprites if sprite.emotion == group.base_emotion), group.sprites[0])
        self.write_character_background(default_sprite, group.base_emotion_size, group.base_emotion_offset, group.base_origin_offset)
        for sprite in group.sprites:
            self.write_character_sprite(sprite, group)
        group_metadata_name = (f"{group.character_name}"
                               f"{f'_{group.pose}' if group.pose else ''}"
                               f"{f'_{group.outfit}' if group.outfit else ''}")
        self.write_character_group_metadata(group, f'{group_metadata_name}')

    def write_character_background(self, character: CharacterSprite, remove_size: tuple[int, int], remove_offset: tuple[int, int], y_offset: int = 0):
        os.makedirs(self.sprite_output_dir, exist_ok=True)
        output_filename = os.path.join(self.sprite_output_dir,
                                       f"{character.character_name}_bg"
                                       f"{f'_{character.pose}' if character.pose else ''}"
                                       f"{f'_{character.outfit}' if character.outfit else ''}")

        ImageTools.resize_character_background(character.original_path, f'{output_filename}.bmp', remove_size, remove_offset, y_offset)
        self.write_character_background_metadata(f'{output_filename}.json')

    def write_character_background_metadata(self, output_filename):
        metadata = {
            "type": "regular_bg",
            # "bpp_mode": "bpp_4_manual",
            "bpp_mode": "bpp_8",
            "colors_count": 128,
            "compression": "auto_no_huffman",  # or auto_no_huffman?
        }

        with open(output_filename, "w", encoding="utf-8") as json_file:
            json.dump(metadata, json_file, indent=4)

    def write_character_sprite(self, character: CharacterSprite, group: CharacterSpritesGroup):
        os.makedirs(self.sprite_output_dir, exist_ok=True)
        output_filename = os.path.join(self.sprite_output_dir,
                                       f"{character.character_name}_spr"
                                       f"{f'_{character.pose}' if character.pose else ''}"
                                       f"_{character.emotion}"
                                       f"{f'_{character.outfit}' if character.outfit else ''}")

        ImageTools.resize_character_emotion_sprite(character.original_path, f'{output_filename}.bmp',
                                                   group.base_emotion_offset, group.base_emotion_size, group.base_origin_offset)
        # # for tile in ImageTools.create_8x8_tiles(f'{output_filename}.bmp', f'{output_filename}.bmp'):
        # #     self.write_character_sprite_tiles_metadata(tile.removesuffix('.bmp') + '.json')
        # # os.remove(f'{output_filename}.bmp')
        self.write_character_sprite_metadata(f'{output_filename}.json')

    def write_character_sprite_tiles_metadata(self, json_filename):
        metadata = {
            "type": "sprite",
            "bpp_mode": "bpp_4",
            "colors_count": 16,
            "compression": "auto_no_huffman",
        }

        with open(json_filename, "w", encoding="utf-8") as json_file:
            json.dump(metadata, json_file, indent=4)

    def write_character_sprite_metadata(self, json_filename):
        metadata = {
            "type": "sprite",
            # "bpp_mode": "bpp_4",
            # "colors_count": 16,
            "bpp_mode": "bpp_8",
            "colors_count": 128,
            "compression": "auto_no_huffman",
        }

        with open(json_filename, "w", encoding="utf-8") as json_file:
            json.dump(metadata, json_file, indent=4)

    def write_character_group_metadata(self, group: CharacterSpritesGroup, meta_name: str):
        meta_filename = os.path.join(self.sprite_headers_dir, f"{meta_name}.h")
        os.makedirs(self.sprite_headers_dir, exist_ok=True)
        with open(meta_filename, "w", encoding="utf-8") as meta_file:
            meta_file.write(f"#ifndef KS_SPRITEMETA_{meta_name.upper()}\n")
            meta_file.write(f"#define KS_SPRITEMETA_{meta_name.upper()}\n\n")
            meta_file.write(f'#include "character_sprite_meta.h"\n\n')
            # meta_file.write(f'#include "bn_sprite_item.h"\n\n')
            # meta_file.write(f'#include <bn_vector.h>\n\n')
            # for sprite in group.sprites:
            #     character_spr_name = f'{group.character_name}_spr_{group.pose}_{sprite.emotion}{f'_{sprite.outfit}' if sprite.outfit else ''}'
            #     # group.base_emotion_size[0]
            #     for yy in range(group.base_emotion_size[1] // 8):
            #         for xx in range(group.base_emotion_size[0] // 8):
            #             meta_file.write(f'#include "bn_sprite_items_{character_spr_name}_{xx:02X}_{yy:02X}.h"\n')
            meta_file.write(f'namespace ks::sprite_metas {{\n')
            meta_file.write(f'    constexpr inline character_sprite_meta {meta_name}({group.base_emotion_offset[0] + group.base_emotion_size[0] // 2 - 128},\n')
            meta_file.write(f'                                           {group.base_emotion_offset[1] + group.base_emotion_size[1] // 2 - 128});\n')
            # for sprite in group.sprites:
            #     character_spr_name = f'{group.character_name}_spr_{group.pose}_{sprite.emotion}{f'_{sprite.outfit}' if sprite.outfit else ''}'
            #     # group.base_emotion_size[0]
            #     meta_file.write(
            #         f'    constexpr inline unsigned BN_CODE_EWRAM int {character_spr_name}_tiles_x = {group.base_emotion_size[0] // 8};\n')
            #     meta_file.write(
            #         f'    constexpr inline unsigned BN_CODE_EWRAM int {character_spr_name}_tiles_y = {group.base_emotion_size[1] // 8};\n')
            #     meta_file.write(f'    constexpr inline BN_CODE_EWRAM const bn::sprite_item* {character_spr_name}_tiles[] = {{\n')
            #     for yy in range(group.base_emotion_size[1] // 8):
            #         for xx in range(group.base_emotion_size[0] // 8):
            #             meta_file.write(f'        &bn::sprite_items::{character_spr_name}_{xx:02X}_{yy:02X},\n')
            #     meta_file.write(f'    }};\n')
            meta_file.write(f'}}\n\n')
            meta_file.write(f'#endif  // KS_SPRITEMETA_{meta_name.upper()}\n')

def _from_filename(filename: str, regex: str, nude_if=None):
    match = re.match(regex, filename)
    if not match:
        raise Exception(f"Filename {filename} does not match regex {regex}")
    character_name = match.group("name")
    pose = match.group("pose") if "pose" in match.groupdict() else None
    outfit = match.group("outfit") if "outfit" in match.groupdict() else None
    emotion = match.group("emotion")
    nude_if(filename.removesuffix('.png')) if nude_if else False
    return CharacterSprite(character_name, pose, emotion, outfit, False)
