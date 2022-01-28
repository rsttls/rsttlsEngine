#pragma once
#include <gameObject/gameObject.h>
#include <unordered_map>
class gameObjectManagerClass
{
public:
    std::unordered_map<int, gameObject> gameObjectMap;
    int createObject(int id, gameObject& object);
    int deleteObject(int id);
    gameObject &operator[](int id);
};