#include "Projectile.h"

Projectile::Projectile(unsigned short categorie,unsigned int mAngle,sf::Vector2f pos,short craftVitesse)
{
    mtype = categorie;
    setType();
    float Nangle;
    float toast;
    if(mAngle >= 0 && mAngle <= 90)
        toast = 270+mAngle;
    else if(mAngle >= 90 && mAngle <= 360)
        toast = mAngle-90;
    Nangle = (toast*pi)/180;
    laserDirection.x = cos(Nangle);
    laserDirection.y = sin(Nangle);
    this->setPosition(pos);
    this->setRotation(mAngle);
    destroyClock.restart();
    if(craftVitesse >= 0)
        speed += craftVitesse*1.1;
}
Projectile::~Projectile()
{
}
void Projectile::setType()
{
    if(!laserTexture.loadFromFile("ressources/sprite/Lasers/laserBlue01.png"))
        exit(1);
    laserSprite.setTexture(laserTexture);
    this->scale(1,0.5);
    this->setOrigin(laserTexture.getSize().x/2,laserTexture.getSize().y/2);
}
void Projectile::Update()
{
    if(destroyClock.getElapsedTime().asMilliseconds() >= 100)
        this->scale(0.99,1);
    this->move(speed*laserDirection.x,speed*laserDirection.y);
    if(this->getScale().x < 0.5)
        destroy = true;
    laserSprite.setPosition(this->getPosition());
    laserSprite.setScale(this->getScale());
    laserSprite.setRotation(this->getRotation());
}
void Projectile::draw(sf::RenderTarget &target,sf::RenderStates states) const
{
    target.draw(laserSprite,states);
}
bool Projectile::getDestroy()
{
    return destroy;
}


