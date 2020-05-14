//
// Created by irena on 07.05.2020.
//

#ifndef DONT_TOUCH_THE_SPIKES_BIRD_H
#define DONT_TOUCH_THE_SPIKES_BIRD_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>

#define gravity 0.9
#define alpha (70*2*M_PI/360)
#define velocity 0.4

enum Direction{BEAK_RIGHT,BEAK_LEFT};
class Bird : public sf::Drawable
{
public:
    Bird();
    virtual ~Bird();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void resetClock();
    void birdUpdate();
    void changeDirection();

    int getBirdPositionX() const;

private:
    sf::Sprite birdSprite;
    sf::Texture texture;
    sf::Clock clockBird;
    Direction direction;
};


#endif //DONT_TOUCH_THE_SPIKES_BIRD_H
