// Reuse the exact DXTV DXT lookup tables, but force them into .rodata
// (ROM) instead of IWRAM to keep IWRAM small.
//
// Trick: base.h uses `#pragma once`, so if we pull it in first and then
// override IWRAM_DATA to a no-op, the second include performed by
// dxt_tables.cpp is a no-op and our override survives.
#include "../dxtvplayer/base.h"
#undef IWRAM_DATA
#define IWRAM_DATA
#include "../dxtvplayer/dxt_tables.cpp"
