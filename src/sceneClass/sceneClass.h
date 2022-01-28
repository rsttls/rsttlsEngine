#pragma once
#include <gameObject/gameObject.h>
#include <rsttlsRenderer/rsttlsRenderer.h>
#include <vector>
class sceneClass
{
public:
    std::vector<gameObject *> gameObjects;
    int draw();
    int update();
};