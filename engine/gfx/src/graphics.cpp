#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <iterator>
#include <memory>
#include <optional>
#include "graphics.h"
#include "tiledmap.h"

using namespace engine;

void Graphics::init()
{
	if( SDL_Init(SDL_INIT_VIDEO ) < 0)
	{
		std::cout << "SDL could not initialized! SDL_Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		window = SDL_CreateWindow("Revolucion",
					  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					  SCREEN_WIDTH, SCREEN_HEIGHT,
				  	  SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
		}
		else
		{
			renderer = SDL_CreateRenderer(window, -1,
					SDL_RENDERER_ACCELERATED);
			if (renderer == NULL) {
				std::cout << "Failed to create renderer. SDL Error: " << SDL_GetError() << std::endl;
			} else {
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF,
							 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					std::cout << "Could not initialize SDL image. Error: " << SDL_GetError() << std::endl;
				}
			}
		}
	}
}

Graphics::~Graphics()
{
	if (renderer != NULL) {
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
	}
	window = NULL;
	renderer = NULL;
	IMG_Quit();
	SDL_Quit();
}

# if 0
std::optional<std::shared_ptr<Texture>> Graphics::loadTexture(const std::string& filename)
{
	SDL_Texture* tex = nullptr;
	std::shared_ptr<Texture> retval;

	SDL_Surface* loadedImage = IMG_Load(filename.c_str());
	if (loadedImage != nullptr) {
		tex = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		if (tex == nullptr) {
			std::cout << "Failed to create texture " << filename
				<< std::endl;
		}
	} else {
		std::cout << "Failed to load texture image." << std::endl;
	}
	if (tex != nullptr) {
		retval = Texture{}
		retval = tex;
	} else {
		return std::nullopt;
	}
	return retval;
}
#endif

#if 0
bool Graphics::loadMedia(const std::string& file_name)
{
	bool success = true;

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	//std::optional<SDL_Texture*> texture = loadTexture(renderer, file_name);
	//Texture tex = Texture{renderer, file_name};
	textures.push_back(std::make_shared<Texture>());

	SDL_RenderPresent(renderer);
	return success;
}
#endif

#if 0
bool Graphics::loadTileSet(const std::string& file_name,
			   const int width, const int height,
			   const int count, const int count_x, const int count_y)
{
	std::string f = "/home/mep/src/revolucion/assets/" + file_name;
	//f = "../../assets/".to_string() << file_name
	//Texture tex{renderer, f};
	tileset = TileSet{renderer, f, width,
			     height, count, count_x, count_y};

	return true;
}
#endif

std::unique_ptr<TiledMap> Graphics::load_tileset(const std::string& filename)
{
	return std::make_unique<TiledMap>(TiledMap{renderer, filename});
}

void Graphics::setMap(int map[], int width, int height)
{
	map_ = (int*)malloc(sizeof(int) * width * height);
	for(unsigned i=0; i < width*height; i++) {
		map_[i] = map[i];
	}
	map_width = width;
	map_height = height;
}

void Graphics::show()
{
	SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = SCREEN_WIDTH;
	stretchRect.h = SCREEN_HEIGHT;
	SDL_BlitScaled(imageSurface, NULL, screenSurface, &stretchRect);
	SDL_UpdateWindowSurface(window);
}

void Graphics::update()
{
	SDL_Rect box = { 0, 0, 0, 0};
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
	#if 0
	//SDL_RenderCopy(renderer, (*current_texture).texture, NULL, NULL);
	box.w = tileset.tile_width();
	box.h = tileset.tile_height();
	for(int y = 0; y < map_height; y++) {
		for(int x = 0; x < map_width; x++) {
			tileset.render(map_[y*map_width+x], box);
			box.x = box.x + box.w;
		}
		box.y = box.y + box.h;
		box.x = 0;
	}
	#endif
	//SDL_RenderPresent(renderer);
}

#if 0
void Graphics::drawPrimitive(int choice)
{
	//SDL_RenderCopy(renderer, texture, NULL, NULL);
	std::list<std::shared_ptr<Texture>>::iterator it = textures.begin();
	SDL_Rect vp;
	if (choice > 0 && choice < 4) {
		std::advance(it, choice-1);
		std::cout << "Choice: " << choice -1 << std::endl;
		//if (it) {
		//	std::cout << "Texture changed to " << choice -1 << std::endl;
			current_texture = *it;
		//}
	}
	//SDP_RenderCopy(renderer,
}
#endif