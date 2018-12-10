//
// Created by Vadim Melnicuk on 09/12/2018.
//

#include "Map.h"

namespace Enfleurage {

    int LVL[10][10] = {
            {1,1,1,1,2,0,0,0,0,0},
            {1,1,1,2,2,0,0,0,0,0},
            {1,1,1,2,0,0,0,0,0,0},
            {1,2,2,2,0,0,0,0,0,0},
            {2,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0,0}
    };

    Map::Map() {
        mSand = TextureManager::LoadTexture("../assets/sand.png");
        mGrass = TextureManager::LoadTexture("../assets/grass.png");
        mWater = TextureManager::LoadTexture("../assets/water.png");

        this->LoadMap(LVL);

        mSrcRect.x = 0;
        mSrcRect.y = 0;
        mSrcRect.w = 64;
        mSrcRect.h = 64;

        mDestRect.x = 0;
        mDestRect.y = 0;
        mDestRect.w = 64;
        mDestRect.h = 64;
    }

    void Map::LoadMap(int pMap[10][10]) {
        for (int r = 0; r < 10; r++) {
            for (int c = 0; c < 10; c++) {
                mMap[r][c] = pMap[r][c];
            }
        }
    }

    void Map::Render() {
        for (int r = 0; r < 10; r++) {
            for (int c = 0; c < 10; c++) {
                mDestRect.x = c * 64;
                mDestRect.y = r * 64;

                switch (mMap[r][c]) {
                    case 0:
                        Renderer::Draw(mSand, mSrcRect, mDestRect);
                        break;
                    case 1:
                        Renderer::Draw(mGrass, mSrcRect, mDestRect);
                        break;
                    case 2:
                        Renderer::Draw(mWater, mSrcRect, mDestRect);
                        break;
                    default:
                        break;
                }
            }
        }
    }
}