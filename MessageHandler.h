#include<SDL.h>

#pragma once

enum MessageType { INSTRUCTIONS, CONTROLLER_WARNING };

class MessageHandler
{
private:
	const SDL_MessageBoxButtonData button = { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT,
												0,
												"OK" };

	const SDL_MessageBoxData ms_controllerMessage{ SDL_MESSAGEBOX_ERROR,
													NULL,
													"Controller Error",
													"Controller Not Detected !!! - \n Insert controller and press Escape",
													0,
													NULL,
													NULL };

	const SDL_MessageBoxData ms_instructionMessage = { SDL_MESSAGEBOX_INFORMATION,
														NULL,
														"Controller Instructions",
	"Instructions - \nDirectional Buttons = Movement\nA = Throw Weapon\nB = Quit Game\nLB = Show instructions",
														1,
														&button,
														NULL };

public:
	MessageHandler() {};
	~MessageHandler() {};
	void showMessage(MessageType type);

};

