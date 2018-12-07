//
// Created by vmelnicu on 20/11/2018.
//

#pragma once

#include "SDL.h"
#include "Log.h"

namespace Hazel {

    class Window {
    public:
        Window();
        ~Window();
        bool Init(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen);
        void Close();
        inline SDL_Window* getWindow() { return mWindow; }
    private:
        SDL_Window* mWindow = nullptr;
    };
}
