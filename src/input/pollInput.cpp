// #include <memory>

#include <SDL.h> 

#include "input.h"
#include "AISAFenum.h"
// #include "fkore.h"
// #include "window.h"

namespace AISAF {

  int pollInput (SDL_Event event) {

    // Increment pressed state, or delete if released during previous frame
    // updateInputStates(Mouse::clicks);
    AISAF::CORE::updateInputStates(AISAF::CORE::KeyStatesMap::keycodeStates);

    switch(event.type){

    // }
    // while (SDL_PollEvent(&event)) {
    //   // AISAF::Window::pollWindowEvents(event);
    //   switch (event.type) { 

      // case SDL_WINDOWEVENT: {
      // }
      // case SDL_QUIT: 
        // return 1;

      case SDL_KEYDOWN:
        AISAF::CORE::KeyStatesMap::keycodeStates.insert({event.key.keysym.scancode, AISAF::ENUM::KeyStates::DOWN}); 
        break;

      case SDL_KEYUP:
        AISAF::CORE::KeyStatesMap::keycodeStates[event.key.keysym.scancode] = AISAF::ENUM::KeyStates::UP;
        break;

      case SDL_MOUSEBUTTONDOWN:
        Mouse::clicks[event.button.button] = AISAF::ENUM::KeyStates::DOWN;
        break;

      case SDL_MOUSEBUTTONUP:
        Mouse::clicks[event.button.button] = AISAF::ENUM::KeyStates::UP;
        break;

      case SDL_MOUSEMOTION:
        // AISAF::Mouse::position.x = event.motion.x;
        // AISAF::Mouse::position.y = event.motion.y;
        break;
      }
    // }

    return 0;
  }

  namespace CORE{
    void updateInputStates(std::map<SDL_Scancode, AISAF::ENUM::KeyStates> &inputStates){
      std::map<SDL_Scancode, AISAF::ENUM::KeyStates>::iterator it = inputStates.begin();
      while (it != inputStates.end()){

        if(it -> second == AISAF::ENUM::KeyStates::DOWN){
          it->second = AISAF::ENUM::KeyStates::HELD;

        } else if (it -> second == AISAF::ENUM::KeyStates::UP){
          it = inputStates.erase(it);
          continue;
        }

        it++;

      } 

      std::map<int, AISAF::ENUM::KeyStates>::iterator mit = AISAF::Mouse::clicks.begin();
      while (mit != AISAF::Mouse::clicks.end()){

        if(mit -> second == AISAF::ENUM::KeyStates::DOWN){
          mit->second = AISAF::ENUM::KeyStates::HELD;

        } else if (mit -> second == AISAF::ENUM::KeyStates::UP){
          mit->second = AISAF::ENUM::KeyStates::INACTIVE;
        }

        mit++;

      }
    }
  }
}
