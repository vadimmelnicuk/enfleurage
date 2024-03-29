//
// Created by Vadim Melnicuk on 18/11/2018.
//

#include "Application.h"

namespace Enfleurage {

    bool Application::mRunning = false;
    unsigned int Application::mFrameDelay = 0;
    std::shared_ptr<Window> Application::mWindow = nullptr;

    bool Application::Init(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen, unsigned int pFPS) {
        bool success = true;
        mFrameDelay = 1000 / pFPS;
        mWindow = std::make_shared<Window>(pTitle, pXPos, pYPos, pWidth, pHeight, pFullscreen);

        if (mWindow->IsInitialised()) {
            // Init renderer
            Renderer::Init(mWindow->GetWindow());

            if (Renderer::GetRenderer() == nullptr) {
                LOG_CORE_ERROR("Renderer could not be created! SDL_Error: {0}", SDL_GetError());
                success = false;
            } else {
                LOG_CORE_INFO("SDL Renderer created");
            }
        } else {
            success = false;
        }

        if (success) {
            mRunning = true;
        }

        return success;
    }

    void Application::Close() {
        Renderer::Close();
        SDL_Quit();
    }
}