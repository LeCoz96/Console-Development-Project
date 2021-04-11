#pragma once
#include "StaticObject.h"
class JewelBlue :
    public StaticObject
{
public:
    JewelBlue(int x, int y, SDL_Renderer* renderer, Map* map);
    ~JewelBlue() = default;
    void Render()override;
private:
    SDL_Texture* m_jewelBlue;
};

