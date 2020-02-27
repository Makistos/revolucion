#ifndef TILESET_H
#define TILESET_H

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "texture.h"
#include "tile.h"

class TileSet {

public:
	TileSet() = default;
	TileSet(const TileSet&) = default;
	TileSet(TileSet&&) = default;
	TileSet& operator=(const TileSet&) = default;
	TileSet& operator=(TileSet&&) = default;
	TileSet(SDL_Renderer* renderer, const std::string& filename,
		int width, int height,
		int count, int count_x, int count_y);
	virtual ~TileSet() {};
	void render(unsigned idx, SDL_Rect& rect);
	int tile_width() { return tile_width_; }
	int tile_height() { return tile_height_; }
private:
	int tile_width_;
	int tile_height_;
	std::vector<std::shared_ptr<Tile>> tiles;
	Texture texture;
};

#endif