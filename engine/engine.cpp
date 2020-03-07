#include <iostream>
#include "engine.h"
#include "graphics.h"
#include "tiledmap.h"

using namespace engine;

void Engine::init_graphics(int width, int height)
{
    gfx = std::make_shared<Graphics>(Graphics{width, height});
    (*gfx).init();
}

void Engine::load_tileset(const std::string& filename)
{
	tiledmap = (*gfx).load_tileset(filename);
    (*tiledmap).print_layers();
    (*tiledmap).print_tilesets();
}

void Engine::render()
{
    (*gfx).update();
}