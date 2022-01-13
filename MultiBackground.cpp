#include "MultiBackground.h"

MultiBackground::MultiBackground()
{
    if(!backTexture.loadFromFile("ressources/Backgrounds/blue.png"))
        exit(1);
    if(!MeteorTex.loadFromFile("ressources/sprite/Meteors/meteorBrown6.png"))
        exit(1);
    std::uniform_int_distribution<int> distribution_x(-256000,256000);
    sf::sleep(sf::seconds(1));
    std::uniform_int_distribution<int> distribution_y(-256000,256000);
    for(int i=0;i<50000;i++)
    {
        int x,y;
        x = distribution_x(generator);
        y = distribution_y(generator);
        sf::Sprite lolo;
        lolo.setTexture(MeteorTex);
        lolo.setPosition(x,y);
        MeteorSprite.push_back(lolo);
    }
    for(int x=-100;x<100;x++)
    {
        for(int y=-100;y<100;y++)
        {
            int x1,y1;
            x1 = distribution_x(generator);
            y1 = distribution_y(generator);
            sf::Sprite lolo;
            lolo.setTexture(backTexture);
            lolo.setPosition(x*256,y*256);
            backSprite.push_back(lolo);
        }
    }

}
void MultiBackground::draw(sf::RenderTarget &target,sf::RenderStates states) const
{
    for(int i=0;i<backSprite.size();i++)
    {
        if(backSprite[i].getPosition().x < pos.x+1600 && backSprite[i].getPosition().x > pos.x - 1600
           &&  backSprite[i].getPosition().y < pos.y+1600 && backSprite[i].getPosition().y > pos.y - 1600)
        {
            target.draw(backSprite[i],states);
        }
    }
    for(int i=0;i<MeteorSprite.size();i++)
    {
        if(MeteorSprite[i].getPosition().x < pos.x+1600 && MeteorSprite[i].getPosition().x > pos.x - 1600
           &&  MeteorSprite[i].getPosition().y < pos.y+1600 && MeteorSprite[i].getPosition().y > pos.y - 1600)
        {
            target.draw(MeteorSprite[i],states);
        }
    }
}
void MultiBackground::Update(int posX,int posY)
{
    pos.x = posX;
    pos.y = posY;
}
