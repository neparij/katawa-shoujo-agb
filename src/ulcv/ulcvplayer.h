#pragma once

#include <cstdint>

namespace ULCV
{
    struct Info
    {
        uint16_t width = 0;
        uint16_t height = 0;
        uint8_t fps = 0;
        /// Matches clean encoder ``header.frame_payload_layout`` (byte offset 10): 0 = raw
        /// frame packet bytes; 1 = each packet is ``[u8 codec_tag][payload]``.
        uint8_t framePayloadLayout = 0;
        uint32_t nrOfFrames = 0;
        uint32_t payloadSize = 0;
        bool valid = false;
    };

    auto isULCV(const uint32_t* videoSrc) -> bool;
    auto init(const uint32_t* videoSrc, uint32_t* scratchPad, uint32_t scratchPadSize) -> void;
    auto getInfo() -> const Info&;
    auto play() -> void;
    auto stop() -> void;
    auto hasMoreFrames() -> bool;
    auto decodeAndBlitFrame(uint32_t* dst) -> void;
    auto decodeAndBlitFrame(uint32_t* dst, void (*updateCallback)()) -> void;
}
