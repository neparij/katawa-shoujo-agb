from src.dto.sequence_item import SequenceItem, SequenceType
from src.dto.show_item import ShowEvent, ShowPosition


class ShowDisplayableItem(SequenceItem):
    def __init__(self, name: str, subvariant: str | None, event: ShowEvent,
                 position: ShowPosition, palette_variant: str):
        super().__init__(SequenceType.SHOW_DISPLAYABLE)
        self.name = name
        self.subvariant = subvariant
        self.event = event
        self.position = position
        self.palette_variant = palette_variant

    def __str__(self):
        return (f"ShowDisplayableItem(name={self.name}, subvariant={self.subvariant}, "
                f"event={self.event}, position={self.position}, "
                f"palette_variant={self.palette_variant})")
