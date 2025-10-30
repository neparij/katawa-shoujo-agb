import os
from collections import namedtuple

import sentencepiece as spm


class SPMPacker:
    def __init__(self, spm_path: str, gbfs_path: str, locale: str):
        self.spm_path = spm_path
        self.gbfs_path = gbfs_path
        self.locale = locale

    def pack(self):
        print(f"Packing SPM vocabulary for locale {self.locale}...")
        token = namedtuple('Token', ['offset', 'value'])
        model_file = os.path.join(self.spm_path, f'spm-{self.locale}.model')
        vocab_file = os.path.join(self.spm_path, f'spm-{self.locale}.vocab')
        out_file = os.path.join(self.gbfs_path, f'spm_vocab_{self.locale}.bin')

        spp = spm.SentencePieceProcessor()
        tokens: list[token] = []
        try:
            spp.Load(model_file=model_file)
            spp.LoadVocabulary(filename=vocab_file, threshold=0)
        except Exception as e:
            raise Exception(f"Failed to load SPM vocabulary for locale '{self.locale}': {e}")

        offset = 0
        for i in range(1, spp.GetPieceSize()):
            if offset >= 0xFFFF:
                raise Exception(f"SPM vocabulary for locale '{self.locale}' exceeds maximum size of 65535 bytes")

            piece = spp.IdToPiece(i).replace('▁', ' ')
            tokens.append(token(offset=offset, value=piece))
            offset += len(piece.encode('utf-8')) + 1

        with open(out_file, 'wb') as f:
            # Write offset table
            for t in tokens:
                f.write(t.offset.to_bytes(2, byteorder='little'))
            # Write token values
            for t in tokens:
                f.write(t.value.encode('utf-8') + b'\x00')
        print(f"Packed {len(tokens)} tokens into SPM vocabulary file {out_file}")
