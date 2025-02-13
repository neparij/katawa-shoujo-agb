from abc import ABC, abstractmethod
from enum import Enum


class SequenceType(Enum):
    ASSIGNMENT = "assignment"
    BACKGROUND = "background"
    CONDITION = "condition"
    DIALOG = "dialog"
    MENU = "menu"
    MUSIC = "music"
    SOUND = "sound"
    RETURN = "return"
    RUN_LABEL = "run_label"
    SHOW = "show"
    SHOW_TRANSFORM = "show_transform"
    BACKGROUND_TRANSFORM = "background_transform"
    HIDE = "hide"
    UPDATE_VISUALS = "update_visuals"
    SHOW_VIDEO = "show_video"


class SequenceItem(ABC):
    def __init__(self, t: SequenceType):
        self.type = t

    def get_type(self):
        return self.type
