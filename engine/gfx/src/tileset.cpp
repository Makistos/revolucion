
#include <iostream>
#include "tileset.h"
#include "tile.h"

using namespace engine;

TileSet::TileSet(SDL_Renderer* renderer, const std::string& filename,
		 int width, int height,
		 int count, int count_x, int count_y)
{
	int xpos = 0;
	int ypos = 0;
	int xc = 0;
	tile_width_ = width / count_x;
	tile_height_ = height / count_y;
	//texture.load(renderer, filename);

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
	tiles[idx]->render(texture, &rect);
}