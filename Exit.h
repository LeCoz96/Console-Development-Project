#pragma once
#include "StaticObject.h"
class Exit :
    public StaticObject
{
public:
    Exit(int x, int y, SDL_Renderer* renderer, Map* map);
    ~Exit() = default;
    void Render()override;
private:
    SDL_Texture* m_exit;
};

