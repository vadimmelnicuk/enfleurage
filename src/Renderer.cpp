//
// Created by Vadim Melnicuk on 08/12/2018.
//

#include "Renderer.h"

namespace Enfleurage {

    SDL_Renderer* Renderer::msRenderer = nullptr;

    void Renderer::Init(SDL_Window* pWindow) {
        msRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }

    void Renderer::Draw(SDL_Texture *pTexture, SDL_Rect pSrcRect, SDL_Rect pDestRect) {
        SDL_RenderCopy(msRenderer, pTexture, &pSrcRect, &pDestRect);
    }

    void Renderer::Clear() {
        SDL_SetRenderDrawColor(Renderer::GetRenderer(), 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(msRenderer);
    }

    void Renderer::Present() {
        SDL_RenderPresent(msRenderer);
    }

    void Renderer::Close() {
        SDL_DestroyRenderer(msRenderer);
        msRenderer = nullptr;
    }
}
