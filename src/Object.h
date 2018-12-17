//
// Created by VMELNICU on 07/12/2018.
//

#pragma once

#include "SDL.h"

#include "Renderer.h"
#include "TextureManager.h"
#include "Log.h"

namespace Enfleurage {

    class Object {
    public:
        Object(const char* pTextureSheet, int pX, int pY, int pScale);
        ~Object();
        void Update();
        void Render();
        inline int GetX() { return mX; }
        inline int GetY() { return mY; }
        inline int GetScale() { return mScale; }
        inline void SetX(int pX) {mX = pX;}
        inline void SetY(int pY) {mY = pY;}
        inline void ShiftX(int pX) {mX += pX;}
        inline void ShiftY(int pY) {mY += pY;}
    private:
        int mX;
        int mY;
        int mScale;
        SDL_Texture* mTexture;
        SDL_Rect mSrcRect;
        SDL_Rect mDestRect;
    };
}
