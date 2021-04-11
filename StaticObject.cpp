#include "StaticObject.h"

StaticObject::StaticObject(int x, int y, SDL_Renderer* renderer, Map* map)
	: GameObject{ x, y, renderer, map }
{
}

void StaticObject::Update()
{
	m_destRect.x = m_xPos;
	m_destRect.y = m_yPos;
}
