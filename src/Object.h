//
// Created by VMELNICU on 07/12/2018.
//

#pragma once

#include "SDL.h"

#include "Renderer.h"
#include "Texture.h"
#include "Log.h"

namespace Enfleurage {

    class Object {
    public:
        Object(std::shared_ptr<Texture> pTexture, int pX, int pY, int pScale, double pAngle, SDL_Point* pCenter, SDL_RendererFlip pFlip);
        ~Object() = default;
        void Update();
        void Render();
        inline int GetX() { return mX; }
        inline int GetY() { return mY; }
        inline int GetScale() { return mScale; }
        inline std::shared_ptr<Texture> GetTexture() { return mTexture; }
        inline void SetX(int pX) { mX = pX; }
        inline void SetY(int pY) { mY = pY; }
        inline void ShiftX(int pX) { mX += pX; }
        inline void ShiftY(int pY) { mY += pY; }
        inline void SetAngle(double pAngle) { mAngle = pAngle; }
    private:
        int mX;
        int mY;
        int mScale;
        double mAngle;
        SDL_Point* mCenter;
        SDL_RendererFlip mFlip;
        std::shared_ptr<Texture> mTexture;
        SDL_Rect mDestRect;
    };
}
