//
// Created by Vadim Melnicuk on 18/11/2018.
//

#pragma once

#include "Window.h"

namespace Hazel {

    class Application {
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    Application* CreateApplication();
}