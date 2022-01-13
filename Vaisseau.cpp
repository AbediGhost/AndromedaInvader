#include "Vaisseau.h"

Vaisseau::Vaisseau()
{
}
void Vaisseau::draw(sf::RenderTarget &target,sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(craftSprite,states);
}
void Vaisseau::update()
{
}
void Vaisseau::render(sf::RenderWindow *app)
{
    craftTexture->setSmooth(true);
    app->draw(craftSprite);
}
void Vaisseau::EventManage(Gameuse *state,sf::Event event)
{
}
short Vaisseau::getVitesse()
{
    return vitesse;
}
short Vaisseau::getCadence()
{
    return cadenceDeTirs;
}
unsigned int Vaisseau::getManiabilite()
{
    return maniabilite;
}
std::string Vaisseau::getName()
{
    return name;
}
