//
// Created by irena on 14.05.2020.
//

#include "BoardCreator.h"

BoardCreator::BoardCreator(Board &board, MainMenu &mainMenu) : board(board), mainMenu(mainMenu) {
this->createBird();
this->createSpikes();
isFirstMove=true;
this->numberOfCharacter=0;
    if (!bottomSpikesTexture.loadFromFile("../graphics/kolce-down.png") || !topSpikesTexture.loadFromFile("../graphics/kolce-top.png") || !font.loadFromFile("../font.ttf"))
    {
        abort();
    }
    bottomSpikes.setTexture(bottomSpikesTexture);
    bottomSpikes.setPosition(0,WINDOW_HEIGHT-130);
    topSpikes.setTexture(topSpikesTexture);
    topSpikes.setPosition(0,0);
    pointsText.setFont(font);
    pointsText.setFillColor(sf::Color(BLUE,150));
    pointsText.setCharacterSize(300);
    pointsText.setPosition(250,200);
    points=board.getPoints();
}

BoardCreator::~BoardCreator() {}

void BoardCreator::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(int i=0; i<MAX_NUMBER_OF_SPIKES; i++)
    {
        target.draw(spikes[i],states);
    }
    target.draw(pointsText);
    target.draw(birdSprite,states);
    target.draw(bottomSpikes,states);
    target.draw(topSpikes,states);


}
void BoardCreator::createSpikes() {
    for(int i=0; i<MAX_NUMBER_OF_SPIKES; i++) {

        spikes[i]=sf::CircleShape (SPIKE_SIDE_SIZE, 3);
        spikes[i].rotate(-90.f);
        spikes[i].setFillColor(sf::Color::Black);

    }
    this->spikes[3].setPosition(WINDOW_WIDTH -SPIKE_SIDE_SIZE,3*(SPIKE_SIDE_SIZE+30));
    this->spikes[4].setPosition(WINDOW_WIDTH -SPIKE_SIDE_SIZE,4*(SPIKE_SIDE_SIZE+30));

}
void BoardCreator::createBird() {
    if (!textures[0].loadFromFile("../graphics/chicken.png"),!textures[1].loadFromFile("../graphics/sheep.png"),!textures[2].loadFromFile("../graphics/elephant.png"),!textures[3].loadFromFile("../graphics/pig.png"))
    {
        abort();
    }
    if(!leftTextures[0].loadFromFile("../graphics/chicken-left.png"),!leftTextures[1].loadFromFile("../graphics/sheep-left.png"),!leftTextures[2].loadFromFile("../graphics/elephant-left.png"),!leftTextures[3].loadFromFile("../graphics/pig-left.png"))
    {
        abort();
    }
    birdSprite.setTexture(leftTextures[0]);
    birdSprite.setScale(0.13,0.13);
    birdSprite.setPosition(board.getBirdSprite().getPosition());
}

void BoardCreator::birdGraphicUpdate() {
    this->birdSprite.setPosition(board.getBirdSprite().getPosition());
    if(board.getDirection()==BEAK_RIGHT)
    {
        this->birdSprite.setTexture(leftTextures[numberOfCharacter]);

    }
    else{
        this->birdSprite.setTexture(textures[numberOfCharacter]);
    }

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
    points=board.getPoints();
    pointsText.setString(std::to_string(points));

}

bool BoardCreator::changeState() {
    if(board.getGameState()==END)
    {
        isFirstMove=true;
    }
    return(board.getGameState()==END);
}

void BoardCreator::updateState(sf::Event event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Right) {
            board.resetClock();
            isFirstMove=false;
        }
    }
    if(isFirstMove==true)
    {
        this->numberOfCharacter=mainMenu.getCharacters();
    }
    if(isFirstMove==false) {

        board.gameUpdate();
    }
    this->graphicUpdate();


}
