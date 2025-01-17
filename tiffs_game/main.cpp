#include <raylib/raylib.h>

// Main entry point
int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Tiff's Game");

    SetTargetFPS(60);

    const char* text = ("Hello Dan");

    // Main game loop
    {
        while(!WindowShouldClose())
        {
            // Update

            // Draw
            BeginDrawing();

                ClearBackground(SKYBLUE);

                DrawText(text, (float)screenWidth /2 - 150, (float)screenHeight / 2 - 50, 60, DARKBLUE);

            EndDrawing();
        }
    }

    // De-Initialization

    CloseWindow();

    return 0;
}