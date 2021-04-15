#include "Renderer.h"
#include "LevelRenderer.h"
#include "Exit.h"
#include "Key.h"
#include "KeyBlock.h"
#include "JewelBlue.h"
#include "JewelBlueBlock.h"
#include "JewelRed.h"
#include "JewelRedBlock.h"
#include "Player.h"
#include "Enemy.h"
#include "UI.h"

Renderer::Renderer()
{
	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow
	(
		"Game Window",
		SDL_WINDOWPOS_CENTERED_DISPLAY(1),
		SDL_WINDOWPOS_CENTERED_DISPLAY(1),
		800,
		800,
		0
	);

	if (nullptr == m_window)
	{
		std::cout << "Window initialisation failed: " << SDL_GetError() << std::endl;
		std::cout << "Press a key to continue" << std::endl;
		_getch();
		return;
	}

	m_renderer = SDL_CreateRenderer
	(
		m_window,			// link the renderer to the window
		-1,					// index rendering driver (don't worry about this)
		0					// renderer behavior flags (ignore for now)
	);

	if (nullptr == m_renderer)
	{
		std::cout << "Renderer initialisation failed: " << SDL_GetError() << std::endl;
		std::cout << "Press a key to continue" << std::endl;
		_getch();
	}
	RenderGameObjects();
}

Renderer::~Renderer()
{
	if (nullptr != m_UI)
	{
		delete m_UI;
		m_UI = nullptr;
	}
	if (nullptr != m_player)
	{
		delete m_player;
		m_player = nullptr;
	}
	for (size_t i = 0; i < m_listOfEnemy.size(); i++)
	{
		if (nullptr != m_listOfEnemy[i])
		{
			delete m_listOfEnemy[i];
			m_listOfEnemy[i] = nullptr;
		}
	}
	for (size_t i = 0; i < m_listOfJewelRed.size(); i++)
	{
		if (nullptr != m_listOfJewelRed[i])
		{
			delete m_listOfJewelRed[i];
			m_listOfJewelRed[i] = nullptr;
		}
	}
	if (nullptr != m_jewelRedBlock)
	{
		delete m_jewelRedBlock;
		m_jewelRedBlock = nullptr;
	}
	for (size_t i = 0; i < m_listOfJewelBlue.size(); i++)
	{
		if (nullptr != m_listOfJewelBlue[i])
		{
			delete m_listOfJewelBlue[i];
			m_listOfJewelBlue[i] = nullptr;
		}
	}
	if (nullptr != m_jewelBlueBlock)
	{
		delete m_jewelBlueBlock;
		m_jewelBlueBlock = nullptr;
	}
	for (size_t i = 0; i < m_listOfKey.size(); i++)
	{
		if (nullptr != m_listOfKey[i])
		{
			delete m_listOfKey[i];
			m_listOfKey[i] = nullptr;
		}
	}
	if (nullptr != m_keyBlock)
	{
		delete m_keyBlock;
		m_keyBlock = nullptr;
	}
	if (nullptr != m_exit)
	{
		delete m_exit;
		m_exit = nullptr;
	}
	if (nullptr != m_level)
	{
		delete m_level;
		m_level = nullptr;
	}
	if (nullptr != m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
	if (nullptr != m_window)
	{
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}
	// shut down
	SDL_Quit();
}

void Renderer::RenderGameObjects()
{
	m_level = new LevelRenderer(m_renderer, 32);

	m_exit = new Exit(416, 32, m_renderer, m_level);

	m_keyBlock = new KeyBlock(32, 32, m_renderer, m_level);
	m_listOfKey.push_back(new Key(96, 32, m_renderer, m_level));

	m_jewelBlueBlock = new JewelBlueBlock(160, 32, m_renderer, m_level);
	m_listOfJewelBlue.push_back(new JewelBlue(224, 32, m_renderer, m_level));

	m_jewelRedBlock = new JewelRedBlock(288, 32, m_renderer, m_level);
	m_listOfJewelRed.push_back(new JewelRed(352, 32, m_renderer, m_level));

	m_listOfEnemy.push_back(new Enemy(480, 32, 2, m_renderer, m_level));

	m_player = new Player(544, 32, 1, m_renderer, m_level);
	m_UI = new UI();
}

void Renderer::SetBackgroundColour()
{
	// render a green ground
	int result = SDL_SetRenderDrawColor
	(
		m_renderer,	// the target renderer
		0,				// red value
		215,			// green value
		0,				// blue value
		150				// alpha
	);
}

void Renderer::Update()
{
	m_exit->Update();

	m_player->GetPlayerInput();
	m_player->Update();

	m_keyBlock->Update();
	for (size_t i = 0; i < m_listOfKey.size(); i++)
	{
		m_listOfKey[i]->Update();
	}

	m_jewelBlueBlock->Update();
	for (size_t i = 0; i < m_listOfJewelBlue.size(); i++)
	{
		m_listOfJewelBlue[i]->Update();
	}

	m_jewelRedBlock->Update();
	for (size_t i = 0; i < m_listOfJewelRed.size(); i++)
	{
		m_listOfJewelRed[i]->Update();
	}

	for (size_t i = 0; i < m_listOfEnemy.size(); i++)
	{
		m_listOfEnemy[i]->Update();
		m_listOfEnemy[i]->Patrol();
	}
}

void Renderer::ClearAndPresent()
{
	SDL_RenderClear(m_renderer);

	m_level->RenderLevel();

	m_exit->Render();

	m_player->Render();

	m_keyBlock->Render();
	for (size_t i = 0; i < m_listOfKey.size(); i++)
	{
		m_listOfKey[i]->Render();
	}

	m_jewelBlueBlock->Render();
	for (size_t i = 0; i < m_listOfJewelBlue.size(); i++)
	{
		m_listOfJewelBlue[i]->Render();
	}

	m_jewelRedBlock->Render();
	for (size_t i = 0; i < m_listOfJewelRed.size(); i++)
	{
		m_listOfJewelRed[i]->Render();
	}

	for (size_t i = 0; i < m_listOfEnemy.size(); i++)
	{
		m_listOfEnemy[i]->Render();
	}

	m_UI->UpdateUI("Lives: " + std::to_string(m_player->GetLives()), 10, 1, m_renderer, m_UI->m_UIFont, { 255, 255, 255 });
	m_UI->UpdateUI("Keys 1 / " + std::to_string(m_player->GetKeys()), 140, 1, m_renderer, m_UI->m_UIFont, { 255, 255, 255 });
	m_UI->UpdateUI("Blue Jewels 10 / " + std::to_string(m_player->GetBlueJewels()), 300, 1, m_renderer, m_UI->m_UIFont, { 255, 255, 255 });
	m_UI->UpdateUI("Red Jewels 10 / " + std::to_string(m_player->GetRedJewels()), 565, 1, m_renderer, m_UI->m_UIFont, { 255, 255, 255 });

	SDL_RenderPresent(m_renderer);
}

void Renderer::Pause(float delay)
{
	SDL_Delay(delay);
}

void Renderer::Destroy()
{
	// Do cleanup
	if (m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
	}
	if (m_window)
	{
		SDL_DestroyWindow(m_window);
	}
}
