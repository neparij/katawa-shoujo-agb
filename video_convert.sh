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

#FILES=(
##  "4ls|1920|1080||4.3|eq=brightness=0.2:contrast=2.0:saturation=1.00|15"
##  "4ls|1920|1080||4.3|eq=brightness=0.0:contrast=1.60|15"
##  "4ls|1920|1080||1.5|eq=contrast=1.0|15"
##  "tc_act2_emi|1440|960||60.0|eq=contrast=1.0|12"
##  "tc_act2_hanako|1440|960||60.0|eq=contrast=1.0|12"
##  "tc_act2_lilly|1440|960||49.0|eq=contrast=1.0|12"
##  "tc_act2_rin|1440|960||44.0|eq=contrast=1.0|12"
##  "tc_act2_rin|1440|960||44.0|eq=contrast=1.10:saturation=1.30|12"
##  "tc_act2_rin|1440|960||15.0|eq=contrast=1.0|12"
##  "tc_act2_shizune|1440|960||47.0|eq=contrast=1.0|12"
#)


### Use Contrast 1.10, Saturation 1.30 (Vibrant)
#FILES=(
# "4ls|1920|1080||4.3|eq=brightness=0.2:contrast=2.0:saturation=1.00|15"
# "tc_act2_emi|1440|960||60.0|eq=contrast=1.10:saturation=1.30|12"
# "tc_act2_hanako|1440|960||60.0|eq=contrast=1.10:saturation=1.30|12"
# "tc_act2_lilly|1440|960||49.0|eq=contrast=1.10:saturation=1.30|12"
# "tc_act2_rin|1440|960||44.0|eq=contrast=1.10:saturation=1.30|12"
# "tc_act2_shizune|1440|960||47.0|eq=contrast=1.10:saturation=1.30|12"
#)

## Use Contrast 1.10, Saturation 1.30 (Vibrant)
## Reduced FPS
FILES=(
 "4ls|1920|1080||4.3|eq=brightness=0.2:contrast=2.0:saturation=1.00|12"
 "tc_act2_emi|1440|960||60.0|eq=contrast=1.10:saturation=1.30|10"
 "tc_act2_hanako|1440|960||60.0|eq=contrast=1.10:saturation=1.30|10"
 "tc_act2_lilly|1440|960||49.0|eq=contrast=1.10:saturation=1.30|10"
 "tc_act2_rin|1440|960||44.0|eq=contrast=1.10:saturation=1.30|10"
 "tc_act2_shizune|1440|960||47.0|eq=contrast=1.10:saturation=1.30|10"
)

# Locate python interpreter for the ulcv encoder / decoder.
if command -v python3 >/dev/null 2>&1; then
  PYTHON="python3"
elif command -v python >/dev/null 2>&1; then
  PYTHON="python"
else
  echo "Error: python3 not found in PATH" >&2
  exit 1
fi

ULCV_ENCODE="${KSGBA_ROOT}/ulcv/src/encoder.py"
ULCV_DECODE="${KSGBA_ROOT}/ulcv/src/decoder.py"
for f in "${ULCV_ENCODE}" "${ULCV_DECODE}"; do
  if [ ! -f "${f}" ]; then
    echo "Error: required script not found: ${f}" >&2
    exit 1
  fi
done

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

  # TODO: Reconvert all videos with proper gain levels
  #  GAIN_PEAK=$(get_gain_peak $KSRE_PATH/game/video/$VIDEO_NAME.mkv)
  GAIN_PEAK="2.5"

  ffmpeg -y -i "${KSRE_ROOT}/game/video/${VIDEO_NAME}.mkv" -af volume=${GAIN_PEAK} -vn -ar 13379 -ac 1 -sample_fmt s16 -acodec pcm_s16le "${TMPDIR}/${VIDEO_NAME}.wav"
  "${ULCENCODETOOL}" "${TMPDIR}/${VIDEO_NAME}.wav" "${KSGBA_ROOT}/gbfs_files/video_${VIDEO_NAME}.ulc" -75 -blocksize:256

  ULCV_FILE="${KSGBA_ROOT}/video/video_${VIDEO_NAME}.ulcv"
#
#  ENCODE_ARGS=(
#    --input "${KSRE_ROOT}/game/video/${VIDEO_NAME}.mkv"
#    --output "${ULCV_FILE}"
#    --fps "${TARGET_FPS}"
#    --crop-x "${CROP_X}"
#    --crop-y "${CROP_Y}"
#    --filter "${FILTER}"
#    --denoise "hqdn3d=6:5:0:0"
#    --quality "95"
#    --motion-compensation-quality "90"
#    --col-vs-dxt-ratio "1.0"
#    --dxt-lite-ratio "2.5"
#    --mc-range "8"
#    --frame-compression "gba-lz77,lz4hc"
#  )


#  # MSE+DC+Y_ERR KERNEL SETTINGS:
#  ENCODE_ARGS=(
#    --input "${KSRE_ROOT}/game/video/${VIDEO_NAME}.mkv"
#    --output "${ULCV_FILE}"
#    --fps "${TARGET_FPS}"
#    --crop-x "${CROP_X}"
#    --crop-y "${CROP_Y}"
#    --filter "${FILTER}"
#    --denoise "hqdn3d=6:5:0:0"
#    --quality "92"
#    --motion-compensation-quality "92"
#    --col-compensation-quality "98"
#    --mc-range "8"
##    --disable_col8
##    --disable_col4
##    --disable_mc_curr
#    --frame-compression "gba-lz77,lz4hc"
#  )

  # LATEST ENCODER V6
  ENCODE_ARGS=(
    --input "${KSRE_ROOT}/game/video/${VIDEO_NAME}.mkv"
    --output "${ULCV_FILE}"
    --fps "${TARGET_FPS}"
    --crop-x "${CROP_X}"
    --crop-y "${CROP_Y}"
    --filter "${FILTER}"
    --denoise "hqdn3d=6:5:0:0"
    --quality "90"
    --motion-compensation-quality "89"
    --col-compensation-quality "98"
    --frame-compression "gba-lz77,lz4hc"
    --visualize # I wanna see.
  )

  if [ -n "${VIDEO_TO}" ]; then
    ENCODE_ARGS+=(--video-to "${VIDEO_TO}")
  fi

  "${PYTHON}" "${ULCV_ENCODE}" "${ENCODE_ARGS[@]}"
done
