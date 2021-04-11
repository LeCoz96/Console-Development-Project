#include"Map.h"
#include"Image.h"

Map::Map(SDL_Renderer* renderer, int size)
	:m_renderer{ renderer }, m_blockSize{ size }
{
	m_mapSize = 25;

	LoadMap("Assets/Map/Map03.txt");

	m_grass = Image::GetTexture("Assets/Environment/.-Grass.png", renderer);
	m_bush = Image::GetTexture("Assets/Environment/0-Bush.png", renderer);
	m_centerBottom = Image::GetTexture("Assets/Environment/1-HedgeDownCentre.png", renderer);
	m_centerTop = Image::GetTexture("Assets/Environment/2-HedgeTopCentre.png", renderer);
	m_centerRight = Image::GetTexture("Assets/Environment/3-HedgeRightCentre.png", renderer);
	m_centerLeft = Image::GetTexture("Assets/Environment/4-HedgeLeftCentre.png", renderer);
	m_cornerBottomLeft = Image::GetTexture("Assets/Environment/5-HedgeBottomLeftCorner.png", renderer);
	m_cornerBottomRight = Image::GetTexture("Assets/Environment/6-HedgeBottomRightCorner.png", renderer);
	m_cornerTopLeft = Image::GetTexture("Assets/Environment/7-HedgeTopLeftCorner.png", renderer);
	m_cornerTopRight = Image::GetTexture("Assets/Environment/8-HedgeTopRightCorner.png", renderer);
	m_middle = Image::GetTexture("Assets/Environment/9-HedgeMiddle.png", renderer);

	m_sourceRect.w = m_sourceRect.h = m_blockSize;
	m_destRect.w = m_destRect.h = m_blockSize;
}

Map::~Map()
{
	m_mapLayout.clear();
}

int Map::GetBlockSize()
{
	return m_blockSize;
}

void Map::RenderMap()
{
	for (int row = 0; row < m_mapSize; row++)
	{
		for (int column = 0; column < m_mapSize; column++)
		{
			switch (m_mapLayout[row][column])
			{
			case '.':
				m_destRect.x = column * m_blockSize;
				m_destRect.y = row * m_blockSize;
				Image::PrintImage(m_renderer, m_grass, m_sourceRect, m_destRect);
				break;

			case '0':
				m_destRect.x = column * m_blockSize;
				m_destRect.y = row * m_blockSize;
				Image::PrintImage(m_renderer, m_bush, m_sourceRect, m_destRect);
				break;

			case '1':
				m_destRect.x = column * m_blockSize;
				m_destRect.y = row * m_blockSize;
				Image::PrintImage(m_renderer, m_centerBottom, m_sourceRect, m_destRect);
				break;

			case '2':
				m_destRect.x = column * m_blockSize;
				m_destRect.y = row * m_blockSize;
				Image::PrintImage(m_renderer, m_centerTop, m_sourceRect, m_destRect);
				break;

			case '3':
				m_destRect.x = column * m_blockSize;
				m_destRect.y = row * m_blockSize;
				Image::PrintImage(m_renderer, m_centerRight, m_sourceRect, m_destRect);
				break;

			case '4':
				m_destRect.x = column * m_blockSize;
				m_destRect.y = row * m_blockSize;
				Image::PrintImage(m_renderer, m_centerLeft, m_sourceRect, m_destRect);
				break;

			case '5':
				m_destRect.x = column * m_blockSize;
				m_destRect.y = row * m_blockSize;
				Image::PrintImage(m_renderer, m_cornerBottomLeft, m_sourceRect, m_destRect);
				break;

			case '6':
				m_destRect.x = column * m_blockSize;
				m_destRect.y = row * m_blockSize;
				Image::PrintImage(m_renderer, m_cornerBottomRight, m_sourceRect, m_destRect);
				break;

			case '7':
				m_destRect.x = column * m_blockSize;
				m_destRect.y = row * m_blockSize;
				Image::PrintImage(m_renderer, m_cornerTopLeft, m_sourceRect, m_destRect);
				break;

			case '8':
				m_destRect.x = column * m_blockSize;
				m_destRect.y = row * m_blockSize;
				Image::PrintImage(m_renderer, m_cornerTopRight, m_sourceRect, m_destRect);
				break;

			case '9':
				m_destRect.x = column * m_blockSize;
				m_destRect.y = row * m_blockSize;
				Image::PrintImage(m_renderer, m_middle, m_sourceRect, m_destRect);
				break;

			default:
				break;
			}
		}
	}
}

bool Map::IsWall(int x, int y)
{
	if (m_mapLayout[y / m_blockSize][x / m_blockSize] != '.')
	{
		return true;
	}
	if (m_mapLayout[y / m_blockSize][x / m_blockSize] == '0')
	{
		return true;
	}
	return false;
}

int Map::GetMapHeight()
{
	return m_mapLayout.size();
}

int Map::GetMapWidth()
{
	return m_mapLayout[0].length();
}

void Map::LoadMap(std::string fileName)
{
	std::string line;
	std::ifstream file(fileName);
	while (file >> line)
	{
		m_mapLayout.push_back(line);
	}
	file.close();
}
