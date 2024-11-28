#!/bin/sh

# Original convertation
# sox ./\#original/Afternoon.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_tranquil.gsm
# sox ./\#original/Ah_Eh_I_Oh_You.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_nurse.gsm
# sox ./\#original/Air_Guitar.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_soothing.gsm
# sox ./\#original/Aria_de_l\'Etoile.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_twinkle.gsm
# sox ./\#original/Breathlessly.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_moonlight.gsm
# sox ./\#original/Caged_Heart.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_rain.gsm
# sox ./\#original/Cold_Iron.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_tragic.gsm
# sox ./\#original/Comfort.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_comfort.gsm
# sox ./\#original/Concord.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_lilly.gsm
# sox ./\#original/Daylight.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_daily.gsm
# sox ./\#original/Ease.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_ease.gsm
# sox ./\#original/Everyday_Fantasy.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_another.gsm
# sox ./\#original/Friendship.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_friendship.gsm
# sox ./\#original/Fripperies.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_happiness.gsm
# sox ./\#original/Generic_Happy_Music.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_comedy.gsm
# sox ./\#original/High_Tension.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_tension.gsm
# sox ./\#original/Hokabi.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_running.gsm
# sox ./\#original/Innocence.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_innocence.gsm
# sox ./\#original/Letting_my_Heart_Speak.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_heart.gsm
# sox ./\#original/Lullaby_of_Open_Eyes.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_serene.gsm
# sox ./\#original/Moment_of_Decision.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_drama.gsm
# sox ./\#original/Nocturne.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_night.gsm
# sox ./\#original/Out_of_the_Loop.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_kenji.gsm
# sox ./\#original/Painful_History.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_hanako.gsm
# sox ./\#original/Parity.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_rin.gsm
# sox ./\#original/Passing_of_Time.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_timeskip.gsm
# sox ./\#original/Raindrops_and_Puddles.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_dreamy.gsm
# sox ./\#original/Red_Velvet.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_jazz.gsm
# sox ./\#original/Romance_in_Andante_II.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_romance.gsm
# sox ./\#original/Romance_in_Andante.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_credits.gsm
# sox ./\#original/Sarabande_from_BWV1010.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_musicbox.gsm
# sox ./\#original/School_Days.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_normal.gsm
# sox ./\#original/Shadow_of_the_Truth.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_sadness.gsm
# sox ./\#original/Standing_Tall.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_emi.gsm
# sox ./\#original/Stride.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_pearly.gsm
# sox ./\#original/The_Student_Council.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_shizune.gsm
# sox ./\#original/To_Become_One.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_one.gsm
# sox ./\#original/Wiosna.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_menus.gsm

# Optimized

echo "Converting \"music_tranquil.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Afternoon.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_tranquil.gsm

echo "Converting \"music_nurse.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Ah_Eh_I_Oh_You.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_nurse.gsm

echo "Converting \"music_soothing.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Air_Guitar.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_soothing.gsm

echo "Converting \"music_twinkle.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Aria_de_l\'Etoile.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_twinkle.gsm

echo "Converting \"music_moonlight.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Breathlessly.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_moonlight.gsm

echo "Converting \"music_rain.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Caged_Heart.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_rain.gsm

echo "Converting \"music_tragic.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Cold_Iron.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_tragic.gsm

echo "Converting \"music_comfort.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Comfort.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_comfort.gsm

echo "Converting \"music_lilly.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Concord.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_lilly.gsm

echo "Converting \"music_daily.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Daylight.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_daily.gsm

echo "Converting \"music_ease.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Ease.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_ease.gsm

echo "Converting \"music_another.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Everyday_Fantasy.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_another.gsm

echo "Converting \"music_friendship.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Friendship.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_friendship.gsm

echo "Converting \"music_happiness.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Fripperies.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_happiness.gsm

echo "Converting \"music_comedy.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Generic_Happy_Music.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_comedy.gsm

echo "Converting \"music_tension.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/High_Tension.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_tension.gsm

echo "Converting \"music_running.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Hokabi.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_running.gsm

echo "Converting \"music_innocence.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Innocence.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_innocence.gsm

echo "Converting \"music_heart.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Letting_my_Heart_Speak.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_heart.gsm

echo "Converting \"music_serene.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Lullaby_of_Open_Eyes.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_serene.gsm

echo "Converting \"music_drama.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Moment_of_Decision.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_drama.gsm

echo "Converting \"music_night.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Nocturne.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_night.gsm

echo "Converting \"music_kenji.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Out_of_the_Loop.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_kenji.gsm

echo "Converting \"music_hanako.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Painful_History.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_hanako.gsm

echo "Converting \"music_rin.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Parity.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_rin.gsm

echo "Converting \"music_timeskip.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Passing_of_Time.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_timeskip.gsm

echo "Converting \"music_dreamy.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Raindrops_and_Puddles.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_dreamy.gsm

echo "Converting \"music_jazz.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Red_Velvet.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_jazz.gsm

echo "Converting \"music_romance.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Romance_in_Andante_II.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_romance.gsm

echo "Converting \"music_credits.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Romance_in_Andante.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_credits.gsm

echo "Converting \"music_musicbox.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Sarabande_from_BWV1010.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_musicbox.gsm

echo "Converting \"music_normal.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/School_Days.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_normal.gsm

echo "Converting \"music_sadness.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Shadow_of_the_Truth.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_sadness.gsm

echo "Converting \"music_emi.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Standing_Tall.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_emi.gsm

echo "Converting \"music_pearly.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Stride.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_pearly.gsm

echo "Converting \"music_shizune.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/The_Student_Council.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_shizune.gsm

echo "Converting \"music_one.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/To_Become_One.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_one.gsm

echo "Converting \"music_menus.gsm\""
sox --show-progress --replay-gain track --norm ./\#original/Wiosna.ogg -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - music_menus.gsm

