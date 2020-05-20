//
// Created by irena on 20.05.2020.
//

#ifndef BIRDGAME_STATE_H
#define BIRDGAME_STATE_H


class State {
public:
    State();
    virtual ~State();
   virtual bool bringOnTop() =0;
    virtual bool takeOff() =0;
};


#endif //BIRDGAME_STATE_H
