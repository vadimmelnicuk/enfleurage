//
// Created by VMELNICU on 07/12/2018.
//

#include "Object.h"

namespace Hazel {

    Object::Object(SDL_Renderer *pRenderer, const char *pTextureSheet, int pX, int pY, int pScale) {
        mRenderer = pRenderer;
        mTexture = TextureManager::LoadTexture(pTextureSheet, mRenderer);
        mX = pX;
        mY = pY;
        mScale = pScale;
    }

    void Object::Update() {
        mX++;
        mY++;

        mSrcRect.x = 0;
        mSrcRect.y = 0;
        mSrcRect.w = 64;
        mSrcRect.h = 64;

        mDestRect.x = mX;
        mDestRect.y = mY;
        mDestRect.w = mSrcRect.w * mScale;
        mDestRect.h = mSrcRect.h * mScale;
    }

    void Object::Render() {
        SDL_RenderCopy(mRenderer, mTexture, &mSrcRect, &mDestRect);
    }
}
