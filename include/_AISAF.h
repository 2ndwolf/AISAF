#ifndef _AISAF_IMPORT_h_
#define _AISAF_IMPORT_h_

#include <string>


namespace AISAF{
  // Audio
  void play(std::string soundName);

  // Input
  void parseIni(const std::string &fileName);

  int pollInput();
  bool keyUp(std::string key);
  bool keyHeld(std::string key);
  bool keyDown(std::string key);
  bool keyPressed(std::string key);


}


#endif