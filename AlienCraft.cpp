#include "AlienCraft.h"

AlienCraft::AlienCraft()
{
    craftTexture = new sf::Texture();
    setCraftTexture();
}
void AlienCraft::setCraftTexture()
{
    unsigned short choice;
    std::string color;
    std::string name = "ufo";
    choice = rand() %1000;
    if(choice >= 0 && choice < 250)
        color = "Blue";
    if(choice >= 250 && choice < 500)
        color = "Green";
    if(choice >= 500 && choice < 750)
        color = "Red";
    if(choice >= 750)
        color = "Yellow";
    name+=color;
    name+=".png";
    baseTexture+=name;
    if(!craftTexture->loadFromFile(baseTexture.c_str()))
        exit(1);
    craftSprite.setTexture(*craftTexture);
    craftSprite.scale(0.5,0.5);
    craftSprite.setOrigin(craftTexture->getSize().x/2,craftTexture->getSize().y/2);
}
//Unusable
void AlienCraft::unusable() const
{
}
//EndUnusable
void AlienCraft::EventManage(GameState *state,sf::Event event)
{
}
void AlienCraft::Update()
{
    craftSprite.rotate(5);
}
void AlienCraft::AlienMove(float x,float y)
{
    craftSprite.move(x,y);
}
