#ifndef MULTIPLAYERGAME_H
#define MULTIPLAYERGAME_H

#include <SFML/Graphics.hpp>
#include <sstream>
#include "PlayerCraft.h"
#include "Usefull_Things.h"
#include "Includer.h"
#include "MultiBackground.h"

class MultiplayerGame
{
public:
    MultiplayerGame();
    ~MultiplayerGame();
    void Run(sf::RenderWindow*,Gameuse*);
    void render(sf::RenderWindow*);
    void setPlayer(PlayerCraft*);
    void Update();
    void EventManage(Gameuse*,sf::Event);
private:
    //Declaration des attributs prives
    sf::View gameView;
    PlayerCraft *playeur = 0;
    bool exitingGame = false;
    MultiBackground *backGround = 0;
    short fps = 0;
    sf::Clock fpsClock;
};

#endif // MULTIPLAYERGAME_H
