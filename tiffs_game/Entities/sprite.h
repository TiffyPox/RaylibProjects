#ifndef SPRITE_H
#define SPRITE_H

#include <raylib/raylib.h>

class Sprite
{
public:
    Texture2D texture;
    int x, y, width, height;
    int scale;

    // Constructor
    Sprite(Texture2D texture, int x, int y, int width, int height, int scale = 1) 
        : texture(texture), x(x), y(y), width(width), height(height), scale(scale) {}

        int GetRenderWidth() const { return width * scale; }
        int GetRenderHeight() const { return height * scale; } 

        void Draw(Vector2 position, Color color) const 
        {
            // Using raylib DrawTextureRec
            Rectangle sourceRec = { static_cast<float>(x), static_cast<float>(y), static_cast<float>(width), static_cast<float>(height) };
            Vector2 origin = { static_cast<float>(width) / 2.0f, static_cast<float>(height) / 2.0f };
            DrawTexturePro(texture, sourceRec, { position.x, position.y, static_cast<float>(GetRenderWidth()), static_cast<float>(GetRenderHeight())}, origin, 0.0f, color);   
        }
};

#endif // SPRITE_H