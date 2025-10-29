-- ===============================
--  KS GBA System Stats Logger
-- ===============================

local ST = {
    server = nil,
    sockets = {},
    next_id = 1,
    port = 8888,
}

local state = {
    callback_id = -1,
    stats = nil,
}

-- =========================================
--  Memory scanning for system_stats_t
-- =========================================
local MAGIC = "KSGBASYSSTATS\0\0\0"

local function find_ks_stats_magic(region)
    local size = region:size()
    for addr = 0, size - #MAGIC do
        local bytes = region:readRange(addr, #MAGIC)
        if bytes == MAGIC then
            return {
                abs = region:bound() + addr,
                region = region,
                offset = addr,
            }
        end
    end
    return nil
end

local function r16(off)
    return state.stats.region:read16(state.stats.offset + off)
end

local function r32(off)
    return state.stats.region:read32(state.stats.offset + off)
end

function safe_send(id, sock, msg)
    local ok, err
    ok, err = sock:poll()
    if err then
        ST_log(id, "Poll failed: " .. tostring(err), true)
        ST_stop(id)
        return
    end
    ok, err = sock:send(msg)
    if not ok and err ~= socket.ERRORS.AGAIN then
        ST_log(id, "Send failed: " .. tostring(err), true)
        ST_stop(id)
    end
end

-- =========================================
--  State update per frame
-- =========================================
function state.update()
    if not state.stats then
        -- Uncomment this line and comment the next to search both WRAM and IWRAM
        -- state.stats = find_ks_stats_magic(emu.memory.wram) or find_ks_stats_magic(emu.memory.iwram)
        state.stats = find_ks_stats_magic(emu.memory.iwram)
        if state.stats then
            console:log(("✅ system_stats_t found at 0x%08X in %s"):format(state.stats.abs, state.stats.region:name()))
        end
    else
        local data = {
            r32(0x10),  -- last_used_cpu
            r32(0x14),  -- ewram_used
            r16(0x18),  -- bg_tiles_used
            r16(0x1A),  -- bg_maps_used
            r16(0x1C),  -- bg_palettes_used
            r16(0x1E),  -- sprite_tiles_used
            r16(0x20),  -- sprite_palettes_used
        }

        local line = table.concat(data, ":") .. "\n"

        for id, sock in pairs(ST.sockets) do
            if sock then safe_send(id, sock, line) end
        end
    end
end

-- =========================================
--  Socket handling
-- =========================================
local function ST_log(id, msg, is_error)
    console:log("ST_LOG")
    local prefix = ("Socket #%d %s: "):format(id, is_error and "Error" or "Received")
    if is_error then
        console:error(prefix .. msg)
    else
        console:log(prefix .. msg)
    end
end

local function ST_stop(id)
    local sock = ST.sockets[id]
    if sock then
        sock:close()
        ST.sockets[id] = nil
        console:log("Socket " .. id .. " closed")
    end
end

local function ST_on_error(id, err)
    ST_log(id, err, true)
    ST_stop(id)
end

local function ST_on_received(id)
    local sock = ST.sockets[id]
    if not sock then return end

    while true do
        local data, err = sock:receive(1024)
        if data then
            ST_log(id, data:match("^(.-)%s*$"), false)
        elseif err ~= socket.ERRORS.AGAIN then
            ST_on_error(id, err)
            break
        else
            break
        end
    end
end

local function ST_accept()
    local sock, err = ST.server:accept()
    if err then
        console:error("Socket Accept Error: " .. err)
        return
    end

    local id = ST.next_id
    ST.next_id = id + 1
    ST.sockets[id] = sock

    sock:add("received", function() ST_on_received(id) end)
    sock:add("error", function() ST_on_error(id) end)

    console:log("Socket " .. id .. " connected")
end

-- =========================================
--  Clear stats struct
-- =========================================
function ST_clear()
    console:log("Clear stats struct...")
    state.stats = nil
end

-- =========================================
--  Server setup
-- =========================================
local function ST_start_server()
    local port = ST.port
    local err

    repeat
        ST.server, err = socket.bind(nil, port)
        if err == socket.ERRORS.ADDRESS_IN_USE then
            port = port + 1
        elseif err then
            console:error("Bind error: " .. err)
            return
        end
    until ST.server

    local ok
    ok, err = ST.server:listen()
    if not ok then
        console:error("Listen error: " .. (err or "unknown"))
        ST.server:close()
        return
    end

    ST.port = port
    ST.server:add("received", ST_accept)
    console:log("Listening on port " .. port)
end

-- =========================================
--  Register emulator callbacks
-- =========================================
callbacks:add("reset", ST_clear)
callbacks:add("stop", ST_clear)
callbacks:add("shutdown", ST_clear)

-- =========================================
--  Boot
-- =========================================
ST_start_server()
state.callback_id = callbacks:add("frame", state.update)