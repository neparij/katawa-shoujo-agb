class TextPaletteData:
    def __init__(self, name: str, text_color: tuple, background_color: tuple):
        self.name = name
        self.text_color = text_color
        self.background_color = background_color

    def get_palette(self) -> [int]:
        colors = []
        alpha_threshold = 0.2
        colors_count = 16

        for i in range(colors_count):
            if i == 0:
                r = int(self.background_color[0])
                g = int(self.background_color[1])
                b = int(self.background_color[2])
                colors.extend([r, g, b])
                continue

            lerp_factor = (i / (colors_count - 1)) + alpha_threshold - (i / (colors_count - 1)) * alpha_threshold

            r = int(self.background_color[0] + (self.text_color[0] - self.background_color[0]) * lerp_factor)
            g = int(self.background_color[1] + (self.text_color[1] - self.background_color[1]) * lerp_factor)
            b = int(self.background_color[2] + (self.text_color[2] - self.background_color[2]) * lerp_factor)
            colors.extend([r, g, b])
        return colors

    def get_name(self) -> str:
        return f'fontpalette_{self.name}'