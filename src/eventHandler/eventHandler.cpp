#include "eventHandler.h"
eventHandlerClass::eventHandlerClass() {}
int eventHandlerClass::handle(SDL_Event &event)
{
    switch (event.type)
    {
    case SDL_QUIT:
        quit = 1;
        break;
    case SDL_KEYDOWN:
        if (event.key.keysym.sym == SDLK_a)
            keyA = 1;
        if (event.key.keysym.sym == SDLK_b)
            keyB = 1;
        if (event.key.keysym.sym == SDLK_c)
            keyC = 1;
        if (event.key.keysym.sym == SDLK_d)
            keyD = 1;
        if (event.key.keysym.sym == SDLK_e)
            keyE = 1;
        if (event.key.keysym.sym == SDLK_f)
            keyF = 1;
        if (event.key.keysym.sym == SDLK_g)
            keyG = 1;
        if (event.key.keysym.sym == SDLK_h)
            keyH = 1;
        if (event.key.keysym.sym == SDLK_i)
            keyI = 1;
        if (event.key.keysym.sym == SDLK_j)
            keyJ = 1;
        if (event.key.keysym.sym == SDLK_k)
            keyK = 1;
        if (event.key.keysym.sym == SDLK_l)
            keyL = 1;
        if (event.key.keysym.sym == SDLK_m)
            keyM = 1;
        if (event.key.keysym.sym == SDLK_n)
            keyN = 1;
        if (event.key.keysym.sym == SDLK_o)
            keyO = 1;
        if (event.key.keysym.sym == SDLK_p)
            keyP = 1;
        if (event.key.keysym.sym == SDLK_q)
            keyQ = 1;
        if (event.key.keysym.sym == SDLK_r)
            keyR = 1;
        if (event.key.keysym.sym == SDLK_s)
            keyS = 1;
        if (event.key.keysym.sym == SDLK_t)
            keyT = 1;
        if (event.key.keysym.sym == SDLK_u)
            keyU = 1;
        if (event.key.keysym.sym == SDLK_v)
            keyV = 1;
        if (event.key.keysym.sym == SDLK_w)
            keyW = 1;
        if (event.key.keysym.sym == SDLK_x)
            keyX = 1;
        if (event.key.keysym.sym == SDLK_y)
            keyY = 1;
        if (event.key.keysym.sym == SDLK_z)
            keyZ = 1;
        if (event.key.keysym.sym == SDLK_0)
            key0 = 1;
        if (event.key.keysym.sym == SDLK_1)
            key1 = 1;
        if (event.key.keysym.sym == SDLK_2)
            key2 = 1;
        if (event.key.keysym.sym == SDLK_3)
            key3 = 1;
        if (event.key.keysym.sym == SDLK_4)
            key4 = 1;
        if (event.key.keysym.sym == SDLK_5)
            key5 = 1;
        if (event.key.keysym.sym == SDLK_6)
            key6 = 1;
        if (event.key.keysym.sym == SDLK_7)
            key7 = 1;
        if (event.key.keysym.sym == SDLK_8)
            key8 = 1;
        if (event.key.keysym.sym == SDLK_9)
            key9 = 1;
        if (event.key.keysym.sym == SDLK_SPACE)
            keySpacebar = 1;
        if (event.key.keysym.sym == SDLK_LCTRL)
            keyLCtrl = 1;
        if (event.key.keysym.sym == SDLK_LSHIFT)
            keyLShift = 1;
        if (event.key.keysym.sym == SDLK_LALT)
            keyLAlt = 1;
        if (event.key.keysym.sym == SDLK_ESCAPE)
            keyESC = 1;
        break;
    case SDL_KEYUP:
        if (event.key.keysym.sym == SDLK_a)
            keyA = 0;
        if (event.key.keysym.sym == SDLK_b)
            keyB = 0;
        if (event.key.keysym.sym == SDLK_c)
            keyC = 0;
        if (event.key.keysym.sym == SDLK_d)
            keyD = 0;
        if (event.key.keysym.sym == SDLK_e)
            keyE = 0;
        if (event.key.keysym.sym == SDLK_f)
            keyF = 0;
        if (event.key.keysym.sym == SDLK_g)
            keyG = 0;
        if (event.key.keysym.sym == SDLK_h)
            keyH = 0;
        if (event.key.keysym.sym == SDLK_i)
            keyI = 0;
        if (event.key.keysym.sym == SDLK_j)
            keyJ = 0;
        if (event.key.keysym.sym == SDLK_k)
            keyK = 0;
        if (event.key.keysym.sym == SDLK_l)
            keyL = 0;
        if (event.key.keysym.sym == SDLK_m)
            keyM = 0;
        if (event.key.keysym.sym == SDLK_n)
            keyN = 0;
        if (event.key.keysym.sym == SDLK_o)
            keyO = 0;
        if (event.key.keysym.sym == SDLK_p)
            keyP = 0;
        if (event.key.keysym.sym == SDLK_q)
            keyQ = 0;
        if (event.key.keysym.sym == SDLK_r)
            keyR = 0;
        if (event.key.keysym.sym == SDLK_s)
            keyS = 0;
        if (event.key.keysym.sym == SDLK_t)
            keyT = 0;
        if (event.key.keysym.sym == SDLK_u)
            keyU = 0;
        if (event.key.keysym.sym == SDLK_v)
            keyV = 0;
        if (event.key.keysym.sym == SDLK_w)
            keyW = 0;
        if (event.key.keysym.sym == SDLK_x)
            keyX = 0;
        if (event.key.keysym.sym == SDLK_y)
            keyY = 0;
        if (event.key.keysym.sym == SDLK_z)
            keyZ = 0;
        if (event.key.keysym.sym == SDLK_0)
            key0 = 0;
        if (event.key.keysym.sym == SDLK_1)
            key1 = 0;
        if (event.key.keysym.sym == SDLK_2)
            key2 = 0;
        if (event.key.keysym.sym == SDLK_3)
            key3 = 0;
        if (event.key.keysym.sym == SDLK_4)
            key4 = 0;
        if (event.key.keysym.sym == SDLK_5)
            key5 = 0;
        if (event.key.keysym.sym == SDLK_6)
            key6 = 0;
        if (event.key.keysym.sym == SDLK_7)
            key7 = 0;
        if (event.key.keysym.sym == SDLK_8)
            key8 = 0;
        if (event.key.keysym.sym == SDLK_9)
            key9 = 0;
        if (event.key.keysym.sym == SDLK_SPACE)
            keySpacebar = 0;
        if (event.key.keysym.sym == SDLK_LCTRL)
            keyLCtrl = 0;
        if (event.key.keysym.sym == SDLK_LSHIFT)
            keyLShift = 0;
        if (event.key.keysym.sym == SDLK_LALT)
            keyLAlt = 0;
        if (event.key.keysym.sym == SDLK_ESCAPE)
            keyESC = 0;
        break;
    }
    return 0;
}