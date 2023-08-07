#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include <memory>

#include "../include/RenderWindow.hpp"
#include "../include/Entity.hpp"
#include "../include/Utils.hpp"
#include "../include/Player.hpp"

int main(int argc, char* argv[]){

    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "SDL_Init has failed. SDL_Error: " << SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;
    }

    RenderWindow window("Game v0.0.1", 1280, 720);

    // Get texture for entity
    SDL_Texture* grassTexture = window.loadTexture("../res/gfx/ground_tile.png");
    // Create list of entities
    std::vector<std::unique_ptr<Entity>> entities;
    for (int i = 0; i < 20; i++){
        entities.push_back(std::make_unique<Entity>(Vector2f(i * 64, 720 - 64), grassTexture));
    }

    entities.push_back(std::make_unique<Entity>(Vector2f(300, 300), grassTexture));

    // Get texture for player
    SDL_Texture* playerTexture = window.loadTexture("../res/gfx/player.png");
    // Create player
    std::unique_ptr<Player> player = std::make_unique<Player>(Vector2f(100, 100), playerTexture);


    // Set game parameters
    bool gameRunning = true;
    SDL_Event event;

    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    // Start gameloop
    while (gameRunning){
        int startTicks = SDL_GetTicks();

        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;
        accumulator += frameTime;

        // PoolEvent loop inside frame controll loop
        while (accumulator >= timeStep){
            while (SDL_PollEvent(&event)){
                switch (event.type){
                    case SDL_QUIT:
                        gameRunning = false;
                        break;
                }
            }
            
            // Game controls
            const Uint8* keystates = SDL_GetKeyboardState(NULL);

            if(keystates[SDL_SCANCODE_W])
                player->jump();
            if(keystates[SDL_SCANCODE_A])
                player->moveLeft();
            else if(keystates[SDL_SCANCODE_D])
                player->moveRight();
            else
                player->stand();

            accumulator -= timeStep;
        }

        const float alpha = accumulator / timeStep;


        window.clear();

        // Render entities
        for (auto& entity : entities) {
            window.render(*entity);
        }
        // Render player
        window.render(*player); 
        player->update(entities);

        // std::cout << utils::hireTimeInSeconds() << std::endl;

        window.display();

        int frameTicks = SDL_GetTicks() - startTicks;
        if (frameTicks < 1000 / window.getRefreshRate()){
            SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
        }
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
