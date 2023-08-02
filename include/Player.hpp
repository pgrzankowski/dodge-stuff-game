#pragma once
#include "Entity.hpp"
#include <vector>
#include <memory>

class Player : public Entity {
    private:
        Vector2f velocity;
        float maxSpeed = 5.0f;
        float maxFallSpeed = 10.0f;
        bool isJumping;
        bool inAir;
    public:
        Player(Vector2f p_position, SDL_Texture* p_texture);
        void moveLeft();
        void moveRight();
        void jump();
        void stand();

        bool isOn(std::unique_ptr<Entity>& p_entity);

        void update(std::vector<std::unique_ptr<Entity>>& p_entity);
        SDL_bool isColliding(std::unique_ptr<Entity>& p_entity);
};