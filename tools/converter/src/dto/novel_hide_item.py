from src.dto.sequence_item import SequenceItem, SequenceType

class NovelHideItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self):
        super().__init__(SequenceType.NVL_HIDE)

    def __str__(self):
        return f"NovelHideItem()"
