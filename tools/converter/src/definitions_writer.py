from datetime import datetime, UTC
from typing import List

from src.dto.definitions import RouteDefinition, GalleryImageDefinition
from src.translation.translation_container import TranslationContainer


COMMON_DEFINITIONS_MAP = {
    "no_scene": "No scene",
    "nothing": "Nothing",

    "hi": "Hisao",
    "ha": "Hanako",
    "emi": "Emi",
    "rin": "Rin",
    "li": "Lilly",
    "shi": "Shizune",
    "mi": "Misha",
    "ke": "Kenji",
    "mu": "Mutou",
    "nk": "Nurse",
    "no": "Nomiya",
    "yu": "Yuuko",
    "sa": "Sae",
    "aki": "Akira",
    "hh": "Hideaki",
    "hx": "Jigoro",
    "emm": "Meiko",
    "sk": "Shopkeep",
    "mk": "Miki",

    "mi_shi": "Shizune",
    "mi_not_shi": "{s}Shizune{/s} Misha",
    "mystery": "???",

    "ha_": "Purple-haired girl",
    "emi_": "Twintails girl",
    "rin_": "Strange girl",
    "li_": "Wavy-haired girl",
    "mi_": "Laughing girl",
    "ke_": "Bespectacled hallmate",
    "mu_": "Tall man",
    "yu_": "Librarian",
    "no_": "Silver-haired man",
    "sa_": "Gallery owner",
    "aki_": "Well-dressed person",
    "nk_": "Smiling man",
    "hx_": "Huge man",
    "hh_": "Slim girl",
    "emm_": "Woman with braid",
}


class DefinitionsWriter:
    def __init__(self, include_dir: str, source_dir: str):
        self.include_dir = include_dir
        self.source_dir = source_dir

    def write_common_definitions(self, tl: TranslationContainer):
        language = tl.language if tl is not None else "en"
        with open(f"{self.source_dir}/tl/{language}/definitions_commons.inc", "w") as f:
            f.write(f'// Generated code, do not edit\n')
            f.write(f'// Generated at {datetime.now(UTC).isoformat(timespec='seconds')}\n')
            f.write(f'#pragma once\n')
            f.write(f'#define KSDEF(name, value) \\\n')
            f.write(f'    const char* definitions_##name() {{ return value; }}\n\n')
            for key, value in COMMON_DEFINITIONS_MAP.items():
                if tl is None:
                    f.write(f'KSDEF({key}, "{value}")\n')
                else:
                    if value in tl.strings:
                        f.write(f'KSDEF({key}, "{tl.strings[value]}")\n')
                    else:
                        f.write(f'KSDEF({key}, "{value}")\n')
            f.write(f'#undef KSDEF\n')

    def write_scripts_definitions(self, routes: List[RouteDefinition]):
        """
        Write the definitions of the routes to a file.
        """
        scripts = []
        with open(f"{self.include_dir}/definitions/scripts.h", "w") as f:
            f.write("#ifndef SCRIPTS_DEFINITIONS_H\n")
            f.write("#define SCRIPTS_DEFINITIONS_H\n\n")
            f.write("typedef unsigned char script_t;\n")
            f.write("#define SCRIPT_A0_ACTNAME ((script_t)0xFF)\n")
            script_i = 0
            for route in routes:
                for act in route.acts:
                    for label in act.labels:
                        script_name = label.label_id.split(".")[0]
                        if script_name not in scripts:
                            scripts.append(script_name)
                            f.write(f"#define SCRIPT_{script_name.upper()} ((script_t){script_i})\n")
                            script_i += 1
                f.write("\n")
            f.write("\n#endif // SCRIPTS_DEFINITIONS_H\n")

    def write_labels_definitions(self, routes: List[RouteDefinition]):
        """
        Write the definitions of the labels to a file.
        """
        with open(f"{self.include_dir}/definitions/labels.h", "w") as f:
            f.write("#ifndef LABELS_DEFINITIONS_H\n")
            f.write("#define LABELS_DEFINITIONS_H\n\n")
            f.write("typedef unsigned short label_t;\n")
            f.write("#define LABEL_A0_ACTNAME_SCENE1 ((label_t)0xFFFF)\n")
            label_i = 0
            for route in routes:
                for act in route.acts:
                    for label in act.labels:
                        label_name = label.label_id.replace(".", "_").upper()
                        f.write(f"#define LABEL_{label_name.upper()} ((label_t){label_i})\n")
                        label_i += 1
                f.write("\n")
            f.write("\n#endif // LABELS_DEFINITIONS_H\n")

    def write_labels_translations(self, routes: List[RouteDefinition], tl_key: str):
        """
        Write the translations of the labels to a file.
        """
        with open(f"{self.source_dir}/tl/{tl_key}/definitions_labels.h", "w") as f:
            f.write(f"#ifndef {tl_key.upper()}_DEFINITIONS_LABELS_H\n")
            f.write(f"#define {tl_key.upper()}_DEFINITIONS_LABELS_H\n\n")
            f.write("#include \"definitions/labels.h\"\n\n")
            f.write("namespace ks::tl {\n")
            f.write(f"    inline const char* get_label_translation(const label_t label) {{\n")
            f.write("        switch (label) {\n")
            for route in routes:
                for act in route.acts:
                    for label in act.labels:
                        label_name = label.label_id.replace(".", "_").upper()
                        f.write(f"            case LABEL_{label_name}: return \"{label.label_name}\";\n")
            f.write("            default: return nullptr;\n")
            f.write("        }\n")
            f.write("    }\n")
            f.write("}\n\n")
            f.write(f"\n#endif // {tl_key.upper()}_DEFINITIONS_LABELS_H\n")

    def write_seen_bitmask_definitions(self, gallery_images : List[GalleryImageDefinition]):
        """
        Write the definitions of the gallery images to a file.
        """
        definitions = []

        with open(f"{self.include_dir}/definitions/seen_bitmask.h", "w") as f:
            f.write("#ifndef SEEN_BITMASK_DEFINITIONS_H\n")
            f.write("#define SEEN_BITMASK_DEFINITIONS_H\n\n")

            f.write("typedef unsigned int displayable_bitmask_t;\n")
            f.write("#define DISPLAYABLE_BITMASK_NONE ((displayable_bitmask_t)0x00000000)\n")

            bit_idx = 1
            for entry in gallery_images:
                for image in entry.images:
                    image_name = image.replace(" ", "_").upper()
                    if not image_name in definitions:
                        definitions.append(image_name)
                        f.write(f"#define DISPLAYABLE_BITMASK_{image_name} ((displayable_bitmask_t)0x{bit_idx:08X})\n")
                        bit_idx += 1

            f.write(f"\n#endif // SEEN_BITMASK_DEFINITIONS_H\n")