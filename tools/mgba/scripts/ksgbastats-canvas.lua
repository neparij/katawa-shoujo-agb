-- ===============================
--  KS GBA System Stats Logger
-- ===============================

local MAGIC = "KSGBASYSSTATS\0\0\0"

local RESET_MAX_CPU_PERIOD = 30
local MAX_CPU_SAMPLES = 240
local EWRAM_TOTAL = 262144
local BG_TILES_TOTAL = 2048
local BG_MAPS_TOTAL = 32768
local BG_PALS_TOTAL = 256
local SPR_TILES_TOTAL = 1024
local SPR_PALS_TOTAL = 256

local state = {
    stats = nil,
    callback_id = -1,
    width = canvas:screenWidth(),
    height = canvas:screenHeight(),
    overlay = nil,
    painter = nil,
    cpu_usages = {},
}

-- =========================================
--  Memory scanning for system_stats_t
-- =========================================

local function findStatsStruct(region)
    local size = region:size()
    for addr = 0, size - #MAGIC do
        if region:readRange(addr, #MAGIC) == MAGIC then
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

-- =========================================
--  Stats rendering
-- =========================================

local function drawTextLine(line, index)
    local metrics = state.painter:textRunMetrics(line)
    local y = (index - 1) * 10

    -- Disable stroke
    state.painter:setStrokeWidth(0)
    state.painter:setStrokeColor(0x00000000)

    -- Background
    state.painter:setFillColor(0x80000000)
    state.painter:drawRectangle(0, y, metrics:width() + 4, 10)

    -- Text
    state.painter:setFillColor(0xFFFFFFFF)
    state.painter:drawText(line, 2, y - 2, C.ALIGN.TOP | C.ALIGN.LEFT)
end

local function drawCpuGraph()
    local samples = state.cpu_usages
    if #samples < 2 then return end

    state.painter:setStrokeWidth(1)
    state.painter:setStrokeColor(0x80FF8080)
    state.painter:drawLine(240 - MAX_CPU_SAMPLES, 60, 240, 60)

    for i = 1, #samples - 1 do
        local x1 = 240 - #samples + i - 1
        local x2 = x1 + 1
        local y1 = 160 - samples[i]
        local y2 = 160 - samples[i + 1]

        local usage = math.min(math.max(math.max(samples[i], samples[i + 1]), 0), 100)
        local r = math.floor((usage / 100) * 255)
        local g = math.floor(((100 - usage) / 100) * 255)
        local color = (r << 16) | (g << 8)

        state.painter:setStrokeColor(0xA0000000 | color)
        state.painter:drawLine(x1, y1, x2, y2)
    end
end

-- =========================================
--  Frame update
-- =========================================

function state.update()
    if not state.stats then
        -- Uncomment this line and comment the next to search both WRAM and IWRAM
        -- state.stats = findStatsStruct(emu.memory.iwram) or findStatsStruct(emu.memory.wram)
        state.stats = findStatsStruct(emu.memory.iwram)
        if state.stats then
            console:log(("✅ system_stats_t found at 0x%08X in %s")
                :format(state.stats.abs, state.stats.region:name()))
        end
        return
    end

    local last_cpu   = read32(0x10)
    local ewram_used = read32(0x14)
    local bg_tiles   = read16(0x18)
    local bg_maps    = read16(0x1A)
    local bg_pals    = read16(0x1C)
    local spr_tiles  = read16(0x1E)
    local spr_pals   = read16(0x20)

    -- Update CPU usage list
    if #state.cpu_usages >= MAX_CPU_SAMPLES then
        table.remove(state.cpu_usages, 1)
    end
    table.insert(state.cpu_usages, last_cpu)

    -- Clear overlay
    state.painter:setStrokeWidth(0)
    state.painter:setFillColor(0x00000000)
    state.painter:drawRectangle(0, 0, state.width, state.height)

    -- Draw CPU usage graph
    drawCpuGraph()

    -- Draw text stats
    state.painter:setBlend(true)
    local lines = {
        string.format("CPU: %d%%", last_cpu),
        string.format("EWRAM: %d/%d (%.0f%%)", ewram_used, EWRAM_TOTAL, ewram_used / EWRAM_TOTAL * 100),
        string.format("BG Tiles: %d/%d (%.0f%%)", bg_tiles, BG_TILES_TOTAL, bg_tiles / BG_TILES_TOTAL * 100),
        string.format("BG Maps: %d/%d (%.0f%%)", bg_maps, BG_MAPS_TOTAL, bg_maps / BG_MAPS_TOTAL * 100),
        string.format("BG Palettes: %d/%d (%.0f%%)", bg_pals, BG_PALS_TOTAL, bg_pals / BG_PALS_TOTAL * 100),
        string.format("SPR Tiles: %d/%d (%.0f%%)", spr_tiles, SPR_TILES_TOTAL, spr_tiles / SPR_TILES_TOTAL * 100),
        string.format("SPR Palettes: %d/%d (%.0f%%)", spr_pals, SPR_PALS_TOTAL, spr_pals / SPR_PALS_TOTAL * 100),
    }

    for i, line in ipairs(lines) do
        drawTextLine(line, i)
    end
    state.painter:setBlend(false)

    -- Update overlay
    state.overlay:update()
end

-- =========================================
--  Cleanup
-- =========================================

local function clearStats()
    console:log("Clear stats struct...")
    state.stats = nil
end

callbacks:add("reset", clearStats)
callbacks:add("stop", clearStats)
callbacks:add("shutdown", clearStats)

-- =========================================
--  Boot setup
-- =========================================

state.overlay = canvas:newLayer(state.width, state.height)
state.painter = image.newPainter(state.overlay.image)
state.painter:loadFont(script.dir .. "/NFPixels-Regular.otf")
state.painter:setFontSize(7)
state.painter:setFill(true)
state.painter:setBlend(false)
state.callback_id = callbacks:add("frame", state.update)