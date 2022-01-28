#pragma once
#include <rsttlsRenderer/rsttlsRenderer.h>

constexpr SDL_RendererFlip flipNone = SDL_RendererFlip::SDL_FLIP_NONE;
constexpr SDL_RendererFlip flipHorizontal = SDL_RendererFlip::SDL_FLIP_HORIZONTAL;
constexpr SDL_RendererFlip flipVertical = SDL_RendererFlip::SDL_FLIP_VERTICAL;

class gameObject
{
public:
    static inline rsttlsRenderer *renderer = nullptr;
    static inline double *cameraX = nullptr, *cameraY = nullptr;
    // texture variables
    imageClass texture;
    vector2d<double> position;
    double *rotation = &texture.rotation;
    vector2d<int *> rotationPoint = {&texture.centerPoint.x, &texture.centerPoint.y};
    SDL_RendererFlip *flip = &texture.flip;
    int loadTexture(const char *path);
    int draw();
    int update();
};

class physicsObject : public gameObject
{
public:
    // other
    vector2d<double> velocity;
    double friction = 0.01;
    vector2d<double> acceleration;
    double maxSpeed = 5;
    int update();
};


class amogusObject : public gameObject
{
public:
    bool direction;
    int update();
};