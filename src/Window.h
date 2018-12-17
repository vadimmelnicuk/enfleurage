//
// Created by vmelnicu on 20/11/2018.
//

#pragma once

#include "SDL.h"
#include "Log.h"

namespace Enfleurage {

    class Window {
    public:
        Window(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen);
        ~Window();
        inline SDL_Window* GetWindow() { return mWindow; }
        inline bool IsInitialised() { return mInitialised; }
        inline int GetWidth() { return mWidth; }
        inline int GetHeigth() { return mHeight; }
    private:
        SDL_Window* mWindow = nullptr;
        bool mInitialised = false;
        const char* mTitle;
        int mXPos;
        int mYPos;
        int mWidth;
        int mHeight;
        bool mFullscreen;
    };
}
