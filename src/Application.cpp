//
// Created by Vadim Melnicuk on 18/11/2018.
//

#include "Application.h"

namespace Hazel {

    Application::Application() {

    }

    Application::~Application() {

    }

    void Application::Run() {
        Window* window = new Window();
        if (window->Init()) {
            window->LoadMedia();
            window->GameLoop();
            window->Close();
        }
    }
}