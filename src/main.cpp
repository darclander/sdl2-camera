#include<iostream>

#include<SDL2/SDL.h>

#include "window.hpp"
#include "player.hpp"
#include "tile.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		std::cout << "SDL, Error: " << SDL_GetError() << std::endl;
	}

    SDL_Event event;

    /* Instead of an fpscap we limit movement to time passed. */
    double deltaTime;
	Uint64 currentTick = SDL_GetPerformanceCounter();
	Uint64 lastTick = 0;

    Window window = Window("SDL2 Camera", WINDOW_WIDTH, WINDOW_HEIGHT);
    SDL_Texture *backgroundTxt = window.loadTexture("../gfx/background.png");

    bool running = true;

    SDL_Rect camera = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    while(running) {

        /* Update deltaTime - see definition above. */
        lastTick = currentTick;
		currentTick = SDL_GetPerformanceCounter();
		deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );

        window.clear();

        

        /* Function to render the background texture at coordinates X, Y. */
        window.render(0, 0, backgroundTxt);
        
        window.display();

        /* To move window, etcetera... */
        while (SDL_PollEvent(&event)) {
			switch(event.type)
			{
			case SDL_QUIT:
				running = false;
				break;
			}
		}
    }

}