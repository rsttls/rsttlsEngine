#include <rsttlsRenderer/rsttlsRenderer.h>

rsttlsRenderer::~rsttlsRenderer()
{
    SDL_Quit();
}
int rsttlsRenderer::createWindowAndRenderer(const char *title, int w, int h, Uint32 windowFlags, Uint32 rendererFlags)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, windowFlags);
    renderer = SDL_CreateRenderer(window, -1, rendererFlags);
    if (window == nullptr || renderer == nullptr)
        throw 1;
    int ret = SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    if (ret != 0)
        logger.logSDL();
    return ret;
}
int rsttlsRenderer::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    int ret = SDL_SetRenderDrawColor(renderer, r, g, b, a);
    if (ret != 0)
        logger.logSDL();
    return ret;
}
void rsttlsRenderer::update()
{
    SDL_RenderPresent(renderer);
}
int rsttlsRenderer::clear()
{
    int ret = SDL_RenderClear(renderer);
    if (ret != 0)
        logger.logSDL();
    return ret;
}
int imageClass::loadImage(rsttlsRenderer *engine, const char *path)
{
    texture = IMG_LoadTexture(engine->renderer, path);
    if (texture == nullptr)
    {
        logger.log((std::string("Couldn't load texture: ") += path).c_str());
        return -1;
    }
    int ret = SDL_QueryTexture(texture, nullptr, nullptr, &rectOriginal.w, &rectOriginal.h);
    if (ret != 0)
        logger.logSDL();
    rect.h = rectOriginal.h;
    rect.w = rectOriginal.w;
    return ret;
}
imageClass::imageClass()
{
}
imageClass::imageClass(rsttlsRenderer *engine, const char *path)
{
    loadImage(engine, path);
}
void imageClass::scale(double s)
{
    rect.h = rectOriginal.h * s;
    rect.w = rectOriginal.w * s;
    centerPoint.x = rect.w / 2;
    centerPoint.y = rect.h / 2;
}
int imageClass::draw(rsttlsRenderer *engine)
{
    int ret = SDL_RenderCopyEx(engine->renderer, texture, NULL, &rect, rotation, &centerPoint, flip);
    if (ret != 0)
        logger.logSDL();
    return ret;
}
int imageClass::draw(rsttlsRenderer *engine, int x, int y)
{
    rect.x = x;
    rect.y = y;
    int ret = draw(engine);
    rect.x = rectOriginal.x;
    rect.y = rectOriginal.y;
    return ret;
}
void imageClass::setPos(int x, int y)
{
    rect.x = x;
    rect.y = y;
    rectOriginal.x = x;
    rectOriginal.y = y;
}
void imageClass::getPos(int *x, int *y)
{
    *x = rect.x;
    *y = rect.y;
}
imageClass::imageClass(rsttlsRenderer *engine, const char *path, int x, int y)
{
    loadImage(engine, path);
    setPos(x, y);
}