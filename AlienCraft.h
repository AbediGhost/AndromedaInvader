#ifndef ALIENCRAFT_H
#define ALIENCRAFT_H

#include "Vaisseau.h"
#include <fstream>
#include <iostream>

class AlienCraft : public Vaisseau
{
public:
    AlienCraft();
    void EventManage(GameState*,sf::Event);
    void Update();
    void AlienMove(float,float);
protected:
    virtual void unusable() const;
private:
    void setCraftTexture();
    void loadSpecs();
};

#endif // ALIENCRAFT_H
