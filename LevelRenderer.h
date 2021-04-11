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
	cornerTopLeft,
	cornerTopRight,
	middle,
	TOTAL
};

class AreaLoader;

class LevelRenderer
{
public:
	LevelRenderer(SDL_Renderer* renderer, int blockSize);
	~LevelRenderer();

	int GetBlockSize();

	void RenderLevel();

	bool IsWall(int x, int y);

private:


	SDL_Texture* m_grass;
	SDL_Texture* m_bush;
	SDL_Texture* m_centerBottom;
	SDL_Texture* m_centerTop;
	SDL_Texture* m_centerRight;
	SDL_Texture* m_centerLeft;
	SDL_Texture* m_cornerBottomLeft;
	SDL_Texture* m_cornerBottomRight;
	SDL_Texture* m_cornerTopLeft;
	SDL_Texture* m_cornerTopRight;
	SDL_Texture* m_middle;


	int m_blockSize;

	int m_levelSize;

	SDL_Renderer* m_renderer;
	SDL_Rect m_sourceRect, m_destRect;

	AreaLoader* m_load;

	std::vector<std::string> m_levelLayout;
	std::vector<SDL_Texture*> m_tileLayout;

};

