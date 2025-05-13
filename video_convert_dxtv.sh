#!/bin/sh

# Input directory
INPUT_DIR="./#original"
KSRE_PATH="/Users/n.laptev/development/ksre"

# Define an array of input and output filenames
FILES=(
  "4ls:1920:1080::4.25"
#  "op_1:1440:960::"
#  "tc_act1:1440:960::"
  "tc_act2_emi:1440:960::"
  "tc_act2_hanako:1440:960::"
  "tc_act2_lilly:1440:960::"
  "tc_act2_rin:1440:960::"
  "tc_act2_shizune:1440:960::"
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
  IFS=":" read -r VIDEO_NAME CROP_X CROP_Y VIDEO_FROM VIDEO_TO <<< "$VID_INFO"

  mkdir -p /tmp/ksre_conv/video
  GAIN_PEAK=$(get_gain_peak $KSRE_PATH/game/video/$VIDEO_NAME.mkv)

  if [ $VIDEO_TO ]; then
    ffmpeg -y -i ${KSRE_PATH}/game/video/${VIDEO_NAME}.mkv -t $VIDEO_TO -r 10 -filter:v "crop=${CROP_X}:${CROP_Y}:(in_w-${CROP_X})/2:(in_h-${CROP_Y})/2,scale=160:128" /tmp/ksre_conv/video/${VIDEO_NAME}.mp4
  else
    ffmpeg -y -i ${KSRE_PATH}/game/video/${VIDEO_NAME}.mkv -r 10 -filter:v "crop=${CROP_X}:${CROP_Y}:(in_w-${CROP_X})/2:(in_h-${CROP_Y})/2,scale=160:128" /tmp/ksre_conv/video/${VIDEO_NAME}.mp4
  fi

  ffmpeg -y -i $KSRE_PATH/game/video/$VIDEO_NAME.mkv -af volume=$GAIN_PEAK -vn -ar 13379 -ac 1 -c:a pcm_u8 /tmp/ksre_conv/video/${VIDEO_NAME}.wav
  sox --show-progress --replay-gain track --norm "/tmp/ksre_conv/video/${VIDEO_NAME}.wav" -r 13379 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - "gbfs_files/video_${VIDEO_NAME}.gsm"

#  ./vid2h --truecolor=RGB888 --outformat=BGR555 --dxtv=95 --lz10 /tmp/ksre_conv/video/${VIDEO_NAME}.mp4 video_dxtv/dxtv_${VIDEO_NAME}
  ./vid2h --truecolor=RGB888 --outformat=BGR555 --dxtv=95 /tmp/ksre_conv/video/${VIDEO_NAME}.mp4 video_dxtv/dxtv_${VIDEO_NAME}
done
