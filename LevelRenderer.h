#pragma once
#include <SDL.h>
#include <vector>
#include <iostream>

enum Tiles
{
	grass,
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
class Player;

class LevelRenderer
{
public:
	LevelRenderer(SDL_Renderer* renderer, int blockSize);
	~LevelRenderer();

	int GetBlockSize();

	void RenderLevel();

	void NextArea();

	void SetPlayer(Player* player);

	bool IsWall(int x, int y);

private:

	int m_levelToLoad = 0;

	int m_blockSize;

	int m_levelSize;

	SDL_Renderer* m_renderer;
	SDL_Rect m_sourceRect, m_destRect;

	AreaLoader* m_load;
	Player* m_player;

	std::vector<std::string> m_levelLayout;
	std::vector<SDL_Texture*> m_tileLayout;

};

