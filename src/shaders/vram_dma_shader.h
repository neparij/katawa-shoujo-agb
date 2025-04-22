#ifndef VRAM_DMA_SHADER_H
#define VRAM_DMA_SHADER_H

#ifdef __cplusplus
extern "C" {
#endif
#include "gba_dma.h"

#define CODE_ROM __attribute__((section(".code")))
#define CODE_EWRAM __attribute__((section(".ewram")))
#define INLINE static inline __attribute__((always_inline))

struct shader_data {
    uint32_t *tiles_buffer;
    uint32_t *vram_ptr;
    int dwords;
};

void shader_dissolve_out(int totalDwords, int dissolve_i, uint32_t *tileBackup, uint32_t *vram_ptr, void (*updates)());

void shader_dissolve_out_inverted(int totalDwords, int dissolve_i, uint32_t *tileBackup, uint32_t *vram_ptr, void (*updates)());

void shader_dissolve_in(int totalDwords, int dissolve_i, uint32_t *vram_ptr, void (*updates)());

void shader_dissolve_in_inverted(int totalDwords, int dissolve_i, uint32_t *vram_ptr, void (*updates)());

#ifdef __cplusplus
}
#endif

#endif //VRAM_DMA_SHADER_H
