#pragma once
#include <rsttlsRenderer/rsttlsRenderer.h>
#include <gameObject/gameObject.h>
//#include <gameObjectManager/gameObjectManager.h>
#include <textClass/textClass.h>
#include <logger/logger.h>
class gameClass
{
public:
    // components
    rsttlsRenderer *renderer = nullptr;
    SDL_Event event;
    // variables
    int windowWidth, windowHeight;
    double cameraX, cameraY;
    bool gameActive;
    bool moveLeft = 0, moveRight = 0, moveUp = 0, moveDown = 0, rotateRight = 0, rotateLeft = 0;
    gameClass();
    ~gameClass();
    int handleEvents();
    int init();
    int loadAssets();
    int update();
    int draw();
    gameObject dog;
    amogusObject amogus;
    physicsObject player;
    physicsObject player1;
};