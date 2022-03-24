#include "window.hpp"


Window::Window(const char* title, int w, int h) {

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        std::cout << "Could not init window, Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	worldPos.x = 0;
	worldPos.y = 0;

}


SDL_Texture *Window::loadTexture(const char* filePath) {
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}

void Window::render(int x, int y, SDL_Texture *texture) {
    SDL_Rect src; 
	src.x = 0;
	src.y = 0;
	src.w;
	src.h;

	SDL_QueryTexture(texture, NULL, NULL, &src.w, &src.h);

	SDL_Rect dst;
	dst.x = worldPos.x - x;
	dst.y = worldPos.y - y;
	dst.w = src.w;
	dst.h = src.h;

	SDL_RenderCopy(renderer, texture, &src, &dst);
}


Window::~Window() {
	std::cout << "Destroying window..." << std::endl;
    SDL_DestroyWindow(window);
}

void Window::clear() {
    SDL_RenderClear(renderer);
}

void Window::display() {
    SDL_RenderPresent(renderer);
}

SDL_Renderer *Window::getRenderer() {
	return renderer;
}