from src.dto.sequence_item import SequenceItem, SequenceType

class AssignmentItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, content: str):
        super().__init__(SequenceType.ASSIGNMENT)
        self.content = content
