#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <fstream>
#include "tile.h"
#include "texture.h"

void Tile::render(SDL_Rect* camera)
{
	int ret;
	ret = SDL_RenderCopyEx(renderer, texture_.texture,
			camera, &box, 0.0, NULL, SDL_FLIP_NONE);
	if (ret == -1) {
		std::cout << SDL_GetError() << std::endl;
	}
}

SDL_Rect* Tile::getBox()
{
	return &box;
}

TileSet::TileSet(SDL_Renderer* renderer, const std::string& filename,
		 int width, int height,
		 int count, int count_x, int count_y)
{
	int xpos = 0;
	int ypos = 0;
	int xc = 0;
	tile_width_ = width / count_x;
	tile_height_ = height / count_y;
	texture = Texture{renderer, filename};

	std::cout << std::endl;
	for (unsigned idx = 0; idx < count; idx++) {
		SDL_Rect box;
		box.x = xpos;
		box.y = ypos;
		box.w = tile_width_;
		box.h = tile_height_;
		std::shared_ptr<Tile> tile
			= std::make_shared<Tile>(
					renderer, box,
					texture);
		tiles.push_back(tile);
		xc++;
		if (xc == count_x) {
			xc = 0;
			xpos = 0;
			ypos += tile_height_;
		} else {
			xpos += tile_width_;
		}
	}
}

void TileSet::render(unsigned idx, SDL_Rect& rect)
{
	if (idx >= tiles.size()) {
		std::cout << "Tile number " << idx << " does not exist!" << std::endl;
		return;
	}
	tiles[idx]->render(&rect);
}