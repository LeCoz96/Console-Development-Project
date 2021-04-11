#include "JewelRed.h"
#include "Image.h"

JewelRed::JewelRed(int x, int y, SDL_Renderer* renderer, Map* map)
	: StaticObject{ x, y, renderer, map }
{
	m_jewelRed = Image::GetTexture("Assets/Collectable/JewelRed.png", renderer);
}

void JewelRed::Render()
{
	Image::PrintImage(m_renderer, m_jewelRed, m_sourceRect, m_destRect);
}
