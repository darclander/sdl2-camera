#pragma once

#include <iostream>
#include <vector>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "vector2.hpp"

class Player {

    public:
        Player(SDL_Renderer *r, float x, float y, const char* filePath);
        ~Player();

        void render();
        void update(double deltaTime, SDL_Rect camera);

        Vector2 getScreenPos();
        Vector2 getWorldPos();
        

    private:
        Vector2 worldPos;
        Vector2 screenPos;
        SDL_Texture *texture;
        SDL_Renderer *renderer;

};