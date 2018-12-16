//
// Created by VMELNICU on 07/12/2018.
//

#include "Object.h"

namespace Enfleurage {

    Object::Object(const char *pTextureSheet, int pX, int pY, int pScale) : mX(pX), mY(pY), mScale(pScale) {
        mTexture = TextureManager::LoadTexture(pTextureSheet);
        mSrcRect = {0, 0, 64, 64};
    }

    void Object::Update() {
        mX++;
        mY++;
        mDestRect = {mX, mY, mSrcRect.w * mScale, mSrcRect.h * mScale};
    }

    void Object::Render() {
        SDL_RenderCopy(Renderer::GetRenderer(), mTexture, &mSrcRect, &mDestRect);
    }
}
