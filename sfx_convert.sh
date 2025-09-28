#!/bin/sh

# Input directory
KSGBA_ROOT=$(realpath "./")
KSRE_ROOT=$(realpath "${KSGBA_ROOT}""/../../ksre-2")

# Temporary directory
TMPDIR=$(mktemp -d)

## Ensure cleanup on exit
cleanup() {
  rm -rf "$TMPDIR"
  rm decomp.wav # Clean after wav28ad
}
trap cleanup EXIT

# Find wav28ad (PATH first, then local)
if command -v wav28ad >/dev/null 2>&1; then
  WAV28AD="$(command -v wav28ad)"
elif [ -x "./wav28ad" ]; then
  WAV28AD="./wav28ad"
else
  echo "Error: wav28ad not found in PATH or current directory" >&2
  exit 1
fi

convert_sfx() {
  local input_name="$1"
  local base_name="$2"
  local start_time="$3"
  local end_time="$4"
  local crossfade_duration="$5"

  local input_path="${KSRE_ROOT}/game/sfx/${input_name}.ogg"
  local wav_name="${base_name}.wav"
  local output_name="${base_name}.8ad"

  echo "Converting \"${input_path}\" to \"${KSGBA_ROOT}/gbfs_files/${output_name}\""

  if [[ -n "$start_time" && -n "$end_time" ]]; then
    local duration=$(echo "$end_time - $start_time" | bc)
    local fade_start=$(echo "$duration - $crossfade_duration" | bc)

    if (( $(echo "$crossfade_duration > 0" | bc -l) )); then
      ffmpeg -y -ss "$start_time" -t "$duration" -i "${input_path}" \
       -hide_banner -loglevel error \
       -filter_complex "[0]volume=2.5,atrim=0:$duration,asetpts=PTS-STARTPTS[first]; \
         [first]asplit[pre][post]; \
         [pre]atrim=0:$fade_start,asetpts=PTS-STARTPTS[main]; \
         [post]atrim=start=$fade_start,asetpts=PTS-STARTPTS[tail]; \
         [main][tail]acrossfade=d=$crossfade_duration:c1=tri:c2=tri[out]" \
        -map "[out]" -ac 1 -ar 11468 -sample_fmt s16 "${TMPDIR}/${wav_name}"
    else
      ffmpeg -y -ss "$start_time" -t "$duration" -i "${input_path}" \
        -hide_banner -loglevel error \
        -af "volume=2.5" -ac 1 -ar 11468 -sample_fmt s16 "${TMPDIR}/${wav_name}"
    fi
  else
    ffmpeg -y -i "${input_path}" \
      -hide_banner -loglevel error \
      -af "volume=2.5" -ac 1 -ar 11468 -sample_fmt s16 "${TMPDIR}/${wav_name}"
  fi

  "${WAV28AD}" "${TMPDIR}/${wav_name}" "${KSGBA_ROOT}/gbfs_files/${output_name}"
}

### HEAVY sfx parts
convert_sfx fireworks sfx_fireworks 0.0 19.0 1.0
convert_sfx rain sfx_rain 0.0 9.5 1.5
convert_sfx emijogging sfx_emijogging 0.0 4.0 0.0
convert_sfx emirunning sfx_emirunning # dont crop - used as a sound
convert_sfx emipacing sfx_emipacing # dont crop - used as a sound
convert_sfx emisprinting sfx_emisprinting # dont crop - used as a sound
convert_sfx crowd_indoors sfx_crowd_indoors 0.0 15.5 2.5
convert_sfx crowd_outdoors sfx_crowd_outdoors 0.0 15.5 2.5
convert_sfx crowd_cheer sfx_crowd_cheer 0.0 16.0 0.0
convert_sfx cicadas sfx_cicadas 0.0 11.0 1.0
convert_sfx traffic sfx_traffic 0.0 23.0 3.0
convert_sfx shower sfx_shower 0.0 8.5 3.5
convert_sfx stallbuilding sfx_stallbuilding 0.0 12.5 0.5
convert_sfx parkambience sfx_parkambience 0.0 11.0 1.0
convert_sfx rooftop sfx_rooftop 0.0 10.0 1.0
convert_sfx businterior sfx_businterior 0.0 24.0 12.0

#### COMMON sfx parts
convert_sfx alarm sfx_alarmclock
convert_sfx carillon sfx_normalbell
convert_sfx chaimu sfx_warningbell
convert_sfx crunch sfx_crunchydeath
convert_sfx rustling sfx_rustling
convert_sfx wumph sfx_impact
convert_sfx wumph_2 sfx_impact2
convert_sfx heart_single_fast sfx_heartfast
convert_sfx heart_single_slow sfx_heartslow
convert_sfx heart_stop sfx_heartstop
convert_sfx startpistol sfx_startpistol
convert_sfx doorknock sfx_doorknock
convert_sfx doorknock2 sfx_doorknock2
convert_sfx doorslam sfx_doorslam
convert_sfx doorclose sfx_doorclose
convert_sfx scratch sfx_scratch
convert_sfx rumble sfx_rumble
convert_sfx skid2 sfx_skid
convert_sfx emibounce sfx_gymbounce
convert_sfx hammer sfx_hammer
convert_sfx birdstakeoff sfx_birdstakeoff
convert_sfx storebell sfx_storebell
convert_sfx thunder sfx_thunder
convert_sfx slide sfx_slide
convert_sfx slide2 sfx_slide2
convert_sfx sword_draw sfx_draw
convert_sfx switch sfx_switch
convert_sfx pillow sfx_pillow
convert_sfx cellphone sfx_cellphone
convert_sfx door_creak sfx_door_creak
convert_sfx dooropen sfx_dooropen
convert_sfx dropglasses sfx_dropglasses
convert_sfx can sfx_can
convert_sfx trainint sfx_trainint
convert_sfx footsteps_hard sfx_footsteps_hard
convert_sfx footsteps_soft sfx_footsteps_soft
convert_sfx paper sfx_paper
convert_sfx paperruffling sfx_paperruffling
convert_sfx lighter sfx_lighter
convert_sfx phone sfx_phone
convert_sfx hollowclick sfx_hollowclick
convert_sfx teacup sfx_teacup
convert_sfx can_clatter sfx_can_clatter
convert_sfx snap sfx_snap
convert_sfx billiards_break sfx_billiards_break
convert_sfx billiards sfx_billiards
convert_sfx lock sfx_lock
convert_sfx dropstuff sfx_dropstuff
convert_sfx camera sfx_camera
convert_sfx time sfx_time
convert_sfx flash sfx_flash
convert_sfx whiteout sfx_whiteout


# List of sfx used as ambients:
# sfx_cicadas
# sfx_crowd_outdoors
# sfx_fireworks
# sfx_rooftop
# sfx_crowd_indoors
# sfx_parkambience
# sfx_traffic
# sfx_emisprinting
# sfx_heartslow
# sfx_alarmclock
# sfx_shower
# sfx_emirunning
# sfx_emijogging
# sfx_emipacing
# sfx_rain
# sfx_paperruffling
# sfx_footsteps_hard
# sfx_stallbuilding
# sfx_businterior
# sfx_footsteps_soft
# sfx_trainint