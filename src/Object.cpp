//
// Created by VMELNICU on 07/12/2018.
//

#include "Object.h"

namespace Enfleurage {

    Object::Object(const char *pTextureSheet, int pX, int pY, int pScale) {
        mTexture = TextureManager::LoadTexture(pTextureSheet);
        mX = pX;
        mY = pY;
        mScale = pScale;

        mSrcRect.x = 0;
        mSrcRect.y = 0;
        mSrcRect.w = 64;
        mSrcRect.h = 64;
    }

    void Object::Update() {
        mX++;
        mY++;

        mDestRect.x = mX;
        mDestRect.y = mY;
        mDestRect.w = mSrcRect.w * mScale;
        mDestRect.h = mSrcRect.h * mScale;
    }

    void Object::Render() {
        SDL_RenderCopy(Renderer::GetRenderer(), mTexture, &mSrcRect, &mDestRect);
    }
}
