from src.dto.sequence_item import SequenceItem, SequenceType


class UpdateVisualsItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self):
        super().__init__(SequenceType.UPDATE_VISUALS)

    def __str__(self):
        return f"UpdateVisualsItem()"
