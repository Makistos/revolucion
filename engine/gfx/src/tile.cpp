#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <fstream>
#include "tile.h"
#include "texture.h"
#include "Tileson.h"

void Tile::render(const Texture& texture, SDL_Rect* camera)
{
	int ret;
	ret = SDL_RenderCopyEx(renderer, *(texture.texture),
			&box, camera, 0.0, NULL, SDL_FLIP_NONE);
	if (ret == -1) {
		std::cout << SDL_GetError() << std::endl;
	}
}

SDL_Rect* Tile::getBox()
{
	return &box;
}
