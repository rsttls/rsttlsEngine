#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <string>
class loggerClass
{
protected:
    const char *getError(int error);

public:
    std::ofstream file;
    ~loggerClass();
    int init();
    void log(const char *text);
    void logSDL();
    void logError(int error);
};
extern loggerClass logger;