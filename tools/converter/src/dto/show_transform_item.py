from src.dto.sequence_item import SequenceItem, SequenceType
from src.dto.show_item import ShowPosition


class ShowTransformItem(SequenceItem):
    """Per-line transform applied to the most recently shown sprite —
    Ren'Py-style ``xpos``/``xanchor``/``ypos``/``yanchor`` lines that
    follow a ``show <char>`` block.

    Coordinates are stored normalised (Python ``float`` 0..1) and emitted
    verbatim into the generated C++ as ``bn::fixed`` literals. The
    actual pixel resolution happens at runtime in ``SceneManager`` where
    the current variant's body width is known; see
    ``_resolve_pixel_position`` in ``src/scenemanager.cpp``.
    """

    def some_method(self):
        pass

    def __init__(self, sprite: str, position: ShowPosition | None,
                 xpos: float, xanchor: float,
                 ypos: float = 1.0, yanchor: float = 1.0):
        super().__init__(SequenceType.SHOW_TRANSFORM)
        self.sprite = sprite
        self.position = position
        self.xpos = xpos
        self.xanchor = xanchor
        self.ypos = ypos
        self.yanchor = yanchor

    def __str__(self):
        return (
            f"ShowTransformItem(sprite={self.sprite}, position={self.position}, "
            f"xpos={self.xpos}, xanchor={self.xanchor}, "
            f"ypos={self.ypos}, yanchor={self.yanchor})"
        )
