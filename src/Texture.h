//
// Created by vmelnicu on 18/12/2018.
//

#pragma once

#include "SDL.h"

#include "TextureManager.h"

namespace Enfleurage {
    class Texture {
    public:
        Texture(const char* pPath, int pX, int pY, int pWidth, int pHeight);
        Texture(SDL_Texture* pTexture, int pX, int pY, int pWidth, int pHeight);
        ~Texture();
        void SetColor(Uint8 pRed, Uint8 pGreen, Uint8 pBlue);
        void SetBlendMode(SDL_BlendMode pBlendMode);
        void SetAlpha(Uint8 pAlpha);
        void SetSrcRect(int pX, int pY, int pWidth = 0, int pHeight = 0);
        inline SDL_Texture* GetTexture() { return mTexture; }
        inline SDL_Rect& GetSrcRect() { return mSrcRect; }
    private:
        SDL_Texture* mTexture;
        SDL_Rect mSrcRect;
    };
}