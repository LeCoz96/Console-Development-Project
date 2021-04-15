#pragma once
#include "MovingObject.h"
#include<iostream>
#include<vector>

enum PlayerStates
{
	IDLE, MOVEUP, MOVEDOWN, MOVELEFT, MOVERIGHT
};

class Input;
class MessageHandler;

class Player :
	public MovingObject
{
public:
	Player(int x, int y, int speed, SDL_Renderer* renderer, LevelRenderer* level);
	~Player();

	void TakeDamage();
	int GetLives();

	void IncreaseScore(int object);

	int GetKeys();
	int GetBlueJewels();
	int GetRedJewels();

	void GetPlayerInput();
	bool PlayerEndGame();

	void Render()override;

	void RenderState(PlayerStates state);

private:
	Input* m_input{ nullptr };
	MessageHandler* m_message{ nullptr };

	SDL_Texture* m_idle;

	std::vector<SDL_Texture*> m_listOfPlayerUp;
	std::vector<SDL_Texture*> m_listOfPlayerDown;
	std::vector<SDL_Texture*> m_listOfPlayerLeft;
	std::vector<SDL_Texture*> m_listOfPlayerRight;

	int m_lives;
	int m_blueJewels, m_redJewels, m_keys{ 0 };

	bool m_isIdle = true;
};

