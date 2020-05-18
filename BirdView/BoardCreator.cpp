//
// Created by irena on 14.05.2020.
//

#include "BoardCreator.h"

BoardCreator::BoardCreator(Board &board) : board(board) {
this->createBird();
this->createSpikes();
this->createTopAndDown();
}

BoardCreator::~BoardCreator() {

}

void BoardCreator::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(int i=0; i<MAX_NUMBER_OF_SPIKES; i++)
    {
        target.draw(spikes[i],states);
    }
    target.draw(birdSprite,states);
    target.draw(top,states);
    target.draw(down,states);
}
void BoardCreator::createSpikes() {
    for(int i=0; i<MAX_NUMBER_OF_SPIKES; i++) {

         spikes[i]=sf::CircleShape (SPIKE_SIDE_SIZE, 3);
        spikes[i].rotate(-90.f);
        spikes[i].setFillColor(sf::Color::Blue);

    }
    this->spikes[3].setPosition(WINDOW_WIDTH -SPIKE_SIDE_SIZE,3*(SPIKE_SIDE_SIZE+30));
    this->spikes[4].setPosition(WINDOW_WIDTH -SPIKE_SIDE_SIZE,4*(SPIKE_SIDE_SIZE+30));

}
void BoardCreator::createBird() {
    if (!texture.loadFromFile("../chicken.png"))
    {
        abort();
    }

    birdSprite.setTexture(texture);
    birdSprite.setScale(0.13,0.13);
    birdSprite.setPosition(board.getBirdSprite().getPosition());
}
void BoardCreator::createTopAndDown() {

    down=sf::RectangleShape(sf::Vector2f (WINDOW_WIDTH ,40));
    this->down.setPosition(0,WINDOW_HEIGHT-40);
    this->down.setFillColor(sf::Color::Green);
    top=down;
    this->top.setPosition(0,0);
}

void BoardCreator::birdGraphicUpdate() {
    this->birdSprite.setPosition(board.getBirdSprite().getPosition());
  /*  if(board.getDirection()==BEAK_RIGHT)
    {
        this->birdSprite.setTexture(texture);

    }
    else{
        this->birdSprite.setTexture(texture);
    }*/

}

void BoardCreator::graphicUpdate() {
    this->birdGraphicUpdate();
    this->spikesGraphicUpdate();

}

void BoardCreator::spikesGraphicUpdate() {

    for(int i=0; i<MAX_NUMBER_OF_SPIKES; i++)
    {
        this->spikes[i].setPosition(board.getSpikes(i).getPosition());
       this->spikes[i].setRotation(board.getSpikes(i).getRotation());
    }

}
