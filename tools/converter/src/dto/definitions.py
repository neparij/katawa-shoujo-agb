from typing import List


class LabelDefinition:
    def __init__(self, label_name: str, label_id: str, description: str):
        self.label_name = label_name
        self.label_id = label_id
        self.description = description

    def __str__(self):
        return f"LabelDefinition(label_name={self.label_name}, label_id={self.label_id}, description={self.description})"


class ActDefinition:
    def __init__(self, act_name: str, labels: List[LabelDefinition]):
        self.act_name = act_name
        self.labels = labels

    def __str__(self):
        return f"ActDefinition(act_name={self.act_name}, labels={self.labels})"


class RouteDefinition:
    def __init__(self, route_name: str, acts: List[ActDefinition]):
        self.route_name = route_name
        self.acts = acts

    def __str__(self):
        return f"RouteDefinition(route_name={self.route_name}, acts={self.acts})"
