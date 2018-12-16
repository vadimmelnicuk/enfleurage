//
// Created by vmelnicu on 20/11/2018.
//

#pragma once

#include "SDL.h"
#include "Log.h"

namespace Enfleurage {

    class Window {
    public:
        Window() = default;
        ~Window() = default;
        bool Init(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen);
        void Close();
        inline SDL_Window* getWindow() { return mWindow; }
        inline int getWidth() { return mWidth; }
        inline int getHeigth() { return mHeight; }
    private:
        SDL_Window* mWindow = nullptr;
        int mWidth;
        int mHeight;
    };
}
