#ifndef GAMEPRESENTATION_H
#define GAMEPRESENTATION_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <fstream>
#include "Usefull_Things.h"
#include "Includer.h"
#include "AlienCraft.h"

class GamePresent
{
public:
    GamePresent();
    void Render(sf::RenderWindow *subApp);
    void Update(Gameuse*);
    void EventManage(Gameuse*,sf::Event);
private:
    ///Declaration des membres prives
    sf::Text *presentation;
    sf::Text *subpresentation;
    sf::Font *Fpresentation;
    sf::Font *Jacques;
    std::ifstream *presentationLoader;
    std::string *IntroTxt;
    std::string *tempo;
    ///Declaration des fonctions privees
    void load();
    AlienCraft *starski;
    AlienCraft *hutch;
};

#endif // GAMEPRESENTATION_H
