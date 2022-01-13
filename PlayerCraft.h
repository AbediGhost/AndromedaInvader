#ifndef PLAYERCRAFT_H
#define PLAYERCRAFT_H

#include "Vaisseau.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include "Projectile.h"
#include "Includer.h"

class PlayerCraft : public Vaisseau
{
public:
    std::string colorTab[4] = {"Blue","Green","Orange","Red"};
public:
    PlayerCraft();
    ~PlayerCraft();
    virtual void update();
    virtual void EventManage(Gameuse*,sf::Event);
    void switchTexture(int i=0);
    std::vector<Projectile*> projectilChild;
    virtual void unusable() const;
    void setHP(unsigned short);
    unsigned short getHP();
    float getCurrentSpeed();
    void copyCraft(PlayerCraft*);
    void handleInput();
    void setPlaying(bool);
    void setSoundFxParam(unsigned int,unsigned int);
private:
    void loadSpecs();
    void shoot();
    std::string defaultTexture = "playerShip4.png";
    std::string currentTexture;
    int currentIndex = 0;
    int colorIndex = 0;
    int typeIndex = 1;
    std::vector<sf::Texture> textureTable;
    std::string id;
    std::string color;
    unsigned short HealthPoint = 500;
    Projectile *craftLaser = 0;
    sf::Vector2f gatlinPos;
    sf::Clock shootCadencer;
    float currentSpeed;
    bool playing = false;
protected:
};

#endif // PLAYERCRAFT_H
