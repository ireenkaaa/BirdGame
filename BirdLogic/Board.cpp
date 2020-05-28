//
// Created by irena on 08.05.2020.
//

#include "Board.h"
#include <iostream>

Board::Board() {
   this->createSpikes();
    this->createBird();
    gameState=RUNNING;
    spikes[3].setPosition(WINDOW_WIDTH-SPIKE_SIDE_SIZE,3*(SPIKE_SIDE_SIZE+SPACE_BETWEEN_SPIKES));
    spikes[4].setPosition(WINDOW_WIDTH-SPIKE_SIDE_SIZE,4*(SPIKE_SIDE_SIZE+SPACE_BETWEEN_SPIKES));
    this->points=0;

}

Board::~Board() {
}

void Board::createSpikes() {
    for(int i=0; i<MAX_NUMBER_OF_SPIKES; i++) {
        spikes[i] = sf::CircleShape(SPIKE_SIDE_SIZE, 3);
        spikes[i].rotate(-90.f);
        spikes[i].setFillColor(sf::Color::Blue);
    }

}


void Board::createBird() {

    birdSprite.setSize(sf::Vector2f(30,30));
    birdSprite.setPosition(100.f,300.f);
    this->direction=BEAK_RIGHT;

}

void Board::resetClock() {
    this->clockBird.restart();

}

void Board::birdUpdate() {
    float time=clockBird.getElapsedTime().asSeconds()+0.4;
    if(direction==BEAK_RIGHT)
    {
        this->birdSprite.setPosition((VELOCITY*time*cos(ALPHA))+birdSprite.getPosition().x, birdSprite.getPosition().y-(VELOCITY*time*sin(ALPHA)-0.5*GRAVITY*time*time));
    } else{
        this->birdSprite.setPosition(birdSprite.getPosition().x-(VELOCITY*time*cos(ALPHA)), birdSprite.getPosition().y-(VELOCITY*time*sin(ALPHA)-0.5*GRAVITY*time*time));
    }

}

void Board::changeDirection() {
    if(direction==BEAK_RIGHT)
    {
        direction=BEAK_LEFT;
    } else{
        direction=BEAK_RIGHT;
    }
}

int Board::getBirdPositionX() const {
    return birdSprite.getPosition().x;
}



void Board::collisions() {
    boundingBoxBird = birdSprite.getGlobalBounds();
    for(int i=0; i<MAX_NUMBER_OF_SPIKES;i++)
    {
        if(spikesState[i]==ENABLED)
        {
            boxesForSpikes[i]=spikes[i].getGlobalBounds();
            if(boundingBoxBird.intersects(boxesForSpikes[i]))
            {

                gameState=END;
            }
        }
    }

    if (getBirdPositionY() <= TOP_AND_DOWN_HEIGHT || getBirdPositionY() >= (WINDOW_HEIGHT - TOP_AND_DOWN_HEIGHT)) {
        gameState = END;
    }
}
GameState Board::getGameState() const {
    return gameState;
}

void Board::showSpikes() {

    int quantity = rand() % MAX_NUMBER_OF_SPIKES+2;
    for (int i = 0; i <8; ++i) {
        spikesState[i]=DISABLED;
        spikes[i].setPosition(0,0);

    }
        for(int i=0; i<quantity; i++)
        {
            int randomSpike=rand()%MAX_NUMBER_OF_SPIKES;
            spikesState[randomSpike]=ENABLED;
            if(direction==BEAK_RIGHT) {
                spikes[randomSpike].setPosition(WINDOW_WIDTH-SPIKE_SIDE_SIZE,randomSpike*(SPIKE_SIDE_SIZE+SPACE_BETWEEN_SPIKES));
                spikes[randomSpike].setRotation(-90.f);
            }
            else{
                spikes[randomSpike].setPosition(SPIKE_SIDE_SIZE,randomSpike*(SPIKE_SIDE_SIZE+SPACE_BETWEEN_SPIKES));
                spikes[randomSpike].setRotation(90.f);
            }
            spikes[randomSpike].move(0,40);
        }


}

void Board::wallChecker() {
    if (getBirdPositionX() < 0 || getBirdPositionX() > 650)
    {
        this->changeDirection();
        this->showSpikes();
        points++;
    }
}

sf::RectangleShape Board::getBirdSprite() const{
    return this->birdSprite;
}

int Board::getBirdPositionY() const {
    return this->birdSprite.getPosition().y;
}
sf::CircleShape Board::getSpikes(int numberInTable) const{
    return this->spikes[numberInTable];
}

void Board::gameUpdate() {

    this->wallChecker();
    this->birdUpdate();
    this->collisions();

}

Direction Board::getDirection() const {
    return direction;
}

int Board::getPoints() const {
    return points;
}
