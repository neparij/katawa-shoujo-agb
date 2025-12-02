from typing import List, cast

from src.characters import CHARACTERS
from src.dto.background_item import BackgroundItem
from src.dto.condition_item import ConditionItem
from src.dto.custom_event_item import CustomEventItem
from src.dto.hide_item import HideItem
from src.dto.sequence_item import SequenceItem
from src.dto.show_item import ShowItem
from src.scenario.sequence_group import SequenceGroup, SequenceGroupType


class ScenarioGraphParser:
    def __init__(self, scenario_data: List[SequenceGroup], max_sprites_per_pack: int = 3):
        self.scenario_data = scenario_data
        self.shown_sprites: List[ShowItem] = []
        self.max_sprites_per_pack = max_sprites_per_pack
        self.graph_branches: List[List[SequenceItem]] = []

    def is_show_item_in_shown_sprites(self, show_item: ShowItem) -> bool:
        for shown_item in self.shown_sprites:
            if shown_item.sprite == show_item.sprite:
                return True
        return False

    def add_or_replace_show_item_to_shown_sprites(self, show_item: ShowItem):
        if show_item.sprite not in CHARACTERS:
            return
        if self.is_show_item_in_shown_sprites(show_item):
            # Replace existing show item
            for i, shown_item in enumerate(self.shown_sprites):
                if shown_item.sprite == show_item.sprite:
                    self.shown_sprites[i] = show_item
                    break
        else:
            self.shown_sprites.append(show_item)

    def remove_show_item_from_shown_sprites(self, hide_item: HideItem):
        if hide_item.sprite not in CHARACTERS:
            return
        self.shown_sprites = [item for item in self.shown_sprites if item.sprite != hide_item.sprite]

    def clear_shown_sprites(self):
        self.shown_sprites.clear()

    def shown_sprites_count(self) -> int:
        return len(self.shown_sprites)

    def run(self):
        for sequence_group in self.scenario_data:
            if not sequence_group.is_initial and sequence_group.is_called_inline:
                # Recursively traverses the sequence_group, extracting all possible branches.
                print(f"Collecting graph branches from sequence group: {sequence_group.name}")
                self.graph_branches.clear()
                self.traverse_sequence(sequence_group.sequence, [])
                for graph_branch in self.graph_branches:
                    self.check_for_max_sprites(graph_branch, sequence_group.name)

    def get_scenario_condition_branches(self, function_name: str) -> List[List[SequenceItem]]:
        condition_sequences: List[List[SequenceItem]] = []
        for sequence_group in [sg for sg in self.scenario_data if
                               sg.name == function_name and sg.type == SequenceGroupType.CONDITION]:
            if len(sequence_group.sequence) > 0:
                raise Exception(f"Scenario condition sequence group '{function_name}' "
                                f"has direct sequence items, which is not allowed.")
            for condition_wrapper in sequence_group.conditions:
                condition_sequences.append(condition_wrapper.sequence)
        return condition_sequences

    def traverse_sequence(self, items: List[SequenceItem], current_path: List[SequenceItem]):
        for item in items:
            current_path.append(item)
            if isinstance(item, ConditionItem):
                condition = cast(ConditionItem, item)
                branches = self.get_scenario_condition_branches(condition.function_callback)
                for branch in branches:
                    # Create a new path for each branch and add the remaining items after the condition
                    self.traverse_sequence(branch + items[items.index(item) + 1:], current_path.copy())
                # After processing all branches, we return to avoid adding the current path again
                return
        # If we reach here, it means we have traversed all items without hitting a condition
        self.graph_branches.append(current_path)

    def on_max_sprites_per_pack_exceeded(self, graph_branch: List[SequenceItem], item: SequenceItem, label_name: str):
        raise Exception(f"Max sprites of {self.max_sprites_per_pack} exceeded for graph branch in label \"{label_name}\".\n"
                        f"Item: {item}\n"
                        f"Shown sprites: {[f"{str(sprite.sprite)} ({str(sprite.variant)})" for sprite in self.shown_sprites]}\n"
                        f"Sequence block ends at line: {item.line_number}")

    # Read the graph and call on_max_sprites_per_pack_exceeded when max_sprites_per_pack is exceeded
    def check_for_max_sprites(self, items: List[SequenceItem], label_name: str):
        for item in items:
            if isinstance(item, ShowItem):
                self.add_or_replace_show_item_to_shown_sprites(cast(ShowItem, item))
            elif isinstance(item, HideItem):
                self.remove_show_item_from_shown_sprites(cast(HideItem, item))
            elif isinstance(item, BackgroundItem) or isinstance(item, CustomEventItem):
                self.clear_shown_sprites()

            # After processing each item, check if the max sprites per pack is exceeded
            if self.shown_sprites_count() > self.max_sprites_per_pack:
                self.on_max_sprites_per_pack_exceeded(items, item, label_name)
