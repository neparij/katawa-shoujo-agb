#include "act_opening.h"
#include "../globals.h"
#include "../scenemanager.h"
#include "../sound_manager.h"

#include "bn_regular_bg_items_act_background.h"
#include "bn_bg_palette_items_pal_act_slide.h"


namespace ks {
    template<int BgMoveables>
    void ActOpening<BgMoveables>::init() {
        _slide_ptrs.clear();
        header_sprites.clear();
        caption_sprites.clear();
        text_move_actions.clear();


        bg_ptr = bn::regular_bg_items::act_background.create_bg(0, 0);
        bg_pal_ptr = bg_ptr->palette();

        slides_pal_ptr = bn::bg_palette_items::pal_act_slide.create_new_palette();
        for (int i = 0; i < BgMoveables; i++) {
            auto bg = _slides[i].item.create_bg(_slides[i].x_offset, _slides[i].y_offset);

            _slide_ptrs.push_back(moveable_bg{
                _slides[i],
                bn::move(bg),
                bn::nullopt
            });
        }

        bg_pal_ptr->set_fade(globals::colors::WHITE, bn::fixed(1));
        slides_pal_ptr->set_fade(globals::colors::WHITE, bn::fixed(1));
        slides_pal_ptr->set_grayscale_intensity(bn::fixed(1));

        text_generator_bold->set_palette_item(globals::text_palettes::beige);
        text_generator->set_palette_item(globals::text_palettes::beige);
        text_generator_small->set_palette_item(globals::text_palettes::beige);

        text_generator_bold->set_left_alignment();
        text_generator->set_left_alignment();
        text_generator_small->set_left_alignment();

        int caption_width = 0;
        if (_text.caption_1 == nullptr) {
            caption_width = text_generator->width(_text.caption_0);
            const int offset_x = _text_config.align == OP_TEXT_ALIGN_CENTER ? caption_width / 2 :
                                 _text_config.align == OP_TEXT_ALIGN_RIGHT ? caption_width : 0;

            text_generator->generate_top_left(_text_config.value_x - offset_x - 8, _text_config.top_y + 16, _text.caption_0,
                                              caption_sprites);
        } else {
            caption_width = text_generator_small->width(_text.caption_0);
            const int offset_x = _text_config.align == OP_TEXT_ALIGN_CENTER ? caption_width / 2 :
                                 _text_config.align == OP_TEXT_ALIGN_RIGHT ? caption_width : 0;

            text_generator_small->generate_top_left(_text_config.value_x - offset_x - 8, _text_config.top_y + 16, _text.caption_0,
                                                    caption_sprites);
            text_generator_small->generate_top_left(_text_config.value_x - offset_x - 8, _text_config.top_y + 24, _text.caption_1,
                                                    caption_sprites);

            // Add header 8px offset for two-lines text for better visual balance
            caption_width -= 8;
        }

        for (auto &sprite: caption_sprites) {
            sprite.set_visible(false);
        }


        const int offset_x = _text_config.align == OP_TEXT_ALIGN_CENTER ? caption_width / 2 :
                                 _text_config.align == OP_TEXT_ALIGN_RIGHT ? caption_width : 0;
        text_generator_bold->generate_top_left(_text_config.value_x - offset_x, _text_config.top_y, _text.header,
                                               header_sprites);
        for (auto &sprite: header_sprites) {
            sprite.set_visible(false);
        }
    }

    template<int BgMoveables>
    void ActOpening<BgMoveables>::run() {
        _text = get_text();
        init();

        if (_ulc_audiofile != nullptr) {
            ks::sound_manager::stop<SOUND_CHANNEL_VIDEO>();
            ks::sound_manager::play<SOUND_CHANNEL_VIDEO>(_ulc_audiofile);
        }

        while (_current_update < _fade_out.end) {
            // CREATE ACTIONS:
            if (_current_update == _fade_in.start) {
                bg_fade_action = bn::bg_palette_fade_to_action(
                    bg_pal_ptr.value(),
                    _fade_in.end - _fade_in.start,
                    bn::fixed(0));
            }

            if (_current_update == _fade_out.start) {
                bg_fade_action = bn::bg_palette_fade_to_action(
                    bg_pal_ptr.value(),
                    _fade_out.end - _fade_out.start,
                    bn::fixed(1));
                slides_fade_action = bn::bg_palette_fade_to_action(
                    slides_pal_ptr.value(),
                    _fade_out.end - _fade_out.start,
                    bn::fixed(1));
            }

            if (_current_update == _slides_move_in.start) {
                for (auto &slide: _slide_ptrs) {
                    slide.move_action = regular_bg_move_to_easing_action(
                        slide.ptr,
                        EASING_CUBIC_OUT,
                        _slides_move_in.end - _slides_move_in.start,
                        0, 0);
                }
            }

            if (_current_update == _slides_fade_in.start) {
                slides_fade_action = bn::bg_palette_fade_to_action(
                    slides_pal_ptr.value(),
                    _slides_fade_in.end - _slides_fade_in.start,
                    bn::fixed(0));
            }

            if (_current_update == _slides_colorize_in.start) {
                slides_colorize_action = bn::bg_palette_grayscale_to_action(
                    slides_pal_ptr.value(),
                    _slides_colorize_in.end - _slides_colorize_in.start,
                    bn::fixed(0));
            }

            // TEXT ACTIONS:
            if (_current_update == 420) {
                for (auto &sprite: header_sprites) {
                    sprite.set_visible(true);
                    sprite.set_blending_enabled(true);
                    text_move_actions.push_back(bn::sprite_move_by_action(sprite, -bn::fixed(0.125), 0));
                }
                for (auto &sprite: caption_sprites) {
                    sprite.set_visible(true);
                    sprite.set_blending_enabled(true);
                    text_move_actions.push_back(bn::sprite_move_by_action(sprite, bn::fixed(0.125), 0));
                }
            }
            if (_current_update >= 420 && _current_update < 480) {
                bn::blending::set_transparency_alpha(1 - bn::fixed(480 - _current_update) / 60);
            }
            if (_current_update == 480) {
                text_move_actions.clear();
                bn::blending::restore();
            }
            if (_current_update >= _fade_out.start && _current_update < _fade_out.end) {
                bn::blending::set_transparency_alpha(
                    bn::fixed(_fade_out.end - _current_update) / (_fade_out.end - _fade_out.start));
            }

            // DO UPDATES:
            if (bg_fade_action.has_value()) {
                if (!bg_fade_action->done()) {
                    bg_fade_action->update();
                }
            }

            if (slides_fade_action.has_value()) {
                if (!slides_fade_action->done()) {
                    slides_fade_action->update();
                }
            }

            if (slides_colorize_action.has_value()) {
                if (!slides_colorize_action->done()) {
                    slides_colorize_action->update();
                }
            }

            for (auto &slide: _slide_ptrs) {
                if (slide.move_action.has_value()) {
                    if (!slide.move_action->done()) {
                        slide.move_action->update();
                    }
                }
            }
            for (auto &action: text_move_actions) {
                action.update();
            }

            _current_update++;
            globals::main_update();
        }

        text_generator_bold->set_palette_item(globals::text_palettes::original);
        text_generator->set_palette_item(globals::text_palettes::original);
        text_generator_small->set_palette_item(globals::text_palettes::original);

        bn::blending::restore();
    }

    template class ActOpening<1>;
    template class ActOpening<2>;
}
