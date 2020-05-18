//
// Created by irena on 14.05.2020.
//

#ifndef DONT_TOUCH_THE_SPIKES_BOARDCREATOR_H
#define DONT_TOUCH_THE_SPIKES_BOARDCREATOR_H

#include "../BirdLogic/Board.h"


class BoardCreator : public sf::Drawable {
    Board &board;

   sf::CircleShape spikes[8];
  //  SpikeState spikesState[8];
    sf::FloatRect boxesForSpikes[8];
    sf::RectangleShape top;
    sf::RectangleShape down;
    sf::Sprite birdSprite;
    sf::Texture texture;
    void createSpikes();
    void createBird();
    void createTopAndDown();
    void birdGraphicUpdate();
    void spikesGraphicUpdate();

public:
    BoardCreator(Board &board);
    ~BoardCreator();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void graphicUpdate();


};


#endif //DONT_TOUCH_THE_SPIKES_BOARDCREATOR_H
