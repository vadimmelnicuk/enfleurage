//
// Created by VMELNICU on 07/12/2018.
//

#pragma once

#include "SDL.h"
#include "Log.h"
#include "TextureManager.h"

namespace Hazel {

    class Object {
    public:
        Object(SDL_Renderer* pRenderer, const char* pTextureSheet, int pX, int pY, int pScale);
        ~Object() = default;
        void Update();
        void Render();
    private:
        int mX;
        int mY;
        int mScale;
        SDL_Texture* mTexture;
        SDL_Rect mSrcRect;
        SDL_Rect mDestRect;
        SDL_Renderer* mRenderer;
    };
}
