#include <string>

#include "input.h"
#include "AISAFenum.h"


namespace AISAF{
  bool keyPressed(std::string key){
    for(int i = 0; i < CORE::Keybinds::keys[key].size(); i++){
      if(CORE::KeyStatesMap::keycodeStates[CORE::Keybinds::keys[key][i]] > AISAF::ENUM::KeyStates::INACTIVE) return true;
    }
    return false;
  }

  bool keyHeld(std::string key){
    for(int i = 0; i < CORE::Keybinds::keys[key].size(); i++){
      if(CORE::KeyStatesMap::keycodeStates[CORE::Keybinds::keys[key][i]] == AISAF::ENUM::KeyStates::HELD) return true;
    }
    return false;
  }

  bool keyUp(std::string key){
    for(int i = 0; i < CORE::Keybinds::keys[key].size(); i++){
      if(CORE::KeyStatesMap::keycodeStates[CORE::Keybinds::keys[key][i]] == AISAF::ENUM::KeyStates::UP) return true;
    }
    return false;
  }

  bool keyDown(std::string key){
    for(int i = 0; i < CORE::Keybinds::keys[key].size(); i++){
      if(CORE::KeyStatesMap::keycodeStates[CORE::Keybinds::keys[key][i]] == AISAF::ENUM::KeyStates::DOWN) return true;
    }
    return false;
  }

}
