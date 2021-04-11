#pragma once
#include "GameObject.h"
class MovingObject :
    public GameObject
{
public:
    MovingObject(int x, int y, int speed, SDL_Renderer* renderer, Map* map);
    MovingObject() = default;
    ~MovingObject() = default;

    virtual void Left();
    virtual void Right();
    virtual void Up();
    virtual void Down();
   
protected:
    int m_moveSpeed;
};

