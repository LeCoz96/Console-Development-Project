#include "KeyBlock.h"
#include "Image.h"
#include "Player.h"

KeyBlock::KeyBlock(int x, int y, SDL_Renderer* renderer, LevelRenderer* level)
	: StaticObject{ x, y, renderer, level }
{
	m_keyBlock = Image::GetTexture("Assets/Collectable/KeyBlock.png", renderer);
}

void KeyBlock::Render()
{
	Image::PrintImage(m_renderer, m_keyBlock, m_sourceRect, m_destRect);
}

bool KeyBlock::HasEnoughKeys()
{
	if (m_player->GetKeys() > 0)
	{
		return true;
	}
	return false;
}
