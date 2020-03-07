#include <iostream>
#include "tiledmap.h"

TiledMap::TiledMap(SDL_Renderer* renderer, const std::string& filename)
{
    tson::Tileson parser;

    renderer_ = renderer;
    map = parser.parse(fs::path(filename.c_str()));
    if (map.getStatus() != tson::Map::ParseStatus::OK) {
        std::cout << "Could not load map" << std::endl;
    }
    tson::Tileset* tileset = map.getTileset("desert.tsx");
    std::cout << tileset->getImage().u8string() << std::endl;
    SDL_Surface* loadedImage = IMG_Load(tileset->getImage().u8string().c_str());
    if (loadedImage != NULL) {
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
		if (texture == nullptr) {
			std::cout << "Failed to create texture " << filename
				<< std::endl;
		}
	} else {
		std::cout << "Failed to load texture image." << std::endl;
	}
}

int TiledMap::tile_height()
{
    return map.getTileSize().y;
}

int TiledMap::tile_width()
{
    return map.getTileSize().x;
}


void TiledMap::drawMap(SDL_Rect* camera)
{
    for (auto& layer : map.getLayers()) {
        drawLayer(layer, camera);
    }
}

void TiledMap::drawLayer(tson::Layer& layer, SDL_Rect* camera)
{

    switch(layer.getType()) {
        case tson::Layer::Type::TileLayer:
            drawTileLayer(layer, camera);
            break;
        case tson::Layer::Type::ObjectGroup:
            drawObjectLayer(layer);
            break;
        case tson::Layer::Type::ImageLayer:
            drawImageLayer(layer);
            break;
    }
}
void TiledMap::drawTileLayer(tson::Layer& layer, SDL_Rect* camera)
{
    int firstId = tileset->getFirstgid();
    int columns = tileset->getColumns();
    int rows = tileset->getTileCount() / columns;
    int lastId = (tileset->getFirstgid() + tileset->getTileCount());

    for (auto& [pos, tile] : layer.getTileData()) {
        if (tile->getId() >= firstId && tile->getId() <= lastId) {
            tson::Vector2f position = {(float) std::get<0>(pos) * map.getTileSize().x,
                                       (float) std::get<1>(pos) * map.getTileSize().y};

            int baseTilePosition = (tile->getId() - firstId);

            int tileModX = baseTilePosition % columns;
            int currentRow = baseTilePosition / columns;
            int xpos = (tileModX != 0 ?
                           (tileModX * map.getTileSize().x) :
                           0);
            int ypos = (currentRow < rows-1 ?
                           (currentRow * map.getTileSize().y) :
                           ((rows-1) * map.getTileSize().y));

            SDL_Rect box;
            box.x = xpos;
            box.y = ypos;
            box.w = map.getTileSize().x;
            box.h = map.getTileSize().y;
            SDL_RenderCopyEx(renderer_, texture, &box, camera, 0.0,
                             NULL, SDL_FLIP_NONE);
        }
    }

}

void TiledMap::drawObjectLayer(tson::Layer& layer)
{

}

void TiledMap::drawImageLayer(tson::Layer& layer)
{

}

void TiledMap::print_tilesets()
{
    for (auto& tileset : map.getTilesets()) {
        std::cout << tileset.getName() << " : " << tileset.getImage() << " : " << tileset.getTileCount() << std::endl;
    }
}
void TiledMap::print_layers()
{
    for (auto& layer : map.getLayers()) {
        std::cout << layer.getDrawOrder() << " : " << layer.getImage() << " : " << layer.getName() << std::endl;
    }
}