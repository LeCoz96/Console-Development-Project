#include "Input.h"
#include "MessageHandler.h"

Input::Input()
{
	m_controllerInitialised = false;
	InitialiseController();
	for (int i = 0; i < SIZE; i++)
	{
		m_buttonsPressed[i] = NULL;
	}
}

Input::~Input()
{
	if (m_controllerInitialised)
	{
		SDL_GameControllerClose(mp_controller);
	}
}

void Input::InitialiseController()
{
	if (SDL_WasInit(SDL_INIT_GAMECONTROLLER) == 0)
	{
		SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
	}

	if (SDL_NumJoysticks() > 0)
	{
		SDL_GameController* pad = NULL;

		if (SDL_IsGameController)
		{
			pad = SDL_GameControllerOpen(0);

			if (pad)
				mp_controller = pad;
#if _DEBUG
			else
				fprintf(stderr, "Could not open controller: %s\n", SDL_GetError());
#endif
		}

		SDL_GameControllerEventState(SDL_ENABLE);
		m_controllerInitialised = true;

		std::cout << "Initialised 1 Gamepad" << std::endl;
	}

	else
		m_controllerInitialised = false;
}

void Input::Update()
{
	if (!getControllerInitialised())
	{
		InitialiseController();
	}

	while (SDL_PollEvent(&m_event) != NULL)
	{
		if (m_event.type == SDL_CONTROLLERBUTTONDOWN)
		{
			SDL_ControllerButtonEvent buttonPressed = m_event.cbutton;
			switch (buttonPressed.button)
			{
			case SDL_CONTROLLER_BUTTON_DPAD_UP:
				m_buttonsPressed[UP] = true;
				break;

			case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
				m_buttonsPressed[DOWN] = true;
				break;

			case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
				m_buttonsPressed[LEFT] = true;
				break;

			case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
				m_buttonsPressed[RIGHT] = true;
				break;

			case SDL_CONTROLLER_BUTTON_A:
				m_buttonsPressed[A] = true;
				break;

			case SDL_CONTROLLER_BUTTON_B:
				m_buttonsPressed[B] = true;
				break;

			case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
				m_buttonsPressed[LEFTSHOULDER] = true;
				break;
			}
		}
		else if (m_event.type == SDL_CONTROLLERBUTTONUP)
		{
			SDL_ControllerButtonEvent buttonPressed = m_event.cbutton;
			switch (buttonPressed.button)
			{
			case SDL_CONTROLLER_BUTTON_DPAD_UP:
				m_buttonsPressed[UP] = false;
				break;

			case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
				m_buttonsPressed[DOWN] = false;
				break;

			case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
				m_buttonsPressed[LEFT] = false;
				break;

			case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
				m_buttonsPressed[RIGHT] = false;
				break;

			case SDL_CONTROLLER_BUTTON_A:
				m_buttonsPressed[A] = false;
				break;

			case SDL_CONTROLLER_BUTTON_B:
				m_buttonsPressed[B] = false;
				break;

			case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
				m_buttonsPressed[LEFTSHOULDER] = false;
				break;
			}
		}
		else if (m_event.type == SDL_CONTROLLERDEVICEREMOVED)
		{
			m_controllerInitialised = false;
			std::cout << "Gamepad Removed" << std::endl;
			MessageHandler message;
			message.showMessage(CONTROLLER_WARNING);
		}
	}
}

bool Input::buttonIsPressed(Buttons button)
{
	return m_buttonsPressed[button];
}

bool Input::getControllerInitialised()
{
	return m_controllerInitialised;
}
