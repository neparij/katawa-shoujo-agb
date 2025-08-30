from typing import List

from src.scenario.sequence_group import SequenceGroup, SequenceGroupType


class ScenarioScriptStack:
    def __init__(self):
        self.stack: [(SequenceGroup, int)] = []

    def current_label(self) -> SequenceGroup|None:
        for entry in reversed(self.stack):
            if entry[0].type == SequenceGroupType.LABEL:
                return entry[0]
        return None

    def parent_label(self) -> SequenceGroup|None:
        for entry in self.stack:
            if entry[0].type == SequenceGroupType.LABEL:
                return entry[0]
        return None

    def current_indent(self) -> int:
        if len(self.stack) == 0:
            return 0
        return self.stack[-1][1]

    def current(self) -> SequenceGroup|None:
        if len(self.stack) == 0:
            return None
        return self.stack[-1][0]

    def push(self, sequence_group, indent):
        self.stack.append((sequence_group, indent))

    def pop(self) -> SequenceGroup|None:
        if len(self.stack) == 0:
            return None
        return self.stack.pop()[0]

    def top(self) -> SequenceGroup|None:
        if len(self.stack) == 0:
            return None
        return self.stack[-1][0]

    def size(self) -> int:
        return len(self.stack)

    def clear(self):
        self.stack.clear()

    def __str__(self):
        return str(self.stack)