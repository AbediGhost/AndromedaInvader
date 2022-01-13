#include "GamePrepare.h"

GamePrepare::GamePrepare()
{
    load();
}

void GamePrepare::load()
{
    if(!fondTexture.loadFromFile("ressources/BackGrounds/Andromeda1.jpg"))
        int i=0;
    if(!font.loadFromFile("ressources/font/ALGER.ttf"))
        exit(1);
    retour.setCharacterSize(60);
    retour.setColor(sf::Color::Yellow);
    retour.setFont(font);
    retour.setString("Retour");
    retour.setPosition(290,500);
    warning.setCharacterSize(35);
    warning.setColor(sf::Color::Red);
    warning.setFillColor(sf::Color::Red);
    warning.setFont(font);
    warning.setString("Cette fonctionnalité sera disponible à\n             la prochaine mise à jour !");
    warning.setPosition(40,250);
    fondSprite.setTexture(fondTexture);
}
void GamePrepare::Render(sf::RenderWindow *app)
{
    app->draw(fondSprite);
    app->draw(retour);
    app->draw(warning);
}
void GamePrepare::update(Gameuse *jeux)
{
}
void GamePrepare::EventManage(Gameuse *jeux,sf::Event event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Return:
                jeux->setState(MAINMENUE);
                break;
        }
    }
}
