#pragma once
#include "StaticObject.h"
class JewelBlue :
    public StaticObject
{
public:
    JewelBlue(int x, int y, SDL_Renderer* renderer, LevelRenderer* level);
    ~JewelBlue() = default;
    void Render()override;

    int m_jewelValue{ 0 };
private:
    SDL_Texture* m_jewelBlue;
};

