#include "logger.h"

int loggerClass::init()
{
    file.open("latest.log");
    if (file.is_open())
        return 0;
    return 1;
}

void loggerClass::log(const char *text)
{
    std::cout << text << std::endl;
    file << text << std::endl;
}

void loggerClass::logSDL()
{
    std::cout << SDL_GetError() << std::endl;
    file << SDL_GetError() << std::endl;
    SDL_ClearError();
}

const char *loggerClass::getError(int error)
{
    switch (error)
    {
    case 1:
        return "Failed to create window or renderer";
    case 2:
        return "Couldn't load ttf file";
    default:
        return "Unknown error";
    }
}

void loggerClass::logError(int error)
{
    std::cout << getError(error) << std::endl;
    file << getError(error) << std::endl;
}

loggerClass::~loggerClass()
{
    if (file.is_open())
        file.close();
}