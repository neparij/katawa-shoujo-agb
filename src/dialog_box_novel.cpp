#include <gba_video.h>

#include "bn_blending_actions.h"
#include "bn_core.h"
#include "dialog_box.h"

#include "bn_regular_bg_items_ui_nvl.h"
#include "bn_regular_bg_items_ui_nvl_8bpp.h"
#include "bn_regular_bg_position_hbe_ptr.h"
#include "scenemanager.h"
#include "utils/scenario_reader.h"

namespace ks {
    void dialog_box_novel::update() {
        const bool skip_render = bn::keypad::b_held() || bn::keypad::a_pressed();
        if (camera.has_value()) {
            if (skip_render) {
                // instantly set:
                int target_render_offset = render_offset; // - (12 * (current_line_index + 1)) + (12 * lines_count());
                target_render_offset += 12 * lines_count();
                target_render_offset -= 12 * (current_line_index + (text_single_sprites.size() > 0 ? 1 : 0));
                // const int target_render_offset = render_offset + 12 * (lines_count());
                if (camera->y() < target_render_offset - 144) {
                    camera->set_y(target_render_offset - 144);
                    for (int i = 0; i < text_cache_sprites.size(); i++) {
                        auto sprite = text_cache_sprites.back();
                        text_cache_sprites.pop_back();
                        if (sprite.y() - camera->y() >= -80) {
                            sprite.set_camera(camera);
                            text_cache_sprites.insert(text_cache_sprites.begin(), bn::move(sprite));
                        }
                    }
                }
            } else {
                if (camera->y() < render_offset - 144) {
                    camera->set_y(camera->y() + 2);
                    if (camera->y() >= render_offset - 144) {
                        for (int i = 0; i < text_cache_sprites.size(); i++) {
                            auto sprite = text_cache_sprites.back();
                            text_cache_sprites.pop_back();
                            if (sprite.y() - camera->y() >= -80) {
                                sprite.set_camera(camera);
                                text_cache_sprites.insert(text_cache_sprites.begin(), bn::move(sprite));
                            }
                        }
                    }
                }
            }
        }
        if (skip_render) {
            globals::main_update();
        }
        dialog_box::update(skip_render);
        if (camera.has_value()) {
            for (auto &sprite: text_chunk_sprites) {
                sprite.set_camera(camera);
            }
            for (auto &sprite: text_single_sprites) {
                sprite.set_camera(camera);
            }
        }
    }

    void dialog_box_novel::add_tl_key(const unsigned int tl_key) {
        current_tl_indexes.push_back(tl_key);
    }

    void dialog_box_novel::render_previous_line() {
        for (int i = 0; i < lines_count(); i++) {
            draw_line(i, false);
        }
        for (int i = 0; i < text_chunk_sprites.size(); i++) {
            auto sprite = text_chunk_sprites.back();
            text_chunk_sprites.pop_back();
            if (sprite.y() - camera->y() >= -80) {
                text_cache_sprites.insert(text_cache_sprites.begin(), bn::move(sprite));
            }
        }
        globals::main_update();
    }

    void dialog_box_novel::show(const bool blending) {
        dialog_box::show(blending);

        if (!nvl_box.has_value()) {
            nvl_box = bn::regular_bg_items::ui_nvl.create_bg_optional(0, 0);
            if (!nvl_box.has_value()) {
                nvl_box = bn::regular_bg_items::ui_nvl_8bpp.create_bg(0, 0);
            }
            nvl_box->set_priority(1);
        }

        if (blending && hidden) {
            bn::blending::set_transparency_alpha(0);
            auto alpha_action = bn::blending_transparency_alpha_to_action(10, globals::transparency_alpha());
            while (!alpha_action.done()) {
                alpha_action.update();
                set_blending(true, false);
                globals::main_update();
            }
            alpha_action.reset();
            bn::blending::set_transparency_alpha(globals::transparency_alpha());
        }

        bn::blending::set_transparency_alpha(globals::transparency_alpha());
        set_blending(true, false);
        hidden = false;


        // Setup camera and object-cutting windows (to prevent diaplaying text out of the novelbox)
        if (!camera.has_value()) {
            camera = bn::camera_ptr::create(0, 0);
        }
        left_window.set_boundaries(-80, -120, -80 + 4, 120);
        right_window.set_boundaries(80 - 4, -120, 80, 120);
        left_window.set_show_sprites(false);
        right_window.set_show_sprites(false);

        if (current_tl_indexes.size() > 1) {
            render_offset += 6;
        }

        if (current_tl_indexes.size() > 1 && text_chunk_sprites.empty() && text_single_sprites.empty() &&
            text_cache_sprites.empty()) {
            BN_LOG("Restore previous novel lines.");
            // The novel was shown from pause or hidden state, so we need to restore previous lines
            text_chunk_sprites.clear();
            text_single_sprites.clear();

            // Create or update lines count index
            if (tl_index_lines_count.size() < current_tl_indexes.size() - 1) {
                tl_index_lines_count.clear();
                for (int i = tl_index_lines_count.size(); i < current_tl_indexes.size() - 1; i++) {
                    ks::textdb::get_tl<1024>(current_tl_indexes.at(i), message);
                    proceed_message();
                    tl_index_lines_count.push_back(lines_count());
                }
            }

            // Backward search until novel window will be filled with previous messages
            int aggregated_offset = 0;
            int start_index = current_tl_indexes.size() - 2;
            for (int i = current_tl_indexes.size() - 2; i >= 0; i--) {
                aggregated_offset += tl_index_lines_count.at(i) * 12 + 6;
                BN_LOG("Aggregated offset: ", aggregated_offset);
                start_index = i;
                if (aggregated_offset >= 144) {
                    break;
                }
            }

            // Render previous lines and setup camera
            render_offset = 0;
            for (int i = start_index; i < current_tl_indexes.size() - 1; i++) {
                ks::textdb::get_tl<1024>(current_tl_indexes.at(i), message);
                proceed_message();
                for (int line = 0; line < tl_index_lines_count.at(i); line++) {
                    draw_line(line, false);
                }
                render_offset += 6;
            }
            if (camera->y() < render_offset - 144 + 12) {
                camera->set_y(render_offset - 144 + 12);
            }
        }

        ks::textdb::get_tl<1024>(current_tl_indexes.back(), message);
        proceed_message();
        while (text_chunk_sprites.size() > 0) {
            auto sprite = text_chunk_sprites.back();
            if (sprite.y() - camera->y() >= -80) {
                sprite.set_camera(camera);
                text_cache_sprites.push_back(bn::move(sprite));
            }
            text_chunk_sprites.pop_back();
        }

        text_chunk_sprites.clear();
    }

    void dialog_box_novel::hide(const bool blending) {
        if (!hidden) {
            // Reset windows only once on the real hiding event
            left_window.restore_boundaries();
            right_window.restore_boundaries();
            left_window.set_show_sprites(true);
            right_window.set_show_sprites(true);
        }
        nvl_box.reset();
        text_chunk_sprites.clear();
        text_single_sprites.clear();
        text_cache_sprites.clear();
        camera.reset();
        render_offset = 0;
        hidden = true;
    }

    void dialog_box_novel::set_blending(const bool boxes_blending_enabled, const bool text_blending_enabled) {
        if (nvl_box.has_value()) {
            nvl_box->set_blending_enabled(boxes_blending_enabled);
        }
        for (auto &sprite: text_chunk_sprites) {
            sprite.set_blending_enabled(text_blending_enabled);
        }
        for (auto &sprite: text_single_sprites) {
            sprite.set_blending_enabled(text_blending_enabled);
        }
        for (auto &sprite: text_cache_sprites) {
            sprite.set_blending_enabled(text_blending_enabled);
        }
    }

    void dialog_box_novel::clear_messages() {
        current_tl_indexes.clear();
        tl_index_lines_count.clear();
        text_chunk_sprites.clear();
        text_single_sprites.clear();
        text_cache_sprites.clear();
        render_offset = 0;
        camera.reset();
    }
}
