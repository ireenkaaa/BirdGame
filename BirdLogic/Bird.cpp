//
// Created by irena on 07.05.2020.
//

#include "Bird.h"

Bird::Bird() {

    if (!texture.loadFromFile("../gru.png"))
    {
        abort();
    }

    birdSprite.setTexture(texture);
    birdSprite.setScale(0.1,0.1);
    birdSprite.setPosition(100.f,300.f);
    this->direction=BEAK_RIGHT;
}

Bird::~Bird() {

}

void Bird::birdUpdate() {
 //   float time=clock.getElapsedTime().asSeconds();
    float time=clockBird.getElapsedTime().asSeconds()+0.5;
    if(direction==BEAK_RIGHT)
    {
        this->birdSprite.setPosition((velocity*time*cos(alpha))+birdSprite.getPosition().x, birdSprite.getPosition().y-(velocity*time*sin(alpha)-0.5*gravity*time*time));

    } else{
        this->birdSprite.setPosition(birdSprite.getPosition().x-(velocity*time*cos(alpha)), birdSprite.getPosition().y-(velocity*time*sin(alpha)-0.5*gravity*time*time));
    }


}

void Bird::resetClock() {
    clockBird.restart();
}

void Bird::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(birdSprite,states);
}

void Bird::changeDirection() {
if(direction==BEAK_RIGHT)
{
    direction=BEAK_LEFT;
} else{
    direction=BEAK_RIGHT;
}
}

int Bird:: getBirdPositionX() const {
    return birdSprite.getPosition().x;
}
