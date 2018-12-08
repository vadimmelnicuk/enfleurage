//
// Created by Vadim Melnicuk on 18/11/2018.
//

#include "Application.h"

namespace Hazel {

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

                mObject = new Object(mRenderer, "../assets/darkDirtBlock.png", 0, 0, 1);
                mObject2 = new Object(mRenderer, "../assets/sprite.png", 64, 64, 1);
            }
        } else {
            success = false;
        }

        return success;
    }

    void Application::Run() {
        mRunning = true;

        while (mRunning) {
            mFrameStart = SDL_GetTicks();

            this->HandleEvents();
            this->Update();
            this->Render();

            mFrameTime = SDL_GetTicks() - mFrameStart;

            if (FRAME_DELAY > mFrameTime) {
                SDL_Delay(FRAME_DELAY - mFrameTime);
            }
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
        mObject->Update();
        mObject2->Update();
    }

    void Application::Render() {
        SDL_RenderClear(mRenderer);

        mObject->Render();
        mObject2->Render();

        SDL_RenderPresent(mRenderer);
    }

    void Application::Close() {
        mWindow->Close();

        SDL_DestroyRenderer(mRenderer);
        mRenderer = nullptr;

        SDL_Quit();
    }
}