#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Gameuse.h"
#include "Usefull_Things.h"
#include "GamePresentation.h"
#include "GameLoader.h"
#include "MainMenu.h"
#include "GamePrepare.h"
#include "GameOption.h"
#include "MultiPrepare.h"
#include "MultiplayerGame.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include "Curseur.h"

class Game : public Gameuse
{
public:
    Game();
    void Run();
    virtual void setState(GameState);
private:
    ///On declare les fonctions privées
    void MemoryFree1();
    void update();
    void EventManage();
    void render();
    ///On declare les attributs  privés principaux
    GamePresent *presentor = 0;
    GameLoader *loader = 0;
    MainMenu *Menue = 0;
    GamePrepare *preparator = 0;
    GameOption *option = 0;
    MultiPrepare *MultPrep = 0;
    MultiplayerGame *MultiGame = 0;
    sf::RenderWindow *app = 0;
    MpValues *MultiOpt = 0;
    ///On declare les vector
    std::vector<sf::Sprite> m_Graphites;
    std::vector<sf::Text> m_Menu_Text;
    ///On declare les elements secondaires
    GameState state;
    Curseur *cursor;
    short fps = 0;
    sf::Clock fpsClock;
protected:
    virtual void veryUnusable();
};
#endif // GAME_H_INCLUDED
