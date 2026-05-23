-- ===============================
--  KS GBA System Stats Logger
--  (canvas overlay — throttled redraw)
-- ===============================

local MAGIC = "KSGBASYSSTATS\0\0\0"
local MAGIC_U32 = 0x4247534B -- "KSGB" as little-endian u32

local UPDATE_INTERVAL = 3      -- redraw overlay every N emulated frames
local MAX_CPU_SAMPLES = 120
local EWRAM_TOTAL = 262144
local BG_TILES_TOTAL = 2048
local BG_MAPS_TOTAL = 4096
local BG_PALS_TOTAL = 256
local SPR_TILES_TOTAL = 1024
local SPR_PALS_TOTAL = 256

-- HUD layout (overlay is only this tall — not full 160px screen)
local HUD_W = 240
local TEXT_LINES = 7
local LINE_H = 10
local TEXT_H = TEXT_LINES * LINE_H
local GRAPH_Y = TEXT_H + 2
local GRAPH_H = 28
local HUD_H = GRAPH_Y + GRAPH_H + 2

local state = {
    stats = nil,
    callback_id = -1,
    overlay = nil,
    painter = nil,
    cpu_ring = {},
    cpu_head = 0,
    cpu_count = 0,
    frame_tick = 0,
    line_widths = {},
}

-- Widest plausible strings — measured once at boot, not each redraw.
local LINE_WIDTH_PROBES = {
    "CPU: 100%",
    "EWRAM: 262144/262144 (100%)",
    "BG Tiles: 2048/2048 (100%)",
    "BG Maps: 32768/32768 (100%)",
    "BG Palettes: 256/256 (100%)",
    "SPR Tiles: 1024/1024 (100%)",
    "SPR Palettes: 256/256 (100%)",
}

-- =========================================
--  Memory scanning for system_stats_t
-- =========================================

local function findStatsStruct(region)
    local size = region:size()
    -- Align to 4 bytes; cheap u32 prefilter before readRange().
    for addr = 0, size - #MAGIC, 4 do
        if region:read32(addr) == MAGIC_U32
            and region:readRange(addr, #MAGIC) == MAGIC then
            return {
                abs = region:bound() + addr,
                region = region,
                offset = addr,
            }
        end
    end
    return nil
end

local function read16(offset)
    return state.stats.region:read16(state.stats.offset + offset)
end

local function read32(offset)
    return state.stats.region:read32(state.stats.offset + offset)
end

local function pushCpuSample(value)
    state.cpu_head = (state.cpu_head % MAX_CPU_SAMPLES) + 1
    state.cpu_ring[state.cpu_head] = value
    if state.cpu_count < MAX_CPU_SAMPLES then
        state.cpu_count = state.cpu_count + 1
    end
end

-- =========================================
--  Stats rendering
-- =========================================

local function drawTextLine(line, index)
    local y = (index - 1) * LINE_H
    local w = state.line_widths[index] or 0

    state.painter:setStrokeWidth(0)
    state.painter:setStrokeColor(0x00000000)
    state.painter:setFillColor(0x80000000)
    state.painter:drawRectangle(0, y, w + 4, LINE_H)

    state.painter:setFillColor(0xFFFFFFFF)
    state.painter:drawText(line, 2, y - 2, C.ALIGN.TOP | C.ALIGN.LEFT)
end

local function drawTextBlock(lines)
    for i, line in ipairs(lines) do
        drawTextLine(line, i)
    end
end

local function cpuBarColor(usage)
    if usage < 0 then
        usage = 0
    end
    local u = usage
    if u > 100 then
        u = 100
    end
    local r = math.floor((u / 100) * 255)
    local g = math.floor(((100 - u) / 100) * 255)
    return 0xFF000000 | (r << 16) | (g << 8)
end

local function drawCpuGraph()
    local count = state.cpu_count
    if count < 2 then
        return
    end

    local graph_w = MAX_CPU_SAMPLES
    local base_y = GRAPH_Y + GRAPH_H

    -- Background + baseline (2 rects instead of a line)
    state.painter:setFillColor(0x40000000)
    state.painter:drawRectangle(0, GRAPH_Y, graph_w, GRAPH_H)
    state.painter:setFillColor(0x80404040)
    state.painter:drawRectangle(0, base_y - 1, graph_w, 1)

    local max_bar_h = GRAPH_H - 2
    for i = 1, count do
        local idx = state.cpu_head - count + i
        if idx <= 0 then
            idx = idx + MAX_CPU_SAMPLES
        end
        local usage = state.cpu_ring[idx] or 0

        local bar_h
        if usage <= 0 then
            bar_h = 0
        elseif usage >= 100 then
            bar_h = max_bar_h
        else
            bar_h = math.floor((usage / 100) * max_bar_h + 0.5)
        end

        if bar_h > 0 then
            state.painter:setFillColor(cpuBarColor(usage))
            state.painter:drawRectangle(i - 1, base_y - bar_h, 1, bar_h)
        end
    end
end

local function redrawOverlay(last_cpu, ewram_used, bg_tiles, bg_maps, bg_pals, spr_tiles, spr_pals)
    state.painter:setStrokeWidth(0)
    state.painter:setFillColor(0x00000000)
    state.painter:drawRectangle(0, 0, HUD_W, HUD_H)

    state.painter:setBlend(true)
    drawCpuGraph()

    local lines = {
        string.format("CPU: %d%%", last_cpu),
        string.format("EWRAM: %d/%d (%.0f%%)", ewram_used, EWRAM_TOTAL, ewram_used / EWRAM_TOTAL * 100),
        string.format("BG Tiles: %d/%d (%.0f%%)", bg_tiles, BG_TILES_TOTAL, bg_tiles / BG_TILES_TOTAL * 100),
        string.format("BG Maps: %d/%d (%.0f%%)", bg_maps, BG_MAPS_TOTAL, bg_maps / BG_MAPS_TOTAL * 100),
        string.format("BG Palettes: %d/%d (%.0f%%)", bg_pals, BG_PALS_TOTAL, bg_pals / BG_PALS_TOTAL * 100),
        string.format("SPR Tiles: %d/%d (%.0f%%)", spr_tiles, SPR_TILES_TOTAL, spr_tiles / SPR_TILES_TOTAL * 100),
        string.format("SPR Palettes: %d/%d (%.0f%%)", spr_pals, SPR_PALS_TOTAL, spr_pals / SPR_PALS_TOTAL * 100),
    }
    drawTextBlock(lines)
    state.painter:setBlend(false)

    state.overlay:update()
end

-- =========================================
--  Frame update
-- =========================================

function state.update()
    if not state.stats then
        state.stats = findStatsStruct(emu.memory.iwram)
        if state.stats then
            console:log(("✅ system_stats_t found at 0x%08X in %s")
                :format(state.stats.abs, state.stats.region:name()))
        end
        return
    end

    local last_cpu = read32(0x10)
    pushCpuSample(last_cpu)

    state.frame_tick = state.frame_tick + 1
    if state.frame_tick % UPDATE_INTERVAL ~= 0 then
        return
    end

    redrawOverlay(
        last_cpu,
        read32(0x14),
        read16(0x18),
        read16(0x1A),
        read16(0x1C),
        read16(0x1E),
        read16(0x20)
    )
end

-- =========================================
--  Cleanup
-- =========================================

local function clearStats()
    console:log("Clear stats struct...")
    state.stats = nil
    state.cpu_head = 0
    state.cpu_count = 0
    state.frame_tick = 0
end

callbacks:add("reset", clearStats)
callbacks:add("stop", clearStats)
callbacks:add("shutdown", clearStats)

-- =========================================
--  Boot setup
-- =========================================

state.overlay = canvas:newLayer(HUD_W, HUD_H)
state.painter = image.newPainter(state.overlay.image)
state.painter:loadFont(script.dir .. "/NFPixels-Regular.otf")
state.painter:setFontSize(7)
state.painter:setFill(true)
state.painter:setBlend(false)

for i, probe in ipairs(LINE_WIDTH_PROBES) do
    state.line_widths[i] = state.painter:textRunMetrics(probe):width()
end

state.callback_id = callbacks:add("frame", state.update)
