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
        ~Texture();
        inline SDL_Texture* GetTexture() { return mTexture; }
        inline SDL_Rect& GetSrcRect() { return mSrcRect; }
    private:
        SDL_Texture* mTexture;
        SDL_Rect mSrcRect;
    };
}