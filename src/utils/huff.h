#ifndef HUFF_H
#define HUFF_H

#include "gba_types.h"

// UnCompress Huffman Data to WRAM (8-bit or 4-bit units depending on header low nibble)
inline void HuffUnComp(u32 source, u32 dest) {
    asm("mov r0, %0\n"
        "mov r1, %1\n"
        "swi 0x13\n"
        :
        :"r" (source), "r" (dest)
        :"r0", "r1" );
}

#endif // HUFF_H

