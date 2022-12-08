#include <iostream>
#include <vector>
#include <string>
#include <map>

#include <fstream>
#include <sstream>

// #include "info.h"
// #include "renderable.h"
#include "SDL_scancode.h"

#include "input.h"
#include "utility.h"
#include "preferences.h"


namespace AISAF{

  namespace CORE{
    void initKeyBinds(std::map<std::string, std::vector<SDL_Scancode>> &iniDefinedKeys){
      std::map<std::string, std::vector<SDL_Scancode>>::iterator it;
      for (it = iniDefinedKeys.begin(); it != iniDefinedKeys.end(); it++){
        Keybinds::keys.insert({it->first, it->second});
      }
    }
  }

  void parseIni(const std::string &fileName){
    bool doubleDot = false;

    CORE::loadScancodes();

    std::ifstream infile(fileName);
    std::string line;
    while (std::getline(infile, line)){

        if(AISAF::CORE::strip(line, ' ').rfind("#",0) != std::string::npos) continue;

        if(line.find("..") != std::string::npos){
          doubleDot = true;
          std::cout << AISAF::CORE::strip(line, '.') << std::endl;
          continue;
        }

        std::vector<std::string> params = AISAF::CORE::split(line, ':');

        if(params[0].rfind("IMAGE",0) != std::string::npos){
          std::vector<std::string> info = AISAF::CORE::split(params[0], ' ');
          CORE::uPreferences::uPrefs.images.insert({AISAF::CORE::strip(info[1], ' '), AISAF::CORE::strip(params[1], ' ')});
          continue;
        }

        if(params[0].rfind("SOUND",0) != std::string::npos){
          std::vector<std::string> info = AISAF::CORE::split(params[0], ' ');
          CORE::uPreferences::uPrefs.sounds.insert({AISAF::CORE::strip(info[1], ' '), AISAF::CORE::strip(params[1], ' ')});
          continue;
        }

        if(params[0].rfind("KEY",0) != std::string::npos){
          std::vector<std::string> keyPrefs = AISAF::CORE::split(params[1], ' ');
          CORE::uPreferences::uPrefs.keys.insert({AISAF::CORE::split(params[0], ' ')[1], CORE::findScancode(keyPrefs)});
          continue;
        }
    }

    CORE::initKeyBinds(CORE::uPreferences::uPrefs.keys);
    if(doubleDot) std::cout << "Note: lines containing '..' are printed instead of being parsed." << std::endl;
  }
}