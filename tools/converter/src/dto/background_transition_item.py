from src.dto.background_item import BgTransition
from src.dto.sequence_item import SequenceItem, SequenceType


class BackgroundTransitionItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, transition: BgTransition):
        super().__init__(SequenceType.BACKGROUND_TRANSITION)
        self.transition = transition

    def __str__(self):
        return f"BackgroundTransitionItem(transition={self.transition})"
