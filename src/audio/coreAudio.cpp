#include <string>
#include <iostream>

#include "SDL_audio.h"
#include "SDL_stdinc.h"

#include "audio.h"
#include "SDL_scancode.h"


namespace AISAF{
  namespace CORE{
    void init(){
      devices();
    }

    void devices(){
      SDL_memset(&Device::AudioSpecWant, 0, sizeof(Device::AudioSpecWant));
      Device::AudioSpecWant.freq = 44100;
      Device::AudioSpecWant.format = AUDIO_S16;
      Device::AudioSpecWant.channels = 2;
      Device::AudioSpecWant.samples = 4096;

      Device::currentId = -1;
    }

    void closeAllAudioDevices(){
      CORE::Device::currentId = -1;
      for(int i = 0; i < CORE::Device::deviceIds.size(); i++){
        SDL_CloseAudioDevice(CORE::Device::deviceIds[i]);
        std::cout << "Closing devices!!!!!" + i << std::endl;
      }
      CORE::Device::deviceIds.resize(0);
    }

  }
}