//
// Created by irena on 14.05.2020.
//

#ifndef DONT_TOUCH_THE_SPIKES_BOARDCREATOR_H
#define DONT_TOUCH_THE_SPIKES_BOARDCREATOR_H

#include "../BirdLogic/Board.h"
#include "../State.h"
#include "../BirdView/MainMenu.h"

class BoardCreator : public sf::Drawable, public State {
    Board &board;
    MainMenu &mainMenu;
    bool isFirstMove;
   sf::CircleShape spikes[MAX_NUMBER_OF_SPIKES];
    sf::FloatRect boxesForSpikes[MAX_NUMBER_OF_SPIKES];
    sf::RectangleShape top;
    sf::RectangleShape down;
    sf::Sprite birdSprite;
    int numberOfCharacter;
    sf::Texture textures[4];
    sf::Texture leftTextures[4];
    void createSpikes();
    void createBird();
    void createTopAndDown();
    void birdGraphicUpdate();
    void spikesGraphicUpdate();
    void graphicUpdate();
public:
    BoardCreator(Board &board, MainMenu &mainMenu);
    ~BoardCreator();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool changeState() override;
    void updateState(sf::Event event) override;


};


#endif //DONT_TOUCH_THE_SPIKES_BOARDCREATOR_H
