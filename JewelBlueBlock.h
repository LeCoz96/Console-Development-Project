#pragma once
#include "StaticObject.h"
class JewelBlueBlock :
    public StaticObject
{
public:
    JewelBlueBlock(int x, int y, SDL_Renderer* renderer, LevelRenderer* level);
    ~JewelBlueBlock() = default;
    void Render()override;
private:
    SDL_Texture* m_jewelBlueBlock;
};

