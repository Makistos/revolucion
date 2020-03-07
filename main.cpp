#include <SDL2/SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <memory>
#include "eventhandler.h"
#include "engine.h"

int main( int argc, char* argv[] )
{
	(void) argc;
	(void) argv;
	bool quit = false;
	SDL_Event e;
	std::string map_file = "/home/mep/src/revolucion/assets/desert.json";

	auto engine = engine::Engine();
	engine.init_graphics(1920, 1080);
	engine.load_tileset(map_file);
	auto eh = eventhandler::EventHandler();

	while(!quit) {
		eventhandler::Events_e action;
		while(SDL_PollEvent(&e) != 0) {
			action = eh.handle(e);
			if (action == eventhandler::QUIT) {
				quit = true;
			}
		}
		engine.render();
	}

	return 0;
}
