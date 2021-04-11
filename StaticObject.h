#pragma once
#include "GameObject.h"
class StaticObject :
    public GameObject
{
public:
    StaticObject(int x, int y, SDL_Renderer* renderer, Map* map);
    ~StaticObject() = default;
    void Update()override;
};

