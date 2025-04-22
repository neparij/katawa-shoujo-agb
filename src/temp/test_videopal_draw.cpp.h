#ifndef TEST_VIDEOPAL_DRAW_CPP_H
#define TEST_VIDEOPAL_DRAW_CPP_H

inline void test() {
    // ks::main_background = bn::regular_bg_items::ui_bg_menu.create_bg(0, 0);
    // ks::secondary_background = bn::regular_bg_items::ui_test_paldraw_b.create_bg_optional(0, 0);
    // bn::bg_palette_ptr minbg_palette = ks::main_background->palette();
    // bn::bg_palette_ptr secbg_palette = ks::secondary_background->palette();
    // minbg_palette.set_fade(globals::colors::WHITE, bn::fixed(1));
    // secbg_palette.set_grayscale_intensity(bn::fixed(1));
    // secbg_palette.set_fade(globals::colors::WHITE, bn::fixed(1));
    // bn::bg_palette_fade_to_action main_fade_action(minbg_palette, 128, bn::fixed(0));
    // bn::bg_palette_fade_to_action fade_action(secbg_palette, 96, bn::fixed(0));
    // bn::bg_palette_grayscale_to_action grayscale_action(secbg_palette, 64, bn::fixed(0));
    //
    // ks::main_background->set_mosaic_enabled(true);
    // ks::secondary_background->set_mosaic_enabled(true);
    // bn::bgs_mosaic::set_stretch(0.5);
    // bn::bgs_mosaic_stretch_to_action main_mosaic_action(48, bn::fixed(0));
    //
    // float move_f = 0.0f;
    // while (!fade_action.done() || !grayscale_action.done() || move_f < 1) {
    //     if (!main_mosaic_action.done()) {
    //         main_mosaic_action.update();
    //     }
    //
    //     if (!main_fade_action.done()) {
    //         main_fade_action.update();
    //     }
    //
    //     if (!fade_action.done() && move_f > 0.6f) {
    //         fade_action.update();
    //     }
    //
    //     if (!grayscale_action.done() && fade_action.done()) {
    //         grayscale_action.update();
    //     }
    //
    //     ks::secondary_background->set_position(-72 * bezier_f(move_f), 0);
    //     if (move_f < 1) {
    //         move_f += 0.003f;
    //     }
    //     bn::core::update();
    // }
    //
    // ks::SceneManager::fade_out(globals::colors::BLACK);
}

inline float bezier_f(float t) {
    return t * t * (3.0f - 2.0f * t);
}

#endif //TEST_VIDEOPAL_DRAW_CPP_H
