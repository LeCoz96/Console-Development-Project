#undef main
#include <SDL.h>
#include<stdio.h>
#include<iostream>
#include "Application.h"

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
