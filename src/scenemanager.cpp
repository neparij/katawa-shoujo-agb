#include "scenemanager.h"
#include "bn_music.h"
#include "sequence/backgrounditem.h"
#include "sequence/istartitem.h"
#include "sequence/musicitem.h"
#include "sequence/runlabelitem.h"
#include "sequence/runlabelfinishitem.h"

#include "variable_16x16_sprite_font.h"
#include "bn_music_items.h"


namespace ks {

SceneManager::SceneManager(bn::optional<bn::regular_bg_ptr>& bg_ptr)
    : _bg(bg_ptr)
{
    _text_generator = new bn::sprite_text_generator(variable_16x16_sprite_font);
    _dialog = new ks::DialogBox(_text_generator, variable_16x16_sprite_font);

    hold_iterator();
}

// SceneManager::~SceneManager() {
//     for (auto iterator : _iterators) {
//         for (auto* sequence : iterator) {
//             delete sequence;
//         }
//     }
//     _iterators.clear();
//     _label_statuses.clear();

//     delete _dialog;
//     delete _text_generator;
// }

SceneManager::~SceneManager() {
    // Delete all sequences in all iterators:
    for (auto iterator : _iterators) {
        for (auto* sequence : iterator) {
            delete sequence;
        }
    }
    _iterators.clear();

    // Clear label statuses
    _label_statuses.clear();

    // Delete current sequence if not already part of iterators
    if (_current_sequence) {
        delete _current_sequence;
        _current_sequence = nullptr;
    }

    // Delete dialog and text generator
    delete _dialog;
    _dialog = nullptr;

    delete _text_generator;
    _text_generator = nullptr;
}


void SceneManager::hold_iterator() {
    auto iterator = bn::vector<ks::SequenceItem*, ks::system::interator_size>();
    _iterators.push_back(iterator);
};

// void SceneManager::release_iterator() {
//     _iterators.pop_back();
// };

void SceneManager::release_iterator() {
    if (!_iterators.empty()) {
        auto& current_iterator = _iterators.back();

        // Delete all sequences in the iterator:
        for (auto* sequence : current_iterator) {
            delete sequence;  // Free allocated memory
        }

        current_iterator.clear();  // Clear the iterator contents
        _iterators.pop_back();     // Remove the iterator itself
    }
}

// void SceneManager::add_sequence(const ks::SequenceItem& item) {
//     auto& current_iterator = _iterators.back();
//     current_iterator.insert(current_iterator.begin(), item.clone());
// }
void SceneManager::add_sequence(const ks::SequenceItem& item) {
    if (!_iterators.empty()) {
        auto& current_iterator = _iterators.back();
        current_iterator.insert(current_iterator.begin(), item.clone());
    }
}

void SceneManager::start() {
    processNext();
}

void SceneManager::update() {
    _dialog->update();
    processNext();
}

bool SceneManager::is_label_finished(int label_id) {
    // return _label_statuses.at(label_id);
    return true;
}

void SceneManager::finish_label(int label_id) {
    // _label_statuses.at(label_id) = true;
}

void SceneManager::processNext() {
    while (!_iterators.empty()) {
        auto& current_iterator = _iterators.back();

        // If the current sequence is finished or nullptr, move to the next sequence:
        if (_current_sequence == nullptr || _current_sequence->finished()) {
            if (!current_iterator.empty()) {
                delete _current_sequence;  // Free the finished sequence
                _current_sequence = current_iterator.back();
                current_iterator.pop_back();

                // Process the current sequence as before:
                if (_current_sequence->type() == ks::SequenceType::RunLabel) {
                    auto* run_label_item = static_cast<ks::RunLabelItem*>(_current_sequence);
                    hold_iterator();
                    run_label_item->run(*this);
                } else if (_current_sequence->type() == ks::SequenceType::Dialog) {
                    auto* dialog_item = static_cast<ks::DialogItem*>(_current_sequence);
                    _dialog->show(dialog_item);
                } else if (_current_sequence->type() == ks::SequenceType::Music) {
                    auto* music_item = static_cast<ks::MusicItem*>(_current_sequence);
                    music_item->item().play(1.0);
                } else if (_current_sequence->type() == ks::SequenceType::MusicStop) {
                    auto* music_item = static_cast<ks::MusicItem*>(_current_sequence);
                    if (bn::music::playing()) {
                        bn::music::stop();
                    }
                } else if (_current_sequence->type() == ks::SequenceType::MusicNotFound) {
                    auto* music_not_found = static_cast<ks::MusicNotFoundItem*>(_current_sequence);
                    if (bn::music::playing()) {
                        bn::music::stop();
                    }
                    bn::music::play(bn::music_items::not_found, 1.0, false);
                } else if (_current_sequence->type() == ks::SequenceType::Background) {
                    auto* background_item = static_cast<ks::BackgroundItem*>(_current_sequence);
                    _bg.reset();
                    _bg = background_item->item().create_bg(0, 0);
                }

                // If the current sequence is finished, reset it:
                if (_current_sequence->finished()) {
                    _current_sequence = nullptr;
                }
            } else {
                // If the current iterator is empty, release it:
                release_iterator();
            }
        } else {
            break;  // Stop if the current sequence is not finished
        }
    }

    // Finish if no iterators are left:
    if (_iterators.empty()) {
        finish();
    }
}

// void SceneManager::processNext() {
//     if (_iterators.empty()) {
//         finish();
//         return;
//     }

//     auto& current_iterator = _iterators.back();

//     // If _current_sequence is finished or nullptr, process the next item:
//     if (_current_sequence == nullptr || _current_sequence->finished()) {
//         if (!current_iterator.empty()) {
//             _current_sequence = current_iterator.back();
//             current_iterator.pop_back(); // Remove the item after assigning to _current_sequence

//             // Process the sequence based on its type:
//             if (_current_sequence->type() == ks::SequenceType::RunLabel) {
//                 auto* run_label_item = static_cast<ks::RunLabelItem*>(_current_sequence);
//                 hold_iterator();
//                 run_label_item->run(*this);
//             } else if (_current_sequence->type() == ks::SequenceType::Dialog) {
//                 auto* dialog_item = static_cast<ks::DialogItem*>(_current_sequence);
//                 _dialog->show(dialog_item);
//             } else if (_current_sequence->type() == ks::SequenceType::Music) {
//                 auto* music_item = static_cast<ks::MusicItem*>(_current_sequence);
//                 music_item->item().play(1.0);
//             } else if (_current_sequence->type() == ks::SequenceType::MusicStop) {
//                 auto* music_item = static_cast<ks::MusicItem*>(_current_sequence);
//                 if (bn::music::playing()) {
//                     bn::music::stop();
//                 }
//             } else if (_current_sequence->type() == ks::SequenceType::Background) {
//                 auto* background_item = static_cast<ks::BackgroundItem*>(_current_sequence);
//                 _bg.reset();
//                 _bg = background_item->item().create_bg(0, 0);
//             }

//             // Reset _current_sequence after processing:
//             if (_current_sequence->finished()) {
//                 _current_sequence = nullptr;
//             }

//         } else {
//             release_iterator();
//             processNext();
//         }
//     }
// }

// void SceneManager::processNext() {
//     if (_iterators.empty()) {
//         finish();
//         return;
//     }

//     auto& current_iterator = _iterators.back();

//     // If _current_sequence is finished or nullptr, process the next item:
//     if (_current_sequence == nullptr || _current_sequence->finished()) {
//         if (!current_iterator.empty()) {
//             _current_sequence = current_iterator.back();
//             current_iterator.pop_back(); // Remove the item after assigning to _current_sequence

//             // Process the sequence based on its type:
//             if (_current_sequence->type() == ks::SequenceType::RunLabel) {
//                 auto* run_label_item = static_cast<ks::RunLabelItem*>(_current_sequence);
//                 hold_iterator();
//                 run_label_item->run(*this);
//             } else if (_current_sequence->type() == ks::SequenceType::Dialog) {
//                 auto* dialog_item = static_cast<ks::DialogItem*>(_current_sequence);
//                 _dialog->show(dialog_item);
//             } else if (_current_sequence->type() == ks::SequenceType::Music) {
//                 auto* music_item = static_cast<ks::MusicItem*>(_current_sequence);
//                 music_item->item().play(1.0);
//             } else if (_current_sequence->type() == ks::SequenceType::MusicStop) {
//                 auto* music_item = static_cast<ks::MusicItem*>(_current_sequence);
//                 if (bn::music::playing()) {
//                     bn::music::stop();
//                 }
//             } else if (_current_sequence->type() == ks::SequenceType::Background) {
//                 auto* background_item = static_cast<ks::BackgroundItem*>(_current_sequence);
//                 _bg.reset();
//                 _bg = background_item->item().create_bg(0, 0);
//             }

//             // Reset _current_sequence after processing:
//             // if (_current_sequence->finished()) {
//                 // release_iterator();
//                 // _current_sequence = nullptr;
//             // }

//         } else {
//             release_iterator();
//             processNext();
//         }
//     }
// }

// Possible that would works
// void SceneManager::processNext() {
//     while (!_iterators.empty()) {
//         auto& current_iterator = _iterators.back();

//         if (_current_sequence == nullptr || _current_sequence->finished()) {
//             if (!current_iterator.empty()) {
//                 _current_sequence = current_iterator.back();
//                 current_iterator.pop_back();

//                 // Process the sequence as before...
//                 if (_current_sequence->type() == ks::SequenceType::RunLabel) {
//                     auto* run_label_item = static_cast<ks::RunLabelItem*>(_current_sequence);
//                     hold_iterator();
//                     run_label_item->run(*this);
//                 } else if (_current_sequence->type() == ks::SequenceType::Dialog) {
//                     auto* dialog_item = static_cast<ks::DialogItem*>(_current_sequence);
//                     _dialog->show(dialog_item);
//                 } else if (_current_sequence->type() == ks::SequenceType::Music) {
//                     auto* music_item = static_cast<ks::MusicItem*>(_current_sequence);
//                     music_item->item().play(1.0);
//                 } else if (_current_sequence->type() == ks::SequenceType::MusicStop) {
//                     auto* music_item = static_cast<ks::MusicItem*>(_current_sequence);
//                     if (bn::music::playing()) {
//                         bn::music::stop();
//                     }
//                 } else if (_current_sequence->type() == ks::SequenceType::Background) {
//                     auto* background_item = static_cast<ks::BackgroundItem*>(_current_sequence);
//                     _bg.reset();
//                     _bg = background_item->item().create_bg(0, 0);
//                 }

//                 if (_current_sequence->finished()) {
//                     _current_sequence = nullptr;
//                 }
//             } else {
//                 release_iterator();
//             }
//         } else {
//             break;  // Stop processing if current sequence is not finished
//         }
//     }

//     if (_iterators.empty()) {
//         finish();
//     }
// }

} // namespace ks
