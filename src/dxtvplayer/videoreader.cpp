#include "videoreader.h"

#include "memory.h"

namespace Video
{

    Info GetInfo(const uint32_t *data)
    {
        static_assert(sizeof(FileHeader) % 4 == 0);
        Info info;
        Memory::memcpy32(&info, data, sizeof(FileHeader) / 4);
        info.fileData = data;
        info.imageSize = info.width * info.height;
        switch (info.bitsPerColor)
        {
        case 1:
            info.imageSize = (info.imageSize + 7) / 8;
            break;
        case 2:
            info.imageSize = (info.imageSize + 3) / 4;
            break;
        case 4:
            info.imageSize = (info.imageSize + 1) / 2;
            break;
        case 8:
            info.imageSize *= 1;
            break;
        case 15:
        case 16:
            info.imageSize *= 2;
            break;
        case 24:
            info.imageSize *= 3;
            break;
        default:
            // TODO: What?
            break;
        }
        info.colorMapSize = info.colorMapEntries;
        switch (info.bitsPerColor)
        {
        case 15:
        case 16:
            info.colorMapSize *= 2;
            break;
        case 24:
            info.colorMapSize *= 3;
            break;
        default:
            // TODO: What?
            break;
        }
        return info;
    }

    Frame GetNextFrame(const Info &info, const Frame &previous)
    {
        static_assert(sizeof(FrameHeader) % 4 == 0);
        Frame frame;
        const uint32_t *frameStart = nullptr;
        if (previous.index < 0 || previous.index >= static_cast<int32_t>(info.nrOfFrames - 1))
        {
            // read first frame
            frame.index = 0;
            frameStart = info.fileData + sizeof(FileHeader) / 4;
        }
        else
        {
            frame.index = previous.index + 1;
            const uint32_t previousFrameSize = previous.pixelDataSize + previous.colorMapDataSize + previous.audioDataSize;
            frameStart = previous.frame + sizeof(FrameHeader) / 4 + previousFrameSize / 4;
        }
        frame.frame = frameStart;
        frame.data = frameStart + sizeof(FrameHeader) / 4;
        auto header = reinterpret_cast<const FrameHeader *>(frameStart);
        frame.pixelDataSize = header->pixelDataSize;
        frame.colorMapDataSize = header->colorMapDataSize;
        frame.audioDataSize = header->audioDataSize;
        return frame;
    }

}