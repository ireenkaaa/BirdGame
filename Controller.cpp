//
// Created by irena on 14.05.2020.
//

#include "Controller.h"
#include <iostream>
using std::cout, std::endl;
Controller::Controller(Board &board, BoardCreator &boardCreator, FinalScreen &finalScreen, MainMenu &mainMenu)
        : board(board), boardCreator(boardCreator), finalScreen(finalScreen), mainMenu(mainMenu) {
    this->initWindow();
    gameStack.push(boardCreatorState);
    gameStack.push(mainMenuState);
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
    gameStack.top()->updateState(event);
    if( gameStack.top()->changeState() ==true)
    {
        gameStack.pop();
    }
    if(gameStack.empty())
        {
            Board newBoard;
            board = newBoard;
            gameStack.push(boardCreatorState);
            gameStack.push(mainMenuState);
        }
}

void Controller::render() {
    window->clear(sf::Color(250,250,250));
    if(gameStack.top() == mainMenuState)
    {
        window->draw(mainMenu);
    }
    else{
        window->draw(boardCreator);
    }
    window->display();

}



