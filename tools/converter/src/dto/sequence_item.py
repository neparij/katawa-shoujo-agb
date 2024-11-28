from abc import ABC, abstractmethod
from enum import Enum


class SequenceType(Enum):
    ASSIGNMENT = "assignment"
    BACKGROUND = "background"
    CONDITION = "condition"
    DIALOG = "dialog"
    MENU = "menu"
    MUSIC = "music"
    RETURN = "return"
    RUN_LABEL = "run_label"
    SHOW = "show"
    HIDE = "hide"


class SequenceItem(ABC):
    def __init__(self, t: SequenceType):
        self.type = t
