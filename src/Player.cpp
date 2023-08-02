#include "../include/Player.hpp"

Player::Player(Vector2f p_position, SDL_Texture* p_texture) : Entity(p_position, p_texture), velocity(0, 0), isJumping(false), inAir(false) {
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 64;
    currentFrame.h = 109;

    this->calculateHitbox();
}

void Player::moveLeft(){
    if (velocity.x > -maxSpeed){
        velocity.x -= 1.0f;
    };
}

void Player::moveRight(){
    if (velocity.x < maxSpeed){
        velocity.x += 1.0f;
    };
}

void Player::jump(){
    if (!inAir){
        velocity.y = -10;
        isJumping = true;
    }
}

void Player::stand(){
    velocity.x = 0;
    if (!isJumping)
        velocity.y = 0;
}

bool Player::isOn(std::unique_ptr<Entity>& p_entity){
    if (this->isColliding(p_entity) && hitbox.y + hitbox.h <= p_entity->getHitbox().y){
        return true;
    }
    return false;
}


//TODO: Refactor this to use the Entity::update() method
void Player::update(std::vector<std::unique_ptr<Entity>>& p_entities){
    position.x += velocity.x;
    position.y += velocity.y;
    this->calculateHitbox();
    for (auto& p_entity : p_entities) {
        if (this->isColliding(p_entity)){
            position.y = p_entity->getPosition().y - hitbox.h;
            inAir = false;
            break;
        } else {
            inAir = true;
        }
    }
    if (inAir && velocity.y < maxFallSpeed){
        velocity.y += 0.5f;
    }


}

//TODO: Refactor this to use the Entity::checkCollisions() method
SDL_bool Player::isColliding(std::unique_ptr<Entity>& p_entity){
    return SDL_HasIntersection(&hitbox, &p_entity->getHitbox());
}