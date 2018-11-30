//
// Created by Vadim Melnicuk on 18/11/2018.
//

#pragma once

#include <iostream>

#include "Application.h"
#include "Log.h"

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char *argv[]) {
    Hazel::Log::Init();
    LOG_CORE_WARN("Initialised Log!");
    int a = 5;
    LOG_INFO("Hello! Var={0}", a);

    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;

    return 0;
}