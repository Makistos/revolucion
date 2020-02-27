#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "texture.h"

Texture::Texture()
{
	std::cout << "Texture";
}

void Texture::load(SDL_Renderer* renderer, const std::string& filename)
{
	SDL_Surface* surface = IMG_Load(filename.c_str());
	if (surface == NULL) {
		std::cout << "Failed to load image " << filename << "! Error: " << IMG_GetError();
		return;
	}
	texture = std::make_shared<SDL_Texture*>(SDL_CreateTextureFromSurface(renderer, surface));
	if (*texture == nullptr) {
		std::cout << "Failed to create texture from surface: " << SDL_GetError() << std::endl;
	}
	SDL_QueryTexture(*texture, NULL, NULL, &width, &height);
	SDL_FreeSurface(surface);
	//SDL_SetColorKey(surface, SDL_TRUE,
	//	     SDL_MapRGB(surface->format, 0, 0xFF, 0xFF));
	//SDL_Texture* newTexture = SDL_CreateTextureFromSurface();

	//texture = tex;
}

Texture::Texture(SDL_Renderer* renderer, const std::string& str, SDL_Color color)
{

}

void Texture::render(int x, int y, std::shared_ptr<SDL_Rect> clip,
		     double angle, SDL_Point* center,
		     SDL_RendererFlip flip)
{

}
