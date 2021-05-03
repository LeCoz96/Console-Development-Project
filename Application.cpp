#include "Application.h"
#include "Renderer.h"
#include "Input.h"
#include "MessageHandler.h"
#include "Audio.h"
#include "Timer.h"
#include "Player.h"

#ifdef _DEBUG
#include"MemoryManager.h"

#endif

Application::Application()
{
	mp_controllers = new Input();
	mp_renderer = new Renderer();
	mp_sounds = new Audio();

	mp_sounds->LoadAudio("Assets/Audio/Background.mp3", 0, MUSIC, 20);
}

Application::~Application()
{
}

void Application::Run()
{
	if (nullptr == mp_renderer) return;

	MessageHandler message;

	if (!mp_controllers->getControllerInitialised())
	{
		std::cout << "Gamepads not detected" << std::endl;
		message.showMessage(CONTROLLER_WARNING);
	}

	message.showMessage(INSTRUCTIONS);

	mp_sounds->PlayMusicTrack(0, 1);

	mp_renderer->Update(); // Renderer Update stores the game loop

#ifdef _DEBUG
	file.close(); //Close the file opened to store the console output in Memory Manager
#endif // _DEBUG

	mp_renderer->Destroy();
	Destroy();
}

void Application::Destroy()
{
	delete mp_renderer;
	mp_renderer = nullptr;

	delete mp_controllers;
	mp_controllers = nullptr;
}

