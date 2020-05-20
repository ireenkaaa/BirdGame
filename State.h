//
// Created by irena on 20.05.2020.
//

#ifndef BIRDGAME_STATE_H
#define BIRDGAME_STATE_H

#include <SFML/Graphics.hpp>

class State {
public:
    State();
    virtual ~State();
   virtual bool changeState() =0;
   virtual void updateState(sf::Event event)=0;

};


#endif //BIRDGAME_STATE_H
