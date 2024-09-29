#include <raylib/raylib.h>

// Main entry point
int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "Input Program");
    
    Vector2 ballPosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
    
    const char* text = ("use W, A, S, D to move the ball!");
    
    SetTargetFPS(60);
    
    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        if (IsKeyDown(KEY_D))
        {
            ballPosition.x += 2.0f;
        }
        if (IsKeyDown(KEY_A))
        {
            ballPosition.x -= 2.0f;
        }
        if (IsKeyDown(KEY_W))
        {
            ballPosition.y -= 2.0f;
        }
        if (IsKeyDown(KEY_S))
        {
            ballPosition.y += 2.0f;
        }
        
        // Draw
        BeginDrawing();
            
            ClearBackground(SKYBLUE);
            
            DrawText(text, 10, 10, 20, DARKBLUE);
            
            DrawCircleV(ballPosition, 50, DARKBLUE);
            
        EndDrawing();
    }
    
    // De-Initialization
    
    CloseWindow();

    return 0;
}