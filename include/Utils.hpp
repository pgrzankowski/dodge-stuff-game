#pragma once
#include <SDL2/SDL.h>

namespace utils{
    inline float hireTimeInSeconds(){
        float t = SDL_GetTicks();
        t *= 0.001f;

        return t;
    }

    inline float g() {
        return 9.81f;
    }
}