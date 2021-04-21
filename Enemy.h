#pragma once
#include "MovingObject.h"
#include<vector>
#include<iostream>
#include<random>
class Enemy :
    public MovingObject
{
public:
    Enemy(int x, int y, SDL_Renderer* renderer, LevelRenderer* level, int speed = 16);
    ~Enemy() = default;
    
    void Patrol();
    void Render()override;
    void Update()override;
    void MoveInRandomDirection();
private:
    std::vector<SDL_Texture*> m_listOfEnemyTexture;

    int m_currentTimer, m_jumpInterval, m_landInterval, m_frame;
    bool m_isJumping, m_changeFrame{ false };
};

