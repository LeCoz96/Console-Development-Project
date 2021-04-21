#pragma once
#include "StaticObject.h"

class Player;

class KeyBlock :
    public StaticObject
{
public:
    KeyBlock(int x, int y, SDL_Renderer* renderer, LevelRenderer* level);
    ~KeyBlock() = default;
    void Render()override;
    
    bool HasEnoughKeys(Player* player);
private:
    SDL_Texture* m_keyBlock;
};

