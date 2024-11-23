#ifndef KS_SCENEMANAGER_H
#define KS_SCENEMANAGER_H


#include "sequence/sequenceitem.h"
#include "dialogbox.cpp.h"
#include <bn_regular_bg_ptr.h>


namespace ks {

class SceneManager {
public:
    SceneManager(bn::optional<bn::regular_bg_ptr>& bg_ptr);
    ~SceneManager();

    void add_sequence(const ks::SequenceItem& item);
    bool is_label_finished(int label_id);
    void finish_label(int label_id);
    bn::sprite_text_generator* get_text_generator() { return _text_generator; };
    void start();
    void update();
    bool is_finished() { return _is_finished; };
    void hold_iterator();
    void release_iterator();
    void finish() { _is_finished = true; };

private:
    ks::DialogBox* _dialog;
    bn::optional<bn::regular_bg_ptr>& _bg;
    bn::vector<bn::vector<SequenceItem*, ks::system::interator_size>, ks::system::allocate_iterators> _iterators;
    bn::vector<bool, 32> _label_statuses;
    ks::SequenceItem* _current_sequence = nullptr;
    bn::sprite_text_generator* _text_generator;
    int _current_label_id = 0;
    bool _is_on_label = false;
    bool _is_finished = false;
    bool _hold_iterator = false;

    void processNext();
};

} // namespace ks

#endif // KS_SCENEMANAGER_H
