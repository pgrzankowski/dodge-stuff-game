cmake_minimum_required(VERSION 3.0.0)
project(endless-run-game VERSION 0.1.0 LANGUAGES C CXX)

include_directories(include)

set(SOURCE_FILES
    src/main.cpp
    src/RenderWindow.cpp
    src/Entity.cpp
    src/Math.cpp)

add_executable(endless-run-game ${SOURCE_FILES})

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(endless-run-game ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})
