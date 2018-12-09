//
// Created by Vadim Melnicuk on 08/12/2018.
//

#include "Renderer.h"

namespace Enfleurage {

    SDL_Renderer* Renderer::msRenderer = nullptr;

    void Renderer::Init(SDL_Window* pWindow) {
        msRenderer = SDL_CreateRenderer(pWindow, -1, 0);
    }

    void Renderer::Close() {
        SDL_DestroyRenderer(msRenderer);
    }
}
