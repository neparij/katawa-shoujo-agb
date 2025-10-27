local state = {}
state.width = canvas:screenWidth()
state.height = canvas:screenHeight()
state.overlay = canvas:newLayer(state.width, state.height)
state.painter = image.newPainter(state.overlay.image)
state.painter:loadFont(script.dir .. "/SourceSans3-Regular.otf")
state.painter:setFontSize(8)
state.painter:setFill(true)
state.painter:setBlend(false)
state.callback_id = 0
state.cpu_usages = {}

local function findMagic(region)
    local mem = region
    local region_name = region:name()
    local size = mem:size()
    local magic = "KSGBASYSSTATS\0\0\0"
    local magic_len = #magic

    for addr = 0, size - magic_len do
        local bytes = mem:readRange(addr, magic_len)
        if bytes == magic then
            local abs = mem:bound() + addr
            console:log(string.format("Found '%s' in %s at 0x%08X", magic, region_name, abs))
            return { abs = abs, region = mem, offset = addr }
        end
    end

    console:log(string.format("'%s' not found in %s", magic, region_name))
    return nil
end

-- Try WRAM then IWRAM
local stats = findMagic(emu.memory.wram) or findMagic(emu.memory.iwram)

if not stats then
    console:log("❌ system_stats_t not found")
    return
end

console:log(string.format("✅ system_stats_t found at 0x%08X", stats.abs))

-- Convenience accessors
local base = stats.offset
local region = stats.region
local function r16(off) return region:read16(base + off) end
local function r32(off) return region:read32(base + off) end


reset_max_cpu_period = 30
last_max_cpu = 0
cur_max_cpu = 0
reset_max_cpu_counter = reset_max_cpu_period
max_cpu_usages_count = 240

-- Frame callback: log every frame
function state.update()
    state.painter:setStrokeWidth(0)
    state.painter:setFillColor(0x00000000)
    state.painter:drawRectangle(0, 0, state.width, state.height)

    local last_used_cpu        = r32(0x10)
    local ewram_used           = r32(0x14)
    local bg_tiles_used        = r16(0x18)
    local bg_maps_used         = r16(0x1A)
    local bg_palettes_used     = r16(0x1C)
    local sprite_tiles_used    = r16(0x1E)
    local sprite_palettes_used = r16(0x20)

    if #state.cpu_usages >= max_cpu_usages_count then
       table.remove(state.cpu_usages, 1)
    end
    table.insert(state.cpu_usages, last_used_cpu)

    local lines = {
       string.format("CPU: %d%%", last_used_cpu),
       string.format("EWRAM: %d/%d (%.0f%%)", ewram_used, 262144, ewram_used / 262144 * 100),
       string.format("BG Tiles: %d/%d (%.0f%%)", bg_tiles_used, 2048, bg_tiles_used / 2048 * 100),
       string.format("BG Maps: %d/%d (%.0f%%)", bg_maps_used, 32768, bg_maps_used / 32768 * 100),
       string.format("BG Palettes: %d/%d (%.0f%%)", bg_palettes_used, 256, bg_palettes_used / 256 * 100),
       string.format("SPR Tiles: %d/%d (%.0f%%)", sprite_tiles_used, 1024, sprite_tiles_used / 1024 * 100),
       string.format("SPR Palettes: %d/%d (%.0f%%)", sprite_palettes_used, 256, sprite_palettes_used / 256 * 100),
    }

    state.painter:setBlend(true)
    state.painter:setStrokeWidth(0)
    for i, line in ipairs(lines) do
        line_metrics = state.painter:textRunMetrics(line)
        state.painter:setFillColor(0xFF000000)
        state.painter:drawRectangle(0, 0 + (i-1) * 12, line_metrics:width() + 4, 12)

        state.painter:setFillColor(0xFFFFFFFF)
        state.painter:drawText(line, 2, -2 + (i-1) * 12, C.ALIGN.TOP | C.ALIGN.LEFT)
    end
    state.painter:setBlend(false)


    state.painter:setStrokeWidth(1)
    state.painter:setStrokeColor(0x40FFFFFF)
    state.painter:drawLine(240 - max_cpu_usages_count, 160 - 100, 240, 160 - 100)
    if #state.cpu_usages >= 2 then
        for i = 1, #state.cpu_usages - 1 do
           local x1 = 240 - #state.cpu_usages + i - 1
           local x2 = x1 + 1
           local y1 = 160 - state.cpu_usages[i]
           local y2 = 160 - state.cpu_usages[i + 1]

            local usage = math.max(state.cpu_usages[i], state.cpu_usages[i+1])
            usage = math.min(math.max(usage, 0), 100)
            local r = math.min(255, math.floor((usage / 100) * 255))
            local g = math.min(255, math.floor(((100 - usage) / 100) * 255))
            local color = (r << 16) | (g << 8) | 0x00
            state.painter:setStrokeColor(0xA0000000 | color)

           state.painter:drawLine(x1, y1, x2, y2)
        end
    end

    state.overlay:update()
end

state.callback_id = callbacks:add("frame", state.update)
console:log("Frame callback 'frame' registered. Logging each frame...")
