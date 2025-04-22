from src.dto.sequence_item import SequenceItem, SequenceType


class PauseItem(SequenceItem):
    def __init__(self, value: float):
        super().__init__(SequenceType.PAUSE)
        self.value = value

    def __str__(self):
        return f"PauseItem(value={self.value})"
