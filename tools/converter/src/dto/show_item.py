from enum import Enum

from src.dto.sequence_item import SequenceItem, SequenceType


class ShowEvent(Enum):
    CHARACTER_CHANGE = "character_change"
    NONE = ""


class ShowItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, sprite: str, event: ShowEvent):
        super().__init__(SequenceType.SHOW)
        self.sprite = sprite
        self.event = event

    def __str__(self):
        return f"ShowItem(sprite={self.sprite}, event={self.event})"
