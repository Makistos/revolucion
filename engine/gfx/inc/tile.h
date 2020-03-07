#ifndef tile_h
#define tile_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <memory>
#include "texture.h"

namespace engine {
	class Tile {
	public:
		Tile() = delete;
		Tile(SDL_Renderer* arenderer, SDL_Rect abox, Texture& texture) :
			renderer{arenderer}, box{abox}, width{box.w}, height{box.h} {}

		void render(const Texture& texture, SDL_Rect* camera);
		SDL_Rect* getBox();
	private:
		SDL_Renderer* renderer;
		SDL_Rect box;
		int width;
		int height;
		//Texture& texture_;
	};
}

#endif
