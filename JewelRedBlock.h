#pragma once
#include "StaticObject.h"
class JewelRedBlock :
    public StaticObject
{
public:
    JewelRedBlock(int x, int y, SDL_Renderer* renderer, LevelRenderer* level);
    ~JewelRedBlock() = default;
    void Render()override;
private:
    SDL_Texture* m_jewelRedBlock;
};

