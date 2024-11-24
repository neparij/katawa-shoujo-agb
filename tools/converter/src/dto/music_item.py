from enum import Enum

from src.dto.sequence_item import SequenceItem, SequenceType


class MusicAction(Enum):
    PLAY = "play"
    STOP = "stop"
    PAUSE = "pause"
    RESUME = "resume"


class MusicEffect(Enum):
    FADEIN = "fadein"
    FADEOUT = "fadeout"
    NONE = ""


class MusicItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, action: MusicAction, music, effect: MusicEffect, value):
        super().__init__(SequenceType.MUSIC)
        self.action = action
        self.music = music
        self.effect = effect
        self.value = value

    def __str__(self):
        return f"MusicItem(action={self.action}, music={self.music}, effect={self.effect}, value={self.value})"
