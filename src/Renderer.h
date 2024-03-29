//
// Created by Vadim Melnicuk on 08/12/2018.
//

#pragma once

#include <SDL.h>

namespace Enfleurage {

    class Renderer {
    public:
        static void Init(SDL_Window* pWindow);
        static void Draw(SDL_Texture* pTexture, SDL_Rect pSrcRect, SDL_Rect pDestRect);
        static void Clear();
        static void Present();
        static void Close();
        inline static SDL_Renderer* GetRenderer() { return msRenderer; }
    private:
        static SDL_Renderer* msRenderer;
    };
}
