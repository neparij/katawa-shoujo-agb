#ifndef DIALOG_BOX_H
#define DIALOG_BOX_H
#include "text_parser.h"

#include "bn_assert.h"
#include "bn_log.h"
#include "bn_string.h"
#include "bn_sprite_ptr.h"
#include "character.h"
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
        dialog_box(bn::istring &message_storage, bn::sprite_text_generator &default_text_generator, bn::sprite_text_generator &bold_text_generator)
            : _message_storage(message_storage),
              _default_text_generator(default_text_generator),
              _bold_text_generator(bold_text_generator),
              _text_parser(message_storage, default_text_generator) {
        }

        void proceed_message() {
            _text_parser.generate_lines();
            _text_parser.generate_commands();
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

            for (const character_definition *actor: actors) {
                if (*actor != definitions::no_char) {
                    BN_LOG(" ACTOR: ", actor->name());
                } else {
                    BN_LOG(" ACTOR: (none)");
                }
            }
        }

        void set_actor(const character_definition &actor1, const character_definition &actor2) {
            actors.clear();
            actors.push_back(&actor1);
            actors.push_back(&actor2);
        }

        void set_actor(const character_definition &actor) {
            set_actor(actor, definitions::no_char);
        }

        void show(bool blending);

        void hide(bool blending);

        void update();

        [[nodiscard]] bool is_finished() const {
            return finished;
        }

    protected:
        void draw_line(int line_index, bool one_sprite_per_character);

    private:
        bn::istring &_message_storage;
        bn::sprite_text_generator &_default_text_generator;
        bn::sprite_text_generator &_bold_text_generator;
        text::parser<32> _text_parser;

        int next_render_cooldown = 0;
        bn::vector<bn::sprite_ptr, 8 * 3> text_chunk_sprites;
        bn::vector<bn::sprite_ptr, 128> text_single_sprites;

        bn::vector<const character_definition *, 2> actors;

        unsigned char current_char_index = 0;
        unsigned char current_line_index = 0;
        unsigned char current_page_index = 0;
        bool finished = false;
        bool waiting_for_input = false;
    };
}

#endif //DIALOG_BOX_H
