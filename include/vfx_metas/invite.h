#ifndef KS_VFXMETA_INVITE
#define KS_VFXMETA_INVITE

#include "vfx_meta.h"
#include "definitions/seen_bitmask.h"
#include "bn_regular_bg_items_invite.h"
namespace ks::vfx_metas {
    constexpr inline vfx_meta invite(
                     bn::regular_bg_items::invite,
                     DISPLAYABLE_BITMASK_INVITE);

}

#endif  // KS_VFXMETA_INVITE
