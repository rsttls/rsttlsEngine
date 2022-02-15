#pragma once
#include <eventHandler/eventHandler.h>
#include <rsttlsRenderer/rsttlsRenderer.h>
#include <gameObject/gameObject.h>
#include <logger/logger.h>
#include <textClass/textClass.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_sdl.h>
#include <imgui/imgui_impl_sdlrenderer.h>
class gameClass
{
public:
    // components
    rsttlsRenderer *renderer = nullptr;
    SDL_Event event;
    eventHandlerClass eventHandler;
    // time keeping
    uint64_t startTime, eventTime, updateTime, drawTime;
    uint64_t times[4];
    // variables
    int windowWidth, windowHeight;
    double cameraX, cameraY;
    bool gameActive;
    // functions
    gameClass();
    ~gameClass();
    int handleEvents();
    int init();
    int loadAssets();
    int gui();
    int update();
    int draw();
    gameObject dog;
    amogusObject amogus;
    physicsObject player;
};