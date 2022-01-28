#pragma once
#include <rsttlsRenderer/rsttlsRenderer.h>
#include <SDL2/SDL_ttf.h>
class textClass
{
public:
    static inline rsttlsRenderer *renderer = nullptr;
    static inline TTF_Font *font = nullptr;
    const SDL_Color color = {255, 255, 255};
    SDL_Surface *surface = nullptr;
    SDL_Texture *texture = nullptr;
    SDL_Rect rect;
    vector2d<int &> position = {rect.x, rect.y};
    double scale = 1;
    std::string text;
    ///Creates texture from std::string text;
    int update();
    ///Creates texture from input
    int update(const char *text);
    int draw();
    int draw(int x, int y);
    ~textClass();
};