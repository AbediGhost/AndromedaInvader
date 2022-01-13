#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Usefull_Things.h"
#include "Includer.h"
#include "Curseur.h"

class MainMenu
{
public:
    MainMenu(Curseur*);
    ~MainMenu();
    void Render(sf::RenderWindow *app);
    void update(Gameuse*);
    void EventManage(Gameuse*,sf::Event);
    int getCursPos();
private:
    ///Declarations des principaux attributs
    sf::Text submenu[5];
    sf::Texture fondTexture;
    sf::Sprite fondSprite;
    sf::Font Jacques;
    sf::Text presentation;
    sf::Color specialColor;
    std::vector<sf::Text> indicable;
    Curseur *corse;
    int indique ;
    const std::string submenuComp[5] = {"Campagne","Multijoueur","Options","Quitter","COPYRIGHT 2018 ADRIEN FAYE"};
    ///Declaration des fonctions privees
    void load();
    void cursorGear();
    int posInit[4];
};

#endif // MAINMENU_H
