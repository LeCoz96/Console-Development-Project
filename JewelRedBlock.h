#pragma once
#include "StaticObject.h"
class JewelRedBlock :
    public StaticObject
{
public:
    JewelRedBlock(int x, int y, SDL_Renderer* renderer, Map* map);
    ~JewelRedBlock() = default;
    void Render()override;
private:
    SDL_Texture* m_jewelRedBlock;
};

