#!/usr/bin/env python3
"""Resize / crop / composite layers onto a GBA map canvas (RGBA, pre-qualetize)."""

from __future__ import annotations

import os
from dataclasses import dataclass

import numpy as np
from PIL import Image, ImageOps

# Match bgs_resize event path defaults.
DISPLAY_WIDTH = 240
DISPLAY_HEIGHT = 160
DISPLAY_BOTTOM_MARGIN = 0
SOURCE_HEIGHT = 1080


@dataclass(frozen=True)
class CompositeLayer:
    """One PNG/JPEG layer pasted at ``(x, y)`` on the map canvas."""

    source_path: str
    x: int = 0
    y: int = 0


def _normalize_source_height(source_image: Image.Image) -> Image.Image:
    """Match ``bgs_resize``: force 1080 px height, preserve aspect."""
    width = int((source_image.width / source_image.height) * SOURCE_HEIGHT)
    return source_image.resize((width, SOURCE_HEIGHT), resample=Image.Resampling.LANCZOS)


def _hard_alpha_threshold(rgba: Image.Image) -> Image.Image:
    """Drop semi-transparent pixels before qualetize (GBA tile 0 = fully transparent)."""
    arr = np.array(rgba)
    mask = arr[:, :, 3] > 127
    arr[mask, 3] = 255
    arr[~mask] = (0, 0, 0, 0)
    return Image.fromarray(arr, "RGBA")


def _downscale_event_rgba(
    source_image: Image.Image,
    map_w: int,
    map_h: int,
    display_w: int = DISPLAY_WIDTH,
    display_h: int = DISPLAY_HEIGHT,
) -> Image.Image:
    """Crop/scale a full-res event canvas onto the GBA map (single downscale pass)."""
    if display_w == 240 and display_h == 160:
        gba_resize_factor = display_h / SOURCE_HEIGHT
        extra_width = source_image.width - 1920
        extra_height = source_image.height - SOURCE_HEIGHT
        extra_width_percentage = extra_width / 1920 if extra_width else 0.0
        extra_height_percentage = extra_height / SOURCE_HEIGHT if extra_height else 0.0
        gba_extra_width = max(0, int(display_w * extra_width_percentage))
        gba_extra_height = max(0, int(display_h * extra_height_percentage))
        source_height_resized = ImageOps.scale(
            source_image, gba_resize_factor, resample=Image.Resampling.LANCZOS
        )
        crop_x = source_height_resized.width - (display_w + gba_extra_width)
        crop_y = source_height_resized.height - (display_h + gba_extra_height)
    else:
        resize_factor = display_h / SOURCE_HEIGHT
        source_height_resized = ImageOps.scale(
            source_image, resize_factor, resample=Image.Resampling.LANCZOS
        )
        crop_x = source_height_resized.width - display_w
        crop_y = source_height_resized.height - display_h

    source_cropped = ImageOps.crop(
        source_height_resized,
        (crop_x // 2, crop_y // 2, crop_x // 2, crop_y // 2),
    )

    canvas = Image.new("RGBA", (map_w, map_h), (0, 0, 0, 0))
    paste_x = (map_w - source_cropped.width) // 2
    paste_y = (map_h - source_cropped.height - DISPLAY_BOTTOM_MARGIN) // 2
    canvas.paste(source_cropped, (paste_x, paste_y), source_cropped)
    return _hard_alpha_threshold(canvas)


def _prepare_layer_rgba(
    input_path: str,
    map_w: int,
    map_h: int,
    display_w: int = DISPLAY_WIDTH,
    display_h: int = DISPLAY_HEIGHT,
) -> Image.Image:
    """Resize a single KS event PNG like ``bgs_resize.process_image_quantized``."""
    source_image = _normalize_source_height(Image.open(input_path).convert("RGBA"))
    return _downscale_event_rgba(
        source_image, map_w, map_h, display_w, display_h
    )


def _composite_layers_fullres(layers: list[CompositeLayer]) -> Image.Image:
    """Alpha-composite all layers at source resolution (Ren'Py order)."""
    canvas_w = 0
    canvas_h = 0
    prepared: list[tuple[CompositeLayer, Image.Image]] = []

    for layer in layers:
        if not os.path.exists(layer.source_path):
            raise FileNotFoundError(layer.source_path)
        img = _normalize_source_height(Image.open(layer.source_path).convert("RGBA"))
        prepared.append((layer, img))
        canvas_w = max(canvas_w, layer.x + img.width)
        canvas_h = max(canvas_h, layer.y + img.height)

    canvas = Image.new("RGBA", (canvas_w, canvas_h), (0, 0, 0, 0))
    for layer, img in prepared:
        layer_canvas = Image.new("RGBA", (canvas_w, canvas_h), (0, 0, 0, 0))
        layer_canvas.paste(img, (layer.x, layer.y), img)
        canvas = Image.alpha_composite(canvas, layer_canvas)
    return canvas


def _composite_layers_stacked(
    layers: list[CompositeLayer],
    map_w: int,
    map_h: int,
    canvas_w: int,
    canvas_h: int,
) -> Image.Image:
    """Merge Ren'Py-style stacked composites (e.g. rin_h2 1920×2160) into map_w×map_h."""
    scale = map_w / canvas_w
    intermediate_h = max(map_h, int(round(canvas_h * scale)))
    canvas = Image.new("RGBA", (map_w, intermediate_h), (0, 0, 0, 0))

    for layer in layers:
        if not os.path.exists(layer.source_path):
            raise FileNotFoundError(layer.source_path)
        img = Image.open(layer.source_path).convert("RGBA")
        nw = max(1, int(round(img.width * scale)))
        nh = max(1, int(round(img.height * scale)))
        img = img.resize((nw, nh), resample=Image.Resampling.LANCZOS)
        px = int(round(layer.x * scale))
        py = int(round(layer.y * scale))
        layer_canvas = Image.new("RGBA", (map_w, intermediate_h), (0, 0, 0, 0))
        layer_canvas.paste(img, (px, py), img)
        canvas = Image.alpha_composite(canvas, layer_canvas)

    if intermediate_h <= map_h:
        result = Image.new("RGBA", (map_w, map_h), (0, 0, 0, 0))
        paste_y = (map_h - intermediate_h) // 2
        result.paste(canvas, (0, paste_y), canvas)
        return _hard_alpha_threshold(result)

    crop_y = (intermediate_h - map_h) // 2
    return _hard_alpha_threshold(canvas.crop((0, crop_y, map_w, crop_y + map_h)))


def _composite_layers_huge_stacked(
    layers: list[CompositeLayer],
    map_w: int,
    map_h: int,
    canvas_w: int,
    canvas_h: int,
    content_w: int = DISPLAY_WIDTH,
    content_h: int = DISPLAY_HEIGHT,
    scale_by_height: bool = False,
) -> Image.Image:
    """Merge stacked composites into a scrollable huge map (full height preserved)."""
    if scale_by_height:
        scale = content_h / canvas_h
        merged_h = max(1, int(round(content_h)))
        merged_w = max(1, int(round(canvas_w * scale)))
    else:
        scale = content_w / canvas_w
        merged_h = max(1, int(round(canvas_h * scale)))
        merged_w = max(1, int(round(content_w)))
    merged = Image.new("RGBA", (merged_w, merged_h), (0, 0, 0, 0))

    for layer in layers:
        if not os.path.exists(layer.source_path):
            raise FileNotFoundError(layer.source_path)
        img = Image.open(layer.source_path).convert("RGBA")
        nw = max(1, int(round(img.width * scale)))
        nh = max(1, int(round(img.height * scale)))
        img = img.resize((nw, nh), resample=Image.Resampling.LANCZOS)
        px = int(round(layer.x * scale))
        py = int(round(layer.y * scale))
        layer_canvas = Image.new("RGBA", (merged_w, merged_h), (0, 0, 0, 0))
        layer_canvas.paste(img, (px, py), img)
        merged = Image.alpha_composite(merged, layer_canvas)

    canvas = Image.new("RGBA", (map_w, map_h), (0, 0, 0, 0))
    paste_x = (map_w - merged_w) // 2
    paste_y = 0
    canvas.paste(merged, (paste_x, paste_y), merged)
    return _hard_alpha_threshold(canvas)


def composite_layers_fullres(layers: list[CompositeLayer]) -> Image.Image:
    """Alpha-composite all layers at source resolution (Ren'Py order)."""
    return _composite_layers_fullres(layers)


def composite_layers(
    layers: list[CompositeLayer],
    map_w: int,
    map_h: int,
    display_w: int = DISPLAY_WIDTH,
    display_h: int = DISPLAY_HEIGHT,
    canvas_w: int = 1920,
    canvas_h: int = 1080,
    huge: bool = False,
    huge_scale_by_height: bool = False,
    huge_content_h: int | None = None,
) -> Image.Image:
    """Merge layers bottom-to-top onto one ``map_w × map_h`` RGBA canvas."""
    if huge:
        content_h = huge_content_h if huge_content_h is not None else DISPLAY_HEIGHT
        scale_by_height = huge_scale_by_height or huge_content_h is not None
        return _composite_layers_huge_stacked(
            layers, map_w, map_h, canvas_w, canvas_h,
            content_h=content_h,
            scale_by_height=scale_by_height,
        )

    use_stacked = canvas_h > SOURCE_HEIGHT
    if use_stacked:
        return _composite_layers_stacked(layers, map_w, map_h, canvas_w, canvas_h)

    # Flat event composites (rin_pair, rin_goodend): merge at full resolution,
    # then downscale once. Per-layer downscale + alpha merge leaves bright/dark
    # fringes on anti-aliased overlay edges.
    flattened = _composite_layers_fullres(layers)
    return _downscale_event_rgba(
        flattened, map_w, map_h, display_w, display_h
    )
