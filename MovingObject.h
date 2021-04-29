#pragma once
#include "GameObject.h"
class MovingObject :
    public GameObject
{
public:
    MovingObject(int x, int y, SDL_Renderer* renderer, LevelRenderer* level, int speed = 0);
    MovingObject() = default;
    ~MovingObject() = default;

    virtual void Left();
    virtual void Right();
    virtual void Up();
    virtual void Down();
   
protected:
    int m_moveSpeed;

};

