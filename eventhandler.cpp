#include <SDL2/SDL.h>
#include <iostream>
#include "eventhandler.h"

using namespace eventhandler;

Events_e EventHandler::handle(SDL_Event e)
{
	Events_e retval;
	if (e.type == SDL_QUIT) {
		std::cout << "Quitting" << std::endl;
		return QUIT;
	}
	if (e.type == SDL_KEYDOWN) {
		switch(e.key.keysym.sym) {
		case SDLK_UP:
			std::cout << "Up" << std::endl;
			retval = KEY_UP;
			break;
		case SDLK_DOWN:
			std::cout << "Down" << std::endl;
			retval = KEY_DOWN;
			break;
		case SDLK_LEFT:
			std::cout << "Left" << std::endl;
			retval = KEY_LEFT;
			break;
		case SDLK_RIGHT:
			std::cout << "Right" << std::endl;
			retval = KEY_RIGHT;
			break;
		default:
			std::cout << "Other" << std::endl;
			retval = KEY_OTHER;
			break;
		}
	}
	return retval;
}

