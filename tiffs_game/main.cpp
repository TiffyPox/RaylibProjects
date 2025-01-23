#include <raylib/raylib.h>
#include "game_screen.h"

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

const char* menuText = "Press SPACE to play! Press ESCAPE anytime to close the game.";
const char* playingText = "Press SPACE or TAP anywhere to pause the game!";
const char* pausedText = "Press SPACE to end the game";
const char* gameOverText = "Press SPACE or TAP to go back to the MENU";

const int fontSize = 40;

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

// Update Functions
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

// Draw Functions
void DrawMenu()
{
    // Measure text to center it
    int menuTextSize = MeasureText(menuText, fontSize);

    DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
    DrawText("MENU SCREEN", 20, 20, fontSize, BLACK);
    DrawText(menuText, screenWidth / 2 - menuTextSize / 2, screenHeight / 2, fontSize, BLACK);
}

void DrawPlaying()
{
    int playingTextSize = MeasureText(playingText, fontSize);

    DrawRectangle(0, 0, screenWidth, screenHeight, PINK);
    DrawText("GAME SCREEN", 20, 20, fontSize, BLACK);
    DrawText(playingText, screenWidth / 2 - playingTextSize / 2, screenHeight / 2, fontSize, BLACK);
}

void DrawPaused()
{
    int pausedTextSize = MeasureText(pausedText, fontSize);

    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
    DrawText("PAUSE SCREEN", 20, 20, fontSize, BLACK);
    DrawText(pausedText, screenWidth / 2 - pausedTextSize / 2, screenHeight / 2, fontSize, BLACK);
}

void DrawGameOver()
{
    int gameOverTextSize = MeasureText(gameOverText, fontSize);

    DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
    DrawText("GAME OVER SCREEN", 20, 20, fontSize, BLACK);
    DrawText(gameOverText, screenWidth / 2 - gameOverTextSize / 2, screenHeight / 2, fontSize, BLACK);
}