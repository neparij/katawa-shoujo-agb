#!/bin/sh

#### HEAVY sfx parts
echo "Convering \"sfx_tcard.pcm\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/tcard.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_tcard.wav
wav28ad sfx_tcard.wav sfx_tcard.8ad
rm sfx_tcard.wav

echo "Convering \"sfx_fireworks.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/fireworks.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_fireworks.wav
wav28ad sfx_fireworks.wav sfx_fireworks.8ad
rm sfx_fireworks.wav

echo "Convering \"sfx_rain.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/rain.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_rain.wav
wav28ad sfx_rain.wav sfx_rain.8ad
rm sfx_rain.wav

echo "Convering \"sfx_emijogging.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/emijogging.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_emijogging.wav
wav28ad sfx_emijogging.wav sfx_emijogging.8ad
rm sfx_emijogging.wav

echo "Convering \"sfx_emirunning.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/emirunning.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_emirunning.wav
wav28ad sfx_emirunning.wav sfx_emirunning.8ad
rm sfx_emirunning.wav

echo "Convering \"sfx_emipacing.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/emipacing.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_emipacing.wav
wav28ad sfx_emipacing.wav sfx_emipacing.8ad
rm sfx_emipacing.wav

echo "Convering \"sfx_emisprinting.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/emisprinting.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_emisprinting.wav
wav28ad sfx_emisprinting.wav sfx_emisprinting.8ad
rm sfx_emisprinting.wav

echo "Convering \"sfx_crowd_indoors.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/crowd_indoors.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_crowd_indoors.wav
wav28ad sfx_crowd_indoors.wav sfx_crowd_indoors.8ad
rm sfx_crowd_indoors.wav

echo "Convering \"sfx_crowd_outdoors.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/crowd_outdoors.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_crowd_outdoors.wav
wav28ad sfx_crowd_outdoors.wav sfx_crowd_outdoors.8ad
rm sfx_crowd_outdoors.wav

echo "Convering \"sfx_crowd_cheer.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/crowd_cheer.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_crowd_cheer.wav
wav28ad sfx_crowd_cheer.wav sfx_crowd_cheer.8ad
rm sfx_crowd_cheer.wav

echo "Convering \"sfx_cicadas.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/cicadas.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_cicadas.wav
wav28ad sfx_cicadas.wav sfx_cicadas.8ad
rm sfx_cicadas.wav

echo "Convering \"sfx_traffic.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/traffic.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_traffic.wav
wav28ad sfx_traffic.wav sfx_traffic.8ad
rm sfx_traffic.wav

echo "Convering \"sfx_shower.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/shower.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_shower.wav
wav28ad sfx_shower.wav sfx_shower.8ad
rm sfx_shower.wav

echo "Convering \"sfx_stallbuilding.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/stallbuilding.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_stallbuilding.wav
wav28ad sfx_stallbuilding.wav sfx_stallbuilding.8ad
rm sfx_stallbuilding.wav

echo "Convering \"sfx_parkambience.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/parkambience.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_parkambience.wav
wav28ad sfx_parkambience.wav sfx_parkambience.8ad
rm sfx_parkambience.wav

echo "Convering \"sfx_rooftop.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/rooftop.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_rooftop.wav
wav28ad sfx_rooftop.wav sfx_rooftop.8ad
rm sfx_rooftop.wav

echo "Convering \"sfx_businterior.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/businterior.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_businterior.wav
wav28ad sfx_businterior.wav sfx_businterior.8ad
rm sfx_businterior.wav


#### COMMON sfx parts
echo "Convering \"sfx_alarmclock.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/alarm.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_alarmclock.wav
wav28ad sfx_alarmclock.wav sfx_alarmclock.8ad
rm sfx_alarmclock.wav

echo "Convering \"sfx_normalbell.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/carillon.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_normalbell.wav
wav28ad sfx_normalbell.wav sfx_normalbell.8ad
rm sfx_normalbell.wav

echo "Convering \"sfx_warningbell.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/chaimu.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_warningbell.wav
wav28ad sfx_warningbell.wav sfx_warningbell.8ad
rm sfx_warningbell.wav

echo "Convering \"sfx_crunchydeath.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/crunch.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_crunchydeath.wav
wav28ad sfx_crunchydeath.wav sfx_crunchydeath.8ad
rm sfx_crunchydeath.wav

echo "Convering \"sfx_rustling.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/rustling.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_rustling.wav
wav28ad sfx_rustling.wav sfx_rustling.8ad
rm sfx_rustling.wav

echo "Convering \"sfx_impact.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/wumph.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_impact.wav
wav28ad sfx_impact.wav sfx_impact.8ad
rm sfx_impact.wav

echo "Convering \"sfx_impact2.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/wumph_2.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_impact2.wav
wav28ad sfx_impact2.wav sfx_impact2.8ad
rm sfx_impact2.wav

echo "Convering \"sfx_heartfast.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/heart_single_fast.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_heartfast.wav
wav28ad sfx_heartfast.wav sfx_heartfast.8ad
rm sfx_heartfast.wav

echo "Convering \"sfx_heartslow.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/heart_single_slow.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_heartslow.wav
wav28ad sfx_heartslow.wav sfx_heartslow.8ad
rm sfx_heartslow.wav

echo "Convering \"sfx_heartstop.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/heart_stop.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_heartstop.wav
wav28ad sfx_heartstop.wav sfx_heartstop.8ad
rm sfx_heartstop.wav

echo "Convering \"sfx_startpistol.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/startpistol.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_startpistol.wav
wav28ad sfx_startpistol.wav sfx_startpistol.8ad
rm sfx_startpistol.wav

echo "Convering \"sfx_doorknock.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/doorknock.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_doorknock.wav
wav28ad sfx_doorknock.wav sfx_doorknock.8ad
rm sfx_doorknock.wav

echo "Convering \"sfx_doorknock2.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/doorknock2.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_doorknock2.wav
wav28ad sfx_doorknock2.wav sfx_doorknock2.8ad
rm sfx_doorknock2.wav

echo "Convering \"sfx_doorslam.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/doorslam.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_doorslam.wav
wav28ad sfx_doorslam.wav sfx_doorslam.8ad
rm sfx_doorslam.wav

echo "Convering \"sfx_doorclose.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/doorclose.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_doorclose.wav
wav28ad sfx_doorclose.wav sfx_doorclose.8ad
rm sfx_doorclose.wav

echo "Convering \"sfx_scratch.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/scratch.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_scratch.wav
wav28ad sfx_scratch.wav sfx_scratch.8ad
rm sfx_scratch.wav

echo "Convering \"sfx_rumble.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/rumble.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_rumble.wav
wav28ad sfx_rumble.wav sfx_rumble.8ad
rm sfx_rumble.wav

echo "Convering \"sfx_skid.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/skid2.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_skid.wav
wav28ad sfx_skid.wav sfx_skid.8ad
rm sfx_skid.wav

echo "Convering \"sfx_gymbounce.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/emibounce.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_gymbounce.wav
wav28ad sfx_gymbounce.wav sfx_gymbounce.8ad
rm sfx_gymbounce.wav

echo "Convering \"sfx_hammer.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/hammer.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_hammer.wav
wav28ad sfx_hammer.wav sfx_hammer.8ad
rm sfx_hammer.wav

echo "Convering \"sfx_birdstakeoff.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/birdstakeoff.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_birdstakeoff.wav
wav28ad sfx_birdstakeoff.wav sfx_birdstakeoff.8ad
rm sfx_birdstakeoff.wav

echo "Convering \"sfx_storebell.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/storebell.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_storebell.wav
wav28ad sfx_storebell.wav sfx_storebell.8ad
rm sfx_storebell.wav

echo "Convering \"sfx_thunder.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/thunder.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_thunder.wav
wav28ad sfx_thunder.wav sfx_thunder.8ad
rm sfx_thunder.wav

echo "Convering \"sfx_slide.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/slide.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_slide.wav
wav28ad sfx_slide.wav sfx_slide.8ad
rm sfx_slide.wav

echo "Convering \"sfx_slide2.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/slide2.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_slide2.wav
wav28ad sfx_slide2.wav sfx_slide2.8ad
rm sfx_slide2.wav

echo "Convering \"sfx_draw.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/sword_draw.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_draw.wav
wav28ad sfx_draw.wav sfx_draw.8ad
rm sfx_draw.wav

echo "Convering \"sfx_switch.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/switch.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_switch.wav
wav28ad sfx_switch.wav sfx_switch.8ad
rm sfx_switch.wav

echo "Convering \"sfx_pillow.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/pillow.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_pillow.wav
wav28ad sfx_pillow.wav sfx_pillow.8ad
rm sfx_pillow.wav

echo "Convering \"sfx_cellphone.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/cellphone.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_cellphone.wav
wav28ad sfx_cellphone.wav sfx_cellphone.8ad
rm sfx_cellphone.wav

echo "Convering \"sfx_door_creak.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/door_creak.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_door_creak.wav
wav28ad sfx_door_creak.wav sfx_door_creak.8ad
rm sfx_door_creak.wav

echo "Convering \"sfx_dooropen.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/dooropen.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_dooropen.wav
wav28ad sfx_dooropen.wav sfx_dooropen.8ad
rm sfx_dooropen.wav

echo "Convering \"sfx_dropglasses.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/dropglasses.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_dropglasses.wav
wav28ad sfx_dropglasses.wav sfx_dropglasses.8ad
rm sfx_dropglasses.wav

echo "Convering \"sfx_can.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/can.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_can.wav
wav28ad sfx_can.wav sfx_can.8ad
rm sfx_can.wav

echo "Convering \"sfx_trainint.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/trainint.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_trainint.wav
wav28ad sfx_trainint.wav sfx_trainint.8ad
rm sfx_trainint.wav

echo "Convering \"sfx_footsteps_hard.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/footsteps_hard.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_footsteps_hard.wav
wav28ad sfx_footsteps_hard.wav sfx_footsteps_hard.8ad
rm sfx_footsteps_hard.wav

echo "Convering \"sfx_footsteps_soft.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/footsteps_soft.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_footsteps_soft.wav
wav28ad sfx_footsteps_soft.wav sfx_footsteps_soft.8ad
rm sfx_footsteps_soft.wav

echo "Convering \"sfx_paper.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/paper.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_paper.wav
wav28ad sfx_paper.wav sfx_paper.8ad
rm sfx_paper.wav

echo "Convering \"sfx_paperruffling.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/paperruffling.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_paperruffling.wav
wav28ad sfx_paperruffling.wav sfx_paperruffling.8ad
rm sfx_paperruffling.wav

echo "Convering \"sfx_lighter.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/lighter.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_lighter.wav
wav28ad sfx_lighter.wav sfx_lighter.8ad
rm sfx_lighter.wav

echo "Convering \"sfx_phone.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/phone.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_phone.wav
wav28ad sfx_phone.wav sfx_phone.8ad
rm sfx_phone.wav

echo "Convering \"sfx_hollowclick.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/hollowclick.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_hollowclick.wav
wav28ad sfx_hollowclick.wav sfx_hollowclick.8ad
rm sfx_hollowclick.wav

echo "Convering \"sfx_teacup.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/teacup.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_teacup.wav
wav28ad sfx_teacup.wav sfx_teacup.8ad
rm sfx_teacup.wav

echo "Convering \"sfx_can_clatter.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/can_clatter.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_can_clatter.wav
wav28ad sfx_can_clatter.wav sfx_can_clatter.8ad
rm sfx_can_clatter.wav

echo "Convering \"sfx_snap.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/snap.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_snap.wav
wav28ad sfx_snap.wav sfx_snap.8ad
rm sfx_snap.wav

echo "Convering \"sfx_billiards_break.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/billiards_break.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_billiards_break.wav
wav28ad sfx_billiards_break.wav sfx_billiards_break.8ad
rm sfx_billiards_break.wav

echo "Convering \"sfx_billiards.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/billiards.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_billiards.wav
wav28ad sfx_billiards.wav sfx_billiards.8ad
rm sfx_billiards.wav

echo "Convering \"sfx_lock.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/lock.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_lock.wav
wav28ad sfx_lock.wav sfx_lock.8ad
rm sfx_lock.wav

echo "Convering \"sfx_dropstuff.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/dropstuff.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_dropstuff.wav
wav28ad sfx_dropstuff.wav sfx_dropstuff.8ad
rm sfx_dropstuff.wav

echo "Convering \"sfx_camera.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/camera.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_camera.wav
wav28ad sfx_camera.wav sfx_camera.8ad
rm sfx_camera.wav


echo "Convering \"sfx_time.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/time.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_time.wav
wav28ad sfx_time.wav sfx_time.8ad
rm sfx_time.wav

echo "Convering \"sfx_flash.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/flash.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_flash.wav
wav28ad sfx_flash.wav sfx_flash.8ad
rm sfx_flash.wav

echo "Convering \"sfx_whiteout.8ad\""
ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/whiteout.ogg -ac 1 -ar 11468 -sample_fmt s16 sfx_whiteout.wav
wav28ad sfx_whiteout.wav sfx_whiteout.8ad
rm sfx_whiteout.wav

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

# TODO: decide which of them can be used as GSM (music and ambient should not play simulantuosly)


# #!/bin/sh

# #### HEAVY sfx parts
# echo "Convering \"sfx_tcard.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/tcard.ogg -ac 1 -ar 6689 -f s8 sfx_tcard.pcm

# echo "Convering \"sfx_fireworks.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/fireworks.ogg -ac 1 -ar 6689 -f s8 sfx_fireworks.pcm

# echo "Convering \"sfx_rain.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/rain.ogg -ac 1 -ar 6689 -f s8 sfx_rain.pcm

# echo "Convering \"sfx_emijogging.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/emijogging.ogg -ac 1 -ar 6689 -f s8 sfx_emijogging.pcm

# echo "Convering \"sfx_emirunning.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/emirunning.ogg -ac 1 -ar 6689 -f s8 sfx_emirunning.pcm

# echo "Convering \"sfx_emipacing.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/emipacing.ogg -ac 1 -ar 6689 -f s8 sfx_emipacing.pcm

# echo "Convering \"sfx_emisprinting.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/emisprinting.ogg -ac 1 -ar 6689 -f s8 sfx_emisprinting.pcm

# echo "Convering \"sfx_crowd_indoors.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/crowd_indoors.ogg -ac 1 -ar 6689 -f s8 sfx_crowd_indoors.pcm

# echo "Convering \"sfx_crowd_outdoors.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/crowd_outdoors.ogg -ac 1 -ar 6689 -f s8 sfx_crowd_outdoors.pcm

# echo "Convering \"sfx_crowd_cheer.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/crowd_cheer.ogg -ac 1 -ar 6689 -f s8 sfx_crowd_cheer.pcm

# echo "Convering \"sfx_cicadas.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/cicadas.ogg -ac 1 -ar 6689 -f s8 sfx_cicadas.pcm

# echo "Convering \"sfx_traffic.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/traffic.ogg -ac 1 -ar 6689 -f s8 sfx_traffic.pcm

# echo "Convering \"sfx_shower.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/shower.ogg -ac 1 -ar 6689 -f s8 sfx_shower.pcm

# echo "Convering \"sfx_stallbuilding.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/stallbuilding.ogg -ac 1 -ar 6689 -f s8 sfx_stallbuilding.pcm

# echo "Convering \"sfx_parkambience.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/parkambience.ogg -ac 1 -ar 6689 -f s8 sfx_parkambience.pcm

# echo "Convering \"sfx_rooftop.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/rooftop.ogg -ac 1 -ar 6689 -f s8 sfx_rooftop.pcm

# echo "Convering \"sfx_businterior.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/businterior.ogg -ac 1 -ar 6689 -f s8 sfx_businterior.pcm


# #### COMMON sfx parts
# echo "Convering \"sfx_alarmclock.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/alarm.ogg -ac 1 -ar 11468 -f s8 sfx_alarmclock.pcm

# echo "Convering \"sfx_normalbell.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/carillon.ogg -ac 1 -ar 11468 -f s8 sfx_normalbell.pcm

# echo "Convering \"sfx_warningbell.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/chaimu.ogg -ac 1 -ar 11468 -f s8 sfx_warningbell.pcm

# echo "Convering \"sfx_crunchydeath.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/crunch.ogg -ac 1 -ar 11468 -f s8 sfx_crunchydeath.pcm

# echo "Convering \"sfx_rustling.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/rustling.ogg -ac 1 -ar 11468 -f s8 sfx_rustling.pcm

# echo "Convering \"sfx_impact.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/wumph.ogg -ac 1 -ar 11468 -f s8 sfx_impact.pcm

# echo "Convering \"sfx_impact2.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/wumph_2.ogg -ac 1 -ar 11468 -f s8 sfx_impact2.pcm

# echo "Convering \"sfx_heartfast.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/heart_single_fast.ogg -ac 1 -ar 11468 -f s8 sfx_heartfast.pcm

# echo "Convering \"sfx_heartslow.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/heart_single_slow.ogg -ac 1 -ar 11468 -f s8 sfx_heartslow.pcm

# echo "Convering \"sfx_heartstop.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/heart_stop.ogg -ac 1 -ar 11468 -f s8 sfx_heartstop.pcm

# echo "Convering \"sfx_startpistol.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/startpistol.ogg -ac 1 -ar 11468 -f s8 sfx_startpistol.pcm

# echo "Convering \"sfx_doorknock.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/doorknock.ogg -ac 1 -ar 11468 -f s8 sfx_doorknock.pcm

# echo "Convering \"sfx_doorknock2.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/doorknock2.ogg -ac 1 -ar 11468 -f s8 sfx_doorknock2.pcm

# echo "Convering \"sfx_doorslam.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/doorslam.ogg -ac 1 -ar 11468 -f s8 sfx_doorslam.pcm

# echo "Convering \"sfx_doorclose.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/doorclose.ogg -ac 1 -ar 11468 -f s8 sfx_doorclose.pcm

# echo "Convering \"sfx_scratch.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/scratch.ogg -ac 1 -ar 11468 -f s8 sfx_scratch.pcm

# echo "Convering \"sfx_rumble.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/rumble.ogg -ac 1 -ar 11468 -f s8 sfx_rumble.pcm

# echo "Convering \"sfx_skid.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/skid2.ogg -ac 1 -ar 11468 -f s8 sfx_skid.pcm

# echo "Convering \"sfx_gymbounce.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/emibounce.ogg -ac 1 -ar 11468 -f s8 sfx_gymbounce.pcm

# echo "Convering \"sfx_hammer.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/hammer.ogg -ac 1 -ar 11468 -f s8 sfx_hammer.pcm

# echo "Convering \"sfx_birdstakeoff.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/birdstakeoff.ogg -ac 1 -ar 11468 -f s8 sfx_birdstakeoff.pcm

# echo "Convering \"sfx_storebell.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/storebell.ogg -ac 1 -ar 11468 -f s8 sfx_storebell.pcm

# echo "Convering \"sfx_thunder.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/thunder.ogg -ac 1 -ar 11468 -f s8 sfx_thunder.pcm

# echo "Convering \"sfx_slide.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/slide.ogg -ac 1 -ar 11468 -f s8 sfx_slide.pcm

# echo "Convering \"sfx_slide2.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/slide2.ogg -ac 1 -ar 11468 -f s8 sfx_slide2.pcm

# echo "Convering \"sfx_draw.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/sword_draw.ogg -ac 1 -ar 11468 -f s8 sfx_draw.pcm

# echo "Convering \"sfx_switch.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/switch.ogg -ac 1 -ar 11468 -f s8 sfx_switch.pcm

# echo "Convering \"sfx_pillow.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/pillow.ogg -ac 1 -ar 11468 -f s8 sfx_pillow.pcm

# echo "Convering \"sfx_cellphone.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/cellphone.ogg -ac 1 -ar 11468 -f s8 sfx_cellphone.pcm

# echo "Convering \"sfx_door_creak.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/door_creak.ogg -ac 1 -ar 11468 -f s8 sfx_door_creak.pcm

# echo "Convering \"sfx_dooropen.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/dooropen.ogg -ac 1 -ar 11468 -f s8 sfx_dooropen.pcm

# echo "Convering \"sfx_dropglasses.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/dropglasses.ogg -ac 1 -ar 11468 -f s8 sfx_dropglasses.pcm

# echo "Convering \"sfx_can.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/can.ogg -ac 1 -ar 11468 -f s8 sfx_can.pcm

# echo "Convering \"sfx_trainint.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/trainint.ogg -ac 1 -ar 11468 -f s8 sfx_trainint.pcm

# echo "Convering \"sfx_footsteps_hard.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/footsteps_hard.ogg -ac 1 -ar 11468 -f s8 sfx_footsteps_hard.pcm

# echo "Convering \"sfx_footsteps_soft.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/footsteps_soft.ogg -ac 1 -ar 11468 -f s8 sfx_footsteps_soft.pcm

# echo "Convering \"sfx_paper.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/paper.ogg -ac 1 -ar 11468 -f s8 sfx_paper.pcm

# echo "Convering \"sfx_paperruffling.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/paperruffling.ogg -ac 1 -ar 11468 -f s8 sfx_paperruffling.pcm

# echo "Convering \"sfx_lighter.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/lighter.ogg -ac 1 -ar 11468 -f s8 sfx_lighter.pcm

# echo "Convering \"sfx_phone.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/phone.ogg -ac 1 -ar 11468 -f s8 sfx_phone.pcm

# echo "Convering \"sfx_hollowclick.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/hollowclick.ogg -ac 1 -ar 11468 -f s8 sfx_hollowclick.pcm

# echo "Convering \"sfx_teacup.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/teacup.ogg -ac 1 -ar 11468 -f s8 sfx_teacup.pcm

# echo "Convering \"sfx_can_clatter.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/can_clatter.ogg -ac 1 -ar 11468 -f s8 sfx_can_clatter.pcm

# echo "Convering \"sfx_snap.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/snap.ogg -ac 1 -ar 11468 -f s8 sfx_snap.pcm

# echo "Convering \"sfx_billiards_break.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/billiards_break.ogg -ac 1 -ar 11468 -f s8 sfx_billiards_break.pcm

# echo "Convering \"sfx_billiards.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/billiards.ogg -ac 1 -ar 11468 -f s8 sfx_billiards.pcm

# echo "Convering \"sfx_lock.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/lock.ogg -ac 1 -ar 11468 -f s8 sfx_lock.pcm

# echo "Convering \"sfx_dropstuff.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/dropstuff.ogg -ac 1 -ar 11468 -f s8 sfx_dropstuff.pcm

# echo "Convering \"sfx_camera.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/camera.ogg -ac 1 -ar 11468 -f s8 sfx_camera.pcm


# echo "Convering \"sfx_time.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/time.ogg -ac 1 -ar 11468 -f s8 sfx_time.pcm

# echo "Convering \"sfx_flash.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/flash.ogg -ac 1 -ar 11468 -f s8 sfx_flash.pcm

# echo "Convering \"sfx_whiteout.pcm\""
# ffmpeg -y -i /Users/n.laptev/development/ksre/game/sfx/whiteout.ogg -ac 1 -ar 11468 -f s8 sfx_whiteout.pcm



# # List of sfx used as ambients:
# # sfx_cicadas
# # sfx_crowd_outdoors
# # sfx_fireworks
# # sfx_rooftop
# # sfx_crowd_indoors
# # sfx_parkambience
# # sfx_traffic
# # sfx_emisprinting
# # sfx_heartslow
# # sfx_alarmclock
# # sfx_shower
# # sfx_emirunning
# # sfx_emijogging
# # sfx_emipacing
# # sfx_rain
# # sfx_paperruffling
# # sfx_footsteps_hard
# # sfx_stallbuilding
# # sfx_businterior
# # sfx_footsteps_soft
# # sfx_trainint

# # TODO: decide which of them can be used as GSM (music and ambient should not play simulantuosly)
