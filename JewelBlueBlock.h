#pragma once
#include "StaticObject.h"
class JewelBlueBlock :
    public StaticObject
{
public:
    JewelBlueBlock(int x, int y, SDL_Renderer* renderer, Map* map);
    ~JewelBlueBlock() = default;
    void Render()override;
private:
    SDL_Texture* m_jewelBlueBlock;
};

