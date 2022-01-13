#include "MainMenu.h"

MainMenu::MainMenu(Curseur *curs)
{
    indique = 0;
    corse = curs;
    load();
}
MainMenu::~MainMenu()
{
    corse = 0;
}
void MainMenu::load()
{
    if(!fondTexture.loadFromFile("ressources/BackGrounds/Andromeda1.jpg"))
        exit(1);
    fondSprite.setTexture(fondTexture);
    specialColor.r = 200;
    specialColor.g = 17;
    specialColor.b = 104;
    specialColor.a = 255;
    posInit[0] = 327;
    posInit[1] = 320;
    posInit[2] = 338;
    posInit[3] = 335;
    Jacques.loadFromFile("ressources/font/NIAGENG.ttf");
    for(int i=0;i<4;i++)
    {
        submenu[i].setString(submenuComp[i]);
        submenu[i].setColor(sf::Color::Cyan);
        submenu[i].setFont(Jacques);
        submenu[i].setPosition(posInit[i],150+100*i);
        submenu[i].setCharacterSize(60);
        indicable.push_back(submenu[i]);
    }
    submenu[4].setString(submenuComp[4]);
    submenu[4].setColor(sf::Color::Yellow);
    submenu[4].setFont(Jacques);
    submenu[4].setPosition(506,555);
    submenu[4].setCharacterSize(40);
    presentation.setString("***Andromeda_Invaders***");
    presentation.setColor(specialColor);
    presentation.setScale(1.1,2);
    presentation.setCharacterSize(50);
    presentation.setPosition(30,10);
    presentation.setFont(Jacques);
    presentation.scale(2,1);
    int temp = (indicable[indique].getPosition().y)+(indicable[indique].getCharacterSize()/2);
    corse->setPos(280.0f,(float)temp-15);
    corse->update();
}

void MainMenu::Render(sf::RenderWindow *app)
{
    cursorGear();
    app->draw(fondSprite);
    app->draw(presentation);
    app->draw(*corse);
    for(int i=0;i<5;i++)
        app->draw(submenu[i]);
}

void MainMenu::cursorGear()
{
    int tempo = (indicable[indique].getPosition().y)+(indicable[indique].getCharacterSize()/2);
    corse->setPos(280.0f,(float)tempo-15);
}
int MainMenu::getCursPos()
{
    return indique;
}
void MainMenu::update(Gameuse *jeux)
{
    cursorGear();
    corse->update();
}
void MainMenu::EventManage(Gameuse *jeux,sf::Event event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Up :
                indique--;
                if(indique <0)
                    indique=3;
            break;
            case sf::Keyboard::Down:
                indique++;
                if(indique > 3)
                    indique = 0;
            break;
            case sf::Keyboard::Return:
                switch(indique)
                {
                    case 0:
                        jeux->setState(PREPARING);
                    break;
                    case 1:
                        jeux->setState(MULTIPREPARE);
                    break;
                    case 2:
                        jeux->setState(OPTIONING);
                    break;
                    case 3:
                        jeux->setState(EXITING);
                }
                break;
        }
    }
}
