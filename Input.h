#pragma once
#include<SDL.h>
#include<SDL_gamecontroller.h>
#include<iostream>

enum Buttons{UP, DOWN, LEFT, RIGHT, LEFTSHOULDER, X, Y, B, SIZE};

class Input
{
public:
	Input();
	~Input();

	void InitialiseController();
	void Update();
	bool buttonIsPressed(Buttons button);
	bool getControllerInitialised();

private:
	SDL_Event m_event;
	bool m_buttonsPressed[SIZE];
	SDL_GameController* mp_controller = NULL;
	bool m_controllerInitialised;
};

