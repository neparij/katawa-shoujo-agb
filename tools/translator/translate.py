import re
import json


def parse_translation_file(file_path):
    """Парсинг файла перевода для создания словарей."""
    narration_dict = {}  # Словарь для повествований
    actor_dict = {}  # Словарь для акторов
    errors = []  # Список ошибок для обнаружения дублей

    def add_to_narration(original, translation):
        """Добавить запись в словарь повествований с проверкой на дубли."""
        if original in narration_dict:
            errors.append(f"Дублирующаяся запись для повествования: '{original}'")
        else:
            narration_dict[original] = translation

    def add_to_actor(actor, translation):
        """Добавить запись в словарь акторов без дублей."""
        if actor not in actor_dict:
            actor_dict[actor] = translation

    with open(file_path, "r", encoding="utf-8") as file:
        lines = file.readlines()

    current_original = None  # Текущая оригинальная строка для перевода

    for line in lines:
        line = line.strip()

        # # Обработка структуры old/new
        # old_match = re.match(r"old\s*\"(.*?)\"", line)
        # if old_match:
        #     current_original = old_match.group(1)

        # if current_original and line.startswith("new"):
        #     new_match = re.match(r"new\s*\"(.*?)\"", line)
        #     if new_match:
        #         translation = new_match.group(1)
        #         add_to_narration(current_original, translation)
        #         current_original = None

        # Обработка строки с актором и повествованием
        actor_narration_match = re.match(r"#\s*\"(.*?)\"\s*\"(.*?)\"", line)
        if actor_narration_match:
            actor, narration = actor_narration_match.groups()
            translation_match = re.match(r"\"(.*?)\"\s*\"(.*?)\"", line)
            if translation_match:
                actor_translation, narration_translation = translation_match.groups()
                add_to_actor(actor, actor_translation)  # Сохраняем актора
                add_to_narration(narration, narration_translation)  # Сохраняем текст повествования

        # Проверка на комментарий с оригинальным текстом
        comment_match = re.match(r"#\s*\"(.*?)\"", line)
        if comment_match:
            current_original = comment_match.group(1)

        # Обработка строки перевода после комментария
        if current_original and line.startswith('"') and line.endswith('"'):
            translation = line.strip('"')
            add_to_narration(current_original, translation)
            current_original = None  # Сбрасываем текущий оригинал


    return narration_dict, actor_dict, errors


def save_to_json(data, output_path):
    """Сохранение данных в JSON."""
    with open(output_path, "w", encoding="utf-8") as file:
        json.dump(data, file, ensure_ascii=False, indent=4)
    print(f"Словарь сохранен в файл: {output_path}")


def main():
    input_file = "/Users/n.laptev/development/ksre/game/tl/ru/script-a1-monday.rpy"
    narration_output = "narration_dict.json"
    actor_output = "actor_dict.json"

    print("Парсинг файла перевода...")
    narration_dict, actor_dict, errors = parse_translation_file(input_file)

    # Вывод ошибок дублей
    if errors:
        print("Ошибки:")
        for error in errors:
            print(f"  - {error}")

    print(f"Найдено повествований: {len(narration_dict)}")
    print(f"Найдено акторов: {len(actor_dict)}")

    save_to_json(narration_dict, narration_output)
    save_to_json(actor_dict, actor_output)


if __name__ == "__main__":
    main()



