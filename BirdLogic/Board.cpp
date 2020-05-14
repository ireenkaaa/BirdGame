//
// Created by irena on 08.05.2020.
//

#include "Board.h"
#include <iostream>

Board::Board() {
    this->createSpikes();
    this->createBird();
    this->createTopAndDown();
    gameState=RUNNING;
    spikes[3].setPosition(windowWidth-spikeSideSize,3*(spikeSideSize+30));
    spikes[4].setPosition(windowWidth-spikeSideSize,4*(spikeSideSize+30));

}

Board::~Board() {
}

void Board::createSpikes() {
    for(int i=0; i<8; i++) {
        spikes[i] = sf::CircleShape(spikeSideSize, 3);
        spikes[i].rotate(-90.f);
        spikes[i].setFillColor(sf::Color::Blue);

    }

}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(int i=0; i<maxNumberOfSpikes; i++)
    {
        target.draw(spikes[i],states);
    }
    target.draw(birdSprite,states);
    target.draw(top,states);
    target.draw(down,states);
}

void Board::createBird() {
    if (!texture.loadFromFile("../gru.png"))
    {
        abort();
    }

    birdSprite.setTexture(texture);
    birdSprite.setScale(0.06,0.06);
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
        this->birdSprite.setPosition((velocity*time*cos(alpha))+birdSprite.getPosition().x, birdSprite.getPosition().y-(velocity*time*sin(alpha)-0.5*gravity*time*time));
    } else{
        this->birdSprite.setPosition(birdSprite.getPosition().x-(velocity*time*cos(alpha)), birdSprite.getPosition().y-(velocity*time*sin(alpha)-0.5*gravity*time*time));
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

void Board::createTopAndDown() {

    down=sf::RectangleShape(sf::Vector2f (windowWidth,40));
    this->down.setPosition(0,windowHeight-40);
    this->down.setFillColor(sf::Color::Green);
    top=down;
    this->top.setPosition(0,0);
}

void Board::collisions() {
    boundingBoxBird = birdSprite.getGlobalBounds();
    boundingBoxDown=down.getGlobalBounds();
    boundingBoxTop=top.getGlobalBounds();
    for(int i=0; i<maxNumberOfSpikes;i++)
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
    if (boundingBoxBird.intersects(boundingBoxDown) || boundingBoxBird.intersects(boundingBoxTop))
    {
        gameState=END;
    }
}
GameState Board::getGameState() const {
    return gameState;
}

void Board::showSpikes() {

    int quantity = rand() % maxNumberOfSpikes+2;
    for (int i = 0; i <8; ++i) {
        spikesState[i]=DISABLED;
        spikes[i].setPosition(0,0);

    }
        for(int i=0; i<quantity; i++)
        {
            int randomSpike=rand()%maxNumberOfSpikes;
            spikesState[randomSpike]=ENABLED;
            if(direction==BEAK_RIGHT) {
                spikes[randomSpike].setPosition(windowWidth-spikeSideSize,randomSpike*(spikeSideSize+30));
                spikes[randomSpike].setRotation(-90.f);
            }
            else{
                spikes[randomSpike].setPosition(spikeSideSize,randomSpike*(spikeSideSize+30));
                spikes[randomSpike].setRotation(90.f);
            }
            spikes[randomSpike].move(0,40);
        }


}

void Board::wallChecker() {
    if(getBirdPositionX()==650 || getBirdPositionX()==0 )
    {
        this->changeDirection();
        this->showSpikes();
        points++;
    }

}
