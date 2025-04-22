from enum import Enum

from src.dto.background_item import BgTransition
from src.dto.sequence_item import SequenceItem, SequenceType

class CustomEventItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, background: str, event: str, transition: BgTransition = BgTransition.NONE, dissolve_time: float = 0):
        super().__init__(SequenceType.CUSTOM_EVENT)
        self.background = background
        self.event = event
        self.transition = transition
        self.dissolve_time = dissolve_time

    def __str__(self):
        return f"CustomEventItem(background={self.background}, event={self.event})"
