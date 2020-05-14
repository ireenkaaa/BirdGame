//
// Created by irena on 08.05.2020.
//

#ifndef DONT_TOUCH_THE_SPIKES_SPIKES_H
#define DONT_TOUCH_THE_SPIKES_SPIKES_H

#include <vector>
#include <SFML/Graphics.hpp>
#define spikeSideSize 60
#define windowWidth 700
#define windowHeight 800


class Spikes : public sf::Drawable {
public:
    Spikes();
    virtual ~Spikes();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
    std::vector <sf::CircleShape> spikesRight;
    std::vector <sf::CircleShape> spikesLeft;
    std::vector <sf::CircleShape> spikesTop;
    std::vector <sf::CircleShape> spikesDown;
};


#endif //DONT_TOUCH_THE_SPIKES_SPIKES_H
