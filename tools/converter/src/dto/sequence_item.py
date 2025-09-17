from abc import ABC, abstractmethod
from enum import Enum


class SequenceType(Enum):
    ASSIGNMENT = "assignment"
    BACKGROUND = "background"
    CUSTOM_EVENT = "custom_event"
    CUSTOM_EVENT_STATE = "custom_event_state"
    CONDITION = "condition"
    DIALOG = "dialog"
    DOUBLESPEAK = "doublespeak"
    MENU = "menu"
    MUSIC = "music"
    SOUND = "sound"
    RETURN = "return"
    RUN_LABEL = "run_label"
    SHOW = "show"
    SHOW_TRANSFORM = "show_transform"
    BACKGROUND_TRANSFORM = "background_transform"
    BACKGROUND_TRANSITION = "background_transition"
    HIDE = "hide"
    NVL_CLEAR = "nvl_clear"
    NVL_HIDE = "nvl_hide"
    PAUSE = "pause"
    UPDATE_VISUALS = "update_visuals"
    SHOW_VIDEO = "show_video"


class SequenceItem(ABC):
    def __init__(self, t: SequenceType):
        self.type = t

    def get_type(self):
        return self.type
