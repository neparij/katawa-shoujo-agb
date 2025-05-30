#pragma once

#include <cstdint>

namespace DXT
{

    // Decompresses one DXT1-ish 4x4 block consisting of 2 bytes color0 (RGB555), 2 bytes color1 (RGB555) and 16*2 bit = 4 bytes index information
    // See: https://www.khronos.org/opengl/wiki/S3_Texture_Compression#DXT1_Format
    // Blocks are stored sequentially from left to right, top to bottom, but colors and
    // indices are stored separately for better compression (first all colors, then all indices)
    // See also: https://stackoverflow.com/questions/56474930/efficiently-implementing-dxt1-texture-decompression-in-hardware
    template <uint32_t RESOLUTION_X>
    void UnCompWrite16bit(uint16_t *dst, const uint16_t *src, uint32_t width, uint32_t height);

}
