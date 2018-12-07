//
// Created by vmelnicu on 20/11/2018.
//

#include "Window.h"

namespace Hazel {

    Window::Window() = default;

    Window::~Window() = default;

    bool Window::Init(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen) {
        bool success = true;
        signed int flags = SDL_WINDOW_SHOWN;

        if (pFullscreen) {
            flags =  flags | SDL_WINDOW_FULLSCREEN;
        }

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            LOG_CORE_ERROR("SDL could not initialize! SDL_Error: {0}", SDL_GetError());
            success = false;
        } else {
            LOG_CORE_INFO("SDL initialised");
            mWindow = SDL_CreateWindow(pTitle, pXPos, pYPos, pWidth, pHeight, flags);

            if (mWindow == nullptr) {
                LOG_CORE_ERROR("Window could not be created! SDL_Error: {0}", SDL_GetError());
                success = false;
            } else {
                LOG_CORE_INFO("SDL window created");
            }
        }

        return success;
    }

    void Window::Close() {
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;
    }
}