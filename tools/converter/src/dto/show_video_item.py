
from src.dto.sequence_item import SequenceItem, SequenceType


class ShowVideoItem(SequenceItem):
    def some_method(self):
        pass

    def __init__(self, video: str):
        super().__init__(SequenceType.SHOW_VIDEO)
        self.video = video

    def __str__(self):
        return f"ShowVideoItem(video={self.video})"
