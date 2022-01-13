#include "PlayerCraft.h"

PlayerCraft::PlayerCraft()
{
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<4;j++)
        {
            std::stringstream name;
            name <<baseTexture<<"playerShip"<<colorTab[i]<<j<<".png";

            std::string address = name.str();
            sf::Texture tempo;
            tempo.loadFromFile(address.c_str());
            textureTable.push_back(tempo);
        }
    }
    craftTexture = new sf::Texture();
    craftTexture = &textureTable[currentIndex];
    craftSprite.setTexture(*craftTexture);
    std::stringstream putter;
    putter <<"playerShip"<<colorTab[colorIndex]<<typeIndex;
    id = putter.str();
    loadSpecs();
    gatlinPos.x = (this->getPosition().x);
    gatlinPos.y = (this->getPosition().y);
    shootCadencer.restart();
    craftSpeed.x = 0;
    craftSpeed.y = 0;
    currentSpeed = 0;
    shootBuf.loadFromFile("ressources/Audio/laser1.ogg");
    shootFX.setBuffer(shootBuf);
    this->setOrigin(craftTexture->getSize().x/2,craftTexture->getSize().y/2);
}
PlayerCraft::~PlayerCraft()
{
}
void PlayerCraft::update()
{
    if(currentSpeed > 0 && playing == true && sf::Keyboard::isKeyPressed(sf::Keyboard::Up) == false)
    {
        currentSpeed -= 0.00;
    }
    gatlinPos.x = (this->getPosition().x);
    gatlinPos.y = (this->getPosition().y);
    if(currentSpeed > 0 && currentSpeed > vitesse/30)
    {
        currentSpeed = vitesse/30;
    }
    if(currentSpeed < 0 && currentSpeed < -(vitesse/50))
        currentSpeed = -(vitesse/50);
    craftSpeed.x = (currentSpeed*(sin(this->getRotation()*3.12159265358979/180)));
    craftSpeed.y = (currentSpeed*(-cos(this->getRotation()*3.12159265358979/180)));
    for(std::vector<Projectile*>::iterator it = projectilChild.begin();it<projectilChild.end();it++)
    {
        Projectile *tempo;
        tempo = *it;
        if(tempo != 0)
        {
            tempo->Update();
            if(tempo->getDestroy() == true)
            {
                delete tempo;
                tempo = 0;
                projectilChild.erase(it);
            }
        }
    }
    this->move(craftSpeed);
}
void PlayerCraft::EventManage(Gameuse *state,sf::Event event)
{
}
void PlayerCraft::handleInput()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(shootCadencer.getElapsedTime().asMilliseconds() >= 1000/cadenceDeTirs)
            shoot();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->setRotation(this->getRotation()+maniabilite);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        this->setRotation(this->getRotation()-maniabilite);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        currentSpeed += 0.5;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        currentSpeed -= 1;
    }

}
//Unusable
void PlayerCraft::unusable() const
{
}
//ENdUnusable
void PlayerCraft::switchTexture(int i)
{
    currentIndex += i;
    colorIndex += i;
    typeIndex += i;
    if(currentIndex > 11)
        currentIndex = 0;
    else if(currentIndex < 0)
        currentIndex = 11;
    if(colorIndex > 3)
        colorIndex=0;
    else if(colorIndex<0)
        colorIndex = 3;
    if(typeIndex > 3)
        typeIndex = 1;
    else if(typeIndex < 1)
        typeIndex = 3;
    craftTexture = &textureTable[currentIndex];
    craftSprite.setTexture(*craftTexture);
    this->setOrigin(craftTexture->getSize().x/2,craftTexture->getSize().y/2);
    std::stringstream putter;
    putter <<"playerShip"<<colorTab[colorIndex]<<typeIndex;
    id = putter.str();
    craftSprite.setTextureRect(sf::IntRect(0,0,craftTexture->getSize().x,craftTexture->getSize().y));
    loadSpecs();
}
void PlayerCraft::loadSpecs()
{
    std::string address = "ressources/craftDataBase/";
    address+=id;
    address+=".txt";
    std::string const tempo = address;
    std::ifstream reader(tempo.c_str());
    if(!reader)
        std::cout <<"Error !!"<<std::endl;
    reader >> name >> vitesse >> cadenceDeTirs >> maniabilite;
}
void PlayerCraft::shoot()
{
    shootCadencer.restart();
    craftLaser = 0;
    craftLaser = new Projectile(0,(unsigned int)this->getRotation(),gatlinPos,currentSpeed);
    projectilChild.push_back(craftLaser);
    shootFX.play();
}
void PlayerCraft::setHP(unsigned short attack)
{
    HealthPoint -= attack;
}
unsigned short PlayerCraft::getHP()
{
    return HealthPoint;
}
void PlayerCraft::copyCraft(PlayerCraft *copied)
{
}
void PlayerCraft::setSoundFxParam(unsigned int param1,unsigned int param2)
{
    if(param1 == 0)
    {
        shootFX.setVolume((float)param2);
    }
    else
        shootFX.setVolume(0);
}
void PlayerCraft::setPlaying(bool status)
{
    playing = status;
}
float PlayerCraft::getCurrentSpeed()
{
    return currentSpeed;
}

