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
	Player(int x, int y, SDL_Renderer* renderer, LevelRenderer* level, int speed = 2);
	~Player();

	void TakeDamage();
	int GetLives();

	void IncreaseScore(int value);
	void IncreaseKeys();
	void DecreaseKeys();

	int GetScore();
	int GetKeys();

	void GetPlayerInput();
	bool PlayerEndGame();

	void RenderState(PlayerStates state);
	void Render()override;

private:
	Input* m_input{ nullptr };
	MessageHandler* m_message{ nullptr };

	SDL_Texture* m_idle;

	std::vector<SDL_Texture*> m_listOfPlayerUp;
	std::vector<SDL_Texture*> m_listOfPlayerDown;
	std::vector<SDL_Texture*> m_listOfPlayerLeft;
	std::vector<SDL_Texture*> m_listOfPlayerRight;

	int m_lives;
	int m_keys;
	int m_score;

	bool m_isIdle = true;
};

