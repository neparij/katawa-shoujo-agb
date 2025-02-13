#!/bin/sh

# Input directory
INPUT_DIR="./#original"
KSRE_PATH="/Users/n.laptev/development/ksre"

# Define an array of input and output filenames
FILES=(
  "4ls::4.25:540"
  "op_1:::608" # either 540 itself (half of fullhd), was 160 and 180
  "tc_act1:::608" 
  "tc_act2_emi:::608" 
  "tc_act2_hanako:::608"
  "tc_act2_lilly:::608"
  "tc_act2_rin:::608"
  "tc_act2_shizune:::608"
)

get_gain_peak() {
    local input_file="$1"
    local max_volume=$(ffmpeg -i "$input_file" -af volumedetect -vn -f null - 2>&1 | \
        grep 'max_volume' | \
        awk -F': ' '{print $2}' | \
        sed 's/-/+/' | sed 's/ //')
    echo "${max_volume}"
}

# Loop through the files and process them
for VID_INFO in "${FILES[@]}"; do
  IFS=":" read -r VIDEO_NAME VIDEO_FROM VIDEO_TO VIDEO_SCALE_Y <<< "$VID_INFO"

  rm -f /tmp/ksre_conv/video/frames/*.bmp
  rm -f /tmp/ksre_conv/video/audio.wav
  rm -f /tmp/ksre_conv/video/agmvcmd.agvs

  mkdir -p /tmp/ksre_conv/video
  mkdir /tmp/ksre_conv/video/frames

  GAIN_PEAK=$(get_gain_peak $KSRE_PATH/game/video/$VIDEO_NAME.mkv)

  if [ $VIDEO_TO ]; then
    ffmpeg -y -i $KSRE_PATH/game/video/$VIDEO_NAME.mkv -t $VIDEO_TO -r 15 -vf scale=-1:$VIDEO_SCALE_Y,crop=810:540 /tmp/ksre_conv/video/frames/frame_%d.bmp
  else
    ffmpeg -y -i $KSRE_PATH/game/video/$VIDEO_NAME.mkv -r 15 -vf scale=-1:$VIDEO_SCALE_Y,crop=810:540 /tmp/ksre_conv/video/frames/frame_%d.bmp
  fi

  ffmpeg -y -i $KSRE_PATH/game/video/$VIDEO_NAME.mkv -af volume=$GAIN_PEAK -vn -ar 13379 -ac 1 -c:a pcm_u8 /tmp/ksre_conv/video/audio.wav
  # wav28ad /tmp/ksre_conv/video/audio.wav gbfs_files/video_$VIDEO_NAME.8ad
  sox --show-progress --replay-gain track --norm "/tmp/ksre_conv/video/audio.wav" -r 13379 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - "gbfs_files/video_$VIDEO_NAME.gsm"

  FRAMES_COUNT=`find /tmp/ksre_conv/video/frames -maxdepth 1 -name "frame_*.bmp" -print | wc -l | xargs`
  # AGMV_OPT_GBA_I   = 0x6,  /* 512   COLORS, BITSTREAM V1, HEAVY PDIFS, REDUCED RES */
  # AGMV_OPT_GBA_II  = 0x7,  /* 256   COLORS, BITSTREAM V2, HEAVY PDIFS, REDUCED RES */
  # AGMV_OPT_GBA_III = 0x8,  /* 512   COLORS, BITSTREAM V2, LIGHT PDIFS, REDUCED RES */
  # AGMV_OPT_GBA_IV  = 0x9,  /* 32768 COLORS, BITSTREAM V1, HEAVY PDIFS, REDUCED RES*/
  echo "\$video ENC video/video_$VIDEO_NAME.agmv /tmp/ksre_conv/video/frames frame_ BMP 1 $FRAMES_COUNT 810 540 15 OPT_GBA_I MID_Q NONE" > /tmp/ksre_conv/video/agmvcmd.agvs
  echo "FRAMES_COUNT = [$FRAMES_COUNT]"
  agmvcli /tmp/ksre_conv/video/agmvcmd.agvs
done
