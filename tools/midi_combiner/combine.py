import mido

def combine_tracks_separate_channels(input_files, output_file):
    # Create a new MIDI file
    combined_midi = mido.MidiFile()

    # Assign each input file to a separate channel (up to 16 channels)
    for i, file in enumerate(input_files):
        if i >= 16:
            print("Warning: MIDI only supports 16 channels. Additional tracks will not have unique channels.")
            break

        midi = mido.MidiFile(file)
        new_track = mido.MidiTrack()
        combined_midi.tracks.append(new_track)

        for track in midi.tracks:
            for msg in track:
                if msg.type not in ['note_on', 'note_off', 'control_change', 'program_change']:
                    # Copy meta messages as-is
                    new_track.append(msg)
                elif 'channel' in msg.dict():
                    # Reassign the channel
                    new_track.append(msg.copy(channel=i))
                else:
                    # Copy other messages as-is
                    new_track.append(msg)

    # Save the combined MIDI file
    combined_midi.save(output_file)
    print(f"Combined MIDI file with separate channels saved as {output_file}")

# Example usage:
input_midi_files = ['file1.mid', 'file2.mid', 'file3.mid']  # Replace with your file paths
output_midi_file = 'combined_output.mid'
combine_tracks_separate_channels(input_midi_files, output_midi_file)
