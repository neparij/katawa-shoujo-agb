import re


def sanitize_function_name(text):
    return re.sub(r"[^a-zA-Z0-9_]", "", text.replace(" ", "_").lower())
