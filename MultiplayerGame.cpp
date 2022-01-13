#include "MultiplayerGame.h"

MultiplayerGame::MultiplayerGame()
{
    gameView.setSize(800,600);
    backGround = new MultiBackground();
}
MultiplayerGame::~MultiplayerGame()
{
    playeur = 0;
}
void MultiplayerGame::setPlayer(PlayerCraft *jouyeur)
{
    playeur = jouyeur;
    playeur->setPlaying(true);
    gameView.setCenter(playeur->getPosition());
    gameView.zoom(1.5);
}
void MultiplayerGame::Update()
{
    playeur->update();
    backGround->Update((int)playeur->getPosition().x,(int)playeur->getPosition().y);
    gameView.setCenter(playeur->getPosition());
    gameView.setRotation(playeur->getRotation());
}
void MultiplayerGame::Run(sf::RenderWindow *app,Gameuse *jeux)
{
    app->clear();
    while(app->isOpen())
    {
        while(playeur->getHP() > 0)
        {
            if(fpsClock.getElapsedTime().asMilliseconds() >= 1000)
            {
                fpsClock.restart();
                std::stringstream outputer;
                outputer << "title "<<fps<<" fps"<<" ; "<<playeur->getCurrentSpeed()<<" pxl/s";
                std::string loat = outputer.str();
                system(loat.c_str());
                fps = 0;
            }
            else
            {
                fps++;
            }
            sf::Event event;
            while(app->pollEvent(event))
            {
                EventManage(jeux,event);
            }
            Update();
            render(app);
            app->setView(gameView);
            app->display();
        }
    }
}
void MultiplayerGame::render(sf::RenderWindow *app)
{
    app->clear();
    app->draw(*backGround);
    for(int i=0;i<playeur->projectilChild.size();i++)
    {
        if(playeur->projectilChild[i] != 0)
            app->draw(*playeur->projectilChild[i]);
    }
    app->draw(*playeur);
}
void MultiplayerGame::EventManage(Gameuse *jeux,sf::Event event)
{
    if(event.type == sf::Event::KeyPressed)
    {
        switch(event.key.code)
        {
        }
    }
    else if(event.type == sf::Event::Closed)
    {
        jeux->setState(EXITING);
    }
    playeur->EventManage(jeux,event);
    playeur->handleInput();
}
