#!/bin/sh

# Input directory
INPUT_DIR="./#original"
KSRE_PATH="/Users/n.laptev/development/ksre"

# Define an array of input and output filenames
## TODO: Check the filter options later
#FILES=(
#  "4ls|1920|1080||4.3|eq=contrast=1.2:brightness=0.05:saturation=1.25|12"
#  "op_1|1440|960|||eq=contrast=1.4:brightness=-0.05:saturation=1.2|8"
#  "tc_act1|1440|960|||eq=contrast=1.0|10"
#  "tc_act2_emi|1440|960|||eq=contrast=1.4:brightness=-0.05:saturation=1.2|10"
#  "tc_act2_hanako|1440|960|||eq=contrast=1.1:saturation=1.2|10"
#  "tc_act2_lilly|1440|960|||eq=contrast=1.4:brightness=-0.05:saturation=1.2|10"
#  "tc_act2_rin|1440|960|||eq=contrast=1.4:brightness=-0.05:saturation=1.2|10"
#  "tc_act2_shizune|1440|960|||eq=contrast=1.4:brightness=-0.05:saturation=1.2|10"
#)

FILES=(
#  "4ls|1920|1080||4.3|eq=contrast=1.2:brightness=0.05:saturation=1.25|12"
#  "op_1|1440|960|||eq=contrast=1.4:brightness=-0.05:saturation=1.2|8"
#  "tc_act2_emi|1440|960||60.0|eq=contrast=1.0|10"
#  "tc_act2_hanako|1440|960||60.0|eq=contrast=1.0|10"
  "tc_act2_lilly|1440|960||49.0|eq=contrast=1.0|10"
  "tc_act2_rin|1440|960||44.0|eq=contrast=1.0|10"
  "tc_act2_shizune|1440|960||47.0|eq=contrast=1.0|10"
)

AUDIO_ONLY_FILES=(
  "tc_act1"
)

get_gain_peak() {
    local input_file="$1"
    local max_volume=$(ffmpeg -i "$input_file" -af volumedetect -vn -f null - 2>&1 | \
        grep 'max_volume' | \
        awk -F': ' '{print $2}' | \
        sed 's/-/+/' | sed 's/ //')
    echo "${max_volume}"
}

mkdir -p /tmp/ksre_conv/video

for AUDIO_NAME in "${AUDIO_ONLY_FILES[@]}"; do
  echo "Processing audio only file: $AUDIO_NAME"

  GAIN_PEAK="2.5"
  ffmpeg -y -i $KSRE_PATH/game/video/${AUDIO_NAME}.mkv -af volume=$GAIN_PEAK -vn -ar 13379 -ac 1 -sample_fmt s16 -acodec pcm_s16le /tmp/ksre_conv/video/${AUDIO_NAME}.wav
  ./ulcencodetool "/tmp/ksre_conv/video/${AUDIO_NAME}.wav" "gbfs_files/${AUDIO_NAME}.ulc" -75 -blocksize:256
done

# Loop through the files and process them
for VID_INFO in "${FILES[@]}"; do
  IFS="|" read -r VIDEO_NAME CROP_X CROP_Y VIDEO_FROM VIDEO_TO FILTER TARGET_FPS <<< "$VID_INFO"

#  TODO: Add --interactive flag
  if [ $VIDEO_TO ]; then
    ffplay $KSRE_PATH/game/video/$VIDEO_NAME.mkv -t $VIDEO_TO -vf "crop=${CROP_X}:${CROP_Y}:(in_w-${CROP_X})/2:(in_h-${CROP_Y})/2,scale=160:128,${FILTER},fps=${TARGET_FPS}"
  else
    ffplay $KSRE_PATH/game/video/$VIDEO_NAME.mkv -vf "crop=${CROP_X}:${CROP_Y}:(in_w-${CROP_X})/2:(in_h-${CROP_Y})/2,scale=160:128,${FILTER},fps=${TARGET_FPS}"
  fi

  # If user inputs "Y" or "y", proceed with the conversion
  read -p "Do you want to convert the video to dxtv format? (Y/N): " choice
  if [[ "$choice" != "Y" && "$choice" != "y" ]]; then
    echo "Skipping conversion for $VIDEO_NAME."
    continue
  fi

#  TODO: Decide with gain levels
#  GAIN_PEAK=$(get_gain_peak $KSRE_PATH/game/video/$VIDEO_NAME.mkv)
  GAIN_PEAK="2.5"

  if [ $VIDEO_TO ]; then
    ffmpeg -y -i ${KSRE_PATH}/game/video/${VIDEO_NAME}.mkv -t $VIDEO_TO -r ${TARGET_FPS} -vf "crop=${CROP_X}:${CROP_Y}:(in_w-${CROP_X})/2:(in_h-${CROP_Y})/2,scale=160:128,${FILTER}" /tmp/ksre_conv/video/${VIDEO_NAME}.mp4
  else
    ffmpeg -y -i ${KSRE_PATH}/game/video/${VIDEO_NAME}.mkv -r ${TARGET_FPS} -vf "crop=${CROP_X}:${CROP_Y}:(in_w-${CROP_X})/2:(in_h-${CROP_Y})/2,scale=160:128,${FILTER}" /tmp/ksre_conv/video/${VIDEO_NAME}.mp4
  fi

  ffmpeg -y -i $KSRE_PATH/game/video/$VIDEO_NAME.mkv -af volume=$GAIN_PEAK -vn -ar 13379 -ac 1 -sample_fmt s16 -acodec pcm_s16le /tmp/ksre_conv/video/${VIDEO_NAME}.wav
  ./ulcencodetool "/tmp/ksre_conv/video/${VIDEO_NAME}.wav" "gbfs_files/video_${VIDEO_NAME}.ulc" -75 -blocksize:256

# TODO: use vid2h from PATH (Currently it need to be compiled by yourself and placed in the same directory)
  ./vid2h --truecolor=RGB888 --outformat=BGR555 --dxtv=95 /tmp/ksre_conv/video/${VIDEO_NAME}.mp4 video/video_${VIDEO_NAME}
  mv video/video_${VIDEO_NAME}.bin video/video_${VIDEO_NAME}.dxtv
done
