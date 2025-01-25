#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <raylib/raylib.h>

class GameEntity
{
public:
    virtual ~GameEntity() = default;

    virtual int GetDrawOrder() const = 0;
    virtual void Update() = 0;
    virtual void Draw() const = 0;
};

#endif // GAME_ENTITY_H
