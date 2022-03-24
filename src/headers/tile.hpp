#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "vector2.hpp"

class Tile {

    public:
        Tile(SDL_Renderer *r, float x, float y, const char* filePath);

        void render();
        void update(SDL_Rect camera);
        Vector2 getPos();


    private:

        Vector2 worldPos;
        Vector2 screenPos;
        SDL_Texture *texture;
        SDL_Renderer *renderer;

};