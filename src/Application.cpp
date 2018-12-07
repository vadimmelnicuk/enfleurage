//
// Created by Vadim Melnicuk on 18/11/2018.
//

#include "Application.h"

namespace Hazel {

    Application::Application() = default;

    Application::~Application() = default;

    bool Application::Init(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen) {
        bool success = true;
        mWindow = new Window();

        if (mWindow->Init(pTitle, pXPos, pYPos, pWidth, pHeight, pFullscreen)) {
            mRenderer = SDL_CreateRenderer(mWindow->getWindow(), -1, 0);

            if (mRenderer == nullptr) {
                LOG_CORE_ERROR("Renderer could not be created! SDL_Error: {0}", SDL_GetError());
                success = false;
            } else {
                LOG_CORE_INFO("SDL renderer created");
                SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
            }
        } else {
            success = false;
        }

        mPlayerTexture = this->loadTexture("../assets/darkDirtBlock.png");

        return success;
    }

    void Application::Run() {
        mRunning = true;

        while (mRunning) {
            this->HandleEvents();
            this->Update();
            this->Render();
        }

        this->Close();
    }

    void Application::HandleEvents() {
        SDL_Event event;

        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_QUIT:
                    mRunning = false;
                    break;
                default:
                    break;
            }
        }
    }

    void Application::Update() {
        mDest.x = 0;
        mDest.y = 0;
        mDest.h = 64;
        mDest.w = 64;
    }

    void Application::Render() {
        SDL_RenderClear(mRenderer);

        SDL_RenderCopy(mRenderer, mPlayerTexture, nullptr, &mDest);

        SDL_RenderPresent(mRenderer);
    }

    SDL_Texture* Application::loadTexture(const char* dir) {
        SDL_Texture* tempTexture = nullptr;
        SDL_Surface* tempSurface = IMG_Load(dir);

        if (tempSurface == nullptr) {
            LOG_CORE_ERROR("Texture failed to load! SDL_Error: {0}", SDL_GetError());
        } else {
            LOG_CORE_INFO("Texture loaded: {0}", dir);
            tempTexture = SDL_CreateTextureFromSurface(mRenderer, tempSurface);
        }

        SDL_FreeSurface(tempSurface);

        return tempTexture;
    }

    void Application::Close() {
        mWindow->Close();

        SDL_DestroyRenderer(mRenderer);
        mRenderer = nullptr;

        SDL_Quit();
    }
}