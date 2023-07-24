#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
    private:
        float x, y;
        SDL_Rect currentFrame;
        SDL_Texture* texture;
    public:
        Entity(float p_x, float p_y, SDL_Texture* p_texture);

        float getX() const;
        float getY() const;
        SDL_Texture* getTexture() const;
        SDL_Rect getCurrentFrame() const;


};
