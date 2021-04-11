#include "LevelRenderer.h"

LevelRenderer::LevelRenderer(SDL_Renderer* renderer, int blockSize)
	: m_renderer{renderer}, m_blockSize{blockSize}
{
}

LevelRenderer::~LevelRenderer()
{
}

int LevelRenderer::GetBlockSize()
{
	return 0;
}

void LevelRenderer::RenderLevel()
{
}
