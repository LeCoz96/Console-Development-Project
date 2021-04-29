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
class Audio;

class Player :
	public MovingObject
{
public:
	Player(int x, int y, SDL_Renderer* renderer, LevelRenderer* level, int speed = 150);
	~Player();

	void TakeDamage();
	int GetLives();

	void IncreaseScore(int value);
	void IncreaseKeys();
	void DecreaseKeys();

	int GetScore();

	void GetPlayerInput();

	float GetChosenFPS();

	bool PlayerFinishedGame();
	bool PlayerIsDead();
	
	bool HasKey();

	void Render()override;
	void Update()override;
	void Animate(PlayerStates state);

	bool m_playerFinishedGame{ false };

	float m_chosenFPS{ 30.0f };

private:
	Input* m_input{ nullptr };
	MessageHandler* m_message{ nullptr };
	Audio* m_sounds{ nullptr };

	std::vector<SDL_Texture*> m_listOfPlayerUp;
	std::vector<SDL_Texture*> m_listOfPlayerDown;
	std::vector<SDL_Texture*> m_listOfPlayerLeft;
	std::vector<SDL_Texture*> m_listOfPlayerRight;

	int m_lives;
	int m_keys;
	int m_score;

	int m_state;

	bool m_playerIsDead{ false };

	int m_fpsChange{ 0 };

	void FPS30();
	void FPS60();
	void FPS120();

};

