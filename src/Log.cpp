//
// Created by Vadim Melnicuk on 18/11/2018.
//

#include "Log.h"

namespace Hazel {

    std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
    std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

    void Log::Init()
    {
        // Create a console for the development purposes - only works if windows, but no need for it in osx
//        AllocConsole();
//        freopen("conin$","r",stdin);
//        freopen("conout$","w",stdout);
//        freopen("conout$","w",stderr);

        spdlog::set_pattern("%^[%T] %n: %v%$");

        s_CoreLogger = spdlog::stdout_color_mt("HAZEL");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}