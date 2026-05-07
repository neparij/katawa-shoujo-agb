import re


class CharacterSprite:
    def __init__(self, character_name: str, pose: str, emotion: str, outfit: str, nude: bool, close: bool):
        self.character_name = character_name
        self.pose = pose
        self.outfit = outfit
        self.emotion = emotion
        self.nude = nude
        self.close = close
        self.original_filename = ""
        self.original_path = ""

    def __str__(self):
        return (f"Name: {self.character_name}\n"
                f"Pose: {self.pose}\n"
                f"Emotion: {self.emotion}\n"
                f"Outfit: {self.outfit}\n"
                f"IsNaked: {self.nude}\n"
                f"OriginalFilename: {self.original_filename}\n")

    @staticmethod
    def from_filename(filename: str, regex: str, nude_if=None):
        close = filename.endswith("_close.png")
        if close:
            filename = filename.removesuffix("_close.png") + ".png"
        match = re.match(regex, filename)
        if not match:
            raise Exception(f"Filename {filename} does not match regex {regex}")
        character_name = match.group("name")
        pose = match.group("pose") if "pose" in match.groupdict() else None
        outfit = match.group("outfit") if "outfit" in match.groupdict() else None
        emotion = match.group("emotion")
        nude = nude_if(filename.removesuffix('.png')) if nude_if else False
        return CharacterSprite(character_name, pose, emotion, outfit, nude, close)

    @staticmethod
    def from_displayable(displayable: str, regex: str, nude=False):
        close = displayable.endswith("_close")
        if close:
            displayable = displayable.removesuffix("_close")
        match = re.match(regex, displayable)
        if not match:
            raise Exception(f"Displayable {displayable} does not match regex {regex}")
        character_name = match.group("name")
        pose = match.group("pose") if "pose" in match.groupdict() else None
        outfit = match.group("outfit") if "outfit" in match.groupdict() else None
        emotion = match.group("emotion")
        return CharacterSprite(character_name, pose, emotion, outfit, nude, close)

    def to_bg_name(self) -> str:
        return (f"{self.character_name}_bg"
                f"{f'_{self.pose}' if self.pose else ''}"
                f"{f'_{self.outfit}' if self.outfit else ''}"
                f"{'_close' if self.close else ''}")

    def to_thumb_name(self) -> str:
        return (f"{self.character_name}_thumb"
                f"{f'_{self.pose}' if self.pose else ''}"
                f"{f'_{self.outfit}' if self.outfit else ''}"
                f"{'_close' if self.close else ''}")

    def to_group_name(self) -> str:
        return (f"{self.character_name}"
                f"{f'_{self.pose}' if self.pose else ''}"
                f"{f'_{self.outfit}' if self.outfit else ''}"
                f"{'_close' if self.close else ''}")

    def to_sprite_name(self) -> str:
        return (f"{self.character_name}_spr"
                f"{f'_{self.pose}' if self.pose else ''}"
                f"_{self.emotion}"
                f"{f'_{self.outfit}' if self.outfit else ''}"
                f"{'_close' if self.close else ''}")
        pass


class CharacterRegex:
    @staticmethod
    def default() -> str:
        return r'(?P<name>[^_]+)_(?P<pose>[^_]+)_(?P<emotion>[^_]+)(_(?P<outfit>[^_]+))?$'

    @staticmethod
    def from_filename(regex: str) -> str:
        return regex.removesuffix('$') + r'\.png$'

    @staticmethod
    def nurse() -> str:
        return r'(?P<name>[^_]+)_(?P<emotion>[^_]+)$'

    @staticmethod
    def yuuko() -> str:
        return r'(?P<name>[^_]+)_(?P<emotion>[^_]+)(_(?P<pose>[^_]+))?$'

    @staticmethod
    def yuukoshang() -> str:
        return r'(?P<name>[^_]+)_(?P<emotion>[^_]+)(_(?P<pose>[^_]+))?$'


class CharacterNudeIf:
    @staticmethod
    def default(basename: str) -> bool:
        return False

    @staticmethod
    def eminude(basename: str) -> bool:
        return True

    @staticmethod
    def hanagown(basename: str) -> bool:
        return "stock" in basename

    @staticmethod
    def kenji(basename: str) -> bool:
        return basename.endswith("naked")

    @staticmethod
    def lilly(basename: str) -> bool:
        return basename.endswith("nak")

    @staticmethod
    def shizu(basename: str) -> bool:
        return basename.endswith("nak")


class CharacterDisplayableReplacements:
    @staticmethod
    def emi(displayable_name: str) -> str:
        # TODO: remove gymbounce, its WORKAROUND for thursday script
        return (displayable_name
                .replace("gymbounce", "basic_grin_gym")
                .replace("annoyedbounce", "basic_annoyed")
                )

    @staticmethod
    def emicas(displayable_name: str) -> str:
        # TODO: check for _close notation
        if displayable_name.removesuffix(".png").endswith("_up") or displayable_name.removesuffix("_close.png").endswith("_up"):
            displayable_name = (displayable_name
                                .replace("_up", "")
                                .replace("emicas_", "emicas_up_"))
        else:
            displayable_name = displayable_name.replace("emicas_", "emicas_basic_")
        return displayable_name

    @staticmethod
    def eminude(displayable_name: str) -> str:
        return displayable_name.replace("eminude_", "eminude_basic_")

    @staticmethod
    def emiwheel(displayable_name: str) -> str:
        return displayable_name.replace("emiwheel_", "emiwheel_basic_")

    @staticmethod
    def hanagown(displayable_name: str) -> str:
        if displayable_name.startswith("hanagown_stock"):
            displayable_name = displayable_name.replace("hanagown_stock", "hanagown_stock_")
        else:
            displayable_name = displayable_name.replace("hanagown_", "hanagown_basic_")
        displayable_name = displayable_name.replace("_blush", "blush")
        return displayable_name

    @staticmethod
    def hideaki(displayable_name: str) -> str:
        if displayable_name.removesuffix(".png").endswith("_up"):
            displayable_name = (displayable_name
                                .replace("_up", "")
                                .replace("hideaki_", "hideaki_up_"))
        else:
            displayable_name = displayable_name.replace("hideaki_", "hideaki_basic_")
        return displayable_name

    @staticmethod
    def jigoro(displayable_name: str) -> str:
        return (displayable_name
                .replace("angry", "basic_angry")
                .replace("laugh", "basic_laugh")
                .replace("neutral", "basic_neutral")
                .replace("smug", "basic_smug")
                )

    @staticmethod
    def kenji(displayable_name: str) -> str:
        return (displayable_name
                .replace("happy", "basic_happy")
                .replace("neutral", "basic_neutral")
                .replace("tsun", "basic_tsun")
                .replace("rage", "rage_rage")
                .replace("silhouette_naked", "basic_neutral_naked") # TODO: remove silhouette_naked, its WORKAROUND for kenji sprite
                )

    @staticmethod
    def lilly(displayable_name: str) -> str:
        return (displayable_name
                .replace("basic_arablush_paj", "basic1_arablush_paj")  # hands behind
                .replace("basic_ara_paj", "basic1_ara_paj")  # hands behind
                .replace("basic_ara", "basic2_ara")  # hands joyful
                .replace("basic_emb_paj", "basic1_emb_paj")  # hands behind
                .replace("basic_emb", "basic2_emb")  # hands joyful
                .replace("basic_giggle_paj", "basic1_giggle_paj")  # hands behind
                .replace("basic_giggle", "basic2_giggle")  # hands joyful
                .replace("basic_listen_paj", "basic1_listen_paj")  # hands behind
                .replace("basic_listen", "basic3_listen")  # hands breast
                .replace("basic_oops_paj", "basic1_oops_paj")  # hands behind
                .replace("basic_oops", "basic3_oops")  # hands breast
                .replace("basic_planned_paj", "basic1_planned_paj")  # hands behind
                .replace("basic_planned", "basic2_planned")  # hands joyful
                .replace("basic_pout_paj", "basic1_pout_paj")  # hands behind
                .replace("basic_satisfied_paj", "basic1_satisfied_paj")  # hands behind
                .replace("basic_satisfied", "basic3_satisfied")  # hands breast
                .replace("basic_surprised", "basic3_surprised" if not "_paj" in displayable_name else "basic_surprised")
                # hands breast if not in _paj outfit
                )

    @staticmethod
    def meiko(displayable_name: str) -> str:
        return displayable_name.replace("meiko", "meiko_basic")

    @staticmethod
    def miki(displayable_name: str) -> str:
        return displayable_name.replace("miki", "miki_basic")

    @staticmethod
    def muto(displayable_name: str) -> str:
        return (displayable_name
                .replace("normal", "basic_normal")
                .replace("irritated", "basic_irritated")
                .replace("smile", "basic_smile")
                )

    @staticmethod
    def nomiya(displayable_name: str) -> str:
        return displayable_name.replace("nomiya", "nomiya_basic")

    @staticmethod
    def rin(displayable_name: str) -> str:
        return (displayable_name
                .replace("silhouette", "relaxed_surprised_silhouette")
                )

    @staticmethod
    def sae(displayable_name: str) -> str:
        return (displayable_name
                .replace("sae", "sae_basic")
                .replace("_smoke", "smoke"))

    @staticmethod
    def shopkeep(displayable_name: str) -> str:
        return displayable_name.replace("shopkeep", "shopkeep_basic")

    @staticmethod
    def yuuko(displayable_name: str) -> str:
        # We should swap last two string
        # Example: "yuuko_first_second" -> "yuuko_second_first"
        parts = displayable_name.split('_')
        if len(parts) > 1:
            return '_'.join(parts[:-3] + [parts[-3], parts[-2], parts[-1]])
            # return '_'.join(parts[:-2] + [parts[-1], parts[-2]])

    @staticmethod
    def yuukoshang(displayable_name: str) -> str:
        parts = displayable_name.split('_')
        if len(parts) > 1:
            return '_'.join(parts[:-3] + [parts[-3], parts[-2], parts[-1]])

