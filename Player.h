#pragma once
#include "MovingObject.h"
#include<iostream>
#include<vector>

enum PlayerStates
{
	IDLE, MOVEUP, MOVEDOWN, MOVELEFT, MOVERIGHT
};

class Input;

class Player :
	public MovingObject
{
public:
	Player(int x, int y, int speed, SDL_Renderer* renderer, Map* map);
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

	SDL_Texture* m_idle;

	std::vector<SDL_Texture*> m_listOfPlayerUp;
	std::vector<SDL_Texture*> m_listOfPlayerDown;
	std::vector<SDL_Texture*> m_listOfPlayerLeft;
	std::vector<SDL_Texture*> m_listOfPlayerRight;

	int m_lives;
	int m_blueJewels, m_redJewels, m_keys;

	bool m_isIdle = true;
};

