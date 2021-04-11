#include "KeyBlock.h"
#include "Image.h"

KeyBlock::KeyBlock(int x, int y, SDL_Renderer* renderer, LevelRenderer* level)
	: StaticObject{ x, y, renderer, level }
{
	m_keyBlock = Image::GetTexture("Assets/Collectable/KeyBlock.png", renderer);
}

void KeyBlock::Render()
{
	Image::PrintImage(m_renderer, m_keyBlock, m_sourceRect, m_destRect);
}
