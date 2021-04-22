#include"GameObject.h"
#include"LevelRenderer.h"
#include"Image.h"

GameObject::GameObject(int x, int y, SDL_Renderer* renderer, LevelRenderer* level)
	: m_xPos{ x }, m_yPos{ y }, m_renderer{ renderer }, m_level{ level }
{
	m_currentFrame = 0;
	m_animationSpeed = 0;
	m_imageSize = 2;

	m_blockSize = m_level->GetBlockSize();

	m_sourceRect.w = 16;
	m_sourceRect.h = 16;
	m_destRect.w = m_sourceRect.w * m_imageSize;
	m_destRect.h = m_sourceRect.h * m_imageSize;
}

void GameObject::SetX(int value)
{
	m_xPos = value;
}

void GameObject::SetY(int value)
{
	m_yPos = value;
}

int GameObject::GetX()
{
	return m_xPos;
}

int GameObject::GetY()
{
	return m_yPos;
}

void GameObject::Render()
{
	SDL_RenderCopy(m_renderer, m_listOfTextures[0], &m_imageDictionary[0].first, &m_destRect);
}

bool GameObject::Collision(GameObject* object)
{
	if (m_xPos <= object->GetX() + (m_blockSize - 1) &&
		m_xPos + (m_blockSize - 1) >= object->GetX() &&
		m_yPos <= object->GetY() + (m_blockSize - 1) &&
		m_yPos + (m_blockSize - 1) >= object->GetY())
	{
		return true;
	}

	return false;
}

void GameObject::Update()
{
	m_destRect.x = m_xPos;
	m_destRect.y = m_yPos;
}

