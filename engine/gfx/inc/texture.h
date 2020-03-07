#ifndef texture_h
#define texture_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <istream>
#include <memory>

namespace engine {
	class Texture {
		public:
			Texture(); // = default;
			Texture(const Texture&) = delete;
			Texture(Texture&&) = delete;
			Texture& operator=(const Texture&) = delete;
			Texture& operator=(Texture&& other) {
				texture = other.texture;
				width = other.width;
				height = other.height;
				return *this;
			};
			//Texture(SDL_Renderer* renderer, const std::string& filename);
			Texture(SDL_Renderer* renderer, const std::string& str, SDL_Color color);
			//virtual ~Texture() { SDL_DestroyTexture(*texture); }
			void load(SDL_Renderer* renderer, const std::string& filename);
			void render(int x, int y,
					std::shared_ptr<SDL_Rect> clip = NULL,
					double angle = 0.0,
					SDL_Point* center = NULL,
					SDL_RendererFlip flip = SDL_FLIP_NONE);
			int getWidth();
			int getHeight();
			std::shared_ptr<SDL_Texture*> texture = nullptr;
		private:
			int width = 0;
			int height = 0;
	};
}

#endif
