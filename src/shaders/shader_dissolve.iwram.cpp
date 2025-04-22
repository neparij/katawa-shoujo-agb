#include "vram_dma_shader.h"

void shader_dissolve_out(int totalDwords, int dissolve_i, uint32_t *tileBackup, uint32_t *vram_ptr, void (*updates)()) {
    uint32_t px;
    for (int i = 0; i < totalDwords; i++) {
        // Load original data from backup
        uint32_t orig_px = tileBackup[i];

        // Extract 4 pixels
        uint8_t orig_p0 = orig_px & 0xFF;
        uint8_t orig_p1 = (orig_px >> 8) & 0xFF;
        uint8_t orig_p2 = (orig_px >> 16) & 0xFF;
        uint8_t orig_p3 = (orig_px >> 24) & 0xFF;

        // Start from fully transparent
        uint8_t p0 = 0x00;
        uint8_t p1 = 0x00;
        uint8_t p2 = 0x00;
        uint8_t p3 = 0x00;

        // Restore pixels gradually
        if (dissolve_i >= orig_p0) p0 = orig_p0;
        if (dissolve_i >= orig_p1) p1 = orig_p1;
        if (dissolve_i >= orig_p2) p2 = orig_p2;
        if (dissolve_i >= orig_p3) p3 = orig_p3;

        // Reconstruct modified 32-bit value
        px = (p3 << 24) | (p2 << 16) | (p1 << 8) | p0;

        dmaCopy(&px, &vram_ptr[i], 4);
        __asm volatile("nop"); // Insert a small delay to release VRAM
        if (i == totalDwords / 2) {
            updates();
        }
    }
}


void shader_dissolve_out_inverted(int totalDwords, int dissolve_i, uint32_t *tileBackup, uint32_t *vram_ptr, void (*updates)()) {
    uint32_t px;
    for (int i = 0; i < totalDwords; i++) {
        // Load original data from backup
        uint32_t orig_px = tileBackup[i];

        // Extract 4 pixels
        uint8_t orig_p0 = orig_px & 0xFF;
        uint8_t orig_p1 = (orig_px >> 8) & 0xFF;
        uint8_t orig_p2 = (orig_px >> 16) & 0xFF;
        uint8_t orig_p3 = (orig_px >> 24) & 0xFF;

        // Start from fully transparent
        uint8_t p0 = 0x00;
        uint8_t p1 = 0x00;
        uint8_t p2 = 0x00;
        uint8_t p3 = 0x00;

        // Restore pixels gradually
        if (dissolve_i < orig_p0) p0 = orig_p0;
        if (dissolve_i < orig_p1) p1 = orig_p1;
        if (dissolve_i < orig_p2) p2 = orig_p2;
        if (dissolve_i < orig_p3) p3 = orig_p3;

        // Reconstruct modified 32-bit value
        px = (p3 << 24) | (p2 << 16) | (p1 << 8) | p0;

        dmaCopy(&px, &vram_ptr[i], 4);
        __asm volatile("nop"); // Insert a small delay to release VRAM
        if (i == totalDwords / 2) {
            updates();
        }
    }
}

void shader_dissolve_in(int totalDwords, int dissolve_i, uint32_t *vram_ptr, void (*updates)()) {
    for (int i = 0; i < totalDwords; i++) {
        uint32_t px = vram_ptr[i];

        // Extract 4 pixels
        uint8_t p0 = px & 0xFF;
        uint8_t p1 = (px >> 8) & 0xFF;
        uint8_t p2 = (px >> 16) & 0xFF;
        uint8_t p3 = (px >> 24) & 0xFF;

        // Apply dissolve effect
        if (p0 > dissolve_i) p0 = 0x00;
        if (p1 > dissolve_i) p1 = 0x00;
        if (p2 > dissolve_i) p2 = 0x00;
        if (p3 > dissolve_i) p3 = 0x00;

        // Reconstruct modified 32-bit value
        px = (p3 << 24) | (p2 << 16) | (p1 << 8) | p0;

        dmaCopy(&px, &vram_ptr[i], 4);
        __asm volatile("nop"); // Insert a small delay to release VRAM

        if (i == totalDwords / 2) {
            updates();
        }
    }
}


void shader_dissolve_in_inverted(int totalDwords, int dissolve_i, uint32_t *vram_ptr, void (*updates)()) {
    for (int i = 0; i < totalDwords; i++) {
        uint32_t px = vram_ptr[i];

        // Extract 4 pixels
        uint8_t p0 = px & 0xFF;
        uint8_t p1 = (px >> 8) & 0xFF;
        uint8_t p2 = (px >> 16) & 0xFF;
        uint8_t p3 = (px >> 24) & 0xFF;

        // Apply dissolve effect
        if (p0 <= dissolve_i) p0 = 0x00;
        if (p1 <= dissolve_i) p1 = 0x00;
        if (p2 <= dissolve_i) p2 = 0x00;
        if (p3 <= dissolve_i) p3 = 0x00;

        // Reconstruct modified 32-bit value
        px = (p3 << 24) | (p2 << 16) | (p1 << 8) | p0;

        dmaCopy(&px, &vram_ptr[i], 4);
        __asm volatile("nop"); // Insert a small delay to release VRAM

        if (i == totalDwords / 2) {
            updates();
        }
    }
}
