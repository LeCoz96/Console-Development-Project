#include"Image.h"
#include<SDL_image.h>

#include <iostream>

SDL_Texture* Image::GetTexture(const char* fileName, SDL_Renderer* renderer)
{
    SDL_Surface* tempSurface = IMG_Load(fileName);
    SDL_Texture* finalTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);

    return finalTexture;
}

void Image::PrintImage(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect sourceRect, SDL_Rect destRect)
{
    SDL_RenderCopy(renderer, texture, &sourceRect, &destRect);
}
