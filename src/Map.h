//
// Created by Vadim Melnicuk on 09/12/2018.
//

#pragma once

#include "SDL.h"

#include "TextureManager.h"

namespace Enfleurage {

    class Map {
    public:
        Map();
        ~Map() = default;
        void LoadMap(int pMap[10][10]);
        void Render();
    private:
        SDL_Rect mSrcRect;
        SDL_Rect mDestRect;
        SDL_Texture* mSand;
        SDL_Texture* mGrass;
        SDL_Texture* mWater;
        int mMap[10][10];
    };
}