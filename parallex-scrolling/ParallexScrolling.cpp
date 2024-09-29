#include "raylib/raylib.h"

typedef enum GameState { LOGO = 0, MENUSCREEN, GAMESCREEN } GameState;

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "Parallex Scrolling");
    
    const char* loadingText = "Loading...";
    const char* menuText = "Press SPACE to play!";
    const char* returnText = "Press BACKSPACE to return to the menu!";
    
    Texture2D background = LoadTexture("resources/city_background.png");
    Texture2D midground = LoadTexture("resources/city_midground.png");
    Texture2D foreground = LoadTexture("resources/city_foreground.png");
    
    float scrollingBack = 0.0f;
    float scrollingMid = 0.0f;
    float scrollingFore = 0.0f;
    
    //char debugText[255];
    GameState currentScreen = LOGO;
    
    int framesCounter = 0;
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        // Update 
        switch(currentScreen)
        {
            case LOGO:
            {
                framesCounter++;
                
                if (framesCounter > 120)
                {
                    currentScreen = MENUSCREEN;
                }
            } break;
            
            case MENUSCREEN:
            {
                if (IsKeyPressed(KEY_SPACE))
                {
                    currentScreen = GAMESCREEN;
                }    
            } break;
            
            case GAMESCREEN:
            {
                scrollingBack -= 0.1f;
                scrollingMid -= 0.5f;
                scrollingFore -= 2.0f;
                
                if (scrollingBack <= -background.width)
                {
                  scrollingBack = 0;  
                }
                if (scrollingMid <= -midground.width)
                {
                    scrollingMid = 0;
                }
                if (scrollingFore <= -foreground.width)
                {
                    scrollingFore = 0;
                }
                
                if (IsKeyPressed(KEY_BACKSPACE))
                {
                    currentScreen = MENUSCREEN;
                }                   
            } break; 
        }
        
        
        //sprintf(debugText, "Scrollingfore: %i", scrollingFore);
        
        
        // Draw
        BeginDrawing();
        
            ClearBackground(SKYBLUE);
            
            switch(currentScreen)
            {
                case LOGO:
                {
                    DrawText(loadingText, screenWidth / 2 - 80, screenHeight / 2, 30, BLUE);
                } break;
                
                case MENUSCREEN:
                {
                    DrawRectangle(0, 0, screenWidth, screenHeight, PURPLE);
                    DrawText(menuText, screenWidth / 2 - 170, screenHeight / 2, 30, MAROON);
                } break;
                
                case GAMESCREEN:
                {
                    DrawTextureEx(background, (Vector2) { scrollingBack, 0 }, 0.0f, 2.0f, WHITE);
                    DrawTextureEx(background, (Vector2) {background.width * 2 + scrollingBack, 0 }, 0.0f, 2.0f, WHITE);
                    
                    DrawTextureEx(midground, (Vector2) { scrollingMid, 20 }, 0.0f, 2.0f, WHITE);
                    DrawTextureEx(midground, (Vector2) { midground.width * 2 + scrollingMid, 20 }, 0.0f, 2.0f, WHITE );
                    
                    DrawTextureEx(foreground, (Vector2) { scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
                    DrawTextureEx(foreground, (Vector2) { foreground.width + scrollingFore, 70 }, 0.0f, 2.0f, WHITE);
                    
                    //DrawRectangle(0, 0, screenWidth, screenHeight, YELLOW);
                    
                    //DrawText(debugText, 10, 10, 32, WHITE);
                    
                    DrawText(returnText, screenWidth / 2 - 330, 20, 30, ORANGE);
                } break;
                
                default: break;
            }    
            
        EndDrawing();
    }
    
    // De-initialization
    UnloadTexture(background);
    UnloadTexture(midground);
    UnloadTexture(foreground);
    
    CloseWindow();
    
    return 0;
}