#include <utility>

//
// Created by VMELNICU on 07/12/2018.
//

#include "Object.h"

namespace Enfleurage {

    Object::Object(std::shared_ptr<Texture> pTexture, int pX, int pY, int pScale, double pAngle, SDL_Point* pCenter, SDL_RendererFlip pFlip) :
    mTexture(std::move(pTexture)),
    mX(pX),
    mY(pY),
    mScale(pScale),
    mAngle(pAngle),
    mCenter(pCenter),
    mFlip(pFlip) {

    }

    void Object::Update() {
        mDestRect = {mX, mY, mTexture->GetSrcRect().w * mScale, mTexture->GetSrcRect().h * mScale};
    }

    void Object::Render() {
        SDL_RenderCopyEx(Renderer::GetRenderer(), mTexture->GetTexture(), &mTexture->GetSrcRect(), &mDestRect, mAngle, mCenter, mFlip);
    }
}
