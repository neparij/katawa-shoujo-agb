#include "paletted_color_shader.h"

bn::fixed_t<SHADER_PAL_COL_P> constexpr val(const float value) {
    return {value};
}

bn::color get_paletted_color(const bn::color& color, palette_variant_t palette_variant) {
    if (palette_variant == PALETTE_VARIANT_DEFAULT) {
        return color;
    }

    f_color new_color = {
        color.red(),
        color.green(),
        color.blue(),
    };

    switch (palette_variant) {
        case PALETTE_VARIANT_SPRITE_NIGHT:
            // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(0.9, 0.92, 1.0))) * BrightnessMatrix(-0.05))
            return new_color.tint(val(0.90f),
                                val(0.92f),
                                val(1.00f))
                            .brighten(val(-0.05f))
                            .to_bn_color();
        case PALETTE_VARIANT_SPRITE_SUNSET:
            // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(1.02, 0.95, 0.9))) * SaturationMatrix(1.1) * BrightnessMatrix(0.05))
            return new_color.tint(val(1.02f),
                                val(0.95f),
                                val(0.90f))
                            .saturate(val(1.1f))
                            .brighten(val(0.05f))
                            .to_bn_color();
        case PALETTE_VARIANT_SPRITE_RAIN:
            // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(0.96, 0.96, 1.0))) * SaturationMatrix(0.6) * BrightnessMatrix(-0.05))
            return new_color.tint(val(0.96f),
                                val(0.96f),
                                val(1.00f))
                            .saturate(val(0.6f))
                            .brighten(val(-0.05f))
                            .to_bn_color();
        default:
            return color;
    }
}
