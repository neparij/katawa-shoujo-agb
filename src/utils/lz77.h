#ifndef LZ77_H
#define LZ77_H

#include "gba_types.h"

// UnCompress LZ77 Data to WRAM
inline void LZ77UnCompWRAM(u32 source, u32 dest) {
    asm("mov r0, %0\n"
        "mov r1, %1\n"
        "swi 0x11\n"
        :
        :"r" (source), "r" (dest)
        :"r0", "r1" );
}

#endif // LZ77_H
