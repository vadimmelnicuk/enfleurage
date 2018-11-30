//
// Created by vmelnicu on 20/11/2018.
//

#include "Window.h"

namespace Hazel {

    Window::Window() {

    }

    Window::~Window() {

    }

    bool Window::Init() {
        bool success = true;

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            LOG_CORE_ERROR("SDL could not initialize! SDL_Error: {0}", SDL_GetError());
            success = false;
        } else {
            gWindow = SDL_CreateWindow("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

            if (gWindow == NULL) {
                LOG_CORE_ERROR("Window could not be created! SDL_Error: {0}", SDL_GetError());
                success = false;
            } else {
                //Get window surface
                gScreenSurface = SDL_GetWindowSurface(gWindow);
            }
        }

        return success;
    }

    bool Window::LoadMedia() {
        bool success = true;

        gCross = SDL_LoadBMP("..\\assets\\cross.bmp");

        if (gCross == NULL) {
            LOG_CORE_ERROR("Unable to load image {0}! SDL Error: {1}", "cross.bmp", SDL_GetError());
            success = false;
        }

        return success;
    }

    void Window::GameLoop() {
        bool quit = false;
        SDL_Event e;

        while (!quit) {
            while (SDL_PollEvent(&e) != 0) {
                //User requests quit
                if(e.type == SDL_QUIT) {
                    quit = true;
                }
            }

            SDL_BlitSurface(gCross, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);
        }
    }

    void Window::Close()
    {
        //Deallocate surface
        SDL_FreeSurface(gCross);
        gCross = NULL;

        //Destroy window
        SDL_DestroyWindow(gWindow);
        gWindow = NULL;

        //Quit SDL subsystems
        SDL_Quit();
    }
}