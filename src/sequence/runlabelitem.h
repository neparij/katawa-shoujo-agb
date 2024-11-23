#ifndef KS_RUNLABELITEM_H
#define KS_RUNLABELITEM_H

#include "sequenceitem.h"
#include "../scenemanager.h"

namespace ks {

class RunLabelItem : public ks::SequenceItem {
public:
    explicit RunLabelItem(void(*callback)(ks::SceneManager& scene));

    SequenceType type() const override;
    SequenceItem* clone() const override;

    void run(ks::SceneManager& scene);
    bool finished() const override;

private:
    void(*_callback)(ks::SceneManager& scene);
};

} // namespace ks

#endif // KS_RUNLABELITEM_H
