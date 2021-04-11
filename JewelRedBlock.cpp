#include "JewelRedBlock.h"
#include "Image.h"

JewelRedBlock::JewelRedBlock(int x, int y, SDL_Renderer* renderer, Map* map)
	: StaticObject{ x, y, renderer, map }
{
	m_jewelRedBlock = Image::GetTexture("Assets/Collectable/RedJewelBlock.png", renderer);
}

void JewelRedBlock::Render()
{
	Image::PrintImage(m_renderer, m_jewelRedBlock, m_sourceRect, m_destRect);
}
