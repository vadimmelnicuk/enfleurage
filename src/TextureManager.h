//
// Created by VMELNICU on 07/12/2018.
//

#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include "Renderer.h"
#include "Log.h"

namespace Enfleurage {

    class TextureManager {
    public:
        static SDL_Texture* LoadTexture(const char* pDir);
        static void FreeTexture(SDL_Texture* pTexture);
    };
}