#include "UI.h"

UI::UI()
{
	TTF_Init(); // Initiliase TTF

	m_UIFont = TTF_OpenFont("Assets/Text/DejaVuSans.ttf", 25); // Use the string location to find the font
}

UI::~UI()
{
	if (nullptr != m_UIFont)
	{
		TTF_CloseFont(m_UIFont);
		m_UIFont = nullptr;
	}
}

void UI::UpdateUI(std::string text, int x, int y, SDL_Renderer* renderer, TTF_Font* font, SDL_Colour colour)
{
	SDL_Surface* p_Surface{ nullptr };
	SDL_Texture* p_Texture{ nullptr };

	int textWidth, textHeight = 0;

	p_Surface = TTF_RenderText_Solid(font, text.c_str(), colour);
	if (nullptr == p_Surface)
	{
		SDL_Log("Surface for font not created: %s", SDL_GetError());
		return;
	}
	p_Texture = SDL_CreateTextureFromSurface(renderer, p_Surface);
	if (nullptr == p_Texture)
	{
		SDL_Log("Texture for font not created: %s", SDL_GetError());
		return;
	}

	SDL_QueryTexture(p_Texture, NULL, NULL, &textWidth, &textHeight);
	SDL_Rect textRect{ x, y, textWidth, textHeight };

	SDL_RenderCopy(renderer, p_Texture, NULL, &textRect);

	SDL_DestroyTexture(p_Texture);
	SDL_FreeSurface(p_Surface);
}
