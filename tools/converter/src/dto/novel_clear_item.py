from src.dto.sequence_item import SequenceItem, SequenceType

class NovelClearItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self):
        super().__init__(SequenceType.NVL_CLEAR)

    def __str__(self):
        return f"NovelClearItem()"
