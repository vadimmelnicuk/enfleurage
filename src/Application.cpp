//
// Created by Vadim Melnicuk on 18/11/2018.
//

#include "Application.h"

namespace Enfleurage {

    bool Application::Init(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen) {
        bool success = true;
        mWindow = new Window();

        if (mWindow->Init(pTitle, pXPos, pYPos, pWidth, pHeight, pFullscreen)) {
            // Init renderer
            Renderer::Init(mWindow->getWindow());

            if (Renderer::GetRenderer() == nullptr) {
                LOG_CORE_ERROR("Renderer could not be created! SDL_Error: {0}", SDL_GetError());
                success = false;
            } else {
                LOG_CORE_INFO("SDL renderer created");
                SDL_SetRenderDrawColor(Renderer::GetRenderer(), 0, 0, 0, 255);

                mObject = new Object("../assets/darkDirtBlock.png", 0, 0, 1);
                mObject2 = new Object("../assets/sprite.png", 64, 64, 1);
                mMap = new Map();
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

            // Sleep if the loop runs faster than 60 FPS
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
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            mObject->shiftY(-50);
                            break;
                        case SDLK_DOWN:
                            mObject->shiftY(50);
                            break;
                        default:
                            break;
                    }
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
        // Double buffer
        SDL_RenderClear(Renderer::GetRenderer());

        mMap->Render();
        mObject->Render();
        mObject2->Render();

        SDL_RenderPresent(Renderer::GetRenderer());
    }

    void Application::Close() {
        mWindow->Close();

        Renderer::Close();

        SDL_Quit();
    }
}