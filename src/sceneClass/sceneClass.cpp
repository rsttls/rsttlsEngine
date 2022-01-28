#include <sceneClass/sceneClass.h>

int sceneClass::draw()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->draw();
    }
    return 0;
}

int sceneClass::update()
{
    for (int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->update();
    }
    return 0;
}