#pragma once
#include "StaticObject.h"
class JewelRed :
    public StaticObject
{
public:
    JewelRed(int x, int y, SDL_Renderer* renderer, Map* map);
    ~JewelRed() = default;
    void Render()override;
private:
    SDL_Texture* m_jewelRed;
};

