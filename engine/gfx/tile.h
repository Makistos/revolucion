#ifndef tile_h
#define tile_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <memory>
#include "texture.h"

class Tile {
public:
	Tile() = delete;
	Tile(SDL_Renderer* arenderer, SDL_Rect abox, Texture& texture) :
		renderer{arenderer}, box{abox}, width{box.w}, height{box.h},
		texture_{texture} {}

	void render(SDL_Rect* camera);
	SDL_Rect* getBox();
private:
	SDL_Renderer* renderer;
	SDL_Rect box;
	int width;
	int height;
	Texture& texture_;
};

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
