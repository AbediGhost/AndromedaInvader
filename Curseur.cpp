#include "Curseur.h"

Curseur::Curseur()
{
    if(!mainTexture.loadFromFile("ressources/sprite/cursor.png"))
        exit(1);
    mainSprite.setTexture(mainTexture);
    mainSprite.setRotation(90);
    mainSprite.scale(0.55,0.55);
}

void Curseur::update()
{
    mainSprite.setPosition(position);
}

void Curseur::draw(sf::RenderTarget& target,sf::RenderStates states) const//Rendering
{
    target.draw(mainSprite,states);
}

void Curseur::setPos(float x, float y)
{
    position.x = x;
    position.y = y;
}
