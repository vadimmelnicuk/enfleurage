//
// Created by vmelnicu on 20/11/2018.
//

#pragma once

#include "Log.h"
#include "SDL.h"

namespace Hazel {

    class Window {
    public:
        Window();
        ~Window();
        bool Init(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen);
        void Render();
        void Close();
    private:
        SDL_Window* mWindow = NULL;
        SDL_Renderer* mRenderer = NULL;
    };
}
