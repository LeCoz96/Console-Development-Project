#include "StaticObject.h"

StaticObject::StaticObject(int x, int y, SDL_Renderer* renderer, LevelRenderer* level)
	: GameObject{ x, y, renderer, level }
{
}

