#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.hpp"

class Entity
{
    private:
        Vector2f position;
        SDL_Rect currentFrame;
        SDL_Texture* texture;
    public:
        Entity(Vector2f p_position, SDL_Texture* p_texture);
        Vector2f& getPosition();
        SDL_Texture* getTexture() const;
        SDL_Rect getCurrentFrame() const;


};
