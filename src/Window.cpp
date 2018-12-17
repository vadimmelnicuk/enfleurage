//
// Created by vmelnicu on 20/11/2018.
//

#include "Window.h"

namespace Enfleurage {

    Window::Window(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen) : mTitle(pTitle), mXPos(pXPos), mYPos(pYPos), mWidth(pWidth), mHeight(pHeight), mFullscreen(pFullscreen) {
        signed int flags = SDL_WINDOW_SHOWN;

        if (mFullscreen) {
            flags =  flags | SDL_WINDOW_FULLSCREEN;
        }

        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            LOG_CORE_ERROR("SDL could not initialize! SDL_Error: {0}", SDL_GetError());
        } else {
            LOG_CORE_INFO("SDL initialised");
            mWindow = SDL_CreateWindow(mTitle, mXPos, mYPos, mWidth, mHeight, flags);

            if (mWindow == nullptr) {
                LOG_CORE_ERROR("Window could not be created! SDL_Error: {0}", SDL_GetError());
            } else {
                LOG_CORE_INFO("SDL Window created");
                mInitialised = true;
            }
        }
    }

    Window::~Window() {
        SDL_DestroyWindow(mWindow);
        mWindow = nullptr;
    }
}