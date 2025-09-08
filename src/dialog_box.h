#ifndef DIALOG_BOX_H
#define DIALOG_BOX_H
#include "text_parser.h"

#include "bn_assert.h"
#include "bn_camera_actions.h"
#include "bn_log.h"
#include "bn_string.h"
#include "bn_sprite_ptr.h"
#include "bn_vector.h"
#include "character.h"
#include "constants.h"
#include "utils/utf8.h"

namespace bn {
    class sprite_text_generator;
}

namespace ks {
    // enum class DialogState {
    //     Idle,
    //     Writing,
    //     WaitingForInput,
    //     QuestionActive,
    // };

    class dialog_box {
    public:
        dialog_box(bn::istring &message_storage,
                   bn::sprite_text_generator &default_text_generator,
                   bn::sprite_text_generator &bold_text_generator,
                   const bn::fixed_point text_start_position,
                   const int max_width)
            : _message_storage(message_storage),
              _default_text_generator(default_text_generator),
              _bold_text_generator(bold_text_generator),
              _text_start_position(text_start_position),
              _max_width(max_width),
              _text_parser(message_storage, default_text_generator),
              _actor(&definitions::no_char) {
        }

        virtual ~dialog_box() = default;

        void proceed_message() {
            BN_LOG("GENERATE LINES");
            _text_parser.generate_lines(_max_width);
            BN_LOG("GENERATE COMMANDS");
            _text_parser.generate_commands();
            BN_LOG("---");
        }

        [[nodiscard]] int pages_count() {
            BN_ASSERT(!_text_parser.lines().empty(), "Text-referenced lines should not be empty");
            const int lines_count = _text_parser.lines().size();
            return (lines_count + 2) / 3;
        }

        [[nodiscard]] int lines_count() {
            return _text_parser.lines().size();
        }

        [[nodiscard]] int commands_count() {
            return _text_parser.commands().size();
        }

        void log() {
            BN_ASSERT(!_text_parser.lines().empty(), "Text-referenced lines should not be empty");
            BN_ASSERT(!_text_parser.commands().empty(), "Commands should not be empty");


            if (*_actor != definitions::no_char) {
                BN_LOG(" ACTOR: ", _actor->name());
            } else {
                BN_LOG(" ACTOR: (none)");
            }
        }

        void set_actor(const character_definition &actor_definition) {
            _actor = &actor_definition;
        }

        [[nodiscard]] bool is_finished() const {
            return finished;
        }

        [[nodiscard]] bool is_hidden() const {
            return hidden;
        }

        virtual void update();

        virtual void show(bool blending) {
            next_render_cooldown = 0;
            current_char_index = 0;
            current_line_index = 0;
            current_page_index = 0;
            finished = false;
            waiting_for_input = false;
        }

        virtual void hide(bool blending) {
        }

    protected:
        void draw_line(int line_index, bool one_sprite_per_character);

        const character_definition *_actor;
        bn::sprite_text_generator &_default_text_generator;
        bn::sprite_text_generator &_bold_text_generator;
        bn::vector<bn::sprite_ptr, 8 * 3> text_chunk_sprites;
        bn::vector<bn::sprite_ptr, 128> text_single_sprites;
        bool finished = false;
        bool hidden = true;

    private:
        bn::istring &_message_storage;
        const bn::fixed_point _text_start_position;
        const int _max_width;

        text::parser<32> _text_parser;

        int next_render_cooldown = 0;
        unsigned char current_char_index = 0;
        unsigned char current_line_index = 0;
        unsigned char current_page_index = 0;
        bool waiting_for_input = false;
    };

    class dialog_box_default : public dialog_box {
    public:
        dialog_box_default(bn::istring &message_storage,
                           bn::sprite_text_generator &default_text_generator,
                           bn::sprite_text_generator &bold_text_generator)
            : dialog_box(message_storage,
                         default_text_generator,
                         bold_text_generator,
                         bn::fixed_point(-device::screen_width_half + 10, device::screen_height_half - 36),
                         device::screen_width - 20) {
        }

        void update() override;

        void show(bool blending) override;

        void hide(bool blending) override;

        void show_answers(bn::ivector<bn::string<128>>& answers);

        void set_blending(bool boxes_blending_enabled, bool text_blending_enabled);

        void setup_answer_camera();

        void set_answer_box_blending();

        void set_answers_palette();

        void set_answer_sprites_visibility(unsigned short answer_index);

        void reset_answers();

        [[nodiscard]] int get_answer_index() const {
            return answer_selected;
        }

    private:
        bn::vector<bn::sprite_ptr, 4> text_boxes;
        bn::vector<bn::sprite_ptr, 8> actor_boxes;
        bn::vector<bn::sprite_ptr, 5 * 3> answer_boxes;
        bn::vector<bn::sprite_ptr, 8> title_sprites;

        bool is_question = false;
        bn::vector<unsigned short, 5> answers_widths;
        const unsigned short answers_width_max = 184;
        bn::vector<bn::sprite_ptr, 128> answer_sprites;
        bn::vector<unsigned short, 128> answer_sprite_indexes;
        bn::optional<bn::camera_ptr> answers_camera;
        bn::optional<bn::camera_move_loop_action> answers_camera_action;
        unsigned short answers_camera_loop_duration;
        unsigned char answer_selected;
        unsigned short answer_loop_cycle_counter;
        unsigned short answer_pause_cycle_counter;
    };

    class dialog_box_doublespeak_window : public dialog_box {
    public:
        dialog_box_doublespeak_window(bn::istring &message_storage,
                                      bn::sprite_text_generator &default_text_generator,
                                      bn::sprite_text_generator &bold_text_generator,
                                      const bn::fixed_point text_start_position)
            : dialog_box(message_storage,
                         default_text_generator,
                         bold_text_generator,
                         text_start_position,
                         device::screen_width_half - 20) {
        }
    };

    class dialog_box_doublespeak {
    public:
        dialog_box_doublespeak(bn::istring &message_storage_a,
                               bn::istring &message_storage_b,
                               bn::sprite_text_generator &default_text_generator,
                               bn::sprite_text_generator &bold_text_generator)
            : _left_window(dialog_box_doublespeak_window(message_storage_a,
                                                         default_text_generator,
                                                         bold_text_generator,
                                                         bn::fixed_point(
                                                             -device::screen_width_half + 10,
                                                             device::screen_height_half - 36))),
              _right_window(dialog_box_doublespeak_window(message_storage_b,
                                                          default_text_generator,
                                                          bold_text_generator,
                                                          bn::fixed_point(
                                                              10,
                                                              device::screen_height_half - 36))) {
        }

    private:
        dialog_box_doublespeak_window _left_window;
        dialog_box_doublespeak_window _right_window;
    };
}

#endif //DIALOG_BOX_H
