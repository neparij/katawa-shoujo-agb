#!/usr/bin/env bash

DIR="${1:-.}"
DIR="$(cd "$DIR" && pwd)"
TMP=$(mktemp)

find "$DIR" -type f \( -iname '*.png' -o -iname '*.jpg' -o -iname '*.jpeg' \) \
    -print0 | xargs -0 identify -format "%wx%h %i\n" 2>/dev/null \
    | sed "s|$DIR/|./|" \
    | sort > "$TMP"

awk '
{
    size=$1; $1=""; path=substr($0,2)
    files[size] = files[size] "\n- " path
    counts[size]++
}
END {
    for (s in counts) {
        print s " — " counts[s] " file(s)" files[s] "\n"
    }
}' "$TMP"

rm -f "$TMP"