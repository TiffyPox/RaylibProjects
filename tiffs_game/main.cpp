#include <raylib/raylib.h>
#include "game_screen.h"
#include <iostream>

void UpdateMenu(GameScreen &currentScreen);
void UpdatePlaying(GameScreen &currentScreen);
void UpdatePaused(GameScreen &currentScreen);
void UpdateGameOver(GameScreen &currentScreen);

void DrawMenu();
void DrawPlaying();
void DrawPaused();
void DrawGameOver();

const int screenWidth = 1920;
const int screenHeight = 1200;

// Main entry point
int main(void)
{
    // Initialization

    InitWindow(screenWidth, screenHeight, "Tiffany's Game");

    GameScreen currentScreen = MENU;

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        switch (currentScreen)
        {
            case MENU: UpdateMenu(currentScreen); break;
            case PLAYING: UpdatePlaying(currentScreen); break;
            case PAUSED: UpdatePaused(currentScreen); break;
            case GAMEOVER: UpdateGameOver(currentScreen); break;
            default: break;
        }

        // Draw
        BeginDrawing();
        ClearBackground(SKYBLUE);

        switch(currentScreen)
        {
            case MENU: DrawMenu(); break;
            case PLAYING: DrawPlaying(); break;
            case PAUSED: DrawPaused(); break;
            case GAMEOVER: DrawGameOver(); break;
            default: break;
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}

void UpdateMenu(GameScreen &currentScreen)
{
    if (IsKeyPressed(KEY_SPACE))
    {
        currentScreen = PLAYING;
    }
}

void UpdatePlaying(GameScreen &currentScreen)
{
    if (IsKeyPressed(KEY_SPACE) || IsGestureDetected(GESTURE_TAP))
    {
        currentScreen = PAUSED;
    }    
}

void UpdatePaused(GameScreen &currentScreen)
{
    if (IsKeyPressed(KEY_SPACE))
    {
        printf("Transitioning to GAMEOVER screen\n");  // Debugging line
        currentScreen = GAMEOVER;
    }
}

void UpdateGameOver(GameScreen &currentScreen)
{
    if (IsKeyPressed(KEY_SPACE) || IsGestureDetected(GESTURE_TAP))
    {
        currentScreen = MENU;
    }
}

void DrawMenu()
{
    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
    DrawText("MENU SCREEN", 20, 20, 40, BLACK);
    DrawText("Press SPACE to play! Press ESCAPE anytime to close the game.", 290, 220, 40, BLACK);
}

void DrawPlaying()
{
    DrawRectangle(0, 0, screenWidth, screenHeight, PINK);
    DrawText("GAME SCREEN", 20, 20, 40, BLACK);
    DrawText("Press SPACE or TAP to pause the game!", 120, 220, 40, BLACK);
}

void DrawPaused()
{
    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
    DrawText("PAUSE SCREEN", 20, 20, 40, BLACK);
    DrawText("Press SPACE to end the game", 130, 220, 40, BLACK);
}

void DrawGameOver()
{
    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
    DrawText("GAME OVER SCREEN", 20, 20, 40, BLACK);
    DrawText("Press SPACE or TAP to go back to the MENU", 120, 220, 40, BLACK);
}