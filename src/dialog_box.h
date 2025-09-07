#ifndef DIALOG_BOX_H
#define DIALOG_BOX_H
#include "text_render.h"

#include "bn_assert.h"
#include "bn_log.h"
#include "bn_string.h"
#include "character.h"

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
        dialog_box(bn::istring &message_storage, bn::sprite_text_generator &default_text_generator)
            : _message_storage(message_storage),
              _default_text_generator(default_text_generator),
              _text_renderer(message_storage, default_text_generator) {
        }

        void proceed_message() {
            _text_renderer.generate_lines();
            _text_renderer.generate_commands();
        }

        [[nodiscard]] int pages_count() {
            BN_ASSERT(!_text_renderer.lines().empty(), "Text-referenced lines should not be empty");
            const int lines_count = _text_renderer.lines().size();
            return (lines_count + 2) / 3;
        }

        [[nodiscard]] int lines_count() {
            return _text_renderer.lines().size();
        }

        [[nodiscard]] int commands_count() {
            return _text_renderer.commands().size();
        }

        void log() {
            BN_ASSERT(!_text_renderer.lines().empty(), "Text-referenced lines should not be empty");
            BN_ASSERT(!_text_renderer.commands().empty(), "Commands should not be empty");

            BN_LOG(" DBTR :: Lines count: ", lines_count());
            BN_LOG(" DBTR :: Pages count: ", pages_count());
            BN_LOG(" DBTR :: Commands count: ", commands_count());

            for (auto& line : _text_renderer.lines()) {
                if (!line.empty()) {
                    BN_LOG(" >>> ", line);
                } else {
                    BN_LOG(" >>> (empty)");
                }
            }

            for (auto& command : _text_renderer.commands()) {
                BN_LOG(" CMD: ", command.command);
            }

            for (const character_definition* actor : actors) {
                if (*actor != definitions::no_char) {
                    BN_LOG(" ACTOR: ", actor->name());
                } else {
                    BN_LOG(" ACTOR: (none)");
                }
            }
        }

        void set_actor(const character_definition& actor1, const character_definition& actor2) {
            actors.clear();
            actors.push_back(&actor1);
            actors.push_back(&actor2);
        }

        void set_actor(const character_definition& actor) {
            set_actor(actor, definitions::no_char);
        }

        void show(bool blending);

        void hide(bool blending);

        void update();

        [[nodiscard]] bool is_finished();

    protected:
        void draw_line(int line_index, bool one_sprite_per_char);

    private:
        bn::istring &_message_storage;
        bn::sprite_text_generator &_default_text_generator;
        text::renderer<32> _text_renderer;

        bn::vector<const character_definition*, 2> actors;
        unsigned char current_line_index = 0;
        unsigned char current_page_index = 0;
    };
}

#endif //DIALOG_BOX_H
