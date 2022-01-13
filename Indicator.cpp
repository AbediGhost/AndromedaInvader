#include "Indicator.h"

Indicator::Indicator(int x1,int x2,int x3,int x4,int x5,int x6,int y1,int y2,int y3,int y4,int y5,int y6)
{
    triOne[0] = sf::Vertex(sf::Vector2f(x1,y1),sf::Color::Magenta);
    triOne[1] = sf::Vertex(sf::Vector2f(x2,y2),sf::Color::Magenta);
    triOne[2] = sf::Vertex(sf::Vector2f(x3,y3),sf::Color::Magenta);
    triTwo[0] = sf::Vertex(sf::Vector2f(x4,y4),sf::Color::Magenta);
    triTwo[1] = sf::Vertex(sf::Vector2f(x5,y5),sf::Color::Magenta);
    triTwo[2] = sf::Vertex(sf::Vector2f(x6,y6),sf::Color::Magenta);
}

void Indicator::KeyboardManager()
{
}
