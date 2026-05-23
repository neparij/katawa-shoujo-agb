#ifndef KS_COMPOSITE_HUGE_BG_RUNTIME_H
#define KS_COMPOSITE_HUGE_BG_RUNTIME_H

#include "composite_bg_asset.h"
#include "ks_huge_bg.h"

#include "bn_optional.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"

namespace ks {

class composite_huge_bg_item;

struct composite_huge_bg_state
{
    static constexpr int map_window_w = WIDTH_BLOCKS + 1;
    static constexpr int map_window_h = HEIGHT_BLOCKS + 1;
    static constexpr int map_window_cells = map_window_w * map_window_h;

    const composite_bg_asset*              asset = nullptr;
    int                                    variant_index = 0;
    bn::optional<bn::regular_bg_tiles_ptr> vram_tiles;
    bn::optional<bn::regular_bg_map_ptr>   map;
    /// Decoded 31×21 map window for the current scroll origin (from RLE in ROM).
    alignas(int) bn::regular_bg_map_cell   map_window[map_window_cells];

    int                                    x_offset = 0;
    int                                    y_offset = 0;
    int                                    previous_x_offset = 0;
    int                                    previous_y_offset = 0;
    int                                    previous_bg_x = 0;
    int                                    previous_bg_y = 0;
    bool                                   initialized = false;
};

class composite_huge_bg {
public:
    ~composite_huge_bg();

    [[nodiscard]] static bn::optional<composite_huge_bg> create(
            bn::fixed x, bn::fixed y,
            const composite_huge_bg_item& item,
            composite_huge_bg_state& state);

    [[nodiscard]] bn::regular_bg_ptr regular_bg_ptr() const {
        return _wrapped_bg_ptr;
    }

    [[nodiscard]] bn::size map_dimensions() const {
        return _map_dimensions;
    }

    [[nodiscard]] bn::fixed_point position() const;

    void update();

    composite_huge_bg(composite_huge_bg&& other) noexcept;
    composite_huge_bg& operator=(composite_huge_bg&& other) noexcept;

    composite_huge_bg(const composite_huge_bg&) = delete;
    composite_huge_bg& operator=(const composite_huge_bg&) = delete;

private:
    void _refresh_vram_iterators();

    composite_huge_bg(bn::regular_bg_ptr handle,
                      bn::size map_dimensions,
                      composite_huge_bg_state* state,
                      bn::span<unsigned short>::iterator map_vram,
                      bn::span<bn::tile>::iterator tiles_vram);

    bn::regular_bg_ptr                     _wrapped_bg_ptr;
    bn::size                               _map_dimensions;
    composite_huge_bg_state*               _state;
    bn::span<unsigned short>::iterator     _map_vram;
    bn::span<bn::tile>::iterator           _tiles_vram;
};

namespace composite_huge_bg_runtime {

void init();
[[nodiscard]] composite_huge_bg_state* alloc_state();
void free_state(composite_huge_bg_state* state);
void register_bg(composite_huge_bg* bg);
void unregister_bg(composite_huge_bg* bg);
void switch_variant(composite_huge_bg_state& state, int variant_index);

void update_all();

}  // namespace composite_huge_bg_runtime

}  // namespace ks

#endif  // KS_COMPOSITE_HUGE_BG_RUNTIME_H
