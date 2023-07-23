#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <stdio.h>
#include <iostream>

int main(int argc, char* argv[]){

    SDL_Window* sdl_window = nullptr;

    unsigned int window_flags = SDL_WINDOW_OPENGL;

    if (SDL_Init(SDL_INIT_VIDEO)){
        printf("Failed to init SDL Video, error: %s", SDL_GetError());
        return 1;
    }

    int window_width = 640;
    int window_height = 480;
    enum class SCREENSIZE
    {
        is640x480,
        is1366x768,
        fullscreen
    }
    current_screen_size = SCREENSIZE::is640x480,
    last_non_fullscreen_size = SCREENSIZE::is640x480;

    sdl_window = SDL_CreateWindow(
        "SDL2 Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        window_width,
        window_height,
        window_flags
    );

    if (sdl_window == nullptr){
        printf("Failed to create SDL Window, error: %s", SDL_GetError());
        return 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GLContext Context = SDL_GL_CreateContext(sdl_window);

    glClearColor(255, 0, 0, 255);
    glViewport(0, 0, window_width, window_height);

    bool is_running = true;
    SDL_Event sdl_event;
    while (is_running){
        while (SDL_PollEvent(&sdl_event) != 0){
            if (sdl_event.type == SDL_QUIT){
                is_running = false;
            } else if (sdl_event.type == SDL_KEYDOWN){
                switch (sdl_event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        is_running = false;
                        break;
                    case SDLK_F11:
                        if (current_screen_size == SCREENSIZE::fullscreen){
                            SDL_SetWindowFullscreen(sdl_window, 0);
                            current_screen_size = last_non_fullscreen_size;
                        } else {
                            last_non_fullscreen_size = current_screen_size;
                            SDL_SetWindowFullscreen(sdl_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                            current_screen_size = SCREENSIZE::fullscreen;
                        }
                        SDL_GetWindowSize(sdl_window, &window_width, &window_height);
                        glViewport(0, 0, window_width, window_height);
                        break;
                    case SDLK_F10:
                        switch (current_screen_size){
                            case SCREENSIZE::fullscreen:
                                break;
                            case SCREENSIZE::is640x480:
                                SDL_SetWindowSize(sdl_window, 1366, 768);
                                current_screen_size = SCREENSIZE::is1366x768;
                                break;
                            case SCREENSIZE::is1366x768:
                                SDL_SetWindowSize(sdl_window, 640, 480);
                                current_screen_size = SCREENSIZE::is640x480;
                                break;
                        }
                        SDL_GetWindowSize(sdl_window, &window_width, &window_height);
                        glViewport(0, 0, window_width, window_height);
                        break;
                }
            }

            glClear(GL_COLOR_BUFFER_BIT);

            SDL_GL_SwapWindow(sdl_window);
        }
    }

    SDL_DestroyWindow(sdl_window);

    SDL_Quit();

    return 0;
}
