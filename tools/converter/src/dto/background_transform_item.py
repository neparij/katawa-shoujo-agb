from src.dto.background_item import BgShowPosition
from src.dto.sequence_item import SequenceItem, SequenceType


class BackgroundTransformItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, position: BgShowPosition|None):
        super().__init__(SequenceType.BACKGROUND_TRANSFORM)
        self.position = position

    def __str__(self):
        return f"BackgroundTransformItem(position={self.position})"
