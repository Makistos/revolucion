#ifndef texture_h
#define texture_h

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <istream>
#include <memory>

class Texture {
	public:
		Texture(); // = default;
		Texture(SDL_Renderer* renderer, const std::string& filename);
		Texture(SDL_Renderer* renderer, const std::string& str, SDL_Color color);
		~Texture() { SDL_DestroyTexture(texture); }
		void render(int x, int y,
			    std::shared_ptr<SDL_Rect> clip = NULL,
			    double angle = 0.0,
			    SDL_Point* center = NULL,
			    SDL_RendererFlip flip = SDL_FLIP_NONE);
		int getWidth();
		int getHeight();
		SDL_Texture* texture = nullptr;
	private:
		int width = 0;
		int height = 0;
};

#endif
