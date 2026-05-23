#!/usr/bin/env python3
"""Script-closure layer state for the rin_pair event CG."""

from __future__ import annotations

from dataclasses import dataclass

RIN_PAIR_META_PREFIX = "rin_pair"

_HISAO_CODES = {
    "normal": "hn",
    "frown": "hf",
    "smile": "hs",
}

_RIN_CODES = {
    "normal": "rn",
    "talk": "rt",
    "smile": "rs",
    "frown": "rf",
    "closed": "rc",
}


def rin_pair_meta_name(clothes: bool, hisao: str, rin: str) -> str:
    c = "c" if clothes else "n"
    return f"{RIN_PAIR_META_PREFIX}_{c}_{_HISAO_CODES[hisao]}_{_RIN_CODES[rin]}"


@dataclass
class RinPairLayerState:
    clothes: bool = True
    hisao: str = "normal"
    rin: str = "normal"

    def meta_name(self) -> str:
        return rin_pair_meta_name(self.clothes, self.hisao, self.rin)

    def reset_clothes_scene(self) -> str:
        self.clothes = True
        self.hisao = "normal"
        self.rin = "normal"
        return self.meta_name()

    def set_clothes_off(self) -> str:
        self.clothes = False
        return self.meta_name()

    def set_hisao(self, expr: str) -> str:
        if expr not in _HISAO_CODES:
            raise ValueError(f"unknown rp_hisao expression: {expr!r}")
        self.hisao = expr
        return self.meta_name()

    def set_rin(self, expr: str) -> str:
        if expr not in _RIN_CODES:
            raise ValueError(f"unknown rp_rin expression: {expr!r}")
        self.rin = expr
        return self.meta_name()
