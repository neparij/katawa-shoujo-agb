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
        case PALETTE_VARIANT_NIGHT:
            // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(0.6, 0.6, 0.7))) * SaturationMatrix(0.6))
            return new_color.tint(val(0.6f),
                                val(0.6f),
                                val(0.7f))
                            .saturate(val(0.6f))
                            .to_bn_color();
        case PALETTE_VARIANT_SPRITE_NIGHT:
            // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(0.9, 0.92, 1.0))) * BrightnessMatrix(-0.05))
            return new_color.tint(val(0.90f),
                                val(0.92f),
                                val(1.00f))
                            .brighten(val(-0.05f))
                            .to_bn_color();
        case PALETTE_VARIANT_SUNSET:
            // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(1.1, 0.95, 0.85))) * SaturationMatrix(1.2) * BrightnessMatrix(0.1))
            return new_color.tint(val(1.10f),
                                val(0.95f),
                                val(0.85f))
                            .saturate(val(1.2f))
                            .brighten(val(0.1f))
                            .to_bn_color();
        case PALETTE_VARIANT_SPRITE_SUNSET:
            // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(1.02, 0.95, 0.9))) * SaturationMatrix(1.1) * BrightnessMatrix(0.05))
            return new_color.tint(val(1.02f),
                                val(0.95f),
                                val(0.90f))
                            .saturate(val(1.1f))
                            .brighten(val(0.05f))
                            .to_bn_color();
        case PALETTE_VARIANT_RAIN:
            // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(0.95, 0.95, 1.0))) * SaturationMatrix(0.4) * BrightnessMatrix(-0.1))
            return new_color.tint(val(0.95f),
                                val(0.95f),
                                val(1.00f))
                            .saturate(val(0.4f))
                            .brighten(val(-0.1f))
                            .to_bn_color();
        case PALETTE_VARIANT_SPRITE_RAIN:
            // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(0.96, 0.96, 1.0))) * SaturationMatrix(0.6) * BrightnessMatrix(-0.05))
            return new_color.tint(val(0.96f),
                                val(0.96f),
                                val(1.00f))
                            .saturate(val(0.6f))
                            .brighten(val(-0.05f))
                            .to_bn_color();
        case PALETTE_VARIANT_PAST:
            // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(1.0, 0.94, 0.76))) * SaturationMatrix(0.15))
            return new_color.tint(val(1.00f),
                                  val(0.94f),
                                  val(0.76f))
                            .saturate(val(0.15f))
                            .to_bn_color();
        case PALETTE_VARIANT_SPRITE_PAST:
            // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(1.0, 0.94, 0.76))) * SaturationMatrix(0.15))
            return new_color.tint(val(1.00f),
                                  val(0.94f),
                                  val(0.76f))
                            .saturate(val(0.15f))
                            .to_bn_color();
        case PALETTE_VARIANT_PAST_NIGHT:
            // return Transform(image, matrixcolor=TintMatrix(Color(rgb=(0.6, 0.6, 0.7))) * TintMatrix(Color(rgb=(1.0, 0.94, 0.76))) * SaturationMatrix(0.6) * SaturationMatrix(0.15))
            return new_color.tint(val(0.60f),
                                  val(0.60f),
                                  val(0.70f))
                            .tint(val(1.00f),
                                  val(0.94f),
                                  val(0.76f))
                            .saturate(val(0.6f))
                            .saturate(val(0.15f))
                            .to_bn_color();
        case PALETTE_VARIANT_BLACK_AND_WHITE:
            return new_color.saturate(val(0.0f)).to_bn_color();
        case PALETTE_VARIANT_ADULT:
            return new_color.brighten(val(-1.0f)).to_bn_color();
        default:
            return color;
    }
}
