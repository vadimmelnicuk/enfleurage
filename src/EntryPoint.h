//
// Created by Vadim Melnicuk on 18/11/2018.
//

#pragma once

#include <iostream>

#include "Application.h"
#include "Log.h"

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
    Hazel::Log::Init();
    Hazel::Log::GetCoreLogger()->warn("Initialised log!");

    auto app = Hazel::CreateApplication();
    app->Run();
    delete app;
}