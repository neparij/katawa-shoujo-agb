from enum import Enum

from src.dto.sequence_item import SequenceItem, SequenceType


class BgShowPosition(Enum):
    DEFAULT = "default"
    CENTER = "center"
    BGLEFT = "bgleft"
    BGRIGHT = "bgright"


class BackgroundItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, background: str, position: BgShowPosition = BgShowPosition.DEFAULT, dissolve_time: float = 0):
        super().__init__(SequenceType.BACKGROUND)
        self.background = background
        self.position = position
        self.dissolve_time = dissolve_time

    def __str__(self):
        return f"BackgroundItem(background={self.background})"
