//
// Created by VMELNICU on 07/12/2018.
//

#include "TextureManager.h"

namespace Enfleurage {

    SDL_Texture* TextureManager::LoadTexture(const char* pDir) {
        SDL_Texture* texture = nullptr;
        SDL_Surface* tempSurface = IMG_Load(pDir);

        if (tempSurface == nullptr) {
            LOG_CORE_ERROR("Texture failed to load! SDL_Error: {0}", SDL_GetError());
        } else {
            LOG_CORE_INFO("Texture loaded: {0}", pDir);
            SDL_SetColorKey(tempSurface, SDL_TRUE, SDL_MapRGB(tempSurface->format, 0x00, 0xFF, 0xFF));
            texture = SDL_CreateTextureFromSurface(Renderer::GetRenderer(), tempSurface);
        }

        SDL_FreeSurface(tempSurface);
        tempSurface = nullptr;

        return texture;
    }

    void TextureManager::FreeTexture(SDL_Texture* pTexture) {
        if (pTexture != nullptr) {
            SDL_DestroyTexture(pTexture);
            pTexture = nullptr;
        }
    }
}