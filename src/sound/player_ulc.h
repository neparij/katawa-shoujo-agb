#ifndef PLAYER_ULC_H
#define PLAYER_ULC_H

#define BUFFER_SIZE_ULC 224

#ifdef __cplusplus
extern "C" {
#endif

void playerULC_init();
    void playerULC_play(const char* name);
    void playerULC_set_loop(bool enable);
    void playerULC_set_pause(bool enable);
    void playerULC_stop();
    bool playerULC_is_playing();
    void playerULC_update();
    s8*  playerULC_get_buffer();

#ifdef __cplusplus
}
#endif

#endif //PLAYER_ULC_H
