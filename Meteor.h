#ifndef METEOR_H
#define METEOR_H

#include <SFML/Graphics.hpp>

class Meteor : public sf::Drawable,public sf::Transformable
{
public:
    Meteor();
    void Update(int,int);
private:
    sf::Texture MeteorTex;
    sf::Sprite MeteorSprite;
};

#endif // METEOR_H
