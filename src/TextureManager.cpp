//
// Created by VMELNICU on 07/12/2018.
//

#include "TextureManager.h"

namespace Hazel {

    TextureManager::TextureManager() = default;
    TextureManager::~TextureManager() = default;

    SDL_Texture* TextureManager::LoadTexture(const char *pDir, SDL_Renderer *pRenderer) {
        SDL_Texture* tempTexture = nullptr;
        SDL_Surface* tempSurface = IMG_Load(pDir);

        if (tempSurface == nullptr) {
            LOG_CORE_ERROR("Texture failed to load! SDL_Error: {0}", SDL_GetError());
        } else {
            LOG_CORE_INFO("Texture loaded: {0}", pDir);
            tempTexture = SDL_CreateTextureFromSurface(pRenderer, tempSurface);
        }

        SDL_FreeSurface(tempSurface);

        return tempTexture;
    }

    void TextureManager::Close() {

    }
}