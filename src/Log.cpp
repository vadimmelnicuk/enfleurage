//
// Created by Vadim Melnicuk on 18/11/2018.
//

#include "Log.h"

namespace Hazel {

    std::shared_ptr<spdlog::logger> Log::msCoreLogger;
    std::shared_ptr<spdlog::logger> Log::msClientLogger;

    void Log::Init() {
        // Create a console window for the development purposes in Windows. There is no need for it in OSX.
        #ifdef _WIN32
            AllocConsole();
            freopen("conin$","r",stdin);
            freopen("conout$","w",stdout);
            freopen("conout$","w",stderr);
        #endif

        spdlog::set_pattern("%^[%H:%M:%S.%e] %n: %v%$");

        msCoreLogger = spdlog::stdout_color_mt("HAZEL");
        msCoreLogger->set_level(spdlog::level::trace);

        msClientLogger = spdlog::stdout_color_mt("APP");
        msClientLogger->set_level(spdlog::level::trace);

        LOG_CORE_INFO("Log initialised");
    }
}