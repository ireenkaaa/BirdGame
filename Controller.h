//
// Created by irena on 14.05.2020.
//

#ifndef BIRDGAME_CONTROLLER_H
#define BIRDGAME_CONTROLLER_H
#include "BirdLogic/Board.h"
#include <SFML/Graphics.hpp>
#include "BirdView/BoardCreator.h"
#include "BirdView/FinalScreen.h"
#include "BirdView/MainMenu.h"
#include "BirdLogic/DefineVariables.h"
#include <iostream>
#include <stack>

class Controller {
public:

    Controller(Board &board, BoardCreator &boardCreator, FinalScreen &finalScreen, MainMenu &mainMenu);
    ~Controller();
    void run();
private:
    BoardCreator &boardCreator;
    Board &board;
    MainMenu &mainMenu;
    FinalScreen &finalScreen;
    State *mainMenuState=&mainMenu;
    State *boardCreatorState=&boardCreator;
    State *finalScreenState=&finalScreen;
    std::stack<State*> gameStack;
    sf::RenderWindow *window;
    sf::Event event;
    States states;
    void update();
    void render();
    void initWindow();
    void updateSFMLEvent();

};


#endif //BIRDGAME_CONTROLLER_H
