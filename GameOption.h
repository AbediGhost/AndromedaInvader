#ifndef GAMEOPTION_H
#define GAMEOPTION_H

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include "Usefull_Things.h"
#include "Includer.h"
#include "Curseur.h"

class GameOption
{
public:
    GameOption(Curseur*);
    ~GameOption();
    void Render(sf::RenderWindow*);
    void update(Gameuse*);
    void EventManage(Gameuse*,sf::Event);
    MpValues *tempoMpValues;
private:
    //Fonctions privees
    void load();
    void optModifier(sf::Event);
    void defaut();
    void optSaver();
    void cursorGear();
    //Attributs prives
    sf::Sprite fondSprite;
    sf::Texture fondTexture;
    sf::Font font;
    sf::Text options[5];
    sf::Text optSelected[2];
    std::string strOptions[5] = {"Effets sonores :","Volume :","Difficulte :","Par defaut","Retour"};
    std::string effetSonoreOptions[2] = {"Oui","Non"};
    std::string difficultOptions[3] = {"Facile","Moyen","Difficile"};
    sf::RectangleShape volumeSonoreOptions[5];
    Curseur *corse;
    int selected = 0;
    int ESOSelected = 0;
    int DOSelected = 0;
    int VSOSelected = 0;
};

#endif // GAMEOPTION_H
