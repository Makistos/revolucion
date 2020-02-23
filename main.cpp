#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <memory>
#include "engine/gfx/graphics.h"
#include "eventhandler.h"

int main( int argc, char* argv[] )
{
	(void) argc;
	(void) argv;
	bool quit = false;
	SDL_Event e;
	std::string tile_file = "ground_tiles.png";
	int map[25] =  {1, 1, 6, 1, 1,
			 4, 4, 8, 3, 3,
			 4, 4, 8, 3, 3,
			 4, 4, 8, 3, 3,
			 1, 1, 6, 1, 1};


	auto gfx = Graphics(1920, 1080);
	auto eh = std::make_unique<eventhandler::EventHandler>();

	//gfx->loadMedia("frenchie.png");
	//gfx->loadMedia("buldogs.png");
	//gfx->loadMedia("bulldogs.png");
	//gfx->loadMedia("ground_tiles.png");
	gfx.loadTileSet(tile_file, 384, 128, 12, 6, 2);
	gfx.setMap(map, 5, 5);
	while(!quit) {
		while(SDL_PollEvent(&e) != 0) {
			eventhandler::Events_e action = eh->handle(e);
			if (action == eventhandler::QUIT) {
				quit = true;
			//} else {
			//	gfx->drawPrimitive(int(action));
			}
		}
		gfx.update();
	}

	return 0;
}
