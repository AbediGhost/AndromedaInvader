#include "Game.h"

Game::Game()
{
    ///Allocations
    srand(time(0));
    cursor = new Curseur();
    app = new sf::RenderWindow(sf::VideoMode(800,600,32),"Andromeda Invaders",sf::Style::Close);
    state = LOADER;
    loader = new GameLoader();
    MultiGame = new MultiplayerGame();
    option = new GameOption(cursor);
    MultiOpt = option->tempoMpValues;
    ///Preparatifs
    ///On ajuste les attributs de l'introduction
    ///Fin de l'ajustement
}
void Game::MemoryFree1()
{
    delete cursor;
    delete MultiGame;
    delete MultiOpt;
    MultiOpt = 0;
    MultiGame = 0;
    cursor = 0;
}

void Game::Run()
{
    while(app->isOpen())
    {
        if(fpsClock.getElapsedTime().asMilliseconds() >= 1000)
        {
                fpsClock.restart();
                std::stringstream outputer;
                outputer << "title "<<fps<<" fps";
                std::string loat = outputer.str();
                system(loat.c_str());
                fps = 0;
        }
        else
        {
            fps++;
        }
        EventManage();
        update();
        render();
        app->display();
    }
}
void Game::update()
{
    switch(state)
    {
        case LOADER:
            loader->update(this);
        break;
        case PRESENTATION:
            presentor->Update(this);
        break;
        case MAINMENUE:
            Menue->update(this);
        break;
        case OPTIONING:
            option->update(this);
        break;
        case PREPARING:
            preparator->update(this);
        break;
        case MULTIPREPARE:
            MultPrep->update(this);
        break;
        case MULTIPLAYER:
            MultiGame->Run(app,this);
        break;
        case EXITING:
            MemoryFree1();
            app->close();
        break;
    }
}
void Game::render()
{
    app->clear();
    switch(state)
    {
        case LOADER:
            loader->Render(app);
            break;
        case PRESENTATION:
            presentor->Render(app);
            break;
        case MAINMENUE:
            Menue->Render(app);
            break;
        case PREPARING:
            preparator->Render(app);
            break;
        case OPTIONING:
            option->Render(app);
            break;
        case MULTIPREPARE:
            MultPrep->render(app);
        break;
    }
}
void Game::EventManage()
{
    sf::Event event;
    while(app->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
                app->close();
        switch(state)
        {
            case LOADER:
                loader->EventManage(this,event);
            break;
            case PRESENTATION:
                presentor->EventManage(this,event);
            break;
            case MAINMENUE:
                Menue->EventManage(this,event);
            break;
            case OPTIONING:
                option->EventManage(this,event);
            break;
            case PREPARING:
                preparator->EventManage(this,event);
            break;
            case MULTIPREPARE:
                MultPrep->EventManage(this,event,MultiGame);
            break;
            case EXITING:
                MemoryFree1();
            break;
        }
    }
}
void Game::setState(GameState etat)
{
    switch(etat)
    {
        case PRESENTATION:
            delete loader;
            loader = 0;
            state = PRESENTATION;
            presentor = new GamePresent();
        break;
        case MAINMENUE:
            if(state == PRESENTATION)
            {
                delete presentor;
                presentor = 0;
                state = MAINMENUE;
                Menue = new MainMenu(cursor);
            }
            else if(state == OPTIONING)
            {
                Menue = new MainMenu(cursor);
                delete option;
                option = 0;
                state = MAINMENUE;
            }
            else if(state == MULTIPREPARE)
            {
                Menue = new MainMenu(cursor);
                delete MultPrep;
                MultPrep = 0;
                state = MAINMENUE;
            }
            else if(state == MULTIPLAYER)
            {
                Menue = new MainMenu(cursor);
                delete MultiGame;
                MultiGame = 0;
                state = MAINMENUE;
            }
            else if(state == PREPARING)
            {
                delete preparator;
                preparator = 0;
                Menue = new MainMenu(cursor);
                state = MAINMENUE;
            }
        break;
        case OPTIONING:
            if(state == MAINMENUE)
            {
                delete Menue;
                Menue = 0;
                state = OPTIONING;
                if(option == 0)
                    option = new GameOption(cursor);
            }
        break;
        case MULTIPREPARE:
            if(state == MAINMENUE)
            {
                delete Menue;
                Menue = 0;
                state = MULTIPREPARE;
                MultPrep = new MultiPrepare(MultiOpt);
            }
            else if(state == MULTIPLAYER)
            {
                if(MultiGame != 0)
                {
                    delete MultiGame;
                    MultiGame = 0;
                }
                state = MULTIPREPARE;
                MultPrep = new MultiPrepare(MultiOpt);
            }
        break;
        case MULTIPLAYER:
            delete MultPrep;
            MultPrep = 0;
            state = MULTIPLAYER;
            if(MultiGame == 0)
                MultiGame = new MultiplayerGame();
        break;
        case PREPARING:
            delete Menue;
            Menue = 0;
            state = PREPARING;
            preparator = new GamePrepare();
        break;
        case EXITING:
            if(Menue != 0)
            {
                delete Menue;
                Menue = 0;
            }
            state = EXITING;
            MemoryFree1();
            app->close();
            exit(0);
        break;
    }
}
///Some very unusable bullshit but i use it
void Game::veryUnusable()
{
}
///EndUnusable
