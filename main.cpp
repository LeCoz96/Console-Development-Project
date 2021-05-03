#undef main
#include <SDL.h>
#include<stdio.h>
#include<iostream>
#include<fstream>
#include "Application.h"

/*
Disclaimer:
This game has been built utilising assets that are only available for educational purposes. This game is in no way intended for release and or for profit.
I credit the University of Southampton Solent and God of Thunder (1993) for the access to all the sprites and audio files compiled in this game.
*/

int main(int argc, char* argv[])
{
	Application* App = new Application();
	App->Run();

	delete App;
	App = nullptr;

	std::cout << "Press and key to continue" << std::endl;
	int c = getchar();

	return 0;
}
