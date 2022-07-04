#include "SDL2pp/SDL2pp.hh"
#include <SDL2pp/Mixer.hh>
#include <SDL2pp/Chunk.hh>
#ifndef TP_FINAL_DUNE_GRUPO_1_AUDIO_H
#define TP_FINAL_DUNE_GRUPO_1_AUDIO_H
using namespace SDL2pp;
class AudioPlayer {
    public:
    void play() {
        Mixer mixer(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096);
        Chunk sound(DATA_PATH "/test.wav"); 
        mixer.PlayChannel(-1, sound);
        SDL_Delay(1000);
    }
};
#endif