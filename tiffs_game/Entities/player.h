#ifndef PLAYER_H
#define PLAYER_H

#include "game_entity.h"
//#include "sprite.h"
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

public:
    // Constructor
    Player(Vector2 position, float speed = 5.0f, Color color = BLACK)
        : position(position), speed(speed), color(color) {}

    int GetDrawOrder() const override
    {
        return 1;
    }

    void Initialize()
    {
        state = PlayerState::Idle;
        isAlive = true;
    }

    //Handle player movement
    void Move(int direction)
    {
        position.x += direction * speed;

        // Prevent the player from going off-screen
        if (position.x < 0) {
            position.x = 0;
        } else if (position.x > 1920 - 50) {  // 50 is the player width (size of rectangle)
            position.x = 1920 - 50;
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

        // If no movement, player is idle
        if (!IsKeyDown(KEY_D) && !IsKeyDown(KEY_A))
        {
            state = PlayerState::Idle;
        }
    }

    void Draw() const override
    {
        //sprite.Draw(position, WHITE);
        DrawRectangleV(position, {50, 50}, color);
    }

    Vector2 GetPosition() const
    {
        return position;
    }

    PlayerState GetState() const
    {
        return state;
    }

    // bool IsAlive() const
    // {
    //     return isAlive;
    // }

    // void SetPosition(Vector2 newPosition)
    // {
    //     position = newPosition;
    // }
};

#endif // PLAYER_H