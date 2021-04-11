#pragma once
#include<SDL.h>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

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
	TOTAL
};

class Map
{
public:
	Map(SDL_Renderer* renderer, int size);
	~Map();

	int GetBlockSize();

	void RenderMap();

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

	SDL_Renderer* m_renderer;
	SDL_Rect m_sourceRect, m_destRect;

	int m_blockSize;
	int m_mapSize;

	std::vector<std::string> m_mapLayout;
	std::vector<SDL_Texture*> m_tileLayout;

	int GetMapHeight();
	int GetMapWidth();

	void LoadMap(std::string fileName);
};
