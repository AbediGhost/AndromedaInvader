#ifndef GAMEUSE_H
#define GAMEUSE_H

#include "Usefull_Things.h"

class Gameuse
{
public:
    Gameuse();
    virtual void setState(GameState);
protected:
    virtual void veryUnusable() = 0;
};

#endif // GAMEUSE_H
