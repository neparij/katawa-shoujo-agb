#include <gba_video.h>

#include "bn_blending_actions.h"
#include "bn_core.h"
#include "dialog_box.h"

#include "bn_regular_bg_items_ui_nvl.h"
#include "bn_regular_bg_position_hbe_ptr.h"
#include "scenemanager.h"

namespace ks {

    // desctuctor:
    dialog_box_novel::~dialog_box_novel() {
        // bn::hw::irq::disable(bn::hw::irq::id::HBLANK);
        // bn::hw::irq::set_isr(bn::hw::irq::id::HBLANK, nullptr);
        // REG_DISPCNT |= OBJ_ON;
    }

    // BN_CODE_IWRAM void dialog_box_novel::HBE() {
    //     BN_LOG(REG_VCOUNT);
    //     if (REG_VCOUNT >= 5 && REG_VCOUNT <= 155) {
    //         REG_DISPCNT |= OBJ_ON;
    //     } else {
    //         REG_DISPCNT &= ~OBJ_ON;
    //     }
    // }

    void dialog_box_novel::update() {
        const bool skip_render = bn::keypad::b_held() || bn::keypad::a_pressed();
        if (camera.has_value()) {
            if (skip_render) {
                // instantly set:
                int target_render_offset = render_offset;// - (12 * (current_line_index + 1)) + (12 * lines_count());
                target_render_offset += 12 * lines_count();
                target_render_offset -= 12 * (current_line_index + (text_single_sprites.size() > 0 ? 1 : 0));
                // const int target_render_offset = render_offset + 12 * (lines_count());
                if (camera->y() < target_render_offset - 144) {
                    camera->set_y(target_render_offset - 144);
                }
            } else {
                if (camera->y() < render_offset - 144) {
                    camera->set_y(camera->y() + 2);
                }
            }
            for (int i = 0; i < text_cache_sprites.size(); i++) {
                auto sprite = text_cache_sprites.back();
                text_cache_sprites.pop_back();
                if (sprite.y() - camera->y() >= -80) {
                    sprite.set_camera(camera);
                    // text_cache_sprites.push_back(bn::move(sprite));
                    text_cache_sprites.insert(text_cache_sprites.begin(), bn::move(sprite));
                } else {
                    delete &sprite;
                }
            }
        }
        if (skip_render) {
            globals::main_update();
        }
        dialog_box::update(skip_render);
        if (camera.has_value()) {
            for (auto& sprite : text_chunk_sprites) {
                sprite.set_camera(camera);
            }
            for (auto& sprite : text_single_sprites) {
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
        // for (auto& sprite : text_chunk_sprites) {
        //     sprite.set_position(sprite.x(), sprite.y() - 12 * lines_count());
        // }
        for (int i = 0; i < text_chunk_sprites.size(); i++) {
            auto sprite = text_chunk_sprites.back();
            text_chunk_sprites.pop_back();
            if (sprite.y() - camera->y() >= -80) {
                text_cache_sprites.insert(text_cache_sprites.begin(), bn::move(sprite));
            } else {
                delete &sprite;
            }
            // text_cache_sprites.push_back(bn::move(sprite));
        }
        globals::main_update();
    }

    void dialog_box_novel::show(const bool blending) {
        // if (hidden) {
            // bn::hw::irq::set_isr(bn::hw::irq::id::HBLANK, HBE);
            // bn::hw::irq::enable(bn::hw::irq::id::HBLANK);
        // }

        dialog_box::show(blending);
        if (!camera.has_value()) {
            camera = bn::camera_ptr::create(0, 0);
        }

        if (current_tl_indexes.size() > 1) {
            render_offset += 6;
        }

        // ks::textdb::get_tl<1024>(current_tl_indexes.back(), static_cast<bn::string<1024>&>(_message_storage));
        // ks::textdb::get_tl<1024>(current_tl_indexes.back(), reinterpret_cast<bn::string<1024>&>(_message_storage));
        // ks::textdb::get_tl<1024>(current_tl_indexes.back(), message_nvl);
        // message = "Some test ""\x02""message""\x03""...";
        dialog_novel->proceed_message();
        while (text_chunk_sprites.size() > 0) {
            auto sprite = text_chunk_sprites.back();
            text_chunk_sprites.pop_back();
            text_cache_sprites.push_back(bn::move(sprite));
        }

        text_chunk_sprites.clear();

        // for (int i = 0; i < current_tl_indexes.size(); i++) {
        //     BN_LOG("Prerender previous lines, ", i, " / ", current_tl_indexes.size());
        //     BN_LOG(" - TL key: ", current_tl_indexes.at(i));
        //     ks::textdb::get_tl<1024>(current_tl_indexes.at(i), message);
        //     dialog_novel->proceed_message();
        //     if (current_tl_indexes.at(i) != current_tl_indexes.back()) {
        //         render_previous_line();
        //     }
        // }


        if (!nvl_box.has_value()) {
            nvl_box = bn::regular_bg_items::ui_nvl.create_bg(0, 0);
            nvl_box->set_priority(1);
        }

        if (blending && hidden) {
            bn::blending::set_transparency_alpha(0);
            auto alpha_action = bn::blending_transparency_alpha_to_action(10, globals::transparency_alpha());
            while (!alpha_action.done()) {
                alpha_action.update();
                set_blending(true, true);
                globals::main_update();
            }
            alpha_action.reset();
            bn::blending::set_transparency_alpha(globals::transparency_alpha());
        }

        bn::blending::set_transparency_alpha(globals::transparency_alpha());
        set_blending(true, false);
        hidden = false;
    }

    void dialog_box_novel::hide(const bool blending) {
        // if (!hidden) {
        //     // No blending on hide for NVL mode
        //     // Restore normal display
        //     bn::hw::irq::disable(bn::hw::irq::id::HBLANK);
        //     bn::hw::irq::set_isr(bn::hw::irq::id::HBLANK, nullptr);
        //     REG_DISPCNT |= OBJ_ON;
        // }

        nvl_box.reset();
        text_chunk_sprites.clear();
        text_single_sprites.clear();
        text_cache_sprites.clear();
        camera.reset();
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
        text_chunk_sprites.clear();
        text_single_sprites.clear();
        text_cache_sprites.clear();
        render_offset = 0;
        camera.reset();
    }
}
