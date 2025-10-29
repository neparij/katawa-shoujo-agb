#!/usr/bin/env bash

HOST=127.0.0.1
PORT=8888

WIDTH=50
HEIGHT=10
MAX_CPU_FRAMES=30

cpu_history=()

RED="\033[1;31m"
YELLOW="\033[1;33m"
GREEN="\033[1;32m"
RESET="\033[0m"

draw_bar() {
    local value=$1
    local max=$2
    local width=$3
    local bar_count=$(( value * width / max ))
    if [ $bar_count -gt $width ]; then bar_count=$width; fi

    local color=$GREEN
    local perc=$(( value * 100 / max ))
    if [ $perc -ge 75 ]; then
        color=$RED
    elif [ $perc -ge 50 ]; then
        color=$YELLOW
    fi

    local bar=""
    for ((i=0;i<bar_count;i++)); do bar+="#"; done
    for ((i=bar_count;i<width;i++)); do bar+=" "; done

    printf "%b%s%b" "$color" "$bar" "$RESET"
}


clear
tput civis

trap "tput cnorm" EXIT
trap "tput cnorm; exit" SIGINT SIGTERM


nc $HOST $PORT | while IFS=: read cpu ewram bg_tiles bg_maps bg_pal spr_tiles spr_pal; do
    # Add CPU usage to history
    cpu_history+=($cpu)
    if [ ${#cpu_history[@]} -gt $MAX_CPU_FRAMES ]; then
        cpu_history=("${cpu_history[@]:1}")
    fi

    # Calculate max CPU usage in history
    max_cpu=0
    for c in "${cpu_history[@]}"; do
        if [ $c -gt $max_cpu ]; then max_cpu=$c; fi
    done

    tput cup 0 0
    echo "================== GBA Stats =================="

    # CPU (Max in history)
    printf "CPU Usage:       [%3d%%] " "$max_cpu"
    draw_bar "$max_cpu" 100 "$WIDTH"
    echo

    ewram_max=262144
    printf "EWRAM Used:      [%6d/%-6d %3d%%] " "$ewram" "$ewram_max" "$(( ewram * 100 / ewram_max ))"
    draw_bar "$ewram" "$ewram_max" "$WIDTH"
    echo

    bg_tiles_max=2048
    printf "BG Tiles:        [%4d/%-4d %3d%%] " "$bg_tiles" "$bg_tiles_max" "$(( bg_tiles * 100 / bg_tiles_max ))"
    draw_bar "$bg_tiles" "$bg_tiles_max" "$WIDTH"
    echo

    bg_maps_max=32768
    printf "BG Maps:         [%5d/%-5d %3d%%] " "$bg_maps" "$bg_maps_max" "$(( bg_maps * 100 / bg_maps_max ))"
    draw_bar "$bg_maps" "$bg_maps_max" "$WIDTH"
    echo

    bg_pal_max=256
    printf "BG Palettes:     [%3d/%-3d %3d%%] " "$bg_pal" "$bg_pal_max" "$(( bg_pal * 100 / bg_pal_max ))"
    draw_bar "$bg_pal" "$bg_pal_max" "$WIDTH"
    echo

    spr_tiles_max=1024
    printf "SPR Tiles:       [%4d/%-4d %3d%%] " "$spr_tiles" "$spr_tiles_max" "$(( spr_tiles * 100 / spr_tiles_max ))"
    draw_bar "$spr_tiles" "$spr_tiles_max" "$WIDTH"
    echo

    spr_pal_max=256
    printf "SPR Palettes:    [%3d/%-3d %3d%%] " "$spr_pal" "$spr_pal_max" "$(( spr_pal * 100 / spr_pal_max ))"
    draw_bar "$spr_pal" "$spr_pal_max" "$WIDTH"
    echo

    echo "==============================================="
done
