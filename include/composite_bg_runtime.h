#ifndef KS_COMPOSITE_BG_RUNTIME_H
#define KS_COMPOSITE_BG_RUNTIME_H

#include "composite_bg_asset.h"
#include "bn_optional.h"
#include "bn_regular_bg_map_cell.h"
#include "bn_regular_bg_map_ptr.h"
#include "bn_regular_bg_ptr.h"
#include "bn_regular_bg_tiles_ptr.h"

namespace ks {

class background_item;
class regular_composite_bg_item;

struct composite_bg_state;

/// Per-active-composite upload snapshot (drained at V-Blank).
struct composite_pending_tile_upload
{
    int                   ready = 0;
    const composite_tileset* tileset = nullptr;
    int                   count = 0;
    static constexpr int  max_tiles = 1024;
    uint16_t              used_tiles[max_tiles];
};

struct composite_bg_state
{
    static constexpr int max_decompressed_slabs = 4;

    const composite_bg_asset*           asset = nullptr;
    int                                 variant_index = 0;
    bn::optional<bn::regular_bg_tiles_ptr> vram_tiles;
    bn::optional<bn::regular_bg_map_ptr>   map;
    alignas(int) bn::regular_bg_map_cell  cells[1024];
    int                                 map_cells_count = 0;
    composite_pending_tile_upload       upload;

    /// LZ77/RL/Huffman slabs decompressed here for V-Blank tile streaming.
    const composite_tileset*            decompressed_tileset = nullptr;
    void*                               decompressed_slabs_ewram[max_decompressed_slabs] = {};
    int                                 decompressed_slab_tile_count[max_decompressed_slabs] = {};
    bool                                tiles_copied_to_vram = false;
};

namespace composite_bg_runtime {

void init();

[[nodiscard]] composite_bg_state* alloc_state();
void free_state(composite_bg_state* state);

[[nodiscard]] bn::optional<bn::regular_bg_ptr> create_regular_bg(
        const regular_composite_bg_item& item, bn::fixed x, bn::fixed y,
        composite_bg_state& state);

void register_state(composite_bg_state* state);
void unregister_state(composite_bg_state* state);

void process_pending_uploads();

/// Drop EWRAM tileset decompress buffers after VRAM upload + vblank commit.
void release_decompressed_ewram_if_committed(composite_bg_state& state);

/// Swap map + tile upload in place (same asset, different variant index).
void switch_variant(composite_bg_state& state, int variant_index);

}  // namespace composite_bg_runtime

}  // namespace ks

#endif  // KS_COMPOSITE_BG_RUNTIME_H
