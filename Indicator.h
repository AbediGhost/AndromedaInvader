#ifndef INDICATOR_H
#define INDICATOR_H

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>

///DEPRECATED USE CURSEUR INSTEAD
class Indicator
{
public:
    Indicator(int x1,int x2,int x3,int x4,int x5,int x6,int y1,int y2,int y3,int y4,int y5,int y6);
    void KeyboardManager();
    sf::Vertex triOne[3];
    sf::Vertex triTwo[3];
};

#endif // INDICATOR_H
