#!/bin/sh

# Input directory
INPUT_DIR="./#original"

# Define an array of input and output filenames
FILES=(
  "Afternoon.ogg:music_tranquil.gsm"
  "Ah_Eh_I_Oh_You.ogg:music_nurse.gsm"
  "Air_Guitar.ogg:music_soothing.gsm"
  "Aria_de_l'Etoile.ogg:music_twinkle.gsm"
  "Breathlessly.ogg:music_moonlight.gsm"
  "Caged_Heart.ogg:music_rain.gsm"
  "Cold_Iron.ogg:music_tragic.gsm"
  "Comfort.ogg:music_comfort.gsm"
  "Concord.ogg:music_lilly.gsm"
  "Daylight.ogg:music_daily.gsm"
  "Ease.ogg:music_ease.gsm"
  "Everyday_Fantasy.ogg:music_another.gsm"
  "Friendship.ogg:music_friendship.gsm"
  "Fripperies.ogg:music_happiness.gsm"
  "Generic_Happy_Music.ogg:music_comedy.gsm"
  "High_Tension.ogg:music_tension.gsm"
  "Hokabi.ogg:music_running.gsm"
  "Innocence.ogg:music_innocence.gsm"
  "Letting_my_Heart_Speak.ogg:music_heart.gsm"
  "Lullaby_of_Open_Eyes.ogg:music_serene.gsm"
  "Moment_of_Decision.ogg:music_drama.gsm"
  "Nocturne.ogg:music_night.gsm"
  "Out_of_the_Loop.ogg:music_kenji.gsm"
  "Painful_History.ogg:music_hanako.gsm"
  "Parity.ogg:music_rin.gsm"
  "Passing_of_Time.ogg:music_timeskip.gsm"
  "Raindrops_and_Puddles.ogg:music_dreamy.gsm"
  "Red_Velvet.ogg:music_jazz.gsm"
  "Romance_in_Andante_II.ogg:music_romance.gsm"
  "Romance_in_Andante.ogg:music_credits.gsm"
  "Sarabande_from_BWV1010.ogg:music_musicbox.gsm"
  "School_Days.ogg:music_normal.gsm"
  "Shadow_of_the_Truth.ogg:music_sadness.gsm"
  "Standing_Tall.ogg:music_emi.gsm"
  "Stride.ogg:music_pearly.gsm"
  "The_Student_Council.ogg:music_shizune.gsm"
  "To_Become_One.ogg:music_one.gsm"
  "Wiosna.ogg:music_menus.gsm"
)

# Loop through the files and process them
for FILE_PAIR in "${FILES[@]}"; do
  IFS=":" read -r INPUT_FILE OUTPUT_FILE <<< "$FILE_PAIR"
  
  echo "Converting \"$OUTPUT_FILE\""
  # sox --show-progress --replay-gain track --norm "$INPUT_DIR/$INPUT_FILE" -r 18157 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - "$OUTPUT_FILE"
  sox --show-progress --replay-gain track --norm "$INPUT_DIR/$INPUT_FILE" -r 13379 -t s16 -c 1 - | sox -t s16 -r 8000 -c 1 - "$OUTPUT_FILE"
done