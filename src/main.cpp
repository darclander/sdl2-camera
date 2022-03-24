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

    Player player = Player(window.getRenderer(), 0, 0, "../gfx/player.png");
    Tile tile = Tile(window.getRenderer(), -(WINDOW_WIDTH/2), -(WINDOW_HEIGHT/2), "../gfx/tile.png");

    bool running = true;

    SDL_Rect camera = {0, 0, WINDOW_WIDTH, WINDOW_HEIGHT};

    while(running) {

        /* Update deltaTime - see definition above. */
        lastTick = currentTick;
		currentTick = SDL_GetPerformanceCounter();
		deltaTime = (double)((currentTick - lastTick)*1000 / (double)SDL_GetPerformanceFrequency() );

        window.clear();

        /* Update camera position. */
        camera.x = player.getWorldPos().x - (WINDOW_WIDTH / 2); /* Centralize around X axis. */
		camera.y = player.getWorldPos().y - (WINDOW_HEIGHT / 2); /* Centralize around Y axis. */

        /* Function to render the background texture at coordinates X, Y. */
        window.render(camera.x+1280/2, camera.y+720/2, backgroundTxt);

        /* Update player and render. Camera is sent in to calculate screenPosition. */
        player.update(deltaTime, camera);
        player.render();
        
        tile.update(camera);
        tile.render();
        
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