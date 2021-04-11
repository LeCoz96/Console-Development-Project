#pragma once
#include "StaticObject.h"
class KeyBlock :
    public StaticObject
{
public:
    KeyBlock(int x, int y, SDL_Renderer* renderer, Map* map);
    ~KeyBlock() = default;
    void Render()override;
private:
    SDL_Texture* m_keyBlock;
};

