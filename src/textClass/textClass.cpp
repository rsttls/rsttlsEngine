#include <textClass/textClass.h>
textClass::~textClass()
{
    if (texture != NULL)
        SDL_DestroyTexture(texture);
    if (surface != NULL)
        SDL_FreeSurface(surface);
}

int textClass::update()
{
    return update(text.c_str());
}

int textClass::update(const char *text)
{
    if (texture != nullptr)
        SDL_DestroyTexture(texture);
    if (surface != nullptr)
        SDL_FreeSurface(surface);
    if (font == nullptr)
        return -2;
    surface = TTF_RenderText_Blended(font, text, color);
    if (surface == nullptr)
    {
        logger.log("Failed to create surface from text: ");
        logger.log(text);
        return -1;
    }
    texture = SDL_CreateTextureFromSurface(renderer->renderer, surface);
    int ret = SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
    if (ret != 0)
        logger.logSDL();
    rect.w *= scale;
    rect.h *= scale;
    return ret;
}
int textClass::draw()
{
    if (texture == nullptr)
        return -1;
    int ret = SDL_RenderCopy(renderer->renderer, texture, NULL, &rect);
    if (ret != 0)
        logger.logSDL();
    return ret;
}
int textClass::draw(int x, int y)
{
    int cx = rect.x, cy = rect.y;
    rect.x = x;
    rect.y = y;
    int ret = draw();
    rect.x = cx;
    rect.y = cy;
    return ret;
}