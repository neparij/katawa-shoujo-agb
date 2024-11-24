from enum import Enum
from typing import List

from src.dto.sequence_item import SequenceItem


class SequenceGroupType(Enum):
    LABEL = "label"
    MENU = "menu"
    CONDITION = "condition"


class ConditionWrapper:
    def __init__(self, condition, callback = None):
        self.function_callback = callback
        self.condition = condition
        self.sequence: List[SequenceItem] = []

    def __str__(self):
        return f"ConditionWrapper(condition={self.condition}, sequence={self.sequence})"

class SequenceGroup:
    def __init__(self, name, t: SequenceGroupType, is_called_inline = False):
        self.name = name
        self.type = t
        self.sequence: List[SequenceItem] = []
        self.translation_identifiers: List[str] = []
        self.conditions: List[ConditionWrapper] = []
        self.is_called_inline = is_called_inline

    def __str__(self):
        return f"SequenceGroup(name={self.name}, type={self.type}, sequence={self.sequence}, translation_identifiers={self.translation_identifiers}, conditions={self.conditions})"

    def add_condition(self, condition = None, callback = None):
        self.conditions.append(ConditionWrapper(condition, callback))

    def add_sequence_item(self, item: SequenceItem):
        if isinstance(item, SequenceItem):
            if self.type == SequenceGroupType.CONDITION:
                self.conditions[-1].sequence.append(item)
            elif self.type == SequenceGroupType.MENU and self.conditions:
                self.conditions[-1].sequence.append(item)
            else:
                self.sequence.append(item)
        else:
            raise TypeError("item must be an instance of SequenceItem or its subclasses")