#!/bin/sh
# Optimized

echo "Converting \"video_a_4ls_end.gsm\""
sox --show-progress ./\#original/video_a_4ls_end.wav -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - video_a_4ls_end.gsm

