//
// Created by vmelnicu on 18/12/2018.
//

#include "Texture.h"

namespace Enfleurage {

    Texture::Texture(const char* pPath, int pX, int pY, int pWidth, int pHeight) {
        mTexture = TextureManager::LoadTexture(pPath);
        mSrcRect = {pX, pY, pWidth, pHeight};
        this->SetBlendMode(SDL_BLENDMODE_BLEND);
    }

    Texture::Texture(SDL_Texture *pTexture, int pX, int pY, int pWidth, int pHeight) : mTexture(pTexture) {
        mSrcRect = {pX, pY, pWidth, pHeight};
        this->SetBlendMode(SDL_BLENDMODE_BLEND);
    }

    Texture::~Texture() {
        TextureManager::FreeTexture(mTexture);
        mTexture = nullptr;
    }

    void Texture::SetColor(Uint8 pRed, Uint8 pGreen, Uint8 pBlue) {
        SDL_SetTextureColorMod(mTexture, pRed, pGreen, pBlue);
    }

    void Texture::SetBlendMode(SDL_BlendMode pBlendMode) {
        SDL_SetTextureBlendMode(mTexture, pBlendMode);
    }

    void Texture::SetAlpha(Uint8 pAlpha) {
        SDL_SetTextureAlphaMod(mTexture, pAlpha);
    }

    void Texture::SetSrcRect(int pX, int pY, int pWidth, int pHeight) {
        mSrcRect = {pX, pY, pWidth == 0 ? mSrcRect.w : pWidth, pHeight == 0 ? mSrcRect.h : pHeight};
    }
}