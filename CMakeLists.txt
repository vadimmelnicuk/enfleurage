cmake_minimum_required(VERSION 3.12)
project(hazel)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${hazel_SOURCE_DIR}/cmake")

add_library(hazel STATIC src/Application.cpp src/Application.h src/Window.cpp src/Window.h src/Log.cpp src/Log.h src/Hazel.h src/TextureManager.cpp src/TextureManager.h src/Object.cpp src/Object.h)

# Link all the MinGW DLLs statically on windows
IF(NOT APPLE)
    target_link_libraries(hazel -static)
ENDIF(NOT APPLE)

# Load SDL2 library for both Windows and OSX
IF(APPLE)
    set(SDL2_PATH "${hazel_SOURCE_DIR}/lib/SDL2/")
ELSE()
    set(SDL2_PATH "${hazel_SOURCE_DIR}/lib/SDL2/i686-w64-mingw32")
ENDIF(APPLE)
find_package(SDL2 REQUIRED)
target_include_directories(hazel PUBLIC ${SDL2_INCLUDE_DIR})
target_link_libraries(hazel ${SDL2_LIBRARY})

# Load SDL2_image library for both Windows and OSX
IF(APPLE)
    set(SDL2_IMAGE_PATH "${hazel_SOURCE_DIR}/lib/SDL2_image/")
ELSE(APPLE)
    set(SDL2_IMAGE_PATH "${hazel_SOURCE_DIR}/lib/SDL2_image/i686-w64-mingw32")
ENDIF(APPLE)
find_package(SDL2_image REQUIRED)
target_include_directories(hazel PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(hazel ${SDL2_IMAGE_LIBRARIES})

# spdlog library
target_include_directories(hazel PUBLIC lib/spdlog/include)