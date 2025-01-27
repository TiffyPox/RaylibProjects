#ifndef PLAYER_H
#define PLAYER_H

#include "game_entity.h"
#include "sprite.h"
#include "player_state.h"
#include <raylib/raylib.h>

class Player : public GameEntity
{
private:
    //Sprite sprite;
    Vector2 position;
    bool isAlive;
    float speed;
    Color color;
    PlayerState state;

    float jumpSpeed;
    float gravity;
    bool isJumping;
    bool isOnGround;

public:
    // Constructor
    Player(Vector2 position, float speed = 5.0f, Color color = BLACK)
        : position(position), speed(speed), color(color), jumpSpeed(20.0f), gravity(1.0f) {}

    int GetDrawOrder() const override
    {
        return 1;
    }

    void Initialize()
    {
        state = PlayerState::Idle;
        isAlive = true;
        isJumping = false;
        isOnGround = true;
    }

    //Handle player movement
    void Move(int direction)
    {
        position.x += direction * speed;

        // Prevent the player from going off-screen
        if (position.x < 0) 
        {
            position.x = 0;
        } 
        else if (position.x > 1920 - 100) 
        {
            position.x = 1920 - 100; // 100 is the player width (size of rectangle)
        }
    }

    void Update() override
    {
        // Move right
        if (IsKeyDown(KEY_D))
        {
            Move(1);
            state = PlayerState::Moving;
        }

        // Move left
        if (IsKeyDown(KEY_A))
        {
            Move(-1);
            state = PlayerState::Moving;
        }

        // Jumping logic
        if (IsKeyPressed(KEY_SPACE) && isOnGround)
        {
            isJumping = true;
            state = PlayerState::Jumping;
            isOnGround = false;
        }

        if (isJumping)
        {
            position.y -= jumpSpeed; // Move player up while jumping
            jumpSpeed -= gravity; // Gravity pulls the player down
        }

        // Prevent the player from falling below the ground
        if (position.y >= 1200 - 100)
        {
            // Reset player variables
            position.y = 1200 - 100;
            isJumping = false;
            jumpSpeed = 20.0f;
            isOnGround = true;
            state = PlayerState::Idle;
        }

        // If no movement, player is idle
        if (!IsKeyDown(KEY_D) && !IsKeyDown(KEY_A))
        {
            state = PlayerState::Idle;
        }
    }

    void Draw() const override
    {
        //sprite.Draw(position, WHITE);
        DrawRectangleV(position, {100, 100}, color);
    }

    Vector2 GetPosition() const
    {
        return position;
    }

    PlayerState GetState() const
    {
        return state;
    }

    bool IsAlive() const
    {
        return isAlive;
    }
};

#endif // PLAYER_H