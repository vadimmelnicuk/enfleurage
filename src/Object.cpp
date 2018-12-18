#include <utility>

//
// Created by VMELNICU on 07/12/2018.
//

#include "Object.h"

namespace Enfleurage {

    Object::Object(std::shared_ptr<Texture> pTexture, int pX, int pY, int pScale) : mTexture(std::move(pTexture)), mX(pX), mY(pY), mScale(pScale) {

    }

    void Object::Update() {
        mDestRect = {mX, mY, mTexture->GetSrcRect().w * mScale, mTexture->GetSrcRect().h * mScale};
    }

    void Object::Render() {
        SDL_RenderCopy(Renderer::GetRenderer(), mTexture->GetTexture(), &mTexture->GetSrcRect(), &mDestRect);
    }
}
