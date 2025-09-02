#ifndef KS_ACT_OPENING_H
#define KS_ACT_OPENING_H

#include "bn_regular_bg_actions.h"
#include "bn_bg_palette_actions.h"
#include "bn_sprite_actions.h"
#include "easing_actions.h"

#include "bn_optional.h"
#include "bn_vector.h"
#include "bn_bg_palette_ptr.h"

using opening_text_align_t = unsigned char;
#define OP_TEXT_ALIGN_LEFT ((opening_text_align_t)0)
#define OP_TEXT_ALIGN_CENTER ((opening_text_align_t)1)
#define OP_TEXT_ALIGN_RIGHT ((opening_text_align_t)2)

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
        const char *header{};
        const char *caption_0{};
        const char *caption_1 = nullptr;
    };

    struct opening_text_config {
        const opening_text_align_t header_align;
        const int header_x;
        const int header_y;
        const opening_text_align_t caption_align;
        const int caption_x;
        const int caption_y;
    };

    struct moveable_bg {
        const opening_slide &info;
        bn::regular_bg_ptr ptr;
        bn::optional<regular_bg_move_to_easing_action> move_action;
    };

    template<int BgMoveables>
    class ActOpening {
    public:
        explicit ActOpening(const opening_slide slides[BgMoveables],
                            const opening_text_config &text_config,
                            const action_duration fade_in,
                            const action_duration fade_out,
                            const action_duration slides_move_in,
                            const action_duration slides_fade_in,
                            const action_duration slides_colorize_in): _fade_in(fade_in),
                                                                       _fade_out(fade_out),
                                                                       _slides_move_in(slides_move_in),
                                                                       _slides_fade_in(slides_fade_in),
                                                                       _slides_colorize_in(slides_colorize_in),
                                                                       _slides(slides),
                                                                       _text_config(text_config) {
        }

        explicit ActOpening(const opening_slide slides[BgMoveables],
                            const opening_text_config &text_config): _fade_in{60, 240},
                                                                     _fade_out{720, 900},
                                                                     _slides_move_in{60, 360},
                                                                     _slides_fade_in{120, 300},
                                                                     _slides_colorize_in{240, 420},
                                                                     _slides(slides),
                                                                     _text_config(text_config) {
        }

        virtual ~ActOpening() {
            _slide_ptrs.clear();
        }

        [[nodiscard]] int duration() const;

        void init();

        void process();

    protected:
        opening_text _text;

    private:
        int _current_update = 0;
        action_duration _fade_in;
        action_duration _fade_out;
        action_duration _slides_move_in;
        action_duration _slides_fade_in;
        action_duration _slides_colorize_in;
        const opening_slide *_slides;
        const opening_text_config _text_config;
        bn::vector<moveable_bg, BgMoveables> _slide_ptrs;
        bn::optional<bn::regular_bg_ptr> bg_ptr = bn::nullopt;
        bn::optional<bn::bg_palette_ptr> bg_pal_ptr = bn::nullopt;
        bn::optional<bn::bg_palette_ptr> slides_pal_ptr = bn::nullopt;
        bn::optional<bn::bg_palette_fade_to_action> bg_fade_action = bn::nullopt;
        bn::optional<bn::bg_palette_grayscale_to_action> slides_colorize_action = bn::nullopt;
        bn::optional<bn::bg_palette_fade_to_action> slides_fade_action = bn::nullopt;

        bn::vector<bn::sprite_ptr, 8> header_sprites;
        bn::vector<bn::sprite_ptr, 16> caption_sprites;
        bn::vector<bn::sprite_move_by_action, 8 + 16> text_move_actions;
    };
}

#endif //KS_ACT_OPENING_H
