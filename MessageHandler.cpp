#include "MessageHandler.h"

void MessageHandler::showMessage(MessageType type)
{
	switch (type)
	{
	case INSTRUCTIONS:
		SDL_ShowMessageBox(&ms_instructionMessage, NULL);
		break;
	case CONTROLLER_WARNING:
		SDL_ShowMessageBox(&ms_controllerMessage, NULL);
		break;
	}
}
