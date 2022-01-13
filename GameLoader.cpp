#include "GameLoader.h"

using namespace sf;

GameLoader::GameLoader()
{
    initialize();
}

void GameLoader::initialize()
{
    Sfml_Annonce.setString("SFML Library");
    Sfml_Annonce.setFont(Vtks);
    Sfml_Annonce.setColor(Color::Green);
    Sfml_Annonce.setPosition(70,70);
    Sfml_Annonce.scale(1.8,2);
    Sfml_Annonce.setCharacterSize(55);
    Sfml_Author.setString("(C) Laurent Gomila");
    Sfml_Author.setFont(Vtks);
    Sfml_Author.setColor(Color::Green);
    Sfml_Author.setPosition(210,200);
    Sfml_Author.setCharacterSize(35);
    Author_Annonce.setString("CopyRight(C) 2018 ADRIEN FAYE");
    Author_Annonce.setFont(Vtks);
    Author_Annonce.setColor(Color::White);
    Author_Annonce.setScale(1.4,2);
    Author_Annonce.setPosition(80,500);
    Vtks.loadFromFile("ressources/font/ALGER.ttf");
}
void GameLoader::Render(sf::RenderWindow *app)
{
    app->draw(Author_Annonce);
    app->draw(Sfml_Author);
    app->draw(Sfml_Annonce);
}
void GameLoader::update(Gameuse *jeux)
{
}
void GameLoader::EventManage(Gameuse *jeux,sf::Event event)
{
    if(event.type == sf::Event::KeyPressed)
        jeux->setState(PRESENTATION);
}
