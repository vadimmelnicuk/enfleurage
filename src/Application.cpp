//
// Created by Vadim Melnicuk on 18/11/2018.
//

#include "Application.h"

namespace Hazel {

    Application::Application() {}

    Application::~Application() {}

    bool Application::Init(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen) {
        bool success = true;
        mWindow = new Window();

        if (mWindow->Init(pTitle, pXPos, pYPos, pWidth, pHeight, pFullscreen)) {

        } else {
            success = false;
        }

        return success;
    }

    void Application::Run() {
        mRunning = true;

        while (mRunning) {
            this->HandleEvents();
            this->Update();
            mWindow->Render();
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
        mCount++;

        LOG_CORE_INFO(mCount);
    }

    void Application::Close() {
        mWindow->Close();

        SDL_Quit();
    }
}