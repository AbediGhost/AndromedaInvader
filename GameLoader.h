#ifndef GAMELOADER_H_INCLUDED
#define GAMELOADER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include "Usefull_Things.h"
#include "Includer.h"

class GameLoader
{
public:
    GameLoader();
    void initialize();
    void Render(sf::RenderWindow *app);
    void check();
    void update(Gameuse*);
    void EventManage(Gameuse*,sf::Event);
private:
    sf::Text Sfml_Annonce;
    sf::Text Author_Annonce;
    sf::Text Sfml_Author;
    sf::Font Vtks;
    std::vector<sf::Text> Sia;
};

#endif // GAMELOADER_H_INCLUDED
