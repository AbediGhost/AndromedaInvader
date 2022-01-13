#ifndef MULTIPREPARE_H
#define MULTIPREPARE_H

#include <SFML/Graphics.hpp>
#include "MultiBackground.h"
#include "MultiplayerGame.h"
#include "Curseur.h"
#include "Usefull_Things.h"
#include "PlayerCraft.h"
#include "Indicator.h"

class MultiPrepare
{
public:
    MultiPrepare(MpValues*);
    ~MultiPrepare();
    void render(sf::RenderWindow*);
    void update(Gameuse*);
    void EventManage(Gameuse*,sf::Event,MultiplayerGame*);
private:
    //Fonctions privees
    //Attributs prives
    MultiBackground *BackGround = 0;
    PlayerCraft *player = 0;
    sf::Text indication;
    sf::Font indicFont;
    sf::Font descFont;
    sf::Text craftdescription;
    sf::Text valider;
    Indicator *indicateur;
    bool afficheValider = true;
    sf::Clock *afficheValiderClock;
};

#endif // MULTIPREPARE_H
