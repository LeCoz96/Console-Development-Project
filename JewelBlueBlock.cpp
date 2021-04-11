#include "JewelBlueBlock.h"
#include "Image.h"

JewelBlueBlock::JewelBlueBlock(int x, int y, SDL_Renderer* renderer, Map* map)
	: StaticObject{ x, y, renderer, map }
{
	m_jewelBlueBlock = Image::GetTexture("Assets/Collectable/BlueJewelBlock.png", renderer);
}

void JewelBlueBlock::Render()
{
	Image::PrintImage(m_renderer, m_jewelBlueBlock, m_sourceRect, m_destRect);
}
