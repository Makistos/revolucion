#ifndef ENGINE_H
#define ENGINE_H

#include "graphics.h"
#include "tiledmap.h"

namespace engine {
    class Engine {
        public:
            Engine() {}
            void init_graphics(int width, int height);
            void load_tileset(const std::string& filename);
            void render();
        private:
            std::shared_ptr<Graphics> gfx;
            std::unique_ptr<TiledMap> tiledmap;
    };
}

#endif