#ifndef VAISSEAU_H
#define VAISSEAU_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <cmath>
#include "Usefull_Things.h"
#include "Includer.h"

class Vaisseau : public sf::Transformable,public sf::Drawable//Classe abstraite
{
public:
    Vaisseau();
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
    virtual void EventManage(Gameuse*,sf::Event);
    virtual void render(sf::RenderWindow*);
    virtual void update();
    //Getters
    virtual short getVitesse();
    virtual short getCadence();
    virtual unsigned int getManiabilite();
    virtual std::string getName();
protected:
    //Attributs communs a tous les vaisseaux
    sf::Vector2f craftSpeed;
    sf::Sprite craftSprite;
    sf::Texture *craftTexture;
    sf::Texture speedEffectTexture;
    sf::Sprite speedEffectSprite;
    sf::SoundBuffer shootBuf;
    sf::Sound shootFX;
    unsigned int maniabilite;
    short cadenceDeTirs;
    short vitesse;
    std::string name;
    std::string baseTexture = "ressources/sprite/";
    virtual void unusable() const = 0;
};

#endif // VAISSEAU_H
