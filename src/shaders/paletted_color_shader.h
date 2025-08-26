#ifndef PALETTED_COLOR_SHADER_H
#define PALETTED_COLOR_SHADER_H

#define SHADER_PAL_COL_P 8

#include "bn_color.h"
#include "bn_fixed.h"
#include "gba_math.h"
#include "definitions.h"

struct f_color {
    bn::fixed_t<SHADER_PAL_COL_P> r;
    bn::fixed_t<SHADER_PAL_COL_P> g;
    bn::fixed_t<SHADER_PAL_COL_P> b;

    [[nodiscard]] bn::color to_bn_color() const {
        return {
            clamp(r.integer(), 0, 31),
            clamp(g.integer(), 0, 31),
            clamp(b.integer(), 0, 31),
        };
    }

    f_color saturate(const bn::fixed value) {
        const auto gray = (r + g + b) / 3;
        r = gray + (r - gray) * value;
        g = gray + (g - gray) * value;
        b = gray + (b - gray) * value;
        return *this;
    }

    f_color tint(const bn::fixed r_tint, const bn::fixed g_tint, const bn::fixed b_tint) {
        r *= r_tint;
        g *= g_tint;
        b *= b_tint;
        return *this;
    }

    f_color brighten(const bn::fixed value) {
        r += value;
        g += value;
        b += value;
        return *this;
    }
};

bn::color get_paletted_color(const bn::color& color, palette_variant_t palette_variant);

#endif //PALETTED_COLOR_SHADER_H
