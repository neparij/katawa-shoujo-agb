from src.dto.sequence_item import SequenceItem, SequenceType


class RunLabelItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, function_callback: str, inline_call: bool = False, label_name: str = None):
        super().__init__(SequenceType.RUN_LABEL)
        self.function_callback = function_callback
        self.inline_call = inline_call
        self.label_name = label_name

    def __str__(self):
        return f"RunLabelItem(function_callback={self.function_callback}, inline_call={self.inline_call})"
