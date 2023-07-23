cmake_minimum_required(VERSION 3.0.0)
project(endless-run-game VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(endless-run-game src/main.cpp)

target_link_libraries(endless-run-game SDL2main SDL2 GL)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
