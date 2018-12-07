//
// Created by VMELNICU on 07/12/2018.
//

#pragma once

#include "SDL.h"
#include "Log.h"

namespace Hazel {

    class Object {
    public:
        Object(const char* pTextureSheet, SDL_Renderer* pRenderer);
        ~Object();
    };
}
