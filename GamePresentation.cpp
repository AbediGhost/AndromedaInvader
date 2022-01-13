#include "GamePresentation.h"

GamePresent::GamePresent()
{
    starski = new AlienCraft();
    presentation = new sf::Text;
    subpresentation = new sf::Text;
    Fpresentation = new sf::Font;
    presentationLoader = new std::ifstream;
    IntroTxt = new std::string;
    Jacques = new sf::Font;
    tempo = new std::string;
    hutch = new AlienCraft();
    load();
}

void GamePresent::load()
{
    presentationLoader->open("ressources/Text/Intro.txt");
    IntroTxt->clear();
    tempo->clear();
    int interest=0;
    while(*presentationLoader >> *tempo)
    {
        *IntroTxt+=*tempo;
        *IntroTxt += " ";
        tempo->clear();
        if(interest == 3)
        {
            interest=0;
            IntroTxt->append("\n");
        }
        interest++;
    }
    Fpresentation->loadFromFile("ressources/font/VINERITC.ttf");
    Jacques->loadFromFile("ressources/font/NIAGENG.ttf");
    presentation->setString("***Andromeda_Invaders***");
    presentation->setColor(sf::Color::Green);
    presentation->setScale(1.1,2);
    presentation->setCharacterSize(50);
    presentation->setFont(*Fpresentation);
    subpresentation->setString(*IntroTxt);
    subpresentation->setCharacterSize(50);
    subpresentation->setColor(sf::Color::Cyan);
    subpresentation->setFont(*Fpresentation);
    subpresentation->setPosition(60,600);
    presentation->setPosition(20,2200);
    starski->setPosition(150,2390);
    hutch->setPosition(650,2390);
}

void GamePresent::Render(sf::RenderWindow *subApp)
{
    subApp->draw(*subpresentation);
    subApp->draw(*presentation);
    subApp->draw(*starski);
    subApp->draw(*hutch);
}
void GamePresent::Update(Gameuse *jeux)
{
    presentation->move(0,-3);
    subpresentation->move(0,-3);
    starski->move(0.0f,-3.0f);
    hutch->move(0.0f,-3.0f);
    starski->Update();
    hutch->Update();
    if(starski->getPosition().y < -300)
        jeux->setState(MAINMENUE);
}
void GamePresent::EventManage(Gameuse *jeux,sf::Event event)
{
    if(event.type == sf::Event::KeyPressed)
        jeux->setState(MAINMENUE);
}
