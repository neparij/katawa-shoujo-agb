from src.dto.sequence_item import SequenceItem, SequenceType


class DialogItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, identifier: str, actor: str, message: str, actor_ref: str = None):
        super().__init__(SequenceType.DIALOG)
        self.id = identifier
        self.actor = actor
        self.actor_ref = actor_ref
        self.message = message

    def __str__(self):
        return f"DialogItem(actor={self.actor}, actor_ref={self.actor_ref}, message={self.message}, id={self.id})"
