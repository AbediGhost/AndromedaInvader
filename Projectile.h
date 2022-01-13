#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Vaisseau.h"
#include <iostream>
#include <list>

class Projectile : public sf::Drawable,public sf::Transformable
{
public:
    Projectile(unsigned short,unsigned int,sf::Vector2f,short);
    ~Projectile();
    void Update();
    void draw(sf::RenderTarget&,sf::RenderStates) const;
    bool getDestroy();
private:
    //Fonctions
    void setType();
    //Attributs
    sf::Texture laserTexture;
    sf::Sprite laserSprite;
    unsigned short mtype;
    unsigned int speed = 10;
    sf::Vector2f laserDirection;
    float pi = 3.14159265358979;
    bool destroy = false;
    sf::Clock destroyClock;
};

#endif // PROJECTILE_H
