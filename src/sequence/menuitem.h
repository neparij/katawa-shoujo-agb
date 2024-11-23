#ifndef KS_MENUITEM_H
#define KS_MENUITEM_H

#include "sequenceitem.h"
#include "../scenemanager.h"

namespace ks {

class MenuItem : public ks::SequenceItem {
public:
    explicit MenuItem(void(*callback)(ks::SceneManager& scene));

    SequenceType type() const override;
    SequenceItem* clone() const override;

    void run(ks::SceneManager& scene);
    bool finished() const override;
    void finished(bool flag) const;

private:
    void(*_callback)(ks::SceneManager& scene);
};

} // namespace ks

#endif // KS_MENUITEM_H
