#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <logger/logger.h>

template <class T>
struct vector2d
{
    T x, y;
};

class rsttlsRenderer
{
public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    /*@param title Char array for window title
     * @param w Width of the window
     * @param h Height of the window
     * @param windowFlags SDL_WIDNOW_FLAGS
     * @param rendererFlags SDL_RENDERER_FLAGS
     */
    ~rsttlsRenderer();
    /*@param title Char array for window title
     * @param w Width of the window
     * @param h Height of the window
     * @param windowFlags SDL_WIDNOW_FLAGS
     * @param rendererFlags SDL_RENDERER_FLAGS
     */
    int createWindowAndRenderer(const char *title, int w, int h, Uint32 windowFlags, Uint32 rendererFlags);
    /// Update window
    void update();
    /// Overrides every pixel with background color
    int clear();
    /// Sets renderer color via rgba values
    int setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
};

class imageClass
{
public:
    SDL_Texture *texture = nullptr;
    SDL_Rect rectOriginal, rect;
    double rotation = 0;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Point centerPoint;
    int *x = &rectOriginal.x, *y = &rectOriginal.y;
    /**Loads a img file into memory
     * @param *engine Engine to which it's going to be rendered
     * @param path Path to img file
     */
    int loadImage(rsttlsRenderer *engine, const char *path);
    imageClass();
    /**Loads a img file into memory
     * @param *engine Engine to which it's going to be rendered
     * @param path Path to img file
     */
    imageClass(rsttlsRenderer *engine, const char *path);
    /**Loads a img file into memory
     * @param *engine Engine to which it's going to be rendered
     * @param path Path to img file
     * @param x x position of the img
     * @param y y position of the img
     */
    imageClass(rsttlsRenderer *engine, const char *path, int x, int y);
    /**Sets the scale of the image
     * @param s Scale by s
     */
    void scale(double s);
    /* @param x x position of the img
     * @param y y position of the img
     */
    void setPos(int x, int y);
    /*
    @param *x Pointer to int where to store x position
    @param *y Pointer to int where to store y position
    */
    void getPos(int *x, int *y);
    /// Draw the img
    int draw(rsttlsRenderer *engine);
    ////Draws image at x and y @param x position  @param y position
    int draw(rsttlsRenderer *engine, int x, int y);
};
