#ifndef KS_ACT_OPENING_H
#define KS_ACT_OPENING_H

#include "bn_regular_bg_actions.h"
#include "bn_bg_palette_actions.h"
#include "bn_sprite_actions.h"
#include "easing_actions.h"

#include "bn_optional.h"
#include "bn_vector.h"
#include "bn_blending.h"
#include "bn_bg_palette_ptr.h"

#include "bn_regular_bg_items_act_background.h"
#include "bn_bg_palette_items_pal_act_background.h"
#include "bn_bg_palette_items_pal_act_slide.h"


namespace ks {
    struct action_duration {
        const int start;
        const int end;
    };

    struct opening_slide {
        const bn::regular_bg_item &item;
        const int x_offset;
        const int y_offset;
    };

    struct opening_text {
        const char* header;
        const char* caption_0;
        const char* caption_1 = nullptr;
    };

    template<int BgMoveables>
    class ActOpening {
    public:
        explicit ActOpening(const opening_slide slides[BgMoveables],
                            const action_duration fade_in,
                            const action_duration fade_out,
                            const action_duration slides_move_in,
                            const action_duration slides_fade_in,
                            const action_duration slides_colorize_in): _fade_in(fade_in),
                                                                       _fade_out(fade_out),
                                                                       _slides_move_in(slides_move_in),
                                                                       _slides_fade_in(slides_fade_in),
                                                                       _slides_colorize_in(slides_colorize_in),
                                                                       _slides(slides) {
        }

        explicit ActOpening(const opening_slide slides[BgMoveables]): _fade_in{60, 240},
                                                                       _fade_out{720, 900},
                                                                       _slides_move_in{60, 360},
                                                                       _slides_fade_in{120, 300},
                                                                       _slides_colorize_in{240, 420},
                                                                       _slides(slides) {
        }

        virtual ~ActOpening() {
            _slide_ptrs.clear();
        }

        [[nodiscard]] int duration() const {
            return _fade_out.end;
        }

        [[nodiscard]] opening_slide get_slide(const int n) const {
            return _slides[n];
        }

        void init() {
            _slide_ptrs.clear();
            header_sprites.clear();
            caption_sprites.clear();
            text_move_actions.clear();

            bg_pal_ptr = bn::bg_palette_items::pal_act_background.create_new_palette();
            slides_pal_ptr = bn::bg_palette_items::pal_act_slide.create_new_palette();

            bg_ptr = bn::regular_bg_items::act_background.create_bg(0, 0);

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


            text_generator_bold->set_right_alignment();
            text_generator_bold->generate_top_left(164, 104, "Act 1:", header_sprites);
            // text_generator_bold->generate_top_left(164, 104, "Акт 1:", header_sprites);
            for (auto& sprite : header_sprites) {
                sprite.set_visible(false);
            }

            text_generator->set_center_alignment();
            text_generator->generate_top_left(164, 120, "Life Expectancy", caption_sprites);
            // text_generator_small->set_center_alignment();
            // text_generator_small->generate_top_left(164, 120, "Продолжительность", caption_sprites);
            // text_generator_small->generate_top_left(164, 128, "жизни", caption_sprites);
            for (auto& sprite : caption_sprites) {
                sprite.set_visible(false);
            }

        }

        void process() {
            while (_current_update < duration()) {
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
                    for (auto& sprite : header_sprites) {
                        sprite.set_visible(true);
                        sprite.set_blending_enabled(true);
                        text_move_actions.push_back(bn::sprite_move_by_action(sprite, -bn::fixed(0.125), 0));
                    }
                    for (auto& sprite : caption_sprites) {
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
                    bn::blending::set_transparency_alpha(bn::fixed(_fade_out.end - _current_update) / (_fade_out.end - _fade_out.start));
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

            _slide_ptrs.clear();
            header_sprites.clear();
            caption_sprites.clear();
            text_move_actions.clear();
            bg_ptr.reset();
            bg_pal_ptr.reset();
            slides_pal_ptr.reset();

            text_generator_bold->set_palette_item(globals::text_palettes::original);
            text_generator->set_palette_item(globals::text_palettes::original);
            text_generator_small->set_palette_item(globals::text_palettes::original);

            bn::blending::restore();
        }

    private:
        struct moveable_bg {
            const opening_slide &info;
            bn::regular_bg_ptr ptr;
            bn::optional<regular_bg_move_to_easing_action> move_action;
        };

        int _current_update = 0;
        action_duration _fade_in;
        action_duration _fade_out;
        action_duration _slides_move_in;
        action_duration _slides_fade_in;
        action_duration _slides_colorize_in;
        const opening_slide *_slides;
        bn::vector<moveable_bg, BgMoveables> _slide_ptrs;
        bn::optional<bn::regular_bg_ptr> bg_ptr = bn::nullopt;
        bn::optional<bn::bg_palette_ptr> bg_pal_ptr = bn::nullopt;
        bn::optional<bn::bg_palette_ptr> slides_pal_ptr = bn::nullopt;
        bn::optional<bn::bg_palette_fade_to_action> bg_fade_action = bn::nullopt;
        bn::optional<bn::bg_palette_grayscale_to_action> slides_colorize_action = bn::nullopt;
        bn::optional<bn::bg_palette_fade_to_action> slides_fade_action = bn::nullopt;

        bn::vector<bn::sprite_ptr, 8> header_sprites;
        bn::vector<bn::sprite_ptr, 16> caption_sprites;
        bn::vector<bn::sprite_move_by_action, 8+16> text_move_actions;
    };
}

#endif //KS_ACT_OPENING_H
