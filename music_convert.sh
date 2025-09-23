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

# Define an array of input and output filenames
FILES=(
  "Afternoon.ogg:music_tranquil.ulc"
  "Ah_Eh_I_Oh_You.ogg:music_nurse.ulc"
  "Air_Guitar.ogg:music_soothing.ulc"
  "Aria_de_l'Etoile.ogg:music_twinkle.ulc"
  "Breathlessly.ogg:music_moonlight.ulc"
  "Caged_Heart.ogg:music_rain.ulc"
  "Cold_Iron.ogg:music_tragic.ulc"
  "Comfort.ogg:music_comfort.ulc"
  "Concord.ogg:music_lilly.ulc"
  "Daylight.ogg:music_daily.ulc"
  "Ease.ogg:music_ease.ulc"
  "Everyday_Fantasy.ogg:music_another.ulc"
  "Friendship.ogg:music_friendship.ulc"
  "Fripperies.ogg:music_happiness.ulc"
  "Generic_Happy_Music.ogg:music_comedy.ulc"
  "High_Tension.ogg:music_tension.ulc"
  "Hokabi.ogg:music_running.ulc"
  "Innocence.ogg:music_innocence.ulc"
  "Letting_my_Heart_Speak.ogg:music_heart.ulc"
  "Lullaby_of_Open_Eyes.ogg:music_serene.ulc"
  "Moment_of_Decision.ogg:music_drama.ulc"
  "Nocturne.ogg:music_night.ulc"
  "Out_of_the_Loop.ogg:music_kenji.ulc"
  "Painful_History.ogg:music_hanako.ulc"
  "Parity.ogg:music_rin.ulc"
  "Passing_of_Time.ogg:music_timeskip.ulc"
  "Raindrops_and_Puddles.ogg:music_dreamy.ulc"
  "Red_Velvet.ogg:music_jazz.ulc"
  "Romance_in_Andante_II.ogg:music_romance.ulc"
  "Romance_in_Andante.ogg:music_credits.ulc"
  "Sarabande_from_BWV1010.ogg:music_musicbox.ulc"
  "School_Days.ogg:music_normal.ulc"
  "Shadow_of_the_Truth.ogg:music_sadness.ulc"
  "Standing_Tall.ogg:music_emi.ulc"
  "Stride.ogg:music_pearly.ulc"
  "The_Student_Council.ogg:music_shizune.ulc"
  "To_Become_One.ogg:music_one.ulc"
  "Wiosna.ogg:music_menus.ulc"
)

# Loop through the files and process them
for FILE_PAIR in "${FILES[@]}"; do
  IFS=":" read -r INPUT_FILE OUTPUT_FILE <<< "$FILE_PAIR"
  
  echo "Converting \"$OUTPUT_FILE\""
  TMP_WAV="${TMPDIR}/${OUTPUT_FILE}.wav"

  ffmpeg -y -i "${KSRE_ROOT}/game/bgm/${INPUT_FILE}" \
    -af "highpass=f=60, lowpass=f=13379, acompressor=threshold=-20dB:ratio=2.5:attack=50:release=400:makeup=9dB, alimiter=limit=1.0" \
    -ac 1 -ar 13379 -sample_fmt s16 -acodec pcm_s16le "${TMP_WAV}"

  "${ULCENCODETOOL}" "${TMP_WAV}" "${KSGBA_ROOT}/gbfs_files/${OUTPUT_FILE}" -75 -blocksize:256
done