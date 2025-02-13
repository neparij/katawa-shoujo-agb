from src.dto.sequence_item import SequenceItem, SequenceType
from src.dto.show_item import ShowPosition


class ShowTransformItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, sprite: str, position: ShowPosition|None, x: int|None):
        super().__init__(SequenceType.SHOW_TRANSFORM)
        self.sprite = sprite
        self.position = position
        self.x = x

    def __str__(self):
        return f"ShowTransformItem(sprite={self.sprite}, position={self.position}, x={self.x})"
