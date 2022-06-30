#include "tile.hpp"

Tile::Tile(SDL_Renderer *r, float x, float y, const char* filePath) {
    worldPos = Vector2(x,y);
    renderer = r;
    SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL) {
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }

    this->texture = texture;
}

void Tile::render() {

	float tileScreenX = screenPos.x;
	float tileScreenY = screenPos.y;

	/* View culling */
	if(tileScreenX > 0 && tileScreenY > 0 && tileScreenX < 1280 && tileScreenY < 720) {
		SDL_Rect src; 
		src.x = 0;
        src.y = 0;


		SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

		SDL_Rect dst;
		dst.x = screenPos.x;
		dst.y = screenPos.y;
		dst.w = 48;
		dst.h = 48;

		SDL_RenderCopy(renderer, texture, &src, &dst);
	}

}

void Tile::update(SDL_Rect camera) {
    /* Update position relative to camera. */
    screenPos.x = worldPos.x - camera.x;
    screenPos.y = worldPos.y - camera.y;
}

Vector2 Tile::getPos() {
    return screenPos;
}