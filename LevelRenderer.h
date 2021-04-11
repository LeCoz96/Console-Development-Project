#pragma once
#include <SDL.h>
#include <vector>
#include <iostream>

enum Tiles
{
	grass,
	bush,
	centerBottom,
	centerTop,
	centerRight,
	centerLeft,
	cornerBottomLeft,
	cornerBottomRight,
	cornerTopTop,
	cornerTopBottom,
	middle,
	exit,
	TOTAL
};

class LevelRenderer
{
public:
	LevelRenderer(SDL_Renderer* renderer, int blockSize);
	~LevelRenderer();

	int GetBlockSize();

	void RenderLevel();

private:
	int m_blockSize;

	int m_mapSize;

	SDL_Renderer* m_renderer;
	SDL_Rect m_sourceRect, m_destRect;

	std::vector<SDL_Texture*> m_tileLayout;

};

