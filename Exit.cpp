#include "Exit.h"
#include"Image.h"

Exit::Exit(int x, int y, SDL_Renderer* renderer, LevelRenderer* level)
	: StaticObject{ x, y, renderer, level }
{
	m_exit = Image::GetTexture("Assets/Environment/Hole.png", renderer);
}

void Exit::Render()
{
	Image::PrintImage(m_renderer, m_exit, m_sourceRect, m_destRect);
}
