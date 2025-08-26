from enum import Enum

from src.dto.sequence_item import SequenceItem, SequenceType


class ShowEvent(Enum):
    CHARACTER_CHANGE = "character_change"
    NONE = ""

class ShowPosition(Enum):
    DEFAULT = "default"
    TWOLEFT = "twoleft"
    TWORIGHT = "tworight"
    CLOSELEFT = "closeleft"
    CLOSERIGHT = "closeright"
    OFFSCREENLEFT = "offscreenleft"
    OFFSCREENRIGHT = "offscreenright"
    LEFT = "left"
    RIGHT = "right"
    CENTER = "center"

class ShowItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, sprite: str, variant: str|None, event: ShowEvent, position: ShowPosition, palette_variant: str):
        super().__init__(SequenceType.SHOW)
        self.sprite = sprite
        self.variant = variant
        self.event = event
        self.position = position
        self.palette_variant = palette_variant

    def __str__(self):
        return f"ShowItem(sprite={self.sprite}, variant={self.variant}, event={self.event}, position={self.position}, palette_variant={self.palette_variant})"
