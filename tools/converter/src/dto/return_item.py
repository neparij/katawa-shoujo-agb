from src.dto.sequence_item import SequenceItem, SequenceType


class ReturnItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self):
        super().__init__(SequenceType.RETURN)

    def __str__(self):
        return "ReturnItem()"
