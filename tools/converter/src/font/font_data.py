from typing import List, Tuple

from PIL import ImageFont


class FontData:
    def __init__(self, name: str, font_path: str, char_size: tuple[int, int], font_size: float,
                 stroke_width: float = 0, size_multiplier: float = 10):
        self.name = name
        self.font_path = font_path
        self.char_size = char_size
        self.font_size = font_size
        self.stroke_width = stroke_width
        self.size_multiplier = size_multiplier

    def get_font(self):
        return ImageFont.truetype(self.font_path, self.font_size * self.size_multiplier)

    def get_name(self) -> str:
        return f'font_{self.name}'

def create_font_group(default_font_path: str, bold_font_path: str, small_font_path: str,
                      char_size: Tuple[int, int], main_size: int, small_size: int) -> List[FontData]:
    return [
        FontData("default", default_font_path, char_size, main_size),
        FontData("bold", bold_font_path, char_size, main_size, 0.3),
        FontData("small", small_font_path, char_size, small_size),
    ]