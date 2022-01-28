#include "gameObjectManager.h"

int gameObjectManagerClass::createObject(int id, gameObject& object)
{
    gameObjectMap[id]=object;
    return 0;
}
gameObject &gameObjectManagerClass::operator[](int id)
{
    return gameObjectMap[id];
}