//
// Created by VMELNICU on 07/12/2018.
//

#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "Log.h"

namespace Hazel {

    class TextureManager {
    public:
        TextureManager();
        ~TextureManager();
        SDL_Texture* LoadTexture(const char* pDir, SDL_Renderer* pRenderer);
        void Close();
    };
}