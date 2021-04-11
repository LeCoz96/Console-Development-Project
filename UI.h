#pragma once
#include <SDL_ttf.h>
#include <string>
#include <iostream>

class Player;

class UI
{
public:
	UI();
	~UI();
	TTF_Font* m_UIFont{ nullptr };

	void UpdateUI(std::string text, int x, int y, SDL_Renderer* renderer, TTF_Font* font, SDL_Colour colour);
};

