from typing import Dict

from src.dto.sequence_item import SequenceItem, SequenceType


class DoubleSpeakItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, identifier: str, actor_left_ref: str, actor_right_ref: str, message_left: Dict[str, str], message_right: Dict[str, str], label_name: str = None):
        super().__init__(SequenceType.DOUBLESPEAK)
        self.id = identifier
        self.actor_left_ref = actor_left_ref
        self.actor_right_ref = actor_right_ref
        self.message_left = message_left
        self.message_right = message_right
        self.label_name = label_name

        print(f"Created DoubleSpeakItem: {self}")

    def __str__(self):
        return f"DoubleSpeakItem(actor_left_ref={self.actor_left_ref}, actor_right_ref={self.actor_right_ref}, message_left={self.message_left}, message_right={self.message_right}, id={self.id})"
