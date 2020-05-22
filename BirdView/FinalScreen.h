//
// Created by irena on 18.05.2020.
//

#ifndef BIRDGAME_FINALSCREEN_H
#define BIRDGAME_FINALSCREEN_H

#include "../State.h"
#include <SFML/Graphics.hpp>
#include "../BirdLogic/Board.h"
#include <string>
#include <fstream>
class FinalScreen: public sf::Drawable,public State {
    Board &board;
    sf::Text gameOverText;
    sf::Text scoreText;
    sf::Text bestPoints;
    sf::Text yourPoints;
    sf::Text play;
    sf::Font font;
    sf::RectangleShape button;
    int bestScore;
    void textCreator();
    void setPoints();
    void usingFile();
    void buttonCreator();
    void buttonChange(int x,int y);
    bool isStateChanged;
public:
    FinalScreen(Board &board);
    virtual ~FinalScreen();
    bool changeState() override;
    void updateState(sf::Event event) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setPointsText();
};


#endif //BIRDGAME_FINALSCREEN_H
