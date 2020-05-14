//
// Created by irena on 08.05.2020.
//

#include "Spikes.h"

Spikes::Spikes() {


    for(int i=0; i<(windowHeight/spikeSideSize); i++)
    {
        sf::CircleShape triangle(spikeSideSize-20,3);
        triangle.rotate(90.f);
        triangle.setPosition(spikeSideSize,i*(spikeSideSize+10));
        triangle.setFillColor(sf::Color::Blue);
        spikesLeft.push_back(triangle);
        triangle.setPosition(windowWidth-spikeSideSize,i*(spikeSideSize+10));
        triangle.rotate(-180.f);
        spikesRight.push_back(triangle);
    }

}

Spikes::~Spikes() {}

void Spikes::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(int i=0; i<spikesLeft.size(); i++)
    {
        target.draw(spikesLeft.at(i),states);
        target.draw(spikesRight.at(i),states);
    }



}
