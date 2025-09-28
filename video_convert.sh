#!/bin/sh

# Input directory
KSGBA_ROOT=$(realpath "./")
KSRE_ROOT=$(realpath "${KSGBA_ROOT}""/../../ksre-2")

# Temporary directory
TMPDIR=$(mktemp -d)

## Ensure cleanup on exit
cleanup() {
  rm -rf "$TMPDIR"
}
trap cleanup EXIT

# Find ulcencodetool (PATH first, then local)
if command -v ulcencodetool >/dev/null 2>&1; then
  ULCENCODETOOL="$(command -v ulcencodetool)"
elif [ -x "./ulcencodetool" ]; then
  ULCENCODETOOL="./ulcencodetool"
else
  echo "Error: ulcencodetool not found in PATH or current directory" >&2
  exit 1
fi

# Find vid2h (PATH first, then local)
if command -v vid2h >/dev/null 2>&1; then
  VID2H="$(command -v vid2h)"
elif [ -x "./vid2h" ]; then
  VID2H="./vid2h"
else
  echo "Error: vid2h not found in PATH or current directory" >&2
  exit 1
fi

FILES=(
  "4ls|1920|1080||4.3|eq=contrast=1.2:brightness=0.05:saturation=1.25|12"
  "op_1|1440|960|||eq=contrast=1.0|8" # TODO: recreate on engine
  "tc_act2_emi|1440|960||60.0|eq=contrast=1.0|10"
  "tc_act2_hanako|1440|960||60.0|eq=contrast=1.0|10"
  "tc_act2_lilly|1440|960||49.0|eq=contrast=1.0|10"
  "tc_act2_rin|1440|960||44.0|eq=contrast=1.0|10"
  "tc_act2_shizune|1440|960||47.0|eq=contrast=1.0|10"
)

AUDIO_ONLY_FILES=(
  "tc_act1"
)

# TODO: Reconvert all videos with proper gain levels
get_gain_peak() {
    local input_file="$1"
    local max_volume=$(ffmpeg -i "$input_file" -af volumedetect -vn -f null - 2>&1 | \
        grep 'max_volume' | \
        awk -F': ' '{print $2}' | \
        sed 's/-/+/' | sed 's/ //')
    echo "${max_volume}"
}

for AUDIO_NAME in "${AUDIO_ONLY_FILES[@]}"; do
  echo "Processing audio only file: ${AUDIO_NAME}"

  # TODO: Reconvert all videos with proper gain levels
  GAIN_PEAK="2.5"
  ffmpeg -y -i "${KSRE_ROOT}/game/video/${AUDIO_NAME}.mkv" -af volume=$GAIN_PEAK -vn -ar 13379 -ac 1 -sample_fmt s16 -acodec pcm_s16le "${TMPDIR}/${AUDIO_NAME}.wav"
  "${ULCENCODETOOL}" "${TMPDIR}/${AUDIO_NAME}.wav" "${KSGBA_ROOT}/gbfs_files/${AUDIO_NAME}.ulc" -75 -blocksize:256
done

# Loop through the files and process them
for VID_INFO in "${FILES[@]}"; do
  IFS="|" read -r VIDEO_NAME CROP_X CROP_Y VIDEO_FROM VIDEO_TO FILTER TARGET_FPS <<< "$VID_INFO"

#  TODO: Add --interactive flag
  if [ $VIDEO_TO ]; then
    ffplay "${KSRE_ROOT}/game/video/${VIDEO_NAME}.mkv" -t $VIDEO_TO -vf "crop=${CROP_X}:${CROP_Y}:(in_w-${CROP_X})/2:(in_h-${CROP_Y})/2,scale=160:128,${FILTER},fps=${TARGET_FPS}"
  else
    ffplay "${KSRE_ROOT}/game/video/${VIDEO_NAME}.mkv" -vf "crop=${CROP_X}:${CROP_Y}:(in_w-${CROP_X})/2:(in_h-${CROP_Y})/2,scale=160:128,${FILTER},fps=${TARGET_FPS}"
  fi

  # If user inputs "Y" or "y", proceed with the conversion
  read -p "Do you want to convert the video to dxtv format? (Y/N): " choice
  if [[ "$choice" != "Y" && "$choice" != "y" ]]; then
    echo "Skipping conversion for ${VIDEO_NAME}."
    continue
  fi

  # TODO: Reconvert all videos with proper gain levels
  #  GAIN_PEAK=$(get_gain_peak $KSRE_PATH/game/video/$VIDEO_NAME.mkv)
  GAIN_PEAK="2.5"

  if [ $VIDEO_TO ]; then
    ffmpeg -y -i "${KSRE_ROOT}/game/video/${VIDEO_NAME}.mkv" -t ${VIDEO_TO} -r ${TARGET_FPS} -vf "crop=${CROP_X}:${CROP_Y}:(in_w-${CROP_X})/2:(in_h-${CROP_Y})/2,scale=160:128,${FILTER}" "${TMPDIR}/${VIDEO_NAME}.mp4"
  else
    ffmpeg -y -i "${KSRE_PATH}/game/video/${VIDEO_NAME}.mkv" -r ${TARGET_FPS} -vf "crop=${CROP_X}:${CROP_Y}:(in_w-${CROP_X})/2:(in_h-${CROP_Y})/2,scale=160:128,${FILTER}" "${TMPDIR}/${VIDEO_NAME}.mp4"
  fi

  ffmpeg -y -i "${KSRE_ROOT}/game/video/${VIDEO_NAME}.mkv" -af volume=${GAIN_PEAK} -vn -ar 13379 -ac 1 -sample_fmt s16 -acodec pcm_s16le "${TMPDIR}/${VIDEO_NAME}.wav"
  "${ULCENCODETOOL}" "${TMPDIR}/${VIDEO_NAME}.wav" "${KSGBA_ROOT}/gbfs_files/video_${VIDEO_NAME}.ulc" -75 -blocksize:256

  "${VID2H}" --truecolor=RGB888 --outformat=BGR555 --dxtv=95 "${TMPDIR}/${VIDEO_NAME}.mp4" "${TMPDIR}/video_${VIDEO_NAME}"
  mv "${TMPDIR}/video_${VIDEO_NAME}.bin" "${KSGBA_ROOT}/video/video_${VIDEO_NAME}.dxtv"
done
