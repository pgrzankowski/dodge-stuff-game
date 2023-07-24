#include "../include/Entity.hpp"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_texture) : x(p_x), y(p_y), texture(p_texture){
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 64;
    currentFrame.h = 64;
}

float Entity::getX() const{
    return x;
}

float Entity::getY() const{
    return y;
}

SDL_Texture* Entity::getTexture() const{
    return texture;
}

SDL_Rect Entity::getCurrentFrame() const{
    return currentFrame;
}