#include "JewelBlue.h"
#include"Image.h"

JewelBlue::JewelBlue(int x, int y, SDL_Renderer* renderer, LevelRenderer* level)
	: StaticObject{ x, y, renderer, level }
{
	m_jewelBlue = Image::GetTexture("Assets/Collectable/JewelBlue.png", renderer);
}

void JewelBlue::Render()
{
	Image::PrintImage(m_renderer, m_jewelBlue, m_sourceRect, m_destRect);
}
