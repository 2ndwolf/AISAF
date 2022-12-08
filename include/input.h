//=================================
// include guard
#ifndef _AISAF_input_h_
#define _AISAF_input_h_

#include <map>
#include <string>
#include <vector>

#include "SDL_scancode.h"

// #include "primitives.h"
#include "AISAFenum.h"


namespace AISAF{

  bool keyPressed(std::string key);
  bool keyHeld(std::string key);
  bool keyUp(std::string key);
  bool keyDown(std::string key);
  int pollInput();

  namespace CORE{

    inline std::vector<std::string> scancodeStrVec((int)SDL_NUM_SCANCODES);

    void loadScancodes();
    void initKeyBinds(std::map<std::string, std::vector<SDL_Scancode>> &iniDefinedKeys);
    std::vector<SDL_Scancode> findScancode(std::vector<std::string> keycodeAsStr);

    // void updateMouse(entt::registry &registry);

    void updateInputStates(std::map<SDL_Scancode, ENUM::KeyStates> &inputStates);
    // void MusicFun();


    class KeyStatesMap{
      public:
      inline static std::map<SDL_Scancode, ENUM::KeyStates> keycodeStates;
    };

    class Keybinds{
      public:
      inline static std::map<std::string, std::vector<SDL_Scancode>> keys;
    };


  }



  class Mouse{
    public:
    // Mouse(){};
    // inline static Vec2 position;
    inline static std::map<int, ENUM::KeyStates> clicks;
    inline static ENUM::MouseMode mouseMode = ENUM::MouseMode::DEFAULT;
  };

}

#endif