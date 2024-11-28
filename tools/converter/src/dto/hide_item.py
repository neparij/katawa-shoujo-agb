from enum import Enum

from src.dto.sequence_item import SequenceItem, SequenceType


class HideEvent(Enum):
    CHARACTER_EXIT = "character_exit"
    NONE = ""


class HideItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, sprite: str, event: HideEvent):
        super().__init__(SequenceType.HIDE)
        self.sprite = sprite
        self.event = event

    def __str__(self):
        return f"HideItem(sprite={self.sprite}, event={self.event})"
