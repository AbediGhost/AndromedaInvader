#ifndef GAMEPREPARE_H
#define GAMEPREPARE_H

#include <SFML/Graphics.hpp>
#include "Usefull_Things.h"
#include "Includer.h"

class GamePrepare
{
public:
    GamePrepare();
    void Render(sf::RenderWindow*);
    void update(Gameuse*);
    void EventManage(Gameuse*,sf::Event);
private:
    ///Declaration des attributs prives
    sf::Font font;
    sf::Sprite fondSprite;
    sf::Texture fondTexture;
    sf::Text retour;
    sf::Text warning;
    ///Declaration des focntions privees
    void load();
};

#endif // GAMEPREPARE_H
