from enum import Enum

from src.dto.sequence_item import SequenceItem, SequenceType


class SoundAction(Enum):
    PLAY = "play"
    STOP = "stop"
    PAUSE = "pause"
    RESUME = "resume"


class SoundEffect(Enum):
    FADEIN = "fadein"
    FADEOUT = "fadeout"
    NONE = ""


class SoundChannel(Enum):
    SOUND = "SOUND_CHANNEL_SOUND"
    AMBIENT = "SOUND_CHANNEL_AMBIENT"


class SoundItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, action: SoundAction, sound, channel: SoundChannel, effect: SoundEffect, value):
        super().__init__(SequenceType.SOUND)
        self.action = action
        self.sound = sound
        self.channel = channel
        self.effect = effect
        self.value = value

    def __str__(self):
        return f"SoundItem(action={self.action}, sound={self.sound}, channe={self.channel}, effect={self.effect}, value={self.value})"
