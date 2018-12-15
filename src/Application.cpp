//
// Created by Vadim Melnicuk on 18/11/2018.
//

#include "Application.h"

namespace Enfleurage {

    bool Application::mRunning = false;
    unsigned int Application::mFrameDelay = 0;
    Window* Application::mWindow = nullptr;

    bool Application::Init(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen, unsigned int pFPS) {
        bool success = true;
        mFrameDelay = 1000 / pFPS;
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

                mRunning = true;
            }
        } else {
            success = false;
        }

        return success;
    }

    void Application::Close() {
        mWindow->Close();

        Renderer::Close();

        SDL_Quit();
    }
}