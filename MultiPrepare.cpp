#include "MultiPrepare.h"

MultiPrepare::MultiPrepare(MpValues *toast)
{
    indicateur = new Indicator(183,183,163,606,606,626,281,301,291,281,301,291);
    BackGround = new MultiBackground();
    player = new PlayerCraft();
    if(toast != 0)
        player->setSoundFxParam(toast->ESO,toast->VSO);
    afficheValiderClock = new sf::Clock();
    //Attributions
    player->setPosition(399.0f,290.0f);
    indicFont.loadFromFile("ressources/font/alger.ttf");
    descFont.loadFromFile("ressources/font/alger.ttf");
    indication.setCharacterSize(40);
    indication.setString("Veuillez choisir votre vaisseau !");
    indication.setFont(indicFont);
    indication.setColor(sf::Color::Yellow);
    indication.setPosition(50,100);
    valider.setCharacterSize(30);
    valider.setPosition(95,530);
    valider.setString("Appuyer sur Entree pour commmencer !");
    valider.setFont(indicFont);
    valider.setFillColor(sf::Color::Cyan);
    craftdescription.setCharacterSize(25);
    craftdescription.setFillColor(sf::Color::Green);
    craftdescription.setPosition(180,380);
    craftdescription.setFont(descFont);
}
MultiPrepare::~MultiPrepare()
{
    delete indicateur;
    delete BackGround;
    delete afficheValiderClock;
    indicateur = 0;
    player = 0;
    BackGround = 0;
    afficheValiderClock = 0;
}
void MultiPrepare::render(sf::RenderWindow *app)
{
    app->draw(*BackGround);
    for(int i=0;i<player->projectilChild.size();i++)
    {
        if(player->projectilChild[i] != 0)
            app->draw(*player->projectilChild[i]);
    }
    app->draw(*player);
    app->draw(indicateur->triOne,3,sf::Triangles);
    app->draw(indicateur->triTwo,3,sf::Triangles);
    app->draw(indication);
    app->draw(craftdescription);
    if(afficheValider == true)
        app->draw(valider);
}
void MultiPrepare::update(Gameuse *jeux)
{
    if(afficheValiderClock->getElapsedTime().asMilliseconds() >= 450)
    {
        afficheValider = !afficheValider;
        afficheValiderClock->restart();
    }
    std::stringstream writer;
    writer <<"Nom :                                     "<<player->getName()<<std::endl
           <<"Vitesse de pointe :        "<<player->getVitesse()<<" km/h"<<std::endl
           <<"Cadence de tirs :           "<<player->getCadence()<<" tirs/s"<<std::endl
           <<"Maniabilité :                   "<<player->getManiabilite()<<" rad"<<std::endl;
    craftdescription.setString(writer.str());
    player->rotate(1.0f);
    player->update();
    BackGround->Update((int)player->getPosition().x,(int)player->getPosition().y);
}
void MultiPrepare::EventManage(Gameuse *jeux,sf::Event event,MultiplayerGame *gameeur)
{
    if(event.type == sf::Event::KeyPressed)
    {
        switch(event.key.code)
        {
            case sf::Keyboard::Escape:
                jeux->setState(MAINMENUE);
            break;
            case sf::Keyboard::Left:
                player->switchTexture(-1);
            break;
            case sf::Keyboard::Right:
                player->switchTexture(1);
            break;
            case sf::Keyboard::Return:
                gameeur->setPlayer(player);
                jeux->setState(MULTIPLAYER);
            break;
        }
    }
}
