from src.dto.sequence_item import SequenceItem, SequenceType


class BackgroundItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, background: str):
        super().__init__(SequenceType.BACKGROUND)
        self.background = background

    def __str__(self):
        return f"BackgroundItem(background={self.background})"
