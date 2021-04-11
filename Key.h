#pragma once
#include "StaticObject.h"
class Key :
    public StaticObject
{
public:
    Key(int x, int y, SDL_Renderer* renderer, LevelRenderer* level);
    ~Key() = default;
    void Render()override;
private:
    SDL_Texture* m_key;
};

