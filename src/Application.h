//
// Created by Vadim Melnicuk on 18/11/2018.
//

#pragma once

#include "Window.h"
#include "SDL.h"
#include "SDL_image.h"

namespace Hazel {

    class Application {
    public:
        Application();
        ~Application();
        bool Init(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen);
        void Run();
        void HandleEvents();
        void Update();
        void Render();
        SDL_Texture* loadTexture(const char* dir);
        void Close();
        inline bool isRunning() { return mRunning; }
    private:
        bool mRunning;
        Window* mWindow;
        SDL_Renderer* mRenderer;
        SDL_Texture* mPlayerTexture;
        SDL_Rect mDest;
    };
}