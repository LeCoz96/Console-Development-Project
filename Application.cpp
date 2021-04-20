#include "Application.h"
#include "Renderer.h"
#include "Input.h"
#include "MessageHandler.h"
#include "Audio.h"
#include "Timer.h"

#ifdef _DEBUG
#include"MemoryManager.h"
#endif

Application::Application()
{
	mp_controllers =	new Input();
	mp_renderer =		new Renderer();
	mp_sounds =			new Audio();
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

	//mp_renderer->SetBackgroundColour();

	//message.showMessage(INSTRUCTIONS);

	if (mp_renderer)
	{
		while (true)
		{
			Timer::GetInstance()->Tick();
			mp_renderer->Update();
			mp_renderer->ClearAndPresent();
		}
		//mp_renderer->Pause(20000);
	}

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

