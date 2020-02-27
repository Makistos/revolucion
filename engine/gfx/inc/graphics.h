#include <SDL2/SDL.h>
#include <iostream>
#include <list>
#include <optional>
#include "tileset.h"

class Graphics {
public:
	Graphics(int width, int height);
	~Graphics();

	bool loadMedia(const std::string& file_name);
	std::optional<SDL_Texture*> loadTexture(const std::string& file_name);
	bool loadTileSet(const std::string& file_name, const int width, const
			int height, const int count, const int count_x, const
			int count_y);
	void setMap(int map[], int width, int height);
	void show();
	void update();
	void drawPrimitive(int choice);
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
