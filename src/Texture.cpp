//
// Created by vmelnicu on 18/12/2018.
//

#include "Texture.h"

namespace Enfleurage {

    Texture::Texture(const char* pPath, int pX, int pY, int pWidth, int pHeight) {
        mTexture = TextureManager::LoadTexture(pPath);
        mSrcRect = {pX, pY, pWidth, pHeight};
    }

    Texture::~Texture() {
        TextureManager::FreeTexture(mTexture);
        mTexture = nullptr;
    }
}