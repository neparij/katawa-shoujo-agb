#include "op1.h"

#include "bn_bg_palettes.h"
#include "bn_regular_bg_items_op_cardiogram_bg.h"
#include "bn_regular_bg_items_op_cardiogram_fg_anim.h"
#include "bn_regular_bg_items_op_clock_bg_0.h"
#include "bn_regular_bg_items_op_clock_bg_10to11.h"
#include "bn_regular_bg_items_op_clock_bg_1to8.h"
#include "bn_regular_bg_items_op_clock_bg_9.h"
#include "bn_regular_bg_items_op_clock_fg_anim.h"
#include "bn_regular_bg_items_op_ivdrip_bg.h"
#include "bn_regular_bg_items_op_ivdrip_fg_anim.h"
#include "bn_regular_bg_items_op_table_bg_0.h"
#include "bn_regular_bg_items_op_table_bg_1.h"
#include "bn_regular_bg_items_op_transition_to_clock.h"
#include "bn_regular_bg_items_op_transition_to_end.h"
#include "bn_regular_bg_items_op_transition_to_ivdrip.h"
#include "bn_regular_bg_items_op_transition_to_table.h"
#include "bn_sprite_items_fontpalette_opening_0.h"
#include "bn_sprite_items_fontpalette_opening_0_bold.h"
#include "bn_sprite_items_fontpalette_opening_1.h"
#include "bn_sprite_items_fontpalette_opening_1_bold.h"
#include "bn_sprite_items_op_cardiogram_sprite.h"
#include "bn_sprite_items_op_ivdrip_sprite.h"
#include "bn_sprite_palettes.h"
#include "definitions.h"
#include "../globals.h"
#include "../scenemanager.h"
#include "../sound_manager.h"


void ks::GameOpening::run() {
    bn::bg_palettes::set_fade(globals::colors::BLACK, bn::fixed(1));
    bn::sprite_palettes::set_fade(globals::colors::BLACK, bn::fixed(1));
    ks::text_generator->set_one_sprite_per_character(false);
    ks::text_generator_small->set_one_sprite_per_character(false);

    ks::sound_manager::play<SOUND_CHANNEL_VIDEO>("video_op_1.ulc");
    create_stage_cardiogram();
    while (!is_finished) {
        update();
    }

    primary_background.reset();
    secondary_background.reset();

    blending_action.reset();
    cardiogram_peak_bg.reset();
    cardio_sprite.reset();
    ivdrip_additional_bg.reset();
    ivdrip_sprite.reset();
    clock_additional_bg.reset();
    text_move_actions.clear();

    SceneManager::fade_reset();
}

void ks::GameOpening::update() {
    frame_counter++;

    if (bn::keypad::start_pressed()) {
        is_finished = true;
        return;
    }

    if (text_move_actions.size() > 0) {
        for (auto &action: text_move_actions) {
            if (!action.done()) {
                action.update();
            } else {
                text_move_actions.erase(text_move_actions.begin());
            }
        }
    }

    if (frame_counter < 108) {
        globals::main_update();
        return;
    }

    if (outro) {
        if (opening_fade_duration < 260 && frame_counter % 2 == 0) {
            opening_fade_duration++;
            bn::bg_palettes::set_fade(ks::globals::colors::BLACK, bn::fixed(opening_fade_duration) / 260);
            // bn::sprite_palettes::set_fade(ks::globals::colors::BLACK, bn::fixed(opening_fade_duration) / 260);
        }
        if (!playerULC_is_playing()) {
            is_finished = true;
            return;
        }
        globals::main_update();

        if (heartbeat_frame_counter < op_heartbeat) {
            heartbeat_frame_counter++;
        } else {
            heartbeat_frame_counter = 0;
        }
        return;
    }

    if (opening_fade_duration > 0) {
        opening_fade_duration--;
        bn::bg_palettes::set_fade(ks::globals::colors::BLACK, bn::fixed(opening_fade_duration) / 260);
        bn::sprite_palettes::set_fade(ks::globals::colors::BLACK, bn::fixed(opening_fade_duration) / 260);
    }

    if (cardio_sprite.has_value()) {
        if (heartbeat_frame_counter == op_heartbeat - 11) {
            cardio_sprite->set_position(-168, 24);
        }
        if (heartbeat_frame_counter % 4 == 0) {
            cardio_sprite->set_position(cardio_sprite->position().x() + 16, 24);
        }
    }

    if (cardiogram_peak_bg.has_value()) {
        if (heartbeat_frame_counter % 4 == 0) {
            if (heartbeat_frame_counter == 0) {
                cardio_peak_index = 0;
            } else {
                cardio_peak_index++;
            }
            if (cardio_peak_index >= 0 && cardio_peak_index < 7) {
                cardiogram_peak_bg->set_map(bn::regular_bg_items::op_cardiogram_fg_anim.map_item(), cardio_peak_index);
                cardiogram_peak_bg->set_visible(true);
            } else {
                cardiogram_peak_bg->set_visible(false);
            }
        }
    }

    if (ivdrip_sprite.has_value() && ivdrip_additional_bg.has_value()) {
        short frame = heartbeat_frame_counter;
        if (heartbeat_index % 2 != 0) {
            frame += op_heartbeat;
        }

        if (frame == 0) {
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 1);
        }
        if (frame == 28) {
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 2);
        }
        if (frame == 56) {
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 3);
        }
        if (frame == 84) {
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 4);
        }
        if (frame == 112) {
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 5);
        }
        if (frame == 124) {
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 6);
        }
        if (frame == 136) {
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 7);
        }
        if (frame == 148) {
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 8);
        }
        if (frame == 160) {
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 9);
        }
        if (frame == 172) {
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 10);
        }
        if (frame == 184) {
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 11);
        }
        if (frame == 196) {
            ivdrip_additional_bg->set_visible(true);
            ivdrip_additional_bg->set_map(bn::regular_bg_items::op_ivdrip_fg_anim.map_item(), 0);
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 12);
        }
        if (frame == 210) {
            ivdrip_additional_bg->set_visible(true);
            ivdrip_additional_bg->set_map(bn::regular_bg_items::op_ivdrip_fg_anim.map_item(), 1);
            ivdrip_sprite->set_item(bn::sprite_items::op_ivdrip_sprite, 0);
        }
        if (frame == 224) {
            ivdrip_additional_bg->set_visible(false);
        }
    }

    if (bg_stage == 2) {
        if (frame_counter < 2190) {
            scene_offset_x = -8;
        } else {
            scene_offset_x = bn::fixed(frame_counter - 2190).division(990).multiplication(16) - 8;
            primary_background->set_position(scene_offset_x, 0);
        }
        if (secondary_background.has_value()) {
            secondary_background->set_position(scene_offset_x, 0);
        }
    }

    if (bg_stage == 3 && (heartbeat_frame_counter == 131 || heartbeat_frame_counter == 63)) {
        clock_second_index++;
        if (clock_second_index == 0) {
            clock_additional_bg = bn::regular_bg_items::op_clock_fg_anim.create_bg(0, 0);
            clock_additional_bg->set_priority(2);
        }
        if (clock_second_index >= 0 && clock_second_index < 8) {
            clock_additional_bg->set_map(bn::regular_bg_items::op_clock_fg_anim.map_item(), clock_second_index);
        }
        if (clock_second_index == 0) {
            replace_or_create_main_bg_item(bn::regular_bg_items::op_clock_bg_1to8, 0, 0);
        }
        if (clock_second_index == 8) {
            clock_additional_bg.reset();
            replace_or_create_main_bg_item(bn::regular_bg_items::op_clock_bg_9, 0, 0);
        }
    }

    globals::main_update();

    if (heartbeat_frame_counter < op_heartbeat) {
        heartbeat_frame_counter++;
    } else {
        heartbeat_frame_counter = 0;
        on_heartbeat();
    }
}

void ks::GameOpening::on_heartbeat() {
    heartbeat_index++;
    BN_LOG("HEARTBEAT: ", heartbeat_index);

    if (heartbeat_index == 2) {
        ks::static_text_sprites.clear();
        ks::text_generator_small->set_center_alignment();
        ks::text_generator_small->set_bg_priority(2);
        ks::text_generator_small->set_palette_item(bn::sprite_items::fontpalette_opening_0.palette_item());
        ks::text_generator_small->generate(44, 16, "Four Leaf Studios presents", ks::static_text_sprites);
        fadein_text();
    }

    if (heartbeat_index == 3) {
        fadeout_text();
    }

    if (heartbeat_index == 4) {
        ks::static_text_sprites.clear();
        ks::text_generator->set_center_alignment();
        ks::text_generator->set_bg_priority(2);
        ks::text_generator->set_palette_item(bn::sprite_items::fontpalette_opening_0_bold.palette_item());
        ks::text_generator->generate(44, 32, "Katawa Shoujo", ks::static_text_sprites);
        fadein_text();
    }

    if (heartbeat_index == 5) {
        fadeout_text();
    }

    if (heartbeat_index == 6) {
        bg_stage = 1;
        switch_bg_stage(
            bn::regular_bg_items::op_transition_to_ivdrip
        );
    }

    if (heartbeat_index == 7) {
        create_credits_block(44, 16,
                             bn::sprite_items::fontpalette_opening_1_bold.palette_item(),
                             bn::sprite_items::fontpalette_opening_1.palette_item(),
                             "Inspiration",
                             "RAITA");
        fadein_text();
    }

    if (heartbeat_index == 8) {
        fadeout_text();
    }

    if (heartbeat_index == 9) {
        create_credits_block(44, 16,
                             bn::sprite_items::fontpalette_opening_1_bold.palette_item(),
                             bn::sprite_items::fontpalette_opening_1.palette_item(),
                             "Writing",
                             "Anonymous22",
                             "Aura",
                             "cpl_crud",
                             "Suriko",
                             "TheHivemind");
        fadein_text();
    }

    if (heartbeat_index == 10) {
        fadeout_text();
    }

    if (heartbeat_index == 11) {
        create_credits_block(44, 16,
                             bn::sprite_items::fontpalette_opening_1_bold.palette_item(),
                             bn::sprite_items::fontpalette_opening_1.palette_item(),
                             "Editing",
                             "Kagami",
                             "Losstarot",
                             "Silentcook");
        fadein_text();
    }

    if (heartbeat_index == 12) {
        fadeout_text();
    }

    if (heartbeat_index == 13) {
        create_credits_block(44, 16,
                             bn::sprite_items::fontpalette_opening_1_bold.palette_item(),
                             bn::sprite_items::fontpalette_opening_1.palette_item(),
                             "Music",
                             "Blue123",
                             "NicolArmarfi");
        fadein_text();
    }

    if (heartbeat_index == 14) {
        bg_stage = 2;
        switch_bg_stage(
            bn::regular_bg_items::op_transition_to_table
        );
    }

    if (heartbeat_index == 15) {
        create_credits_block(52, 32,
                             bn::sprite_items::fontpalette_opening_1_bold.palette_item(),
                             bn::sprite_items::fontpalette_opening_1.palette_item(),
                             "Art",
                             "gebyy-terar",
                             "Kamifish",
                             "pimmy");
        fadein_text();
    }

    if (heartbeat_index == 16) {
        fadeout_text();
    }

    if (heartbeat_index == 17) {
        create_credits_block(52, 32,
                             bn::sprite_items::fontpalette_opening_1_bold.palette_item(),
                             bn::sprite_items::fontpalette_opening_1.palette_item(),
                             "Art",
                             "moekki",
                             "raemz",
                             "Raide");
        fadein_text();
    }

    if (heartbeat_index == 18) {
        switch_bg_stage(
            bn::regular_bg_items::op_table_bg_1,
            true
        );
    }

    if (heartbeat_index == 19) {
        create_credits_block(52, 32,
                             bn::sprite_items::fontpalette_opening_1_bold.palette_item(),
                             bn::sprite_items::fontpalette_opening_1.palette_item(),
                             "Additional Art",
                             "climatic",
                             "Doomfest",
                             "yujovi");
        fadein_text();
    }

    if (heartbeat_index == 20) {
        fadeout_text();
    }

    if (heartbeat_index == 21) {
        create_credits_block(52, 32,
                             bn::sprite_items::fontpalette_opening_1_bold.palette_item(),
                             bn::sprite_items::fontpalette_opening_1.palette_item(),
                             "FMV Animation",
                             "Mike Inel");
        fadein_text();
    }

    if (heartbeat_index == 22) {
        bg_stage = 3;
        switch_bg_stage(
            bn::regular_bg_items::op_transition_to_clock,
            false,
            60,
            30
        );
    }

    if (heartbeat_index == 23) {
        create_credits_block(52, 32,
                             bn::sprite_items::fontpalette_opening_1_bold.palette_item(),
                             bn::sprite_items::fontpalette_opening_1.palette_item(),
                             "Directing",
                             "delta",
                             "Raide",
                             "yujovi");
        fadein_text();
    }

    if (heartbeat_index == 24) {
        fadeout_text();
    }

    if (heartbeat_index == 25) {
        create_credits_block(52, 32,
                             bn::sprite_items::fontpalette_opening_1_bold.palette_item(),
                             bn::sprite_items::fontpalette_opening_1.palette_item(),
                             "Engineering",
                             "delta");
        fadein_text();
    }

    if (heartbeat_index == 26) {
        fadeout_text();
    }

    if (heartbeat_index == 27) {
        create_credits_block(52, 32,
                             bn::sprite_items::fontpalette_opening_1_bold.palette_item(),
                             bn::sprite_items::fontpalette_opening_1.palette_item(),
                             "Production",
                             "cpl_crud",
                             "Suriko");
        fadein_text();

        outro = true;
        while (heartbeat_frame_counter < op_heartbeat) {
            update();
        }
        bg_stage = 4;
        switch_bg_stage(
            bn::regular_bg_items::op_clock_bg_10to11,
            false,
            60,
            60
        );

        while (heartbeat_frame_counter < op_heartbeat) {
            update();
        }
        create_credits_block(52, 32,
                             bn::sprite_items::fontpalette_main_bold.palette_item(),
                             bn::sprite_items::fontpalette_main.palette_item(),
                             "GBA port",
                             "neparij");
        fadein_text();
        while (heartbeat_frame_counter < op_heartbeat) {
            update();
        }
        fadeout_text();
    }
}

void ks::GameOpening::switch_bg_stage(const bn::regular_bg_item &transition_bg_item,
                                      const bool persist,
                                      const int in_duration,
                                      const int out_duration) {
    ks::secondary_background = transition_bg_item.create_bg(0, 0);
    if (ks::primary_background.has_value()) {
        ks::primary_background->set_priority(3);
    }

    ks::secondary_background->set_priority(1);
    ks::secondary_background->set_blending_enabled(true);

    bn::blending::set_transparency_alpha(0);
    blending_action = bn::blending_transparency_alpha_to_action(in_duration, 1);
    BN_LOG("  >>> START BLEND");
    while (!blending_action->done()) {
        blending_action->update();
        update();
    }
    BN_LOG("  <<< END BLEND");


    if (cardiogram_peak_bg.has_value()) {
        cardiogram_peak_bg.reset();
    }
    if (cardio_sprite.has_value()) {
        cardio_sprite.reset();
    }
    if (ivdrip_additional_bg.has_value()) {
        ivdrip_additional_bg.reset();
    }
    if (ivdrip_sprite.has_value()) {
        ivdrip_sprite.reset();
    }
    static_text_sprites.clear();
    text_move_actions.clear();
    bn::blending::set_transparency_alpha(1);

    if (persist) {
        replace_or_create_main_bg_item(transition_bg_item, 0, 0);
        primary_background->set_priority(3);
    } else {
        if (bg_stage == 1) {
            create_stage_ivdrip();
        } else if (bg_stage == 2) {
            create_stage_table();
        } else if (bg_stage == 3) {
            create_stage_clock();
        } else if (bg_stage == 4) {
            create_stage_end();
        }
    }
    update(); // Make sure the BG has time to decompress;

    blending_action = bn::blending_transparency_alpha_to_action(out_duration, 0);
    BN_LOG("  >>> START BLEND");
    while (!blending_action->done()) {
        blending_action->update();
        update();
    }
    BN_LOG("  <<< END BLEND");
    bn::blending::set_transparency_alpha(1);
    ks::secondary_background.reset();
    blending_action.reset();
    update();
}

void ks::GameOpening::create_credits_block(const bn::fixed x,
                                           const bn::fixed y,
                                           const bn::sprite_palette_item &header_palette_item,
                                           const bn::sprite_palette_item &caption_palette_item,
                                           const bn::string_view &header,
                                           const bn::string_view &caption_0,
                                           const bn::string_view &caption_1,
                                           const bn::string_view &caption_2,
                                           const bn::string_view &caption_3,
                                           const bn::string_view &caption_4) {
    static_text_sprites.clear();
    text_move_actions.clear();
    int last_text_sprites_index = 0;

    text_generator_small->set_left_alignment();
    text_generator_small->set_bg_priority(2);
    text_generator_small->set_palette_item(header_palette_item);
    text_generator_small->generate(x, y, header, static_text_sprites);

    for (int i = last_text_sprites_index; i < static_text_sprites.size(); i++) {
        auto &spr = static_text_sprites.at(i);
        text_move_actions.push_back(
            bn::sprite_move_to_action(spr, op_heartbeat * 2, spr.x() - 16, spr.y())
        );
    };
    last_text_sprites_index = static_text_sprites.size();

    text_generator_small->set_palette_item(caption_palette_item);
    if (!caption_0.empty()) {
        text_generator_small->generate(x - 16, y + 12 + 10 * 0, caption_0, static_text_sprites);
    }
    for (int i = last_text_sprites_index; i < static_text_sprites.size(); i++) {
        auto &spr = static_text_sprites.at(i);
        text_move_actions.push_back(
            bn::sprite_move_to_action(spr, op_heartbeat * 2, spr.x() + 16, spr.y())
        );
    };
    last_text_sprites_index = static_text_sprites.size();

    if (!caption_1.empty()) {
        text_generator_small->generate(x - 14, y + 12 + 10 * 1, caption_1, static_text_sprites);
    }
    for (int i = last_text_sprites_index; i < static_text_sprites.size(); i++) {
        auto &spr = static_text_sprites.at(i);
        text_move_actions.push_back(
            bn::sprite_move_to_action(spr, op_heartbeat * 2, spr.x() + 14, spr.y())
        );
    };
    last_text_sprites_index = static_text_sprites.size();

    if (!caption_2.empty()) {
        text_generator_small->generate(x - 12, y + 12 + 10 * 2, caption_2, static_text_sprites);
    }
    for (int i = last_text_sprites_index; i < static_text_sprites.size(); i++) {
        auto &spr = static_text_sprites.at(i);
        text_move_actions.push_back(
            bn::sprite_move_to_action(spr, op_heartbeat * 2, spr.x() + 12, spr.y())
        );
    };
    last_text_sprites_index = static_text_sprites.size();

    if (!caption_3.empty()) {
        text_generator_small->generate(x - 10, y + 12 + 10 * 3, caption_3, static_text_sprites);
    }
    for (int i = last_text_sprites_index; i < static_text_sprites.size(); i++) {
        auto &spr = static_text_sprites.at(i);
        text_move_actions.push_back(
            bn::sprite_move_to_action(spr, op_heartbeat * 2, spr.x() + 10, spr.y())
        );
    };
    last_text_sprites_index = static_text_sprites.size();

    if (!caption_4.empty()) {
        text_generator_small->generate(x - 8, y + 12 + 10 * 4, caption_4, static_text_sprites);
    }
    for (int i = last_text_sprites_index; i < static_text_sprites.size(); i++) {
        auto &spr = static_text_sprites.at(i);
        text_move_actions.push_back(
            bn::sprite_move_to_action(spr, op_heartbeat * 2, spr.x() + 8, spr.y())
        );
    };
    last_text_sprites_index = static_text_sprites.size();
}

void ks::GameOpening::fadein_text() {
    for (auto &sprite: static_text_sprites) {
        sprite.set_blending_enabled(true);
    }
    bn::blending::set_transparency_alpha(0);
    blending_action = bn::blending_transparency_alpha_to_action(15, 1);
    BN_LOG("  >>> START BLEND");
    while (!blending_action->done()) {
        blending_action->update();
        update();
    }
    BN_LOG("  <<< END BLEND");
    bn::blending::set_transparency_alpha(1);
    blending_action.reset();
    update();
}

void ks::GameOpening::fadeout_text() {
    for (auto &sprite: static_text_sprites) {
        sprite.set_blending_enabled(true);
    }

    bn::blending::set_transparency_alpha(1);
    blending_action = bn::blending_transparency_alpha_to_action(60, 0);
    BN_LOG("  >>> START BLEND");
    while (!blending_action->done()) {
        blending_action->update();
        update();
    }
    BN_LOG("  <<< END BLEND");

    static_text_sprites.clear();
    text_move_actions.clear();
    bn::blending::set_transparency_alpha(1);
    blending_action.reset();
    update();
}

void ks::GameOpening::replace_or_create_main_bg_item(const bn::regular_bg_item &bg_item,
                                                     const bn::fixed x,
                                                     const bn::fixed y) {
    if (primary_background.has_value()) {
        primary_background->set_item(bg_item);
        primary_background->set_position(x, y);
    } else {
        primary_background = bg_item.create_bg(x, y);
    }
}

void ks::GameOpening::create_stage_cardiogram() {
    replace_or_create_main_bg_item(bn::regular_bg_items::op_cardiogram_bg, 0, 0);
    primary_background->set_priority(3);

    cardiogram_peak_bg = bn::regular_bg_items::op_cardiogram_fg_anim.create_bg(-16, 0);
    cardiogram_peak_bg->set_priority(2);
    cardiogram_peak_bg->set_visible(false);
    cardio_sprite = bn::sprite_items::op_cardiogram_sprite.create_sprite(-168, 24);
    cardio_sprite->set_bg_priority(3);
}

void ks::GameOpening::create_stage_ivdrip() {
    replace_or_create_main_bg_item(bn::regular_bg_items::op_ivdrip_bg, 0, 0);
    primary_background->set_priority(3);

    ivdrip_additional_bg = bn::regular_bg_items::op_ivdrip_fg_anim.create_bg(0, 0);
    ivdrip_additional_bg->set_priority(2);
    ivdrip_additional_bg->set_visible(false);
    ivdrip_sprite = bn::sprite_items::op_ivdrip_sprite.create_sprite(-56, -8);
    ivdrip_sprite->set_bg_priority(2);
}

void ks::GameOpening::create_stage_table() {
    replace_or_create_main_bg_item(bn::regular_bg_items::op_table_bg_0, -8, 0);
    primary_background->set_priority(3);
}

void ks::GameOpening::create_stage_clock() {
    replace_or_create_main_bg_item(bn::regular_bg_items::op_clock_bg_0, 0, 0);
    primary_background->set_priority(3);
}

void ks::GameOpening::create_stage_end() {
    replace_or_create_main_bg_item(bn::regular_bg_items::op_transition_to_end, 0, 0);
    primary_background->set_priority(3);
}
