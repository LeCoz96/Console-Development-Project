#include "StaticObject.h"

StaticObject::StaticObject(int x, int y, SDL_Renderer* renderer, LevelRenderer* level)
	: GameObject{ x, y, renderer, level }
{
}

void StaticObject::Update()
{
	m_destRect.x = m_xPos;
	m_destRect.y = m_yPos;
}
