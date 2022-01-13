#ifndef MULTIBACKGROUND_H
#define MULTIBACKGROUND_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <random>

class MultiBackground : public sf::Drawable
{
public:
    MultiBackground();
    void Update(int,int);
    virtual void draw(sf::RenderTarget&,sf::RenderStates) const;
private:
    sf::Texture backTexture;
    std::vector<sf::Sprite> backSprite;
    sf::Texture MeteorTex;
    std::vector<sf::Sprite> MeteorSprite;
    std::default_random_engine generator;
    sf::Vector2i pos;
};

#endif // MULTIBACKGROUND_H
