//
// Created by irena on 14.05.2020.
//

#include "Controller.h"
#include <iostream>

Controller::Controller(Board &board, BoardCreator &boardCreator,  MainMenu &mainMenu, FinalScreen &finalScreen)
        : board(board), boardCreator(boardCreator), mainMenu(mainMenu) , finalScreen(finalScreen){
    this->initWindow();
    gameStack.push(finalScreenState);
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
    //window->setFramerateLimit(110);

}

void Controller::run() {
    while(this->window->isOpen()) {
        this->update();
        this->render();

    }

}

void Controller::updateSFMLEvent() {

    while (this->window->pollEvent(event)) {
        if (this->event.type == sf::Event::Closed ) {
            window->close();

        }
    }

}

void Controller::update() {
    this->updateSFMLEvent();
    gameStack.top()->updateState(event);
    if( gameStack.top()->changeState() ==true)
    {
        finalScreen.setPointsText();
        gameStack.pop();
    }
    if(gameStack.empty())
    {
            Board newBoard;
            board = newBoard;
            gameStack.push(finalScreenState);
            gameStack.push(boardCreatorState);
            gameStack.push(mainMenuState);
    }
}

void Controller::render() {

    if(gameStack.top() == mainMenuState)
    {
        window->clear(sf::Color(250,250,250));
        window->draw(mainMenu);
    }
    else if(gameStack.top()==boardCreatorState){
        window->clear(sf::Color(250,250,250));
        window->draw(boardCreator);
    }
    else if(gameStack.top()==finalScreenState)
    {
        window->clear(sf::Color(YELLOW));
        window->draw(finalScreen);
    }
    window->display();

}



