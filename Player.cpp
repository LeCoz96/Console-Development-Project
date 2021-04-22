#include "Player.h"
#include "Image.h"
#include "Input.h"
#include "MessageHandler.h"
#include "Audio.h"

Player::Player(int x, int y, SDL_Renderer* renderer, LevelRenderer* level, int speed)
	: MovingObject{ x, y, renderer, level, speed }
{
	m_lives = 5;
	m_keys = 0;
	m_score = 0;

	m_animationSpeed = 250;

	m_input = new Input();
	m_message = new MessageHandler();
	m_sounds = new Audio();

	m_sounds->LoadAudio("Assets/Audio/Kill.mp3", 0, SFX, 20);
	m_sounds->LoadAudio("Assets/Audio/ThorHurt.mp3", 1, SFX, 20);
	m_sounds->LoadAudio("Assets/Audio/ThorInteraction.mp3", 2, SFX, 20);

	m_listOfTextures.push_back(Image::GetTexture("Assets/Player/PlayerIdleSpriteSheet.png", renderer));
	m_listOfTextures.push_back(Image::GetTexture("Assets/Player/PlayerUpSpriteSheet.png", renderer));
	m_listOfTextures.push_back(Image::GetTexture("Assets/Player/PlayerDownSpriteSheet.png", renderer));
	m_listOfTextures.push_back(Image::GetTexture("Assets/Player/PlayerLeftSpriteSheet.png", renderer));
	m_listOfTextures.push_back(Image::GetTexture("Assets/Player/PlayerRightSpriteSheet.png", renderer));
}

Player::~Player()
{
}

void Player::TakeDamage()
{
	--m_lives;
	if (m_lives > 0)
	{
		m_sounds->PlaySFX(1, 0, 0);
	}
	else
	{
		m_sounds->PlaySFX(0, 0, 0);

		m_playerIsDead = true;
	}
}

int Player::GetLives()
{
	return m_lives;
}

void Player::IncreaseScore(int value)
{
	m_score += value;
	m_sounds->PlaySFX(2, 0, 0);
}

void Player::IncreaseKeys()
{
	++m_keys;
	m_sounds->PlaySFX(2, 0, 0);
}

void Player::DecreaseKeys()
{
	--m_keys;
}

int Player::GetScore()
{
	return m_score;
}

void Player::GetPlayerInput()
{
	m_input->Update();

	if (m_input->buttonIsPressed(UP))
	{
		m_state = MOVEUP;
		Up();
	}
	else if (m_input->buttonIsPressed(DOWN))
	{
		m_state = MOVEDOWN;
		Down();
	}
	else if (m_input->buttonIsPressed(LEFT))
	{
		m_state = MOVELEFT;
		Left();
	}
	else if (m_input->buttonIsPressed(RIGHT))
	{
		m_state = MOVERIGHT;
		Right();
	}
	else if (m_input->buttonIsPressed(X))
	{
		FPS30();
	}
	else if (m_input->buttonIsPressed(Y))
	{
		FPS60();
	}
	else if (m_input->buttonIsPressed(B))
	{
		FPS120();
	}
	else
	{
		m_state = IDLE;
	}
}

void Player::FPS30()
{
	m_chosenFPS = 30.f;
}

void Player::FPS60()
{
	m_chosenFPS = 60.f;
}

void Player::FPS120()
{
	m_chosenFPS = 120.f;
}

bool Player::PlayerFinishedGame()
{
	return m_playerFinishedGame;
}

bool Player::PlayerIsDead()
{
	return m_playerIsDead;
}

bool Player::HasKey()
{
	return m_keys > 0;
}

void Player::Render()
{
	SDL_RenderCopy(m_renderer, m_listOfTextures[m_state], &m_sourceRect, &m_destRect);
}

void Player::Update()
{
	switch (m_state)
	{
	case IDLE:
		Animate(IDLE);
		break;

	case MOVEUP:
		Animate(MOVEUP);
		break;

	case MOVEDOWN:
		Animate(MOVEDOWN);
		break;

	case MOVELEFT:
		Animate(MOVELEFT);
		break;

	case MOVERIGHT:
		Animate(MOVERIGHT);
		break;

	default:
		break;
	}

	GameObject::Update();
}

void Player::Animate(PlayerStates state)
{
	int width, height;

	SDL_QueryTexture(m_listOfTextures[state], NULL, NULL, &width, &height);

	m_sourceRect.x = m_sourceRect.w * (int)((SDL_GetTicks() / m_animationSpeed) % (width / m_sourceRect.w));
}

