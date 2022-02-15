#pragma once
#include <SDL2/SDL.h>
class eventHandlerClass
{
public:
    // functions
    eventHandlerClass();
    int handle(SDL_Event &);
    // variables
    bool keyA = 0, keyB = 0, keyC = 0, keyD = 0, keyE = 0, keyF = 0, keyG = 0, keyH = 0, keyI = 0, keyJ = 0, keyK = 0, keyL = 0, keyM = 0, keyN = 0, keyO = 0, keyP = 0, keyQ = 0, keyR = 0, keyS = 0, keyT = 0, keyU = 0, keyV = 0, keyW = 0, keyX = 0, keyY = 0, keyZ = 0;
    bool keyLCtrl = 0, keyLAlt = 0, keyLShift = 0, keySpacebar = 0, keyESC = 0;
    bool key0 = 0, key1 = 0, key2 = 0, key3 = 0, key4 = 0, key5 = 0, key6 = 0, key7 = 0, key8 = 0, key9 = 0;
    bool quit = 0;
};