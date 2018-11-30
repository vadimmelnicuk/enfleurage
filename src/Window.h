//
// Created by vmelnicu on 20/11/2018.
//

#pragma once

#include "Log.h"
#include "SDL.h"

namespace Hazel {

    //Key press surfaces constants
    enum KeyPressSurfaces {
        KEY_PRESS_SURFACE_DEFAULT,
        KEY_PRESS_SURFACE_UP,
        KEY_PRESS_SURFACE_DOWN,
        KEY_PRESS_SURFACE_LEFT,
        KEY_PRESS_SURFACE_RIGHT,
        KEY_PRESS_SURFACE_TOTAL
    };

    class Window {
    public:
        Window();
        ~Window();
        bool Init();
        bool LoadMedia();
        void GameLoop();
        void Close();

    private:
        const int SCREEN_WIDTH = 640;
        const int SCREEN_HEIGHT = 480;
        SDL_Window* gWindow = NULL;
        SDL_Surface* gScreenSurface = NULL;
        SDL_Surface* gCross = NULL;
    };
}
