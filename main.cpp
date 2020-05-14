#include <iostream>
#include "BirdLogic/Board.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

int main() {
    srand (time(NULL));
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
//sf::Style::Default, settings
    sf::RenderWindow window(sf::VideoMode(700, 800), "My window" );
    Board board;
    sf::Clock clock;
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || board.getGameState()==END )
                window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Right)
            {
             board.resetClock();
            }
        }
        board.wallChecker();
        board.collisions();

        board.birdUpdate();
       window.clear(sf::Color(255,255,255));
       window.draw(board);
       window.display();
       /* if(board.getGameState()==END)
        {
            window.close();
        }*/

    }

    return 0;
}
