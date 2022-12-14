#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#include "SDL_scancode.h"
#include "input.h"


namespace AISAF{

  namespace CORE{

    // std::vector<std::string> scancodeStrVec((int)SDL_NUM_SCANCODES);


    std::vector<SDL_Scancode> findScancode(std::vector<std::string> keycodeAsStr){
      std::vector<SDL_Scancode> codes;

      for(int i = 0; i < keycodeAsStr.size(); i++){
        std::vector<std::string>::iterator it = std::find(scancodeStrVec.begin(), scancodeStrVec.end(), keycodeAsStr[i]);
        int index =  it - scancodeStrVec.begin();

        if( it != scancodeStrVec.end() ) codes.push_back((SDL_Scancode) index);
        else codes.push_back(SDL_SCANCODE_UNKNOWN);
      }

      return codes;
    }

    void loadScancodes(){

      scancodeStrVec[0] = "UNKNOWN";
      scancodeStrVec[4] = "A";
      scancodeStrVec[5] = "B";
      scancodeStrVec[6] = "C";
      scancodeStrVec[7] = "D";
      scancodeStrVec[8] = "E";
      scancodeStrVec[9] = "F";
      scancodeStrVec[10] = "G";
      scancodeStrVec[11] = "H";
      scancodeStrVec[12] = "I";
      scancodeStrVec[13] = "J";
      scancodeStrVec[14] = "K";
      scancodeStrVec[15] = "L";
      scancodeStrVec[16] = "M";
      scancodeStrVec[17] = "N";
      scancodeStrVec[18] = "O";
      scancodeStrVec[19] = "P";
      scancodeStrVec[20] = "Q";
      scancodeStrVec[21] = "R";
      scancodeStrVec[22] = "S";
      scancodeStrVec[23] = "T";
      scancodeStrVec[24] = "U";
      scancodeStrVec[25] = "V";
      scancodeStrVec[26] = "W";
      scancodeStrVec[27] = "X";
      scancodeStrVec[28] = "Y";
      scancodeStrVec[29] = "Z";
      scancodeStrVec[30] = "1";
      scancodeStrVec[31] = "2";
      scancodeStrVec[32] = "3";
      scancodeStrVec[33] = "4";
      scancodeStrVec[34] = "5";
      scancodeStrVec[35] = "6";
      scancodeStrVec[36] = "7";
      scancodeStrVec[37] = "8";
      scancodeStrVec[38] = "9";
      scancodeStrVec[39] = "0";
      scancodeStrVec[40] = "RETURN";
      scancodeStrVec[41] = "ESCAPE";
      scancodeStrVec[42] = "BACKSPACE";
      scancodeStrVec[43] = "TAB";
      scancodeStrVec[44] = "SPACE";
      scancodeStrVec[45] = "MINUS";
      scancodeStrVec[46] = "EQUALS";
      scancodeStrVec[47] = "LEFTBRACKET";
      scancodeStrVec[48] = "RIGHTBRACKET";
      scancodeStrVec[49] = "BACKSLASH";
      scancodeStrVec[50] = "NONUSHASH";
      scancodeStrVec[51] = "SEMICOLON";
      scancodeStrVec[52] = "APOSTROPHE";
      scancodeStrVec[53] = "GRAVE";
      scancodeStrVec[54] = "COMMA";
      scancodeStrVec[55] = "PERIOD";
      scancodeStrVec[56] = "SLASH";
      scancodeStrVec[57] = "CAPSLOCK";
      scancodeStrVec[58] = "F1";
      scancodeStrVec[59] = "F2";
      scancodeStrVec[60] = "F3";
      scancodeStrVec[61] = "F4";
      scancodeStrVec[62] = "F5";
      scancodeStrVec[63] = "F6";
      scancodeStrVec[64] = "F7";
      scancodeStrVec[65] = "F8";
      scancodeStrVec[66] = "F9";
      scancodeStrVec[67] = "F10";
      scancodeStrVec[68] = "F11";
      scancodeStrVec[69] = "F12";
      scancodeStrVec[70] = "PRINTSCREEN";
      scancodeStrVec[71] = "SCROLLLOCK";
      scancodeStrVec[72] = "PAUSE";
      scancodeStrVec[73] = "INSERT";
      scancodeStrVec[74] = "HOME";
      scancodeStrVec[75] = "PAGEUP";
      scancodeStrVec[76] = "DELETE";
      scancodeStrVec[77] = "END";
      scancodeStrVec[78] = "PAGEDOWN";
      scancodeStrVec[79] = "RIGHT";
      scancodeStrVec[80] = "LEFT";
      scancodeStrVec[81] = "DOWN";
      scancodeStrVec[82] = "UP";
      scancodeStrVec[83] = "NUMLOCKCLEAR";
      scancodeStrVec[84] = "KP_DIVIDE";
      scancodeStrVec[85] = "KP_MULTIPLY";
      scancodeStrVec[86] = "KP_MINUS";
      scancodeStrVec[87] = "KP_PLUS";
      scancodeStrVec[88] = "KP_ENTER";
      scancodeStrVec[89] = "KP_1";
      scancodeStrVec[90] = "KP_2";
      scancodeStrVec[91] = "KP_3";
      scancodeStrVec[92] = "KP_4";
      scancodeStrVec[93] = "KP_5";
      scancodeStrVec[94] = "KP_6";
      scancodeStrVec[95] = "KP_7";
      scancodeStrVec[96] = "KP_8";
      scancodeStrVec[97] = "KP_9";
      scancodeStrVec[98] = "KP_0";
      scancodeStrVec[99] = "KP_PERIOD";
      scancodeStrVec[100] = "NONUSBACKSLASH";
      scancodeStrVec[101] = "APPLICATION";
      scancodeStrVec[102] = "POWER";
      scancodeStrVec[103] = "KP_EQUALS";
      scancodeStrVec[104] = "F13";
      scancodeStrVec[105] = "F14";
      scancodeStrVec[106] = "F15";
      scancodeStrVec[107] = "F16";
      scancodeStrVec[108] = "F17";
      scancodeStrVec[109] = "F18";
      scancodeStrVec[110] = "F19";
      scancodeStrVec[111] = "F20";
      scancodeStrVec[112] = "F21";
      scancodeStrVec[113] = "F22";
      scancodeStrVec[114] = "F23";
      scancodeStrVec[115] = "F24";
      scancodeStrVec[116] = "EXECUTE";
      scancodeStrVec[117] = "HELP";
      scancodeStrVec[118] = "MENU";
      scancodeStrVec[119] = "SELECT";
      scancodeStrVec[120] = "STOP";
      scancodeStrVec[121] = "AGAIN";
      scancodeStrVec[122] = "UNDO";
      scancodeStrVec[123] = "CUT";
      scancodeStrVec[124] = "COPY";
      scancodeStrVec[125] = "PASTE";
      scancodeStrVec[126] = "FIND";
      scancodeStrVec[127] = "MUTE";
      scancodeStrVec[128] = "VOLUMEUP";
      scancodeStrVec[129] = "VOLUMEDOWN";
      scancodeStrVec[130] = "LOCKINGCAPSLOCK";
      scancodeStrVec[131] = "LOCKINGNUMLOCK";
      scancodeStrVec[132] = "LOCKINGSCROLLLOCK";
      scancodeStrVec[133] = "KP_COMMA";
      scancodeStrVec[134] = "KP_EQUALSAS400";
      scancodeStrVec[135] = "INTERNATIONAL1";
      scancodeStrVec[136] = "INTERNATIONAL2";
      scancodeStrVec[137] = "INTERNATIONAL3";
      scancodeStrVec[138] = "INTERNATIONAL4";
      scancodeStrVec[139] = "INTERNATIONAL5";
      scancodeStrVec[140] = "INTERNATIONAL6";
      scancodeStrVec[141] = "INTERNATIONAL7";
      scancodeStrVec[142] = "INTERNATIONAL8";
      scancodeStrVec[143] = "INTERNATIONAL9";
      scancodeStrVec[144] = "LANG1";
      scancodeStrVec[145] = "LANG2";
      scancodeStrVec[146] = "LANG3";
      scancodeStrVec[147] = "LANG4";
      scancodeStrVec[148] = "LANG5";
      scancodeStrVec[149] = "LANG6";
      scancodeStrVec[150] = "LANG7";
      scancodeStrVec[151] = "LANG8";
      scancodeStrVec[152] = "LANG9";
      scancodeStrVec[153] = "ALTERASE";
      scancodeStrVec[154] = "SYSREQ";
      scancodeStrVec[155] = "CANCEL";
      scancodeStrVec[156] = "CLEAR";
      scancodeStrVec[157] = "PRIOR";
      scancodeStrVec[158] = "RETURN2";
      scancodeStrVec[159] = "SEPARATOR";
      scancodeStrVec[160] = "OUT";
      scancodeStrVec[161] = "OPER";
      scancodeStrVec[162] = "CLEARAGAIN";
      scancodeStrVec[163] = "CRSEL";
      scancodeStrVec[164] = "EXSEL";
      scancodeStrVec[176] = "KP_00";
      scancodeStrVec[177] = "KP_000";
      scancodeStrVec[178] = "THOUSANDSSEPARATOR";
      scancodeStrVec[179] = "DECIMALSEPARATOR";
      scancodeStrVec[180] = "CURRENCYUNIT";
      scancodeStrVec[181] = "CURRENCYSUBUNIT";
      scancodeStrVec[182] = "KP_LEFTPAREN";
      scancodeStrVec[183] = "KP_RIGHTPAREN";
      scancodeStrVec[184] = "KP_LEFTBRACE";
      scancodeStrVec[185] = "KP_RIGHTBRACE";
      scancodeStrVec[186] = "KP_TAB";
      scancodeStrVec[187] = "KP_BACKSPACE";
      scancodeStrVec[188] = "KP_A";
      scancodeStrVec[189] = "KP_B";
      scancodeStrVec[190] = "KP_C";
      scancodeStrVec[191] = "KP_D";
      scancodeStrVec[192] = "KP_E";
      scancodeStrVec[193] = "KP_F";
      scancodeStrVec[194] = "KP_XOR";
      scancodeStrVec[195] = "KP_POWER";
      scancodeStrVec[196] = "KP_PERCENT";
      scancodeStrVec[197] = "KP_LESS";
      scancodeStrVec[198] = "KP_GREATER";
      scancodeStrVec[199] = "KP_AMPERSAND";
      scancodeStrVec[200] = "KP_DBLAMPERSAND";
      scancodeStrVec[201] = "KP_VERTICALBAR";
      scancodeStrVec[202] = "KP_DBLVERTICALBAR";
      scancodeStrVec[203] = "KP_COLON";
      scancodeStrVec[204] = "KP_HASH";
      scancodeStrVec[205] = "KP_SPACE";
      scancodeStrVec[206] = "KP_AT";
      scancodeStrVec[207] = "KP_EXCLAM";
      scancodeStrVec[208] = "KP_MEMSTORE";
      scancodeStrVec[209] = "KP_MEMRECALL";
      scancodeStrVec[210] = "KP_MEMCLEAR";
      scancodeStrVec[211] = "KP_MEMADD";
      scancodeStrVec[212] = "KP_MEMSUBTRACT";
      scancodeStrVec[213] = "KP_MEMMULTIPLY";
      scancodeStrVec[214] = "KP_MEMDIVIDE";
      scancodeStrVec[215] = "KP_PLUSMINUS";
      scancodeStrVec[216] = "KP_CLEAR";
      scancodeStrVec[217] = "KP_CLEARENTRY";
      scancodeStrVec[218] = "KP_BINARY";
      scancodeStrVec[219] = "KP_OCTAL";
      scancodeStrVec[220] = "KP_DECIMAL";
      scancodeStrVec[221] = "KP_HEXADECIMAL";
      scancodeStrVec[224] = "LCTRL";
      scancodeStrVec[225] = "LSHIFT";
      scancodeStrVec[226] = "LALT";
      scancodeStrVec[227] = "LGUI";
      scancodeStrVec[228] = "RCTRL";
      scancodeStrVec[229] = "RSHIFT";
      scancodeStrVec[230] = "RALT";
      scancodeStrVec[231] = "RGUI";
      scancodeStrVec[257] = "MODE";
      scancodeStrVec[258] = "AUDIONEXT";
      scancodeStrVec[259] = "AUDIOPREV";
      scancodeStrVec[260] = "AUDIOSTOP";
      scancodeStrVec[261] = "AUDIOPLAY";
      scancodeStrVec[262] = "AUDIOMUTE";
      scancodeStrVec[263] = "MEDIASELECT";
      scancodeStrVec[264] = "WWW";
      scancodeStrVec[265] = "MAIL";
      scancodeStrVec[266] = "CALCULATOR";
      scancodeStrVec[267] = "COMPUTER";
      scancodeStrVec[268] = "AC_SEARCH";
      scancodeStrVec[269] = "AC_HOME";
      scancodeStrVec[270] = "AC_BACK";
      scancodeStrVec[271] = "AC_FORWARD";
      scancodeStrVec[272] = "AC_STOP";
      scancodeStrVec[273] = "AC_REFRESH";
      scancodeStrVec[274] = "AC_BOOKMARKS";
      scancodeStrVec[275] = "BRIGHTNESSDOWN";
      scancodeStrVec[276] = "BRIGHTNESSUP";
      scancodeStrVec[277] = "DISPLAYSWITCH";
      scancodeStrVec[278] = "KBDILLUMTOGGLE";
      scancodeStrVec[279] = "KBDILLUMDOWN";
      scancodeStrVec[280] = "KBDILLUMUP";
      scancodeStrVec[281] = "EJECT";
      scancodeStrVec[282] = "SLEEP";
      scancodeStrVec[283] = "APP1";
      scancodeStrVec[284] = "APP2";
      scancodeStrVec[285] = "AUDIOREWIND";
      scancodeStrVec[286] = "AUDIOFASTFORWARD";
    }
  }
}
