#include "Player.h"
#include "Image.h"
#include "Input.h"
#include "MessageHandler.h"

Player::Player(int x, int y, int speed, SDL_Renderer* renderer, LevelRenderer* level)
	: MovingObject{ x, y, speed, renderer, level }
{
	m_lives = 5;

	m_animationSpeed = 250;

	m_input = new Input();
	m_message = new MessageHandler();

	m_listOfTextures.push_back(Image::GetTexture("Assets/Player/PlayerIdleSpriteSheet.png", renderer));
	//m_listOfTextures.push_back(Image::GetTexture("Assets/Player/PlayerUpSpriteSheet.png", renderer));
	//m_listOfTextures.push_back(Image::GetTexture("Assets/Player/PlayerDownSpriteSheet.png", renderer));
	//m_listOfTextures.push_back(Image::GetTexture("Assets/Player/PlayerLeftSpriteSheet.png", renderer));
	//m_listOfTextures.push_back(Image::GetTexture("Assets/Player/PlayerRightSpriteSheet.png", renderer));

	for (size_t i = 0; i < m_listOfTextures.size(); i++)
	{
		m_imageDictionary.push_back(std::make_pair(SDL_Rect(), 0));
		SDL_QueryTexture(m_listOfTextures[i], NULL, NULL, &m_imageDictionary[i].first.w, &m_imageDictionary[i].first.h);
		m_imageDictionary[i].first.x = 0;
		m_imageDictionary[i].first.y = 0;
		m_imageDictionary[i].second = 4;

		m_imageDictionary[i].first.w /= m_imageDictionary[i].second;
	}
}

Player::~Player()
{
}

void Player::TakeDamage()
{
	--m_lives;
}

int Player::GetLives()
{
	return m_lives;
}

void Player::IncreaseScore(int value)
{
	m_score += value;
}

void Player::IncreaseKeys()
{
	++m_keys;
}

int Player::GetScore()
{
	return m_score;
}

int Player::GetKeys()
{
	return m_keys;
}


void Player::GetPlayerInput()
{
	m_input->Update();
	
	if (m_input->buttonIsPressed(UP))
	{
		//RenderState(MOVEUP);
		Up();
	}
	else if (m_input->buttonIsPressed(DOWN))
	{
		//RenderState(MOVEDOWN);
		Down();
	}
	else if (m_input->buttonIsPressed(LEFT))
	{
		//RenderState(MOVELEFT);.
		Left();
	}
	else if (m_input->buttonIsPressed(RIGHT))
	{
		//RenderState(MOVERIGHT);
		Right();
	}
	if (m_input->buttonIsPressed(LEFTSHOULDER))
	{
		m_message->showMessage(INSTRUCTIONS);
	}
	else
	{
		//RenderState(IDLE);
	}
}

bool Player::PlayerEndGame()
{
	return false;
}

void Player::Render()
{
	SDL_RenderCopy(m_renderer, m_listOfTextures[0], &m_imageDictionary[0].first, &m_destRect);
}

void Player::RenderState(PlayerStates state)
{
	switch (state)
	{
	case IDLE:
		SDL_RenderCopy(m_renderer, m_listOfTextures[0], &m_imageDictionary[0].first, &m_destRect);
		break;

	case MOVEUP:
		SDL_RenderCopy(m_renderer, m_listOfTextures[1], &m_imageDictionary[1].first, &m_destRect);
		break;

	case MOVEDOWN:
		SDL_RenderCopy(m_renderer, m_listOfTextures[2], &m_imageDictionary[2].first, &m_destRect);
		break;

	case MOVELEFT:
		SDL_RenderCopy(m_renderer, m_listOfTextures[3], &m_imageDictionary[3].first, &m_destRect);
		break;

	case MOVERIGHT:
		SDL_RenderCopy(m_renderer, m_listOfTextures[4], &m_imageDictionary[4].first, &m_destRect);
		break;

	default:
		break;
	}
}

