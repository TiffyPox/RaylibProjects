#include <raylib/raylib.h>
#include "game_screen.h"

void UpdateLogo(int &framesCounter, GameScreen &currentScreen);
void UpdateTitle(GameScreen &currentScreen);
void UpdateGameplay(GameScreen &currentScreen);
void UpdateEnding(GameScreen &currentScreen);

void DrawLogo();
void DrawTitle();
void DrawGameplay();
void DrawEnding();

const int screenWidth = 1920;
const int screenHeight = 1200;

// Main entry point
int main(void)
{
    // Initialization

    InitWindow(screenWidth, screenHeight, "Tiffany's Game");

    GameScreen currentScreen = LOGO;

    int framesCounter = 0;

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        switch (currentScreen)
        {
            case LOGO: UpdateLogo(framesCounter, currentScreen); break;
            case TITLE: UpdateTitle(currentScreen); break;
            case GAMEPLAY: UpdateGameplay(currentScreen); break;
            case ENDING: UpdateEnding(currentScreen); break;
            default: break;
        }

        // Draw
        BeginDrawing();
        ClearBackground(SKYBLUE);

        switch(currentScreen)
        {
            case LOGO: DrawLogo(); break;
            case TITLE: DrawTitle(); break;
            case GAMEPLAY: DrawGameplay(); break;
            case ENDING: DrawEnding(); break;
            default: break;
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}

void UpdateLogo(int &framesCounter, GameScreen &currentScreen)
{
    framesCounter++;
    if (framesCounter > 120) // Wait for 2 seconds
    {
        currentScreen = TITLE;
    }
}

void UpdateTitle(GameScreen &currentScreen)
{
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        currentScreen = GAMEPLAY;
    }    
}

void UpdateGameplay(GameScreen &currentScreen)
{
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        currentScreen = ENDING;
    }
}

void UpdateEnding(GameScreen &currentScreen)
{
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        currentScreen = TITLE;
    }
}

void DrawLogo()
{
    DrawText("LOGO SCREEN", 20, 20, 40, SKYBLUE);
    DrawText("WAIT for 2 seconds...", 290, 220, 40, BLACK);
}

void DrawTitle()
{
    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
    DrawText("TITLE SCREEN", 20, 20, 40, BLACK);
    DrawText("Press ENTER or TAP to jump to GAMEPLAY SCREEN", 120, 220, 40, BLACK);
}

void DrawGameplay()
{
    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
    DrawText("GAMEPLAY SCREEN", 20, 20, 40, BLACK);
    DrawText("Press ENTER or TAP to jump to ENDING SCREEN", 130, 220, 40, BLACK);
}

void DrawEnding()
{
    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
    DrawText("ENDING SCREEN", 20, 20, 40, BLACK);
    DrawText("Press ENTER or TAP to jump to TITLE SCREEN", 120, 220, 40, BLACK);
}