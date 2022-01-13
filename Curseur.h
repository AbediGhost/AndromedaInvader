#ifndef CURSEUR_H
#define CURSEUR_H

#include <SFML/Graphics.hpp>
#include <string>

class Curseur : public sf::Drawable
{
public:
    Curseur();
    void update();
    void setPos(float x,float y);
private:
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
    sf::Sprite mainSprite;
    sf::Texture mainTexture;
    sf::Vector2f position;
};

#endif // CURSEUR_H
