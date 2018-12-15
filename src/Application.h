//
// Created by Vadim Melnicuk on 18/11/2018.
//

#pragma once

#include <vector>

#include "SDL.h"
#include "SDL_image.h"

#include "Window.h"
#include "Renderer.h"
#include "TextureManager.h"
#include "Object.h"
#include "Map.h"

namespace Enfleurage {

    class Application {
    public:
        static bool Init(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen, unsigned int pFPS);
        static void Close();
        inline static void Quit() { mRunning = false; };
        inline static bool isRunning() { return mRunning; }
        inline static unsigned int GetTicks() { return SDL_GetTicks(); }
        inline static unsigned int GetFrameDelay() { return mFrameDelay; }
        inline static void Delay(unsigned int pMs) { SDL_Delay(pMs); }
    private:
        static bool mRunning;
        static unsigned int mFrameDelay;
        static Window* mWindow;
    };
}