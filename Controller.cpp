//
// Created by irena on 14.05.2020.
//

#include "Controller.h"
#include <iostream>
using std::cout, std::endl;
Controller::Controller(Board &board, BoardCreator &boardCreator, FinalScreen &finalScreen, MainMenu &mainMenu)
        : board(board), boardCreator(boardCreator), finalScreen(finalScreen), mainMenu(mainMenu) {
    this->initWindow();
    isFirstMove=true;
}

Controller::~Controller() {
    delete this->window;
}

void Controller::initWindow() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window= new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Fat Bird",sf::Style::Default, settings);

}

void Controller::run() {
    while(this->window->isOpen()) {
        this->update();
        this->render();

    }

}

void Controller::updateSFMLEvent() {


    while (this->window->pollEvent(event)) {
        if (this->event.type == sf::Event::Closed || board.getGameState()==END ) {
            window->close();

        }
    }



}

void Controller::update() {
    this->updateSFMLEvent();
    if(states==MAIN_MENU)
    {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                mainMenu.buttonChange(event.mouseButton.x,event.mouseButton.y);
                states=mainMenu.getStates();
            }
        }
    }
    else if(states==GAME) {


        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Right) {
                board.resetClock();
                isFirstMove=false;
            }
        }
        if(isFirstMove==false) {

            board.gameUpdate();

        }
        boardCreator.graphicUpdate();

        if (board.getGameState() == END) {
            states=MAIN_MENU;
            Board newBoard;
            board = newBoard;
            isFirstMove=true;

        }
    }
}

void Controller::render() {
    window->clear(sf::Color(250,250,250));
    if(states==MAIN_MENU)
    {
        window->draw(mainMenu);
    } else{
        window->draw(boardCreator);
    }

    window->display();

}



