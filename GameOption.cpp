#include "GameOption.h"

GameOption::GameOption(Curseur *curse)
{
    corse = curse;
    std::ifstream saver("ressources/GameData/opt.abe");
    saver >>ESOSelected>>DOSelected>>VSOSelected;
    saver.close();
    load();
    tempoMpValues = new MpValues();
    tempoMpValues->VSO = VSOSelected;
    tempoMpValues->ESO = ESOSelected;
}
GameOption::~GameOption()
{
    corse = 0;
    tempoMpValues = 0;
}
void GameOption::load()
{
    font.loadFromFile("ressources/font/NIAGENG.ttf");
    if(!fondTexture.loadFromFile("ressources/BackGrounds/Andromeda1.jpg"))
        exit(1);
    fondSprite.setTexture(fondTexture);
    for(int i=0;i<3;i++)
    {
        options[i].setString(strOptions[i]);
        if(i != 0)
            options[i].setPosition(100,(100*i+70));
        else
            options[i].setPosition(100,60);
        options[i].setColor(sf::Color::Green);
        options[i].setCharacterSize(80);
        options[i].setFont(font);
    }
    for(int i=3;i<5;i++)
    {
        options[i].setString(strOptions[i]);
        if(i!=3)
            options[i].setPosition(330,(100*i)+70);
        else
            options[i].setPosition(300,(100*i)+70);
        options[i].setColor(sf::Color::Green);
        options[i].setCharacterSize(80);
        options[i].setFont(font);
        options[i].setStyle(sf::Text::Italic);
    }
    for(int i=0;i<5;i++)
    {
        volumeSonoreOptions[i].setSize(sf::Vector2f(15,15*i+10));
        volumeSonoreOptions[i].setOutlineColor(sf::Color::Yellow);
        volumeSonoreOptions[i].setOutlineThickness(1);
        volumeSonoreOptions[i].setFillColor(sf::Color::Transparent);
        if(i == 0)
            volumeSonoreOptions[i].setPosition(600,170+(15*4-volumeSonoreOptions[i].getSize().y));
        if(i != 0)
            volumeSonoreOptions[i].setPosition(i*20+600,170+(15*4-volumeSonoreOptions[i].getSize().y));
    }
    optSelected[0].setCharacterSize(80);
    optSelected[0].setColor(sf::Color::Green);
    optSelected[0].setFont(font);
    optSelected[0].setString(effetSonoreOptions[ESOSelected]);
    optSelected[0].setPosition(600,70);
    optSelected[1].setCharacterSize(80);
    optSelected[1].setColor(sf::Color::Green);
    optSelected[1].setFont(font);
    optSelected[1].setString(difficultOptions[DOSelected]);
    optSelected[1].setPosition(600,270);
    int temp = (options[selected].getPosition().y)+(options[selected].getCharacterSize()/2);
    corse->setPos(280.0f,(float)temp-15);
    corse->update();
}
void GameOption::Render(sf::RenderWindow *app)
{
    app->draw(fondSprite);
    for(int i=0;i<5;i++)
    {
        app->draw(options[i]);
    }
    for(int i=0;i<2;i++)
    {
        app->draw(optSelected[i]);
    }
    for(int i=0;i<5;i++)
    {
        app->draw(volumeSonoreOptions[i]);
    }
    app->draw(*corse);
}
void GameOption::update(Gameuse *jeux)
{
    cursorGear();
    corse->update();
    //Mise a jour des couleurs des textes
    //Mise a jours des valeurs des options
    optSelected[0].setString(effetSonoreOptions[ESOSelected]);
    optSelected[1].setString(difficultOptions[DOSelected]);
    for(int i=0;i<VSOSelected;i++)
    {
        volumeSonoreOptions[i].setFillColor(sf::Color::Green);
    }
    if(ESOSelected == 1)//On met le volume a zero si les effets sonores sont desactives
        VSOSelected = 0;
    for(int i=VSOSelected;i<5;i++)
    {
        volumeSonoreOptions[i].setFillColor(sf::Color::Transparent);
    }
}
void GameOption::optModifier(sf::Event event)//Partie pour gerer la modification des options
{
    if(event.type == sf::Event::KeyPressed)
    {
        if(event.key.code == sf::Keyboard::Left)
        {
            if(selected == 0)
            {
                ESOSelected--;
                if(ESOSelected < 0)
                    ESOSelected = 1;
            }
            else if(selected == 2)
            {
                DOSelected--;
                if(DOSelected < 0)
                    DOSelected = 2;
            }
            else if(selected == 1 && ESOSelected == 0)
            {
                VSOSelected--;
                if(VSOSelected < 0)
                    VSOSelected = 0;
            }
        }
        else if(event.key.code == sf::Keyboard::Right)
        {
            if(selected == 0)
            {
                ESOSelected++;
                if(ESOSelected > 1)
                    ESOSelected = 0;
            }
            else if(selected == 2)
            {
                DOSelected++;
                if(DOSelected > 2)
                    DOSelected = 0;
            }
            else if(selected == 1 && ESOSelected == 0)
            {
                VSOSelected++;
                if(VSOSelected > 5)
                    VSOSelected = 5;
            }
        }
    }
}
void GameOption::defaut()
{
    ESOSelected = 0;
    DOSelected = 1;
    VSOSelected = 3;
}
void GameOption::optSaver()
{
    std::ofstream saver("ressources/GameData/opt.abe");
    saver <<ESOSelected<<" "<<DOSelected<<" "<<VSOSelected;
    tempoMpValues->ESO = ESOSelected;
    tempoMpValues->VSO = VSOSelected*20;
    saver.close();
}
void GameOption::EventManage(Gameuse *jeux,sf::Event event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Up:
                --selected;
                if(selected < 0)
                    selected = 4;
            break;
            case sf::Keyboard::Down:
                ++selected;
                if(selected > 4)
                    selected = 0;
            break;
            case sf::Keyboard::Return:
                if(selected == 4){
                    selected = 0;
                    optSaver();
                    jeux->setState(MAINMENUE);
                }
                else if(selected == 3){
                    defaut();
                }
            break;
        }
    }
    optModifier(event);
}
void GameOption::cursorGear()
{
    int tempo = (options[selected].getPosition().y)+(options[selected].getCharacterSize()/2);
    int posX = 0;
    if(selected < 3)
        posX = 75;
    else
        posX = 280;
    corse->setPos(posX,(float)tempo-15);
}
