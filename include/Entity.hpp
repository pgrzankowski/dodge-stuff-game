#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.hpp"

class Entity
{
    protected:
        Vector2f position;
        SDL_Rect currentFrame;
        SDL_Rect hitbox;
        SDL_Texture* texture;
    public:
        Entity(Vector2f p_position, SDL_Texture* p_texture);
        Vector2f& getPosition();
        SDL_Texture* getTexture() const;
        const SDL_Rect& getCurrentFrame();
        const SDL_Rect& getHitbox();

        void setTexture(SDL_Texture* p_texture);
        void setCurrentFrame(int x, int y, int w, int h);

        void calculateHitbox();

        void update();
};
