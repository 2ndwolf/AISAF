#ifndef _AISAF_enum_h_
#define _AISAF_enum_h_

#include <SDL.h>

namespace AISAF{
  namespace ENUM{
    enum KeyStates {
      UP,
      INACTIVE,
      DOWN,
      HELD
    };
    enum MouseMode{
      DEFAULT
    };
  }
}

#endif