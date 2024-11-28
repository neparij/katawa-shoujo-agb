#ifndef PLAYBACK_STATE_H
#define PLAYBACK_STATE_H

#define FINAL_SONG_LOOP 3842 - 160
/* 160 = 10-frame screen transition */

typedef struct {
  unsigned int msecs;
  bool hasFinished;
  bool isLooping;
} Playback;

extern Playback PlaybackState;

#endif  // PLAYBACK_STATE_H
