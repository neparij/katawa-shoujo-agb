#!/bin/sh

convert_sfx() {
  local input_path="$1"
  local base_name="$2"
  local start_time="$3"
  local end_time="$4"
  local crossfade_duration="$5"

  local wav_name="${base_name}.wav"
  local output_name="${base_name}.8ad"

  echo "Processing \"$output_name\""

  if [[ -n "$start_time" && -n "$end_time" ]]; then
    local duration=$(echo "$end_time - $start_time" | bc)
    local fade_start=$(echo "$duration - $crossfade_duration" | bc)

    if (( $(echo "$crossfade_duration > 0" | bc -l) )); then
      ffmpeg -y -ss "$start_time" -t "$duration" -i "$input_path" -filter_complex \
        "[0]volume=2.5,atrim=0:$duration,asetpts=PTS-STARTPTS[first]; \
         [first]asplit[pre][post]; \
         [pre]atrim=0:$fade_start,asetpts=PTS-STARTPTS[main]; \
         [post]atrim=start=$fade_start,asetpts=PTS-STARTPTS[tail]; \
         [main][tail]acrossfade=d=$crossfade_duration:c1=tri:c2=tri[out]" \
        -map "[out]" -ac 1 -ar 11468 -sample_fmt s16 "$wav_name"
    else
      ffmpeg -y -ss "$start_time" -t "$duration" -i "$input_path" -af "volume=2.5" -ac 1 -ar 11468 -sample_fmt s16 "$wav_name"
    fi
  else
    ffmpeg -y -i "$input_path" -af "volume=2.5" -ac 1 -ar 11468 -sample_fmt s16 "$wav_name"
  fi

  wav28ad "$wav_name" "gbfs_files/$output_name"
  rm -f "$wav_name"
}

### HEAVY sfx parts
echo "Convering \"sfx_fireworks.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/fireworks.ogg sfx_fireworks 0.0 19.0 1.0

echo "Convering \"sfx_rain.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/rain.ogg sfx_rain 0.0 9.5 1.5

echo "Convering \"sfx_emijogging.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/emijogging.ogg sfx_emijogging 0.0 4.0 0.0

echo "Convering \"sfx_emirunning.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/emirunning.ogg sfx_emirunning # dont crop - used as a sound

echo "Convering \"sfx_emipacing.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/emipacing.ogg sfx_emipacing # dont crop - used as a sound

echo "Convering \"sfx_emisprinting.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/emisprinting.ogg sfx_emisprinting # dont crop - used as a sound

echo "Convering \"sfx_crowd_indoors.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/crowd_indoors.ogg sfx_crowd_indoors 0.0 15.5 2.5

echo "Convering \"sfx_crowd_outdoors.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/crowd_outdoors.ogg sfx_crowd_outdoors 0.0 15.5 2.5

echo "Convering \"sfx_crowd_cheer.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/crowd_cheer.ogg sfx_crowd_cheer 0.0 16.0 0.0

echo "Convering \"sfx_cicadas.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/cicadas.ogg sfx_cicadas 0.0 11.0 1.0

echo "Convering \"sfx_traffic.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/traffic.ogg sfx_traffic 0.0 23.0 3.0

echo "Convering \"sfx_shower.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/shower.ogg sfx_shower 0.0 8.5 3.5

echo "Convering \"sfx_stallbuilding.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/stallbuilding.ogg sfx_stallbuilding 0.0 12.5 0.5

echo "Convering \"sfx_parkambience.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/parkambience.ogg sfx_parkambience 0.0 11.0 1.0

echo "Convering \"sfx_rooftop.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/rooftop.ogg sfx_rooftop 0.0 10.0 1.0

echo "Convering \"sfx_businterior.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/businterior.ogg sfx_businterior 0.0 24.0 12.0

#### COMMON sfx parts
echo "Convering \"sfx_alarmclock.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/alarm.ogg sfx_alarmclock

echo "Convering \"sfx_normalbell.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/carillon.ogg sfx_normalbell

echo "Convering \"sfx_warningbell.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/chaimu.ogg sfx_warningbell

echo "Convering \"sfx_crunchydeath.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/crunch.ogg sfx_crunchydeath

echo "Convering \"sfx_rustling.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/rustling.ogg sfx_rustling

echo "Convering \"sfx_impact.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/wumph.ogg sfx_impact

echo "Convering \"sfx_impact2.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/wumph_2.ogg sfx_impact2

echo "Convering \"sfx_heartfast.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/heart_single_fast.ogg sfx_heartfast

echo "Convering \"sfx_heartslow.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/heart_single_slow.ogg sfx_heartslow

echo "Convering \"sfx_heartstop.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/heart_stop.ogg sfx_heartstop

echo "Convering \"sfx_startpistol.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/startpistol.ogg sfx_startpistol

echo "Convering \"sfx_doorknock.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/doorknock.ogg sfx_doorknock

echo "Convering \"sfx_doorknock2.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/doorknock2.ogg sfx_doorknock2

echo "Convering \"sfx_doorslam.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/doorslam.ogg sfx_doorslam

echo "Convering \"sfx_doorclose.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/doorclose.ogg sfx_doorclose

echo "Convering \"sfx_scratch.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/scratch.ogg sfx_scratch

echo "Convering \"sfx_rumble.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/rumble.ogg sfx_rumble

echo "Convering \"sfx_skid.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/skid2.ogg sfx_skid

echo "Convering \"sfx_gymbounce.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/emibounce.ogg sfx_gymbounce

echo "Convering \"sfx_hammer.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/hammer.ogg sfx_hammer

echo "Convering \"sfx_birdstakeoff.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/birdstakeoff.ogg sfx_birdstakeoff

echo "Convering \"sfx_storebell.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/storebell.ogg sfx_storebell

echo "Convering \"sfx_thunder.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/thunder.ogg sfx_thunder

echo "Convering \"sfx_slide.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/slide.ogg sfx_slide

echo "Convering \"sfx_slide2.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/slide2.ogg sfx_slide2

echo "Convering \"sfx_draw.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/sword_draw.ogg sfx_draw

echo "Convering \"sfx_switch.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/switch.ogg sfx_switch

echo "Convering \"sfx_pillow.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/pillow.ogg sfx_pillow

echo "Convering \"sfx_cellphone.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/cellphone.ogg sfx_cellphone

echo "Convering \"sfx_door_creak.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/door_creak.ogg sfx_door_creak

echo "Convering \"sfx_dooropen.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/dooropen.ogg sfx_dooropen

echo "Convering \"sfx_dropglasses.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/dropglasses.ogg sfx_dropglasses

echo "Convering \"sfx_can.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/can.ogg sfx_can

echo "Convering \"sfx_trainint.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/trainint.ogg sfx_trainint

echo "Convering \"sfx_footsteps_hard.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/footsteps_hard.ogg sfx_footsteps_hard

echo "Convering \"sfx_footsteps_soft.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/footsteps_soft.ogg sfx_footsteps_soft

echo "Convering \"sfx_paper.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/paper.ogg sfx_paper

echo "Convering \"sfx_paperruffling.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/paperruffling.ogg sfx_paperruffling

echo "Convering \"sfx_lighter.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/lighter.ogg sfx_lighter

echo "Convering \"sfx_phone.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/phone.ogg sfx_phone

echo "Convering \"sfx_hollowclick.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/hollowclick.ogg sfx_hollowclick

echo "Convering \"sfx_teacup.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/teacup.ogg sfx_teacup

echo "Convering \"sfx_can_clatter.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/can_clatter.ogg sfx_can_clatter

echo "Convering \"sfx_snap.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/snap.ogg sfx_snap

echo "Convering \"sfx_billiards_break.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/billiards_break.ogg sfx_billiards_break

echo "Convering \"sfx_billiards.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/billiards.ogg sfx_billiards

echo "Convering \"sfx_lock.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/lock.ogg sfx_lock

echo "Convering \"sfx_dropstuff.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/dropstuff.ogg sfx_dropstuff

echo "Convering \"sfx_camera.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/camera.ogg sfx_camera

echo "Convering \"sfx_time.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/time.ogg sfx_time

echo "Convering \"sfx_flash.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/flash.ogg sfx_flash

echo "Convering \"sfx_whiteout.8ad\""
convert_sfx /Users/n.laptev/development/ksre/game/sfx/whiteout.ogg sfx_whiteout


# Clean after wav28ad
rm decomp.wav


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