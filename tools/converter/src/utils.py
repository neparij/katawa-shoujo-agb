import re
from typing import Dict, List, cast
import sentencepiece as spm

from src.scenario.sequence_group import SequenceGroup

FILL_COLORS = [
    "black",
    "bloodred",
    "white",
    "pink",
    "darkgrey"
]

#     /// SOH - sets cursor to render text by chars
#     static constexpr char CTL_FAST = 0x01;
#     /// STX - starts bold text (switch spritefont)
#     static constexpr char CTL_BOLD_START = 0x02;
#     /// ETX - ends bold text (restore spritefont)
#     static constexpr char CTL_BOLD_END = 0x03;
#     /// EOT - starts strikethrough text (switch spritefont?)
#     static constexpr char CTL_STRIKE_START = 0x04;
#     /// ENQ - ends strikethrough text (restore spritefont?)
#     static constexpr char CTL_STRIKE_END = 0x05;
#     /// ACK - wait command (next byte is count of 1/10 seconds to wait or 0xFF to wait for user input)
#     static constexpr char CTL_WAIT = 0x06;
#     /// BEL - do not wait for user input to continue dialogue
#     static constexpr char CTL_NOWAIT = 0x07;
#     /// BS - sets the color (switch spritepalette, next byte is palette index starting from 0x01)
#     static constexpr char CTL_COLOR_START = 0x08;
#     /// HT - restore color (switch spritepalette)
#     static constexpr char CTL_COLOR_END = 0x09;

CMD_START = b'\xFF'
CTL_FAST = b'\x01'
CTL_BOLD_START = b'\x02'
CTL_BOLD_END = b'\x03'
CTL_STRIKE_START = b'\x04'
CTL_STRIKE_END = b'\x05'
CTL_WAIT = b'\x06'
CTL_NOWAIT = b'\x07'
CTL_COLOR_START = b'\x08'
CTL_COLOR_END = b'\x09'
CTL_NEWLINE = b'\x0A'

def sanitize_function_name(text):
    return re.sub(r"[^a-zA-Z0-9_]", "", text.replace(" ", "_").lower())

def sanitize_comment_text(text):
    return text.replace("\n", " ").replace("\r", " ").replace("\t", " ")

def sanitize_ingame_text(text: str):
    text = text.replace("’", "'")
    # text = text.replace("　", " ") # Ideographic space (CJK)
    return text

def fixed_literal(value: float) -> str:
    """Render a Python float as a Butano `bn::fixed` literal preserving
    the converter's normalised Ren'Py semantics (0.0 = left/top edge,
    1.0 = right/bottom edge of the relevant container).

    Position resolution — anchor offset, screen mapping — happens at
    runtime in `SceneManager` (see `_resolve_pixel_position` in
    `src/scenemanager.cpp`) where the actual `body.vis_*` bbox of the
    current variant is known. The converter no longer hardcodes
    `sprite_width = 128`; that hack mispositioned every body whose
    visible width differs from 128 px (which is most of them — bodies
    range ~64..120 px). See `tools/converter/src/utils.py` history /
    `git blame` for the pre-migration math.
    """
    return f"bn::fixed({value:g})"

def get_paletted_variant(variant: str) -> (str, str):
    if variant.endswith("_ss"):
        return variant.removesuffix("_ss"), "PALETTE_VARIANT_SPRITE_SUNSET"
    elif variant.endswith("_ni"):
        return variant.removesuffix("_ni"), "PALETTE_VARIANT_SPRITE_NIGHT"
    elif variant.endswith("_rn"):
        return variant.removesuffix("_rn"), "PALETTE_VARIANT_SPRITE_RAIN"
    else:
        return variant, "PALETTE_VARIANT_DEFAULT"

def is_color_filled_bg(background: str) -> bool:
    return background in FILL_COLORS

def starts_with_filled_bg(line: str) -> bool:
    for color in FILL_COLORS:
        if line.startswith(f"scene {color}"):
            return True
    return False

def add_translations(tl_list: List[Dict[str,str]], values: Dict[str,str]) -> int:
    """
    Adds a translation values to the specified translation group in the dictionary.
    :param tl_list: The dictionary containing translation groups.
    :param values: The translation values to add.
    :return: The index of the added value in the group list.
    """
    tl_list.append(values)
    return len(tl_list) - 1

def add_translations_optional(tl_list: List[Dict[str,str]], values: Dict[str,str]) -> int:
    """
    Adds a translation values to the specified translation group in the dictionary if it doesn't already exist.
    :param tl_list: The dictionary containing translation groups.
    :param values: The translation values to add.
    :return: The index of the value in the group list.
    """
    if values in tl_list:
        return tl_list.index(values)
    return add_translations(tl_list, values)

def get_textdb_name(script_filename: str) -> str:
    return script_filename.split(".")[0].removeprefix("script_")

def bytecode_format(text: str, cmd_start_bytes: int = 1) -> bytes:
    """
    :param text: The input text.
    :param cmd_start_bytes: Number of command start bytes to prepend before each control character.
    :return: The text formatted with control characters as bytes.
    """
    cmd = CMD_START * cmd_start_bytes

    data = text.encode("utf-8")
    data = data.replace(b"{fast}", cmd + CTL_FAST)
    data = data.replace(b"{b}", cmd + CTL_BOLD_START)
    data = data.replace(b"{/b}", cmd + CTL_BOLD_END)
    data = data.replace(b"{s}", cmd + CTL_STRIKE_START)
    data = data.replace(b"{/s}", cmd + CTL_STRIKE_END)
    data = data.replace(b"{w}", cmd + CTL_WAIT + b"\xFF")
    data = re.sub(
        br"\{w=(\d*\.*\d+)\}",
        lambda m: cmd + CTL_WAIT + bytes([min(255, max(1, int(float(m.group(1)) * 10)))]),
        data
    )
    data = data.replace(b"{nw}", cmd + CTL_NOWAIT)
    data = data.replace(b"{newline}", cmd + CTL_NEWLINE)
    # TODO: Support colors

    return data

def pack_to_12bits(data: bytes) -> bytes:
    tokens = [data[i] | (data[i + 1] << 8) for i in range(0, len(data), 2)]

    if len(tokens) % 2 == 1:
        tokens.append(0)

    packed = bytearray()
    for i in range(0, len(tokens), 2):
        a, b = tokens[i], tokens[i+1]
        packed.append(a & 0xFF)
        packed.append(((a >> 8) & 0x0F) | ((b & 0x0F) << 4))
        packed.append((b >> 4) & 0xFF)

    return bytes(packed)


def unpack_from_12bits(data: bytes) -> bytes:
    unpacked = bytearray()
    for i in range(0, len(data), 3):
        byte1 = data[i]
        byte2 = data[i + 1]
        byte3 = data[i + 2]

        first_token = byte1 | ((byte2 & 0x0F) << 8)
        second_token = ((byte2 >> 4) & 0x0F) | (byte3 << 4)

        unpacked.append(first_token & 0xFF)
        unpacked.append((first_token >> 8) & 0xFF)
        if second_token != 0:  # Avoid adding extra byte if it was padding
            unpacked.append(second_token & 0xFF)
            unpacked.append((second_token >> 8) & 0xFF)

    return bytes(unpacked)

def spm_with_bytecode_encode(text: str, spp: spm.SentencePieceProcessor, is_cjk: bool, pack_cjk: bool = False) -> bytes:
    """
    :param text: The input text.
    :param spp: The SentencePieceProcessor instance.
    :param is_cjk: Whether to use 2-byte encoding for CJK characters.
    :param pack_cjk: Whether to pack CJK characters into 12-bit encoding
                     (Reduces uncompressed size, but adds complexity).
    :return: The SPM-encoded text formatted with control characters as bytes.
    """
    command_re = re.compile(r"(\{[^\}]+\})")
    text = text.replace("\n", "{newline}") # Ensure newlines are handled, because SPM will revoke them
    parts = command_re.split(text)
    encoded: bytes = b""
    max_spm_value = 0xFFFF if is_cjk else 0xFF
    for part in parts:
        if part and not command_re.match(part):
            spm_ids = spp.EncodeAsIds(part)

            # Check that text is the same:
            decoded_text = spp.DecodeIds(spm_ids)
            if decoded_text != part:
                raise Exception(f"SPM encoding/decoding mismatch: '{part}' != '{decoded_text}'")

            if 0 in spm_ids:
                raise Exception(f"SPM encoding produced ID 0 (unknown token) for part: '{part}'")
            if max_spm_value in spm_ids:
                raise Exception(f"SPM encoding produced ID {max_spm_value} (reserved token) for part: '{part}'")

            if is_cjk and pack_cjk:
                # TODO: To check that we actual need it.
                # TODO: If necessary, set cmd_start_bytes=3 to prevent collisions.
                encoded_chunk = b""
                for spm_id in spm_ids:
                    encoded_chunk += spm_id.to_bytes(2, byteorder='little')
                bitpacked = pack_to_12bits(encoded_chunk)

                # Check that text is the same after packing/unpacking:
                unpacked = unpack_from_12bits(bitpacked)
                if unpacked != encoded_chunk:
                    raise Exception(f"12-bit packing/unpacking mismatch: '{encoded_chunk}' != '{unpacked}'")

                encoded += bitpacked
            elif is_cjk:
                for spm_id in spm_ids:
                    encoded += spm_id.to_bytes(2, byteorder='little')
            else:
                for spm_id in spm_ids:
                    encoded += spm_id.to_bytes(1, byteorder='little')
        elif command_re.match(part):
            encoded += bytecode_format(part, cmd_start_bytes=2 if is_cjk else 1)

    return encoded + b"\x00" * (2 if is_cjk else 1)  # Null-terminate


def split_by_commands(text: str) -> List[str]:
    """
    :param text: The input text with commands (e.g. {b}, {w=1.5}, etc.)
    :return: The array of text without commands (split by commands)
    """
    command_re = re.compile(r"(\{[^\}]+\})")
    parts = command_re.split(text)
    return [part for part in parts if part and not command_re.match(part)]


def collect_scenario_sentences(scenario: List[SequenceGroup], locale: str, out: List[str]):
    def _parse_sequence_item(_item):
        from src.dto.sequence_item import SequenceType
        from src.dto.dialog_item import DialogItem

        if item.type == SequenceType.DIALOG:
            dialog = cast(DialogItem, item)
            if locale not in dialog.message:
                raise ValueError(f"Missing translation for id {dialog.id} in locale {locale}")
            text_with_commands = dialog.message[locale]
            text_array = split_by_commands(text_with_commands)
            out.extend(text_array)

    for sequence_group in scenario:
        for condition in sequence_group.conditions:
            for item in condition.sequence:
                _parse_sequence_item(item)
        for item in sequence_group.sequence:
            _parse_sequence_item(item)
