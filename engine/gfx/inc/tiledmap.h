#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Tileson.h"

class TiledMap {
public:
    TiledMap() {}
    TiledMap(SDL_Renderer* renderer, const std::string& filename);
    //std::unique_ptr<SDL_Texture*> texture();
    int tile_width();
    int tile_height();
    std::unique_ptr<int[]> movement_matrix();
    std::unique_ptr<int[]> visibility_matrix();
    void drawMap(SDL_Rect* camera);
    void print_layers();
    void print_tilesets();
private:
    tson::Map map;
    tson::Tileset* tileset;
    SDL_Texture* texture;
    SDL_Renderer* renderer_;
    void drawLayer(tson::Layer& layer, SDL_Rect* camera);
    void drawTileLayer(tson::Layer& layer, SDL_Rect* camera);
    void drawObjectLayer(tson::Layer& layer);
    void drawImageLayer(tson::Layer& layer);

};

#endif