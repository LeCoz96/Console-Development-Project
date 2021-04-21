#include "Enemy.h"
#include"Image.h"

Enemy::Enemy(int x, int y, SDL_Renderer* renderer, LevelRenderer* level, int speed)
	: MovingObject{ x, y, renderer, level, speed }
{
	m_currentTimer = 0;
	m_jumpInterval = 200;
	m_landInterval = 60;

	m_listOfEnemyTexture.push_back(Image::GetTexture("Assets/Enemy/RedBlob01.png", renderer));
	m_listOfEnemyTexture.push_back(Image::GetTexture("Assets/Enemy/RedBlob02.png", renderer));
	m_listOfEnemyTexture.push_back(Image::GetTexture("Assets/Enemy/RedBlob03.png", renderer));
	m_listOfEnemyTexture.push_back(Image::GetTexture("Assets/Enemy/RedBlob04.png", renderer));
}

void Enemy::Patrol()
{
	++m_currentTimer;

	if (!m_isJumping)
	{
		if (m_currentTimer == m_jumpInterval)
		{
			m_changeFrame = true;
			m_currentTimer = 0;
			m_isJumping = true;
			MoveInRandomDirection();
		}
	}
	else
	{
		if (m_currentTimer == m_landInterval)
		{
			m_changeFrame = true;
			m_currentTimer = 0;
			m_isJumping = false;
		}
	}
}

void Enemy::Render()
{
	if (m_changeFrame)
	{
		++m_frame;
		if (m_frame >= m_listOfEnemyTexture.size())
		{
			m_frame = 0;
		}
		m_changeFrame = false;
	}

	Image::PrintImage(m_renderer, m_listOfEnemyTexture[m_frame], m_sourceRect, m_destRect);
}

void Enemy::Update()
{
	m_destRect.x = m_xPos;
	m_destRect.y = m_yPos;
}

void Enemy::MoveInRandomDirection()
{
	std::random_device rd;	// Get random number
	std::mt19937 gen(rd());	// 
	std::uniform_int_distribution<> distr(0, 3);

	switch (distr(gen))
	{
	case 0:
		Up();
		break;
	case 1:
		Down();
		break;
	case 2:
		Left();
		break;
	case 3:
		Right();
		break;
	default:
		break;
	}
}
