#include "player.hpp"

Player::Player(SDL_Renderer *r, float x, float y, const char* filePath) {
    screenPos = Vector2(x,y);
    renderer = r;

    SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL) {
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;
    }

    this->texture = texture;

}

Player::~Player() {
    std::cout << "Destroying player..." << std::endl;
}

void Player::render() {
    SDL_Rect src; 
	src.x = 0;
	src.y = 0;


	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

	SDL_Rect dst;
	dst.x = screenPos.x;
	dst.y = screenPos.y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, texture, &src, &dst);
}

void Player::update(double deltaTime, SDL_Rect camera) {

    const Uint8 *key_state = SDL_GetKeyboardState(NULL);
    
    /* Update position relative to camera. */
    screenPos.x = worldPos.x - camera.x;
    screenPos.y = worldPos.y - camera.y;

    // Vector2 prevPos = worldPos;
    if(key_state[SDL_SCANCODE_S]) {
        worldPos = worldPos.operator+(Vector2(0, 1*0.1*deltaTime));
    }

    if(key_state[SDL_SCANCODE_W]) {
        worldPos = worldPos.operator-(Vector2(0, 1*0.1*deltaTime));
    }

    if(key_state[SDL_SCANCODE_D]) {
        worldPos = worldPos.operator+(Vector2(1*0.1*deltaTime, 0));
    }

    if(key_state[SDL_SCANCODE_A]) {
        worldPos = worldPos.operator-(Vector2(1*0.1*deltaTime, 0));
    }

}

Vector2 Player::getWorldPos() {
    return worldPos;
}

Vector2 Player::getScreenPos() {
    return screenPos;
}


