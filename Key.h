#pragma once
#include "StaticObject.h"
class Key :
    public StaticObject
{
public:
    Key(int x, int y, SDL_Renderer* renderer, Map* map);
    ~Key() = default;
    void Render()override;
private:
    SDL_Texture* m_key;
};

