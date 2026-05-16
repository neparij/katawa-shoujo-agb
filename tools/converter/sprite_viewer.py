#!/usr/bin/env python3
"""
Katawa Shoujo GBA: Character Editor — sprite YAML viewer (future editor).

Usage:
    python sprite_viewer.py path/to/character_sprites.yaml
    python sprite_viewer.py path/to/character_sprites.yaml --sprites-dir /path/to/sprites
"""

import argparse
import hashlib
import os
import shutil
import sys
import tempfile
import tkinter as tk
from tkinter import ttk

import yaml
from PIL import Image, ImageDraw, ImageTk

# Allow importing from tools/converter/src when running as a script
_CONVERTER_DIR = os.path.dirname(os.path.abspath(__file__))
if _CONVERTER_DIR not in sys.path:
    sys.path.insert(0, _CONVERTER_DIR)

from src.image_tools.image_tools import ImageTools

GRID_BASE = 256   # base canvas size in pixels at zoom x1
GRID_CELL = 8     # sprite-space grid cell in pixels

TREE_DEFAULT_WIDTH = 300

COLORS = {
    "bg":      "#1e1e2e",
    "panel":   "#181825",
    "surface": "#313244",
    "border":  "#45475a",
    "text":    "#cdd6f4",
    "subtext": "#a6adc8",
    "accent":  "#89b4fa",
    "green":   "#a6e3a1",
    "red":     "#f38ba8",
    "img_bg":  "#11111b",
    "zoom_active": "#89b4fa",
    "zoom_idle":   "#45475a",
}


# ---------------------------------------------------------------------------
# Helpers
# ---------------------------------------------------------------------------

def make_grid_image(size: int, cell: int) -> Image.Image:
    """Dark background — used as fallback when no preview is available."""
    return Image.new("RGB", (size, size), (20, 20, 30))


GBA_W, GBA_H = 240, 160   # GBA screen resolution


def draw_gba_mask_overlay(img: Image.Image) -> Image.Image:
    """Darken (black 50%) everything outside the centred GBA viewport.

    The viewport is proportionally scaled with the image: if the image is
    N×N pixels (N = 256 * zoom), the GBA area is (240*N//256) × (160*N//256).
    """
    img = img.copy().convert("RGBA")
    w, h = img.size
    vp_w = GBA_W * w // GRID_BASE   # scaled viewport width
    vp_h = GBA_H * h // GRID_BASE   # scaled viewport height
    rx = (w - vp_w) // 2
    ry = (h - vp_h) // 2

    overlay = Image.new("RGBA", (w, h), (0, 0, 0, 0))
    draw = ImageDraw.Draw(overlay)
    shade = (0, 0, 0, 128)   # 50% black

    # Four rectangles around the central GBA viewport
    if ry > 0:
        draw.rectangle([0, 0, w, ry], fill=shade)                        # top
        draw.rectangle([0, ry + vp_h, w, h], fill=shade)                 # bottom
    if rx > 0:
        draw.rectangle([0, ry, rx, ry + vp_h], fill=shade)               # left
        draw.rectangle([rx + vp_w, ry, w, ry + vp_h], fill=shade)        # right

    return Image.alpha_composite(img, overlay).convert("RGB")


def draw_grid_overlay(img: Image.Image, cell: int) -> Image.Image:
    """Draw grid lines on top of an existing image (in-place copy). Returns the image."""
    img = img.copy()
    draw = ImageDraw.Draw(img)
    size_w, size_h = img.size
    for i in range(0, max(size_w, size_h) + 1, cell):
        minor = i % (cell * 4) != 0
        color = (55, 57, 75) if minor else (90, 94, 130)
        if i <= size_w:
            draw.line([(i, 0), (i, size_h)], fill=color)
        if i <= size_h:
            draw.line([(0, i), (size_w, i)], fill=color)
    return img


def resize_for_display(img: Image.Image, target_h: int) -> Image.Image:
    """Scale image to target_h, choosing filter by direction."""
    w, h = img.size
    new_w = max(1, round(w * target_h / h))
    filt = Image.NEAREST if target_h >= h else Image.LANCZOS
    return img.resize((new_w, target_h), filt)


def compose_on_canvas(img: Image.Image, canvas_size: int) -> Image.Image:
    """Center img on a dark canvas_size x canvas_size RGBA canvas."""
    canvas = Image.new("RGBA", (canvas_size, canvas_size), (20, 20, 30, 255))
    paste_x = max(0, (canvas_size - img.width) // 2)
    paste_y = max(0, (canvas_size - img.height) // 2)
    canvas.paste(img, (paste_x, paste_y), img)
    return canvas


# ---------------------------------------------------------------------------
# Main application
# ---------------------------------------------------------------------------

class SpriteViewer:
    def __init__(self, root: tk.Tk, yaml_path: str, sprites_dir: str | None):
        self.root = root
        self.yaml_path = os.path.abspath(yaml_path)
        self.sprites_dir = (
            os.path.abspath(sprites_dir) if sprites_dir
            else os.path.dirname(self.yaml_path)
        )

        with open(self.yaml_path, "r", encoding="utf-8") as f:
            self.data = yaml.safe_load(f)
        self.sprites_data: dict = self.data.get("sprites", {})

        # State
        self._zoom: int = 1
        self._current_sprite: Image.Image | None = None   # original PIL image
        self._current_bg_preview: Image.Image | None = None  # 256x256 BG preview (RGBA)
        # Emotion overlay: the same BMP the converter will emit for the
        # currently selected emotion, pre-keyed to magenta-transparent so
        # we can paste it on top of the body BG to preview the final
        # composite.
        self._current_emotion_overlay: Image.Image | None = None
        self._current_emotion_offset_px: tuple[int, int] = (0, 0)
        self._photo_left: ImageTk.PhotoImage | None = None
        self._photo_right: ImageTk.PhotoImage | None = None
        self._field_vars: list = []   # keep tk variable refs alive
        self._next_row: int = 0
        self._grid_visible: bool = True
        self._mask_visible: bool = True
        # When True, the emotion sprite is composited on top of the body
        # BG preview at the cell-aligned face position. Mirrors how the
        # converter will lay things out at runtime (BG = body with face
        # cells stamped transparent, OBJ sprite = emotion patch).
        self._emotion_visible: bool = True
        # Pending sprite/group for re-rendering after a toggle.
        self._current_sprite_data: dict | None = None
        self._current_group_data: dict | None = None

        self._clean_cache_dir()
        self._build_ui()
        self._populate_tree()
        self._rerender_right()

    # ------------------------------------------------------------------
    # UI construction
    # ------------------------------------------------------------------

    def _build_ui(self):
        self.root.title("Katawa Shoujo GBA: Character Editor")
        self.root.configure(bg=COLORS["bg"])
        self.root.geometry("1480x860")
        self.root.minsize(1000, 600)

        self._apply_styles()

        # Status bar — bottom of the window, outside the panes
        self.status_var = tk.StringVar(value="Select a group or sprite from the tree")
        ttk.Label(self.root, textvariable=self.status_var, style="Status.TLabel").pack(
            side=tk.BOTTOM, fill=tk.X, padx=6, pady=(0, 4)
        )

        # Three-pane horizontal split: Tree | Viewer | Inspector
        self._paned = ttk.PanedWindow(self.root, orient=tk.HORIZONTAL)
        self._paned.pack(fill=tk.BOTH, expand=True, padx=6, pady=6)

        self._build_tree_panel(self._paned)
        self._build_viewer_panel(self._paned)
        self._build_inspector_panel(self._paned)

        # Set initial sash positions after layout is computed
        INSPECTOR_WIDTH = 320
        self.root.after(80, lambda: (
            self._paned.sashpos(0, TREE_DEFAULT_WIDTH),
            self.root.after(10, lambda: self._paned.sashpos(
                1, self.root.winfo_width() - INSPECTOR_WIDTH
            )),
        ))

        self.root.bind_all("<MouseWheel>",       self._global_scroll)
        self.root.bind_all("<Shift-MouseWheel>", self._global_scroll)
        self.root.bind_all("<Button-4>",         self._global_scroll)
        self.root.bind_all("<Button-5>",         self._global_scroll)

    def _build_tree_panel(self, paned: ttk.PanedWindow):
        left = ttk.Frame(paned, style="Panel.TFrame")
        paned.add(left, weight=0)

        ttk.Label(left, text="Characters", style="Header.TLabel").pack(
            fill=tk.X, padx=6, pady=(6, 2)
        )

        tree_wrap = ttk.Frame(left, style="Panel.TFrame")
        tree_wrap.pack(fill=tk.BOTH, expand=True)

        self.tree = ttk.Treeview(tree_wrap, selectmode="browse", style="Sprite.Treeview")
        vsb = ttk.Scrollbar(tree_wrap, orient=tk.VERTICAL, command=self.tree.yview)
        self.tree.configure(yscrollcommand=vsb.set)
        vsb.pack(side=tk.RIGHT, fill=tk.Y)
        self.tree.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        self.tree.bind("<<TreeviewSelect>>", self._on_select)

    def _build_viewer_panel(self, paned: ttk.PanedWindow):
        center = ttk.Frame(paned, style="Panel.TFrame")
        paned.add(center, weight=1)

        # ---- Zoom toolbar ----
        zoom_bar = ttk.Frame(center, style="Panel.TFrame")
        zoom_bar.pack(fill=tk.X, padx=8, pady=(6, 4))

        ttk.Label(zoom_bar, text="Zoom:", style="SubLabel.TLabel").pack(side=tk.LEFT, padx=(0, 6))

        self._zoom_btns: dict[int, tk.Button] = {}
        for z in (1, 2, 3, 4):
            btn = tk.Button(
                zoom_bar,
                text=f"x{z}",
                width=4,
                relief="flat",
                bd=0,
                cursor="hand2",
                font=("SF Mono", 10, "bold"),
                command=lambda zz=z: self._set_zoom(zz),
            )
            btn.pack(side=tk.LEFT, padx=2)
            self._zoom_btns[z] = btn

        ttk.Separator(zoom_bar, orient=tk.VERTICAL).pack(side=tk.LEFT, fill=tk.Y, padx=8, pady=2)

        self._grid_btn = tk.Button(
            zoom_bar,
            text="Grid",
            width=5,
            relief="flat",
            bd=0,
            cursor="hand2",
            font=("SF Mono", 10, "bold"),
            command=self._toggle_grid,
        )
        self._grid_btn.pack(side=tk.LEFT, padx=2)

        self._mask_btn = tk.Button(
            zoom_bar,
            text="Mask",
            width=5,
            relief="flat",
            bd=0,
            cursor="hand2",
            font=("SF Mono", 10, "bold"),
            command=self._toggle_mask,
        )
        self._mask_btn.pack(side=tk.LEFT, padx=2)

        self._emotion_btn = tk.Button(
            zoom_bar,
            text="Sprite",
            width=6,
            relief="flat",
            bd=0,
            cursor="hand2",
            font=("SF Mono", 10, "bold"),
            command=self._toggle_emotion,
        )
        self._emotion_btn.pack(side=tk.LEFT, padx=2)

        self._update_zoom_buttons()
        self._update_grid_button()
        self._update_mask_button()
        self._update_emotion_button()

        # ---- Images (scrollable both axes) ----
        img_outer = ttk.Frame(center, style="Panel.TFrame")
        img_outer.pack(fill=tk.BOTH, expand=True, padx=8, pady=(0, 8))

        self._img_canvas = tk.Canvas(img_outer, bg=COLORS["panel"], highlightthickness=0)
        hsb = ttk.Scrollbar(img_outer, orient=tk.HORIZONTAL, command=self._img_canvas.xview)
        vsb = ttk.Scrollbar(img_outer, orient=tk.VERTICAL,   command=self._img_canvas.yview)
        self._img_canvas.configure(xscrollcommand=hsb.set, yscrollcommand=vsb.set)
        hsb.pack(side=tk.BOTTOM, fill=tk.X)
        vsb.pack(side=tk.RIGHT,  fill=tk.Y)
        self._img_canvas.pack(fill=tk.BOTH, expand=True)

        self._img_inner = ttk.Frame(self._img_canvas, style="Panel.TFrame")
        self._img_canvas.create_window((0, 0), window=self._img_inner, anchor="nw")
        self._img_inner.bind("<Configure>", self._on_img_inner_configure)

        self.img_left  = tk.Label(self._img_inner, bg=COLORS["img_bg"], relief="flat", bd=0)
        self.img_left.pack(side=tk.LEFT, padx=(0, 8), pady=4)

        self.img_right = tk.Label(self._img_inner, bg=COLORS["img_bg"], relief="flat", bd=0)
        self.img_right.pack(side=tk.LEFT, pady=4)

    def _build_inspector_panel(self, paned: ttk.PanedWindow):
        right = ttk.Frame(paned, style="Panel.TFrame")
        paned.add(right, weight=0)

        ttk.Label(right, text="Inspector", style="Header.TLabel").pack(
            fill=tk.X, padx=6, pady=(6, 4)
        )

        # Scrollable fields area
        insp_canvas = self._insp_canvas = tk.Canvas(right, bg=COLORS["surface"], highlightthickness=0)
        vsb = ttk.Scrollbar(right, orient=tk.VERTICAL, command=insp_canvas.yview)
        insp_canvas.configure(yscrollcommand=vsb.set)
        vsb.pack(side=tk.RIGHT, fill=tk.Y)
        insp_canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        self.fields_frame = ttk.Frame(insp_canvas, style="Surface.TFrame", padding=(10, 6))
        _win_id = insp_canvas.create_window((0, 0), window=self.fields_frame, anchor="nw")

        # Column 1 (values) stretches; column 0 (labels) stays fixed
        self.fields_frame.columnconfigure(1, weight=1)

        def _on_fields_configure(_event):
            insp_canvas.configure(scrollregion=insp_canvas.bbox("all"))

        def _on_canvas_resize(event):
            insp_canvas.itemconfigure(_win_id, width=event.width)

        self.fields_frame.bind("<Configure>", _on_fields_configure)
        insp_canvas.bind("<Configure>", _on_canvas_resize)
        insp_canvas.bind("<MouseWheel>", lambda e: insp_canvas.yview_scroll(
            -1 if e.delta > 0 else 1, "units"
        ))

    def _on_img_inner_configure(self, _event):
        self._img_canvas.configure(scrollregion=self._img_canvas.bbox("all"))

    def _global_scroll(self, event):
        """Route scroll events to the correct canvas based on pointer position."""
        delta = 1 if (event.num == 5 or getattr(event, "delta", 1) < 0) else -1
        horizontal = bool(event.state & 0x0001)  # Shift held or Shift-MouseWheel

        px = self.root.winfo_pointerx()
        py = self.root.winfo_pointery()

        def _over(w: tk.Widget) -> bool:
            return (w.winfo_rootx() <= px <= w.winfo_rootx() + w.winfo_width() and
                    w.winfo_rooty() <= py <= w.winfo_rooty() + w.winfo_height())

        if _over(self._img_canvas):
            if horizontal:
                self._img_canvas.xview_scroll(delta, "units")
            else:
                self._img_canvas.yview_scroll(delta, "units")
        elif _over(self._insp_canvas):
            self._insp_canvas.yview_scroll(delta, "units")

    def _apply_styles(self):
        s = ttk.Style(self.root)
        s.theme_use("clam")

        s.configure(".",
                    background=COLORS["bg"],
                    foreground=COLORS["text"],
                    font=("SF Mono", 11))

        s.configure("Panel.TFrame",   background=COLORS["panel"])
        s.configure("Surface.TFrame", background=COLORS["surface"])

        s.configure("Header.TLabel",
                    background=COLORS["panel"],
                    foreground=COLORS["accent"],
                    font=("SF Mono", 12, "bold"),
                    padding=(2, 2))
        s.configure("SubLabel.TLabel",
                    background=COLORS["panel"],
                    foreground=COLORS["subtext"],
                    font=("SF Mono", 10))
        s.configure("Field.TLabel",
                    background=COLORS["surface"],
                    foreground=COLORS["subtext"],
                    font=("SF Mono", 10),
                    anchor="w",
                    width=22)
        s.configure("Status.TLabel",
                    background=COLORS["panel"],
                    foreground=COLORS["subtext"],
                    font=("SF Mono", 10),
                    padding=(4, 2))

        s.configure("TEntry",
                    fieldbackground=COLORS["panel"],
                    foreground=COLORS["text"],
                    font=("SF Mono", 10),
                    relief="flat")
        s.map("TEntry",
              fieldbackground=[("readonly", COLORS["panel"])],
              foreground=[("readonly", COLORS["text"])])

        s.configure("Sprite.Treeview",
                    background=COLORS["panel"],
                    foreground=COLORS["text"],
                    fieldbackground=COLORS["panel"],
                    rowheight=22,
                    font=("SF Mono", 10))
        s.configure("Sprite.Treeview.Heading",
                    background=COLORS["surface"],
                    foreground=COLORS["subtext"],
                    font=("SF Mono", 10, "bold"))
        s.map("Sprite.Treeview",
              background=[("selected", COLORS["accent"])],
              foreground=[("selected", COLORS["bg"])])

        s.configure("TScrollbar",
                    background=COLORS["surface"],
                    troughcolor=COLORS["panel"],
                    arrowcolor=COLORS["subtext"])

    # ------------------------------------------------------------------
    # Tree population
    # ------------------------------------------------------------------

    def _populate_tree(self):
        self.tree.heading("#0", text="Character / Group / Sprite")
        for char_name, char_data in self.sprites_data.items():
            char_id = self.tree.insert(
                "", "end",
                iid=f"char:{char_name}",
                text=f" {char_name}",
                open=False,
                tags=("char",),
            )
            for group_key, group_data in char_data.get("groups", {}).items():
                close_mark = " ·close" if group_data.get("close") else ""
                group_id = self.tree.insert(
                    char_id, "end",
                    iid=f"group:{char_name}/{group_key}",
                    text=f"  {group_key}{close_mark}",
                    open=False,
                    tags=("group",),
                )
                for sprite_name in group_data.get("sprites", {}):
                    self.tree.insert(
                        group_id, "end",
                        iid=f"sprite:{char_name}/{group_key}/{sprite_name}",
                        text=f"   {sprite_name}",
                        tags=("sprite",),
                    )

        self.tree.tag_configure("char",   foreground=COLORS["accent"])
        self.tree.tag_configure("group",  foreground=COLORS["text"])
        self.tree.tag_configure("sprite", foreground=COLORS["subtext"])

    # ------------------------------------------------------------------
    # Selection
    # ------------------------------------------------------------------

    def _on_select(self, _event):
        sel = self.tree.selection()
        if not sel:
            return
        iid: str = sel[0]

        self._clear_fields()
        self._current_sprite = None
        self._current_bg_preview = None
        self._rerender_left()
        # Do NOT _rerender_right() here: keep the previous preview visible
        # until _load_sprite_data() replaces it, avoiding a flash to an empty grid.

        if iid.startswith("group:"):
            _, path = iid.split(":", 1)
            char_name, group_key = path.split("/", 1)
            group = self.sprites_data[char_name]["groups"][group_key]
            self._show_group_fields(group)
            # Auto-show the base_emotion sprite as preview
            base_emotion = group.get("base_emotion")
            sprites = group.get("sprites", {})
            base_sprite = sprites.get(base_emotion) or (next(iter(sprites.values())) if sprites else None)
            if base_sprite:
                self._load_sprite_data(base_sprite, group)
            self.status_var.set(f"{char_name}  ›  {group_key}")

        elif iid.startswith("sprite:"):
            _, path = iid.split(":", 1)
            char_name, group_key, sprite_name = path.split("/", 2)
            group = self.sprites_data[char_name]["groups"][group_key]
            sprite = group["sprites"][sprite_name]
            self._show_group_fields(group)
            self._field_separator("Sprite")
            self._show_sprite_fields(sprite)
            self._load_sprite_data(sprite, group)
            self.status_var.set(f"{char_name}  ›  {group_key}  ›  {sprite_name}")

    # ------------------------------------------------------------------
    # Fields
    # ------------------------------------------------------------------

    def _clear_fields(self):
        for w in self.fields_frame.winfo_children():
            w.destroy()
        self._field_vars.clear()
        self._next_row = 0

    def _field_separator(self, title: str):
        ttk.Label(
            self.fields_frame,
            text=f"— {title}",
            style="SubLabel.TLabel",
        ).grid(row=self._next_row, column=0, columnspan=2, sticky="w", pady=(8, 2))
        self._next_row += 1

    def _field_row(self, label: str, value, is_bool: bool = False):
        row = self._next_row
        self._next_row += 1
        ttk.Label(self.fields_frame, text=label, style="Field.TLabel").grid(
            row=row, column=0, sticky="w", padx=(0, 8), pady=2
        )
        if is_bool:
            var = tk.BooleanVar(value=bool(value))
            self._field_vars.append(var)
            color = COLORS["green"] if value else COLORS["red"]
            cb = tk.Checkbutton(
                self.fields_frame,
                variable=var,
                state="disabled",
                bg=COLORS["surface"],
                fg=color,
                selectcolor=COLORS["panel"],
                activebackground=COLORS["surface"],
                disabledforeground=color,
                relief="flat",
                bd=0,
            )
            cb.grid(row=row, column=1, sticky="w")
        else:
            text = "" if value is None else str(value)
            var = tk.StringVar(value=text)
            self._field_vars.append(var)
            entry = ttk.Entry(self.fields_frame, textvariable=var, state="readonly")
            entry.grid(row=row, column=1, sticky="ew")

    def _show_group_fields(self, group: dict):
        # Offsets / sizes are in 8-px cell units in the YAML. Show both
        # the cell value and the canvas-px equivalent so the user can
        # cross-check against the source PNG.
        offset = group.get("base_emotion_offset") or [0, 0]
        size   = group.get("base_emotion_size")   or [4, 4]
        rows = [
            ("pose",                 group.get("pose"),                  False),
            ("outfit",               group.get("outfit"),                False),
            ("close",                group.get("close", False),          True),
            ("base_emotion",         group.get("base_emotion"),          False),
            ("emotion_offset x (cells)", f"{offset[0]}  ({offset[0] * 8} px)", False),
            ("emotion_offset y (cells)", f"{offset[1]}  ({offset[1] * 8} px)", False),
            ("emotion_size w (cells)",   f"{size[0]}  ({size[0] * 8} px)",   False),
            ("emotion_size h (cells)",   f"{size[1]}  ({size[1] * 8} px)",   False),
            ("origin_offset",        group.get("base_origin_offset", 0), False),
            ("origin_ycrop",        group.get("base_origin_ycrop", 120), False),
            ("silhouette_tint",      group.get("silhouette_tint"),       False),
        ]
        for lbl, val, ib in rows:
            self._field_row(lbl, val, ib)

    def _show_sprite_fields(self, sprite: dict):
        rows = [
            ("filename", sprite.get("filename"), False),
            ("naked",    sprite.get("naked", False), True),
        ]
        for lbl, val, ib in rows:
            self._field_row(lbl, val, ib)

    # ------------------------------------------------------------------
    # Zoom
    # ------------------------------------------------------------------

    def _set_zoom(self, z: int):
        self._zoom = z
        self._update_zoom_buttons()
        self._rerender_left()
        self._rerender_right()

    def _update_zoom_buttons(self):
        for z, btn in self._zoom_btns.items():
            active = z == self._zoom
            btn.configure(
                bg=COLORS["zoom_active"] if active else COLORS["zoom_idle"],
                fg=COLORS["bg"]          if active else COLORS["text"],
            )

    def _toggle_grid(self):
        self._grid_visible = not self._grid_visible
        self._update_grid_button()
        self._rerender_right()

    def _update_grid_button(self):
        self._grid_btn.configure(
            bg=COLORS["zoom_active"] if self._grid_visible else COLORS["zoom_idle"],
            fg=COLORS["bg"]          if self._grid_visible else COLORS["text"],
        )

    def _toggle_mask(self):
        self._mask_visible = not self._mask_visible
        self._update_mask_button()
        self._rerender_right()

    def _update_mask_button(self):
        self._mask_btn.configure(
            bg=COLORS["zoom_active"] if self._mask_visible else COLORS["zoom_idle"],
            fg=COLORS["bg"]          if self._mask_visible else COLORS["text"],
        )

    def _toggle_emotion(self):
        # The overlay BMP itself is already cached from the previous load;
        # toggling just re-paints the right canvas with / without paste.
        self._emotion_visible = not self._emotion_visible
        self._update_emotion_button()
        self._rerender_right()

    def _update_emotion_button(self):
        self._emotion_btn.configure(
            bg=COLORS["zoom_active"] if self._emotion_visible else COLORS["zoom_idle"],
            fg=COLORS["bg"]          if self._emotion_visible else COLORS["text"],
        )

    # ------------------------------------------------------------------
    # Image rendering
    # ------------------------------------------------------------------

    def _display_size(self) -> int:
        return GRID_BASE * self._zoom

    # ------------------------------------------------------------------
    # Preview caching
    # ------------------------------------------------------------------

    _TRANSPARENT_COLOR = (255, 0, 253)  # magic transparent color used by ImageTools
    _CACHE_DIR = os.path.join(tempfile.gettempdir(), "ksgba_sprite_viewer")

    def _clean_cache_dir(self):
        if not os.path.isdir(self._CACHE_DIR):
            return
        for f in os.listdir(self._CACHE_DIR):
            path = os.path.join(self._CACHE_DIR, f)
            if os.path.isfile(path):
                os.remove(path)
            elif os.path.isdir(path):
                shutil.rmtree(path)

    def _preview_cache_path(self, path: str, y_offset: int, tint,
                            cutout_offset_px: tuple[int, int] | None,
                            cutout_size_px: tuple[int, int] | None) -> str:
        mtime = int(os.path.getmtime(path))
        # Cutout coords are part of the cache key — they get baked into
        # the BMP as a magenta hole, and a different cell window means a
        # different file.
        key = f"{path}|{mtime}|{y_offset}|{tint}|{cutout_offset_px}|{cutout_size_px}"
        h = hashlib.md5(key.encode()).hexdigest()
        return os.path.join(self._CACHE_DIR, f"spr_{h}.bmp")

    def _emotion_cache_path(self, path: str, sprite_offset_px: tuple[int, int],
                            sprite_size_px: tuple[int, int],
                            y_offset: int, tint) -> str:
        mtime = int(os.path.getmtime(path))
        key = f"emotion|{path}|{mtime}|{sprite_offset_px}|{sprite_size_px}|{y_offset}|{tint}"
        h = hashlib.md5(key.encode()).hexdigest()
        return os.path.join(self._CACHE_DIR, f"emo_{h}.bmp")

    def _load_bmp_preview(self, bmp_path: str) -> Image.Image:
        """Load a BMP produced by ImageTools as plain RGB — no alpha conversion needed."""
        return Image.open(bmp_path).convert("RGB")

    def _load_bmp_with_magenta_alpha(self, bmp_path: str) -> Image.Image:
        """Load an emotion BMP and convert ImageTools' magic transparent
        magenta into a proper alpha channel so it can be alpha-pasted
        cleanly onto the body BG preview.
        """
        rgb = Image.open(bmp_path).convert("RGB")
        rgba = rgb.convert("RGBA")
        # Build a 1-bit mask: opaque everywhere except where the pixel is
        # exactly the magic transparent color.
        magenta = self._TRANSPARENT_COLOR
        pixels_rgb  = rgb.load()
        pixels_rgba = rgba.load()
        for y in range(rgb.height):
            for x in range(rgb.width):
                if pixels_rgb[x, y] == magenta:
                    pixels_rgba[x, y] = (0, 0, 0, 0)
        return rgba

    def _load_sprite_data(self, sprite: dict, group: dict):
        """Load original sprite and compute / retrieve cached BG preview.

        The LEFT preview is the currently selected emotion's source PNG.
        The RIGHT preview is the body BG built from the group's
        `base_emotion` PNG with the face region cut out — it is shared
        across every emotion in the group, so it must NOT change as the
        user scrolls through emotions inside the same group. On top of
        that BG we composite the per-emotion sprite (rendered with the
        same `resize_character_emotion_sprite` path the GBA converter
        uses), so the right pane shows the final BG+OBJ composite.
        """
        sprite_filename = sprite.get("filename", "")
        if not sprite_filename:
            return
        sprite_path = os.path.join(self.sprites_dir, sprite_filename)
        if not os.path.isfile(sprite_path):
            self.status_var.set(f"⚠  Image not found: {sprite_path}")
            return
        try:
            self._current_sprite = Image.open(sprite_path).convert("RGBA")
        except Exception as exc:
            print(f"Image load error ({sprite_path}): {exc}", file=sys.stderr)
            return
        # Keep original preview stable: render the LEFT pane once right
        # after we load the source PNG, then avoid touching it during
        # potentially slow cache-miss rendering of BG/emotion assets.
        self._rerender_left()

        # Remember selection so toggles can re-render without bouncing
        # through the tree handler.
        self._current_sprite_data = sprite
        self._current_group_data = group

        # The BG preview always comes from the group's base_emotion file.
        # Falls back to the first sprite if the named base_emotion is
        # missing (shouldn't happen with a clean YAML, but stay defensive).
        base_emotion_name = group.get("base_emotion")
        sprites_map = group.get("sprites", {})
        base_sprite = sprites_map.get(base_emotion_name)
        if not base_sprite and sprites_map:
            base_sprite = next(iter(sprites_map.values()))
        bg_filename = (base_sprite or {}).get("filename") or sprite_filename
        bg_path = os.path.join(self.sprites_dir, bg_filename)
        if not os.path.isfile(bg_path):
            # Group's base_emotion file missing — fall back to the
            # selected sprite so we still show *something* meaningful.
            bg_path = sprite_path

        y_offset = group.get("base_origin_offset", 0)
        y_crop = group.get("base_origin_ycrop", 120)
        silhouette_tint = group.get("silhouette_tint")
        tint = [silhouette_tint] * 3 if silhouette_tint is not None else None

        # YAML stores face cut-out in 8-px cell units. Convert to canvas px
        # for the BG renderer (cut-out is always on now).
        offset_cells = group.get("base_emotion_offset")
        size_cells   = group.get("base_emotion_size")
        cutout_offset_px: tuple[int, int] | None = None
        cutout_size_px: tuple[int, int] | None = None
        if offset_cells and size_cells:
            cutout_offset_px = (offset_cells[0] * 8, offset_cells[1] * 8)
            cutout_size_px   = (size_cells[0] * 8, size_cells[1] * 8)

        cache_path = self._preview_cache_path(
            bg_path, y_offset, tint, cutout_offset_px, cutout_size_px
        )

        cache_hit = os.path.isfile(cache_path)
        if not cache_hit:
            try:
                os.makedirs(self._CACHE_DIR, exist_ok=True)
                self.status_var.set(f"Rendering body BG… {os.path.basename(bg_filename)}")
                self.root.update_idletasks()
                ImageTools.resize_character_background(
                    bg_path, cache_path,
                    y_offset=y_offset,
                    y_crop=y_crop,
                    face_cutout_offset=cutout_offset_px,
                    face_cutout_size=cutout_size_px,
                    tint=tint,
                )
            except Exception as exc:
                print(f"BG preview error ({bg_path}): {exc}", file=sys.stderr)
                self._current_bg_preview = None
                return

        try:
            self._current_bg_preview = self._load_bmp_preview(cache_path)
        except Exception as exc:
            print(f"BG load error ({bg_path}): {exc}", file=sys.stderr)
            self._current_bg_preview = None

        # Build / fetch the per-emotion overlay using the SAME pipeline
        # the GBA converter calls: ImageTools.resize_character_emotion_sprite
        # crops the canvas to the face cut-out region with imgdither
        # quantization. We reuse its cache so further emotion switches in
        # the same group are instant.
        self._current_emotion_overlay = None
        if cutout_offset_px and cutout_size_px:
            emo_cache = self._emotion_cache_path(
                sprite_path, cutout_offset_px, cutout_size_px, y_offset, tint
            )
            if not os.path.isfile(emo_cache):
                try:
                    os.makedirs(self._CACHE_DIR, exist_ok=True)
                    self.status_var.set(
                        f"Rendering emotion sprite… {os.path.basename(sprite_filename)}"
                    )
                    self.root.update_idletasks()
                    ImageTools.resize_character_emotion_sprite(
                        sprite_path, emo_cache,
                        sprite_offset=cutout_offset_px,
                        sprite_size=cutout_size_px,
                        y_offset=y_offset,
                        y_crop=y_crop,
                        tint=tint,
                    )
                except Exception as exc:
                    print(f"Emotion sprite error ({sprite_path}): {exc}",
                          file=sys.stderr)
                    emo_cache = None
            if emo_cache and os.path.isfile(emo_cache):
                try:
                    self._current_emotion_overlay = self._load_bmp_with_magenta_alpha(emo_cache)
                    self._current_emotion_offset_px = cutout_offset_px
                except Exception as exc:
                    print(f"Emotion load error ({emo_cache}): {exc}",
                          file=sys.stderr)
                    self._current_emotion_overlay = None

        # LEFT pane already rendered once at load time; update only RIGHT.
        self._rerender_right()

    def _rerender_left(self):
        size = self._display_size()
        if self._current_sprite is not None:
            scaled = resize_for_display(self._current_sprite, size)
            composed = compose_on_canvas(scaled, size)
        else:
            composed = Image.new("RGBA", (size, size), (20, 20, 30, 255))
        self._photo_left = ImageTk.PhotoImage(composed)
        self.img_left.configure(image=self._photo_left)

    def _rerender_right(self):
        size = self._display_size()
        cell = GRID_CELL * self._zoom

        if self._current_bg_preview is not None:
            # Composite the emotion sprite (if any & visible) at native
            # 256×256 resolution BEFORE upscaling, so both BG and OBJ
            # share the same NEAREST upscaling pass — no resampling
            # mismatch on cell boundaries.
            base_native = self._current_bg_preview.copy()
            if (self._emotion_visible and
                    self._current_emotion_overlay is not None):
                base_rgba = base_native.convert("RGBA")
                base_rgba.alpha_composite(
                    self._current_emotion_overlay,
                    dest=self._current_emotion_offset_px,
                )
                base_native = base_rgba.convert("RGB")
            base = base_native.resize((size, size), Image.NEAREST)
        else:
            base = make_grid_image(size, cell)

        if self._mask_visible:
            base = draw_gba_mask_overlay(base)
        if self._grid_visible:
            base = draw_grid_overlay(base, cell)

        self._photo_right = ImageTk.PhotoImage(base)
        self.img_right.configure(image=self._photo_right)


# ---------------------------------------------------------------------------
# Entry point
# ---------------------------------------------------------------------------

def main():
    parser = argparse.ArgumentParser(description="Katawa Shoujo GBA: Character Editor")
    parser.add_argument("yaml_file", help="Path to character_sprites.yaml")
    parser.add_argument(
        "--sprites-dir",
        default=None,
        help="Root directory containing sprite images (defaults to yaml file directory)",
    )
    args = parser.parse_args()

    root = tk.Tk()
    SpriteViewer(root, args.yaml_file, args.sprites_dir)
    root.mainloop()


if __name__ == "__main__":
    main()
