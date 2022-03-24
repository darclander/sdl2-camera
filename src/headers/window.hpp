#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "vector2.hpp"

class Window {

    public:
        Window(const char* title, int w, int h);
        ~Window();
        void clear();
        void display();
        SDL_Texture *loadTexture(const char* filePath);
        void render(int x, int y, SDL_Texture *texture);

        SDL_Renderer *getRenderer();

    private:
        Vector2 worldPos;
        int width, height;
        SDL_Window *window;
        SDL_Renderer *renderer;

};