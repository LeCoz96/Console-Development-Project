#include"MovingObject.h"
#include"Map.h"

MovingObject::MovingObject(int x, int y, int speed, SDL_Renderer* renderer, Map* map)
	: GameObject{ x, y, renderer, map }, m_moveSpeed{ speed }
{
}

void MovingObject::Left()
{
	int x = m_xPos - m_moveSpeed;
	if (!m_map->IsWall(x, m_yPos) &&
		!m_map->IsWall(x, (m_yPos + m_blockSize - 1)))
	{
		m_xPos = x;
	}
}

void MovingObject::Right()
{
	int x = m_xPos + m_moveSpeed;
	if (!m_map->IsWall((x + m_blockSize - 1), m_yPos) &&
		!m_map->IsWall((x + m_blockSize - 1), (m_yPos + m_blockSize - 1)))
	{
		m_xPos = x;
	}
}

void MovingObject::Up()
{
	int y = m_yPos - m_moveSpeed;
	if (!m_map->IsWall(m_xPos, y)&&
		!m_map->IsWall(m_xPos + (m_blockSize - 1), y))
	{
		m_yPos = y;
	}
}

void MovingObject::Down()
{
	int y = m_yPos + m_moveSpeed;
	if (!m_map->IsWall(m_xPos, (y + m_blockSize - 1)) &&
		!m_map->IsWall((m_xPos + m_blockSize - 1), (y + m_blockSize - 1)))
	{
		m_yPos = y;
	}
}
