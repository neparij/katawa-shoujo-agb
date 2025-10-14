import ast
import re
from typing import List

# TODO: REMOVE THIS FILE COMPLETELY, AND MOVE THE WHOLE `bgs_resize` PROJECT TO `converter` TOOLS!!!

class GalleryImageDefinition:
    def __init__(self, thumbnail: str, images: List[str]):
        self.thumbnail = thumbnail
        self.images = images

    def __str__(self):
        return f"GalleryImageDefinition(thumbnail={self.thumbnail}, images={self.images})"

class DefinitionsReader:
    def __init__(self, definitions_file):
        self.definitions_file = definitions_file

    @staticmethod
    def sanitize_block(block: str) -> str:
        # Replace Ren'Py-style _() with Python-compatible quotes for AST
        block = re.sub(r'_\("([^"]+)"\)', r'"_\1"', block)

        # Replace Ren'Py-style event triggers with Python dict
        block = re.sub(r'Trigger\((\"[^"]+\"),\s*(\"[^"]+\")\)', r'{\1: \2}', block)
        return block

    def extract_gallery_images_block(self):
        with open(self.definitions_file, 'r', encoding="utf-8") as f:
            text = f.read()
        pattern = r'define\s+_gallery_images\s*=\s*(\([\s\S]*?\))\s*\n\s*define'
        match = re.search(pattern, text)
        if not match:
            raise ValueError("Could not find _gallery_images block.")
        sanitized = self.sanitize_block(match.group(1))
        return ast.literal_eval(sanitized)

    @staticmethod
    def parse_gallery_images_structure(gallery_images_ast) -> List[GalleryImageDefinition]:
        gallery_images = []
        ev_pattern = re.compile(r'(ev(?:.*|) |unlock_ev |ovl |)(.*)')
        for entry in gallery_images_ast:
            thumbnail = re.sub(r'thumb/(.*)\.(jpg|png)', r'\1', entry[0])
            images = []
            for img in entry[1:]:
                if isinstance(img, str):
                    images.append(ev_pattern.sub(r'\2', img))
                elif isinstance(img, dict):
                    for key in img:
                        images.append(ev_pattern.sub(r'\2', key))
                        # images.append(ev_pattern.sub(r'\2', img[key]))
                else:
                    raise ValueError(f"Unexpected gallery image format: {img}")

            gallery_images.append(GalleryImageDefinition(thumbnail, images))
        return gallery_images
