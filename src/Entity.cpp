#include "../include/Entity.hpp"

Entity::Entity(Vector2f p_position, SDL_Texture* p_texture) : position(p_position), texture(p_texture){
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 64;
    currentFrame.h = 64;

    this->calculateHitbox();
}

Vector2f& Entity::getPosition(){
    return position;
}

SDL_Texture* Entity::getTexture() const{
    return texture;
}

const SDL_Rect& Entity::getCurrentFrame(){
    return currentFrame;
}

const SDL_Rect& Entity::getHitbox(){
    return hitbox;    
}

void Entity::setTexture(SDL_Texture* p_texture){
    texture = p_texture;
}

void Entity::setCurrentFrame(int x, int y, int w, int h){
    currentFrame.x = x;
    currentFrame.y = y;
    currentFrame.w = w;
    currentFrame.h = h;
}

void Entity::calculateHitbox(){
    hitbox.x = position.x;
    hitbox.y = position.y;
    hitbox.w = currentFrame.w;
    hitbox.h = currentFrame.h;
}