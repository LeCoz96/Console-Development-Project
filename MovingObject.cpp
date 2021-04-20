#include"MovingObject.h"
#include"LevelRenderer.h"
#include "Timer.h"

MovingObject::MovingObject(int x, int y, int speed, SDL_Renderer* renderer, LevelRenderer* level)
	: GameObject{ x, y, renderer, level }, m_moveSpeed{ speed }
{
}

void MovingObject::Left()
{
	int x = m_xPos - m_moveSpeed;
	if (!m_level->IsWall(x, m_yPos) &&
		!m_level->IsWall(x, (m_yPos + m_blockSize - 1)))
	{
		m_xPos = x;
	}
}

void MovingObject::Right()
{
	int x = m_xPos + m_moveSpeed;
	if (!m_level->IsWall((x + m_blockSize - 1), m_yPos) &&
		!m_level->IsWall((x + m_blockSize - 1), (m_yPos + m_blockSize - 1)))
	{
		m_xPos = x;
	}
}

void MovingObject::Up()
{
	int y = m_yPos - m_moveSpeed;
	if (!m_level->IsWall(m_xPos, y)&&
		!m_level->IsWall(m_xPos + (m_blockSize - 1), y))
	{
		m_yPos = y;
	}
}

void MovingObject::Down()
{
	int y = m_yPos + m_moveSpeed;
	if (!m_level->IsWall(m_xPos, (y + m_blockSize - 1)) &&
		!m_level->IsWall((m_xPos + m_blockSize - 1), (y + m_blockSize - 1)))
	{
		m_yPos = y;
	}
}
