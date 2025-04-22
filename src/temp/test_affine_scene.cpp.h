#ifndef TEST_AFFINE_SCENE_CPP_H
#define TEST_AFFINE_SCENE_CPP_H

inline void test() {
    // // ::: AFFINEBG_192x192 in 256x256 halves RIN WISP (START) :::
    // bn::optional<bn::affine_bg_ptr> affine_bg_one;
    // bn::optional<bn::affine_bg_ptr> affine_bg_two;
    //
    // // affine_bg_one = bn::affine_bg_builder(bn::affine_bg_items::rin_wisp3_top)
    // //     .set_position(0, 0)
    // //     .set_scale(1.5)
    // //     .set_wrapping_enabled(false)
    // //     .build();
    // // affine_bg_two = bn::affine_bg_builder(bn::affine_bg_items::rin_wisp3_bottom)
    // //     .set_position(0, 0)
    // //     .set_scale(1.5)
    // //     .set_wrapping_enabled(false)
    // //     .build();
    //
    //
    // affine_bg_one = bn::affine_bg_builder(bn::affine_bg_items::rin_wisp_blurred_full)
    //     .set_position(0, 0)
    //     .set_scale(2.25)
    //     .set_wrapping_enabled(false)
    //     .set_priority(3)
    //     .set_z_order(10)
    //     .build();
    // affine_bg_two = bn::affine_bg_builder(bn::affine_bg_items::rin_wisp_smoke_focused_full)
    //     .set_position(0, 0)
    //     .set_scale(2.25)
    //     .set_wrapping_enabled(false)
    //     .set_blending_enabled(true)
    //     .set_priority(3)
    //     .set_z_order(9)
    //     .build();
    //
    // bn::fixed wisp_turn, smoke_turn = 0.00;
    // bn::blending::set_transparency_and_intensity_alpha(0.0, 1.0);
    //
    // ks::sound_manager::stop<SOUND_CHANNEL_MUSIC>();
    // ks::sound_manager::play(MUSIC_SERENE);
    // ks::dialog->show("Rin", "It's not very tasty. Feels like inhaling the dust lying on top of a forgotten book about the memories of a dead kingdom.", false);
    // while (!bn::keypad::start_pressed()) {
    //     wisp_turn = (wisp_turn - 0.05 + 360) % 360;
    //     smoke_turn = (smoke_turn + 0.05 + 360) % 360;
    //
    //     affine_bg_one->set_rotation_angle(wisp_turn);
    //     // affine_bg_two->set_rotation_angle(wisp_turn);
    //     affine_bg_two->set_rotation_angle(smoke_turn);
    //     if (!ks::dialog->is_finished()) {
    //         ks::dialog->update();
    //     } else {
    //         ks::dialog->hide();
    //     }
    //
    //     ks::globals::main_update();
    // }
    //
    // bn::blending::set_intensity_alpha(0);
    // affine_bg_one.reset();
    // affine_bg_two.reset();
    // // ::: AFFINEBG_192x192 RIN WISP (END) :::
}

#endif //TEST_AFFINE_SCENE_CPP_H
