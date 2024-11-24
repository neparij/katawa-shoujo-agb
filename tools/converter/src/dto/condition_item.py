from src.dto.sequence_item import SequenceItem, SequenceType


class ConditionItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, function_callback: str):
        super().__init__(SequenceType.CONDITION)
        self.function_callback = function_callback

    def __str__(self):
        return f"ConditionItem(function_callback={self.function_callback})"
