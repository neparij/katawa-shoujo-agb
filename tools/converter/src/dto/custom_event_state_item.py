from src.dto.sequence_item import SequenceItem, SequenceType

class CustomEventStateItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, state: int):
        super().__init__(SequenceType.CUSTOM_EVENT_STATE)
        self.state = state

    def __str__(self):
        return f"CustomEventStateItem(state={self.state})"
