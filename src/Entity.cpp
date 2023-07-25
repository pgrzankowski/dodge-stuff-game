#include "../include/Entity.hpp"

Entity::Entity(Vector2f p_position, SDL_Texture* p_texture) : position(p_position), texture(p_texture){
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 64;
    currentFrame.h = 64;
}

Vector2f& Entity::getPosition(){
    return position;
}

SDL_Texture* Entity::getTexture() const{
    return texture;
}

SDL_Rect Entity::getCurrentFrame() const{
    return currentFrame;
}