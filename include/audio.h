//=================================
// include guard
#ifndef _AISAF_audio_h_
#define _AISAF_audio_h_

#include <vector>
#include <map>
#include <string>

// #include <SDL.h>
#include <SDL_mixer.h>
// #include "SDL_scancode.h"

namespace AISAF{

  void play(std::string soundName);


  namespace CORE{

    class Device{
      public:
      inline static SDL_AudioSpec AudioSpecWant, AudioSpecHave;
      inline static SDL_AudioDeviceID deviceId;
      inline static std::vector<SDL_AudioDeviceID> deviceIds;
      inline static int currentId;

    };
    
    class Sound{
      public:
      Uint32  wav_length;
      Uint8 * wav_buffer;
    };

    inline static std::map<std::string, Sound> LoadedSounds;

    void init();
    void devices();

    void closeAllAudioDevices();

  }
}

#endif