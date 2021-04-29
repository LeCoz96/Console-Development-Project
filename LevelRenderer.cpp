#include "LevelRenderer.h"
#include "AreaLoader.h"
#include "Image.h"
#include "Player.h"

LevelRenderer::LevelRenderer(SDL_Renderer* renderer, int blockSize)
	: m_renderer{ renderer }, m_blockSize{ blockSize }
{
	m_levelSize = 25;

	m_tileLayout.push_back(Image::GetTexture("Assets/Environment/.-Grass.png", renderer));
	m_tileLayout.push_back(Image::GetTexture("Assets/Environment/1-HedgeDownCentre.png", renderer));
	m_tileLayout.push_back(Image::GetTexture("Assets/Environment/2-HedgeTopCentre.png", renderer));
	m_tileLayout.push_back(Image::GetTexture("Assets/Environment/3-HedgeRightCentre.png", renderer));
	m_tileLayout.push_back(Image::GetTexture("Assets/Environment/4-HedgeLeftCentre.png", renderer));
	m_tileLayout.push_back(Image::GetTexture("Assets/Environment/5-HedgeBottomLeftCorner.png", renderer));
	m_tileLayout.push_back(Image::GetTexture("Assets/Environment/6-HedgeBottomRightCorner.png", renderer));
	m_tileLayout.push_back(Image::GetTexture("Assets/Environment/7-HedgeTopLeftCorner.png", renderer));
	m_tileLayout.push_back(Image::GetTexture("Assets/Environment/8-HedgeTopRightCorner.png", renderer));
	m_tileLayout.push_back(Image::GetTexture("Assets/Environment/9-HedgeMiddle.png", renderer));

	m_load = new AreaLoader();

	m_levelLayout = m_load->LoadArea(Area01);

	m_sourceRect.w = m_sourceRect.h = m_blockSize;
	m_destRect.w = m_destRect.h = m_blockSize;
}

LevelRenderer::~LevelRenderer()
{
	m_levelLayout.clear();
}

int LevelRenderer::GetBlockSize()
{
	return m_blockSize;
}

void LevelRenderer::RenderLevel()
{
	for (int row = 0; row < m_levelSize; row++)
	{
		for (int column = 0; column < m_levelSize; column++)
		{
			m_destRect.x = column * m_blockSize;
			m_destRect.y = row * m_blockSize;

			Image::PrintImage(m_renderer, m_tileLayout[grass], m_sourceRect, m_destRect);

			switch (m_levelLayout[row][column])
			{
			case '1':
				Image::PrintImage(m_renderer, m_tileLayout[centerBottom], m_sourceRect, m_destRect);
				break;

			case '2':
				Image::PrintImage(m_renderer, m_tileLayout[centerTop], m_sourceRect, m_destRect);
				break;

			case '3':
				Image::PrintImage(m_renderer, m_tileLayout[centerRight], m_sourceRect, m_destRect);
				break;

			case '4':
				Image::PrintImage(m_renderer, m_tileLayout[centerLeft], m_sourceRect, m_destRect);
				break;

			case '5':
				Image::PrintImage(m_renderer, m_tileLayout[cornerBottomLeft], m_sourceRect, m_destRect);
				break;

			case '6':
				Image::PrintImage(m_renderer, m_tileLayout[cornerBottomRight], m_sourceRect, m_destRect);
				break;

			case '7':
				Image::PrintImage(m_renderer, m_tileLayout[cornerTopLeft], m_sourceRect, m_destRect);
				break;

			case '8':
				Image::PrintImage(m_renderer, m_tileLayout[cornerTopRight], m_sourceRect, m_destRect);
				break;

			case '9':
				Image::PrintImage(m_renderer, m_tileLayout[middle], m_sourceRect, m_destRect);
				break;

			case '!':
				Image::PrintImage(m_renderer, m_tileLayout[grass], m_sourceRect, m_destRect);
				break;

			default:
				break;
			}
		}
	}
}

void LevelRenderer::NextArea()
{
	++m_levelToLoad;

	if (m_levelToLoad >= Areas::TotalAreas)
	{
		m_player->m_playerFinishedGame = true;
	}
	else
	{
		m_levelLayout = m_load->LoadArea(static_cast<Areas>(m_levelToLoad)); // Load area in the Areas enum to the value of the level to load

		RenderLevel();
	}
}

void LevelRenderer::SetPlayer(Player* player)
{
	m_player = player; // Set the values of the player so the renderer can check the players position to allow access where there is a key block if they have enough keys (See IsWall)
}

bool LevelRenderer::IsWall(int x, int y)
{
	if (m_levelLayout[y / m_blockSize][x / m_blockSize] != '.')
	{
		if (m_levelLayout[y / m_blockSize][x / m_blockSize] == '!')
		{
			return !m_player->HasKey();
		}
		else
		{
			return true;
		}
	}
	return false;
}
