#include"GameObject.h"
#include"Map.h"
#include"Image.h"

GameObject::GameObject(int x, int y, SDL_Renderer* renderer, Map* map)
	: m_xPos{ x }, m_yPos{ y }, m_renderer{ renderer }, m_map{ map }
{
	m_currentFrame = 0;
	m_animationSpeed = 0;
	m_imageSize = 2;

	m_blockSize = m_map->GetBlockSize();

	m_sourceRect.w = m_destRect.w = 32;
	m_sourceRect.h = m_destRect.h = 32;
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
	Animate();
	m_destRect.x = m_xPos;
	m_destRect.y = m_yPos;
}

void GameObject::Animate()
{
	for (size_t i = 0; i < m_imageDictionary.size(); i++)
	{
		m_imageDictionary[i].first.x = m_imageDictionary[i].first.w * static_cast<int>(((SDL_GetTicks() / m_animationSpeed) % m_imageDictionary[i].second));
	}
	m_destRect.w = m_imageDictionary[0].first.w * m_imageSize;
	m_destRect.h = m_imageDictionary[0].first.h * m_imageSize;
}
