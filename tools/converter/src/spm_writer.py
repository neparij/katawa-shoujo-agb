import os.path
import tempfile
from typing import List

import sentencepiece as spm

from src.utils import collect_scenario_sentences, sanitize_ingame_text


class SPMWriter:
    def __init__(self, assets_path: str, locale: str):
        self.assets_path = assets_path
        self.locale = locale
        self.textdb_strings: List[str] = []
        # We use a biased variable-length token encoding in TextDB:
        # most frequent token IDs stay 1-byte, while the tail uses 2-3 bytes.
        # Keep this in sync with src/utils/scenario_reader.cpp decoder.
        self.max_tokens = 4095

    def process_scenario(self, scenario):
        collect_scenario_sentences(scenario, self.locale, self.textdb_strings)

    def write_model(self):
        output_file_prefix = os.path.join(self.assets_path, f"spm-{self.locale}")
        textdb_strings_file = tempfile.mktemp(suffix=f"_textdb_strings_{self.locale}.txt")
        with open(textdb_strings_file, "w", encoding="utf-8") as f:
            for line in self.textdb_strings:
                f.write(sanitize_ingame_text(line) + "\n")

        spm_args = (f"--input={textdb_strings_file} "
                    f"--model_prefix={output_file_prefix} "
                    f"--vocab_size={self.max_tokens} "
                    f"--model_type=bpe "
                    f"--character_coverage=1.0 "
                    f"--unk_id=0 "
                    f"--bos_id=-1 "
                    f"--eos_id=-1 "
                    f"--normalization_rule_name=identity "
                    f"--remove_extra_whitespaces=false "
                    f"--add_dummy_prefix=false "
                    f"--train_extremely_large_corpus=true "
                    f"--split_by_whitespace=false "
                    f"--max_sentencepiece_length=32 "
                    f"--num_sub_iterations=10 "
                    f"--shrinking_factor=0.95")
        spm.SentencePieceTrainer.Train(spm_args)
