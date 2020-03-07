#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL2/SDL.h>
#include <iostream>
#include <list>
#include <optional>
#include "tileset.h"
#include "tiledmap.h"

namespace engine {
	class Graphics {
	public:
		Graphics() {}
		Graphics(int width, int height) :
			SCREEN_WIDTH{width}, SCREEN_HEIGHT{height} {}
		Graphics(Graphics&& other) {
			// Move constructor
			SCREEN_WIDTH = other.SCREEN_WIDTH;
			SCREEN_HEIGHT = other.SCREEN_HEIGHT;
			window = other.window;
			renderer = other.renderer;
			other.window = NULL;
			other.renderer = NULL;
		}
		Graphics& operator=(Graphics&& other) {
			// Move assignment constructor
			if (this != &other) {
				window = NULL;
				renderer = NULL;
				SCREEN_WIDTH = other.SCREEN_WIDTH;
				SCREEN_HEIGHT = other.SCREEN_HEIGHT;
				window = other.window;
				renderer = other.renderer;
			}
			return *this;
		}
		~Graphics();

		void init();
		//bool loadMedia(const std::string& file_name);
		std::optional<SDL_Texture*> loadTexture(const std::string& file_name);
		//bool loadTileSet(const std::string& file_name, const int width, const
		//		int height, const int count, const int count_x, const
		//		int count_y);
		std::unique_ptr<TiledMap> load_tileset(const std::string& filename);
		void setMap(int map[], int width, int height);
		void show();
		void update();
		//void drawPrimitive(int choice);
		SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
		std::list<std::shared_ptr<Texture>> textures;
		SDL_Surface* screenSurface = NULL;
		SDL_Surface* imageSurface = NULL;
		std::list<SDL_Rect> viewports;

	private:
		int SCREEN_WIDTH;
		int SCREEN_HEIGHT;
		std::shared_ptr<Texture> current_texture;
		SDL_Window* window;
		SDL_Renderer* renderer;
		TileSet tileset;
		int* map_;
		int map_width;
		int map_height;

	};
}

#endif