#include "Renderer.h"
#include "LevelRenderer.h"
#include "Exit.h"
#include "Key.h"
#include "KeyBlock.h"
#include "JewelBlue.h"
#include "Player.h"
#include "Enemy.h"
#include "UI.h"
#include "Timer.h"

Renderer::Renderer()
{
	SDL_Init(SDL_INIT_VIDEO);

	m_window = SDL_CreateWindow
	(
		"Game Window",
		SDL_WINDOWPOS_CENTERED_DISPLAY(1), // Centre to the screen chosen using the index in the parameter
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
		SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC
		//0					// renderer behavior flags (ignore for now)
	);

	if (nullptr == m_renderer)
	{
		std::cout << "Renderer initialisation failed: " << SDL_GetError() << std::endl;
		std::cout << "Press a key to continue" << std::endl;
		_getch();
	}

	m_UI = new UI();
	m_level = new LevelRenderer(m_renderer, 32);
	m_player = new Player(0, 0, m_renderer, m_level);
	m_level->SetPlayer(m_player);

	ConstructLevelObjects();
}

Renderer::~Renderer()
{
	DestructLevelObjects();
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

void Renderer::Update()
{
	while (!m_player->PlayerIsDead() && !m_player->PlayerFinishedGame())
	{
		Timer::GetInstance()->Tick();

		if (m_updateStaticObject)
		{
			StaticObjectUpdate();
		}

		if (Timer::GetInstance()->GetDeltaTime() >= (1 / m_player->GetChosenFPS()))
		{
			m_player->GetPlayerInput();

			m_player->Update();

			for (size_t i = 0; i < m_listOfEnemy.size(); i++)
			{
				m_listOfEnemy[i]->Update();
				m_listOfEnemy[i]->Patrol();
			}

			Timer::GetInstance()->CalculateFPS();

			ClearAndPresent();

			CollisionChecks(m_player);
		}
	}
}

void Renderer::CollisionChecks(Player* player)
{
	if (m_key)
	{
		if (m_key->Collision(player))
		{
			m_player->IncreaseKeys();
			delete m_key;
			m_key = nullptr;
		}
	}

	for (size_t i = 0; i < m_listOfJewelBlue.size(); i++)
	{
		if (m_listOfJewelBlue[i]->Collision(player))
		{
			m_player->IncreaseScore(m_listOfJewelBlue[i]->m_jewelValue);

			delete m_listOfJewelBlue[i];
			m_listOfJewelBlue[i] = nullptr;
			m_listOfJewelBlue.erase(m_listOfJewelBlue.begin() + i);
		}
	}

	for (size_t i = 0; i < m_listOfEnemy.size(); i++)
	{
		if (m_listOfEnemy[i]->Collision(player))
		{
			m_player->SetX(m_startX);
			m_player->SetY(m_startY);
			m_player->TakeDamage();
		}
	}

	if (m_exit->Collision(player))
	{
		m_level->NextArea();
		DestructLevelObjects();
		ConstructLevelObjects();
		m_player->DecreaseKeys();
		m_updateStaticObject = true;
	}

	if (m_keyBlock)
	{
		if (m_keyBlock->Collision(player))
		{
			delete m_keyBlock;
			m_keyBlock = nullptr;
		}
	}
}

void Renderer::ClearAndPresent()
{
	SDL_RenderClear(m_renderer);

	m_level->RenderLevel();

	m_exit->Render();

	if (m_keyBlock)
	{
		m_keyBlock->Render();
	}

	if (m_key)
	{
		m_key->Render();
	}

	if (m_listOfJewelBlue.size() != 0)
	{
		for (size_t i = 0; i < m_listOfJewelBlue.size(); i++)
		{
			m_listOfJewelBlue[i]->Render();
		}
	}

	m_player->Render();

	if (m_listOfEnemy.size() != 0)
	{
		for (size_t i = 0; i < m_listOfEnemy.size(); i++)
		{
			m_listOfEnemy[i]->Render();
		}
	}

	m_UI->UpdateUI("Lives: " + std::to_string(m_player->GetLives()), 10, 1, m_renderer, m_UI->m_UIFont, { 255, 255, 255 });
	m_UI->UpdateUI("Score: " + std::to_string(m_player->GetScore()), 140, 1, m_renderer, m_UI->m_UIFont, { 255, 255, 255 });
	m_UI->UpdateUI("FPS: " + std::to_string((int)Timer::GetInstance()->GetLastFPS()), 5, 770, m_renderer, m_UI->m_UIFont, { 255, 255, 255 });

	SDL_RenderPresent(m_renderer);
}

void Renderer::StaticObjectUpdate()
{
	m_exit->Update();

	m_keyBlock->Update();
	m_key->Update();

	for (size_t i = 0; i < m_listOfJewelBlue.size(); i++)
	{
		m_listOfJewelBlue[i]->Update();
	}

	m_updateStaticObject = false;
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

void Renderer::ConstructLevelObjects()
{
	++m_currentLevel;

	switch (m_currentLevel)
	{
	case 1:
		ConstructLevel01Objects();
		break;
	case 2:
		ConstructLevel02Objects();
		break;
	case 3:
		ConstructLevel03Objects();
		break;
	default:
		break;
	}
}

void Renderer::ConstructLevel01Objects()
{
	m_player->SetX(224);
	m_player->SetY(96);

	m_startX = m_player->GetX();
	m_startY = m_player->GetY();

	m_exit = new Exit(768, 576, m_renderer, m_level);

	m_keyBlock = new KeyBlock(736, 576, m_renderer, m_level);
	m_key = new Key(128, 736, m_renderer, m_level);

	m_listOfEnemy.push_back(new Enemy(640, 96, m_renderer, m_level));
	m_listOfEnemy.push_back(new Enemy(384, 256, m_renderer, m_level));
	m_listOfEnemy.push_back(new Enemy(192, 512, m_renderer, m_level));
	m_listOfEnemy.push_back(new Enemy(544, 480, m_renderer, m_level));

	m_listOfJewelBlue.push_back(new JewelBlue(736, 64, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(704, 32, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(32, 224, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(128, 640, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(128, 608, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(352, 512, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(384, 512, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(416, 512, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(704, 480, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(544, 320, m_renderer, m_level));
}

void Renderer::ConstructLevel02Objects()
{
	m_player->SetX(32);
	m_player->SetY(576);

	m_startX = m_player->GetX();
	m_startY = m_player->GetY();

	m_exit = new Exit(736, 0, m_renderer, m_level);

	m_keyBlock = new KeyBlock(736, 192, m_renderer, m_level);
	m_key = new Key(736, 736, m_renderer, m_level);

	m_listOfEnemy.push_back(new Enemy(512, 64, m_renderer, m_level));
	m_listOfEnemy.push_back(new Enemy(224, 608, m_renderer, m_level));
	m_listOfEnemy.push_back(new Enemy(704, 416, m_renderer, m_level));

	m_listOfJewelBlue.push_back(new JewelBlue(736, 672, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(672, 672, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(96, 672, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(96, 704, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(32, 192, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(160, 288, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(160, 96, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(640, 128, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(448, 352, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(480, 448, m_renderer, m_level));
}

void Renderer::ConstructLevel03Objects()
{
	m_player->SetX(736);
	m_player->SetY(736);

	m_startX = m_player->GetX();
	m_startY = m_player->GetY();

	m_exit = new Exit(352, 384, m_renderer, m_level);

	m_keyBlock = new KeyBlock(576, 480, m_renderer, m_level);
	m_key = new Key(32, 32, m_renderer, m_level);

	m_listOfEnemy.push_back(new Enemy(352, 64, m_renderer, m_level));
	m_listOfEnemy.push_back(new Enemy(64, 544, m_renderer, m_level));
	m_listOfEnemy.push_back(new Enemy(224, 288, m_renderer, m_level));

	m_listOfJewelBlue.push_back(new JewelBlue(32, 512, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(96, 576, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(32, 640, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(512, 32, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(576, 32, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(480, 448, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(576, 608, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(256, 256, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(736, 672, m_renderer, m_level));
	m_listOfJewelBlue.push_back(new JewelBlue(736, 160, m_renderer, m_level));
}

void Renderer::DestructLevelObjects()
{
	m_listOfJewelBlue.clear();

	m_listOfEnemy.clear();

	if (m_key != NULL)
	{
		delete m_key;
		m_key = nullptr;
	}

	if (m_keyBlock != NULL)
	{
		delete m_keyBlock;
		m_keyBlock = nullptr;
	}

	if (m_exit != NULL)
	{
		delete m_exit;
		m_exit = nullptr;
	}
}
