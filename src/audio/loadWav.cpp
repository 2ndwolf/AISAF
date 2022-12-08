#include <string>
#include <iostream>

#include "SDL_timer.h"
#include "SDL_audio.h"
#include "SDL_scancode.h"

#include "SDL_mixer.h"

#include "audio.h"


namespace AISAF{

  void play(std::string soundName){
    if(CORE::LoadedSounds.find((std::string)soundName) == CORE::LoadedSounds.end()){
      std::cout << "Loading new sound..." << std::endl;
      CORE::Sound sample = CORE::Sound();
      if (SDL_LoadWAV(soundName.c_str(), &CORE::Device::AudioSpecWant, &sample.wav_buffer, &sample.wav_length) == NULL) {
        fprintf(stderr, "Could not open %s : %s\n", soundName, SDL_GetError());
        return;
      } else {
        CORE::LoadedSounds[soundName] = sample;
      }
    }

    if(CORE::Device::currentId == -1){
      CORE::Device::deviceId = SDL_OpenAudioDevice(NULL, 0, &CORE::Device::AudioSpecWant, NULL, 0);
    }

    if(CORE::Device::deviceId != 0 && CORE::Device::currentId == -1){
      CORE::Device::deviceIds.push_back(CORE::Device::deviceId);
    } else {
      CORE::Device::currentId++;
      CORE::Device::deviceId = CORE::Device::deviceIds[CORE::Device::currentId%CORE::Device::deviceIds.size()];
    }

    if(SDL_QueueAudio(CORE::Device::deviceId, CORE::LoadedSounds[soundName].wav_buffer, CORE::LoadedSounds[soundName].wav_length) == 0){
      if(CORE::Device::currentId == -1){
        SDL_PauseAudioDevice(CORE::Device::deviceId, 0);
      }
    }
    // SDL_Delay(500);
    // SDL_CloseAudioDevice(deviceId);

    // SDL_FreeWAV(CORE::LoadedSounds[soundName].wav_buffer);
  }
}