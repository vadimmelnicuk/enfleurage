cmake_minimum_required(VERSION 3.12)
project(enfleurage)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${enfleurage_SOURCE_DIR}/cmake")

add_library(enfleurage STATIC src/Application.cpp src/Application.h src/Window.cpp src/Window.h src/Log.cpp src/Log.h src/Enfleurage.h src/TextureManager.cpp src/TextureManager.h src/Object.cpp src/Object.h src/Renderer.cpp src/Renderer.h src/Map.h src/Map.cpp src/ECS.cpp src/ECS.h src/Texture.cpp src/Texture.h src/Text.cpp src/Text.h)

# Link all the MinGW DLLs statically on windows
IF(NOT APPLE)
    target_link_libraries(enfleurage -static)
ENDIF(NOT APPLE)

# Load SDL2 library for both Windows and OSX
IF(APPLE)
    set(SDL2_PATH "${enfleurage_SOURCE_DIR}/lib/SDL2/")
ELSE(APPLE)
    set(SDL2_PATH "${enfleurage_SOURCE_DIR}/lib/SDL2/i686-w64-mingw32")
ENDIF(APPLE)
find_package(SDL2 REQUIRED)
target_include_directories(enfleurage PUBLIC ${SDL2_INCLUDE_DIR})
target_link_libraries(enfleurage ${SDL2_LIBRARY})

# Load SDL2_image library for both Windows and OSX
IF(APPLE)
    set(SDL2_IMAGE_PATH "${enfleurage_SOURCE_DIR}/lib/SDL2_image/")
ELSE(APPLE)
    set(SDL2_IMAGE_PATH "${enfleurage_SOURCE_DIR}/lib/SDL2_image/i686-w64-mingw32")
ENDIF(APPLE)
find_package(SDL2_image REQUIRED)
target_include_directories(enfleurage PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(enfleurage ${SDL2_IMAGE_LIBRARIES})

# Load SDL2_ttf library for both Windows and OSX
IF(APPLE)
    set(SDL2_TTF_PATH "${enfleurage_SOURCE_DIR}/lib/SDL2_ttf/")
ELSE(APPLE)
    set(SDL2_TTF_PATH "${enfleurage_SOURCE_DIR}/lib/SDL2_ttf/i686-w64-mingw32")
ENDIF(APPLE)
find_package(SDL2_ttf REQUIRED)
target_include_directories(enfleurage PUBLIC ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(enfleurage ${SDL2_TTF_LIBRARIES})

# spdlog library
target_include_directories(enfleurage PUBLIC lib/spdlog/include)