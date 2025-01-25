#include <raylib/raylib.h>
#include "screen.h"
#include "Entities/player.h"

void UpdateMenu(Screen &currentScreen);
void UpdatePlaying(Screen &currentScreen, Player &player);
void UpdatePaused(Screen &currentScreen);
void UpdateGameOver(Screen &currentScreen);

void DrawMenu();
void DrawPlaying(Player &player);
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

    Screen currentScreen = Screen::MENU;

    Player player({screenWidth / 2 - 25, screenHeight - 100});

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        switch (currentScreen)
        {
            case Screen::MENU: UpdateMenu(currentScreen); break;
            case Screen::PLAYING: UpdatePlaying(currentScreen, player); break;
            case Screen::PAUSED: UpdatePaused(currentScreen); break;
            case Screen::GAMEOVER: UpdateGameOver(currentScreen); break;
            default: break;
        }

        // Draw
        BeginDrawing();
        ClearBackground(SKYBLUE);

        switch(currentScreen)
        {
            case Screen::MENU: DrawMenu(); break;
            case Screen::PLAYING: DrawPlaying(player); break;
            case Screen::PAUSED: DrawPaused(); break;
            case Screen::GAMEOVER: DrawGameOver(); break;
            default: break;
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}

// Update Functions
void UpdateMenu(Screen &currentScreen)
{
    if (IsKeyPressed(KEY_SPACE))
    {
        currentScreen = Screen::PLAYING;
    }
}

void UpdatePlaying(Screen &currentScreen, Player &player)
{
    player.Update();   

    // if (IsKeyPressed(KEY_SPACE) || IsGestureDetected(GESTURE_TAP))
    // {
    //     currentScreen = Screen::PAUSED;
    // }    
}

void UpdatePaused(Screen &currentScreen)
{
    if (IsKeyPressed(KEY_SPACE))
    {
        currentScreen = Screen::GAMEOVER;
    }
}

void UpdateGameOver(Screen &currentScreen)
{
    if (IsKeyPressed(KEY_SPACE) || IsGestureDetected(GESTURE_TAP))
    {
        currentScreen = Screen::MENU;
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

void DrawPlaying(Player &player)
{
    int playingTextSize = MeasureText(playingText, fontSize);

    DrawRectangle(0, 0, screenWidth, screenHeight, PINK);
    DrawText("GAME SCREEN", 20, 20, fontSize, BLACK);
    //DrawText(playingText, screenWidth / 2 - playingTextSize / 2, screenHeight / 2, fontSize, BLACK);

    player.Draw();
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