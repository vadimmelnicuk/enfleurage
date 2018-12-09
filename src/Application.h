//
// Created by Vadim Melnicuk on 18/11/2018.
//

#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include "Window.h"
#include "Renderer.h"
#include "TextureManager.h"
#include "Object.h"

namespace Enfleurage {

    class Application {
    public:
        const int FPS = 60;
        const int FRAME_DELAY = 1000 / FPS;

        Application() = default;
        ~Application() = default;
        bool Init(const char* pTitle, int pXPos, int pYPos, int pWidth, int pHeight, bool pFullscreen);
        void Run();
        void HandleEvents();
        void Update();
        void Render();
        void Close();
        inline bool isRunning() { return mRunning; }
    private:
        bool mRunning;
        unsigned int mFrameStart;
        unsigned int mFrameTime;
        Window* mWindow;
        Object* mObject;
        Object* mObject2;
        unsigned int mCounter = 0;
    };
}