#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <memory>

#include "../include/RenderWindow.hpp"
#include "../include/Entity.hpp"

int main(int argc, char* argv[]){

    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL_Init has failed. SDL_Error: " << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;
    }

    RenderWindow window("Game v0.0.1", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("../res/gfx/ground_tile.png");

    std::vector<std::unique_ptr<Entity>> entities;

    for (int i = 0; i < 20; i++){
        entities.push_back(std::make_unique<Entity>(Vector2f(i * 64, 720 - 64), grassTexture));
    }

    bool gameRunning = true;
    SDL_Event event;
    while (gameRunning){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                gameRunning = false;
            }
        }

        window.clear();
        
        for (auto& entity : entities){
            window.render(*entity);
        }


        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
