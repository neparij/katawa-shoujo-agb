from typing import List

from src.dto.definitions import RouteDefinition


class DefinitionsWriter:
    def __init__(self, include_dir: str, source_dir: str):
        self.include_dir = include_dir
        self.source_dir = source_dir

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
        with open(f"{self.source_dir}/translations/{tl_key}_definitions_labels.h", "w") as f:
            f.write(f"#ifndef {tl_key.upper()}_DEFINITIONS_LABELS_H\n")
            f.write(f"#define {tl_key.upper()}_DEFINITIONS_LABELS_H\n\n")
            f.write("#include \"definitions/labels.h\"\n\n")
            f.write("namespace ks {\n")
            f.write(f"    inline const char* get_label_{tl_key}_translation(const label_t label) {{\n")
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
