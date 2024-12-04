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


class CharacterSpritesGroup:
    def __init__(self, character_name: str, pose: str, outfit: str | None, base_emotion: str | None,
                 base_emotion_offset: tuple[int, int], base_emotion_size: tuple[int, int] = (32, 32)):
        self.character_name = character_name
        self.pose = pose
        self.outfit = outfit
        self.sprites: List[CharacterSprite] = []
        self.base_emotion = base_emotion
        self.base_emotion_size = base_emotion_size
        self.base_emotion_offset = base_emotion_offset

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
        self.process_rin()
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

    def _process_character(self,
                           character_key: str,
                           regex: str = r'(?P<name>[^_]+)_(?P<pose>[^_]+)_(?P<emotion>[^_]+)(_(?P<outfit>[^_]+))?\.png$',
                           nude_if=None):
        character_dir = os.path.join(self.input_dir, character_key)
        image_files = [f for f in os.listdir(character_dir) if f.lower().endswith('.png')]
        for filename in image_files:
            character = _from_filename(filename, regex, nude_if)
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
                                f" {character.outfit}\"")
            character_group.add_sprite(character)


class CharacterSpritesWriter:
    def __init__(self, sprite_output_dir: str, sprite_headers_output_dir: str):
        self.sprite_output_dir = sprite_output_dir
        self.sprite_headers_dir = sprite_headers_output_dir

    def write(self, group: CharacterSpritesGroup):
        default_sprite = next((sprite for sprite in group.sprites if sprite.emotion == group.base_emotion), group.sprites[0])
        self.write_character_background(default_sprite, group.base_emotion_size, group.base_emotion_offset)
        for sprite in group.sprites:
            self.write_character_sprite(sprite, group)
        group_metadata_name = (f"{group.character_name}_{group.pose}"
                                   f"{f'_{group.outfit}' if group.outfit else ''}")
        self.write_character_group_metadata(group, f'{group_metadata_name}')

    def write_character_background(self, character: CharacterSprite, remove_size: tuple[int, int], remove_offset: tuple[int, int]):
        os.makedirs(self.sprite_output_dir, exist_ok=True)
        output_filename = os.path.join(self.sprite_output_dir,
                                       f"{character.character_name}_bg_{character.pose}"
                                       f"{f'_{character.outfit}' if character.outfit else ''}")

        ImageTools.resize_character_background(character.original_path, f'{output_filename}.bmp', remove_size, remove_offset)
        self.write_character_background_metadata(f'{output_filename}.json')

    def write_character_background_metadata(self, output_filename):
        metadata = {
            "type": "regular_bg",
            "bpp_mode": "bpp_4_manual",
            "compression": "auto_no_huffman",  # or auto_no_huffman?
        }

        with open(output_filename, "w", encoding="utf-8") as json_file:
            json.dump(metadata, json_file, indent=4)

    def write_character_sprite(self, character: CharacterSprite, group: CharacterSpritesGroup):
        os.makedirs(self.sprite_output_dir, exist_ok=True)
        output_filename = os.path.join(self.sprite_output_dir,
                                       f"{character.character_name}_spr_{character.pose}"
                                       f"_{character.emotion}"
                                       f"{f'_{character.outfit}' if character.outfit else ''}")

        ImageTools.resize_character_emotion_sprite(character.original_path, f'{output_filename}.bmp',
                                                   group.base_emotion_offset, group.base_emotion_size)
        # for tile in ImageTools.create_8x8_tiles(f'{output_filename}.bmp', f'{output_filename}.bmp'):
        #     self.write_character_sprite_tiles_metadata(tile.removesuffix('.bmp') + '.json')
        # os.remove(f'{output_filename}.bmp')
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
            "bpp_mode": "bpp_4",
            "colors_count": 16,
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
    pose = match.group("pose")
    outfit = match.group("outfit")
    emotion = match.group("emotion")
    nude_if(filename.removesuffix('.png')) if nude_if else False
    return CharacterSprite(character_name, pose, emotion, outfit, False)
