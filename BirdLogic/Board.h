
#ifndef DONT_TOUCH_THE_SPIKES_BOARD_H
#define DONT_TOUCH_THE_SPIKES_BOARD_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>
#include "DefineVariables.h"

enum Direction{BEAK_RIGHT,BEAK_LEFT};
enum GameState{RUNNING, END};
enum SpikeState{ENABLED,DISABLED};
class Board {
    sf::CircleShape spikes[MAX_NUMBER_OF_SPIKES];
    SpikeState spikesState[MAX_NUMBER_OF_SPIKES];
    sf::FloatRect boxesForSpikes[MAX_NUMBER_OF_SPIKES];
    sf::RectangleShape birdSprite;
    sf::Clock clockBird;
    Direction direction;
    sf::FloatRect boundingBoxBird;
    void createSpikes();
    void createBird();
    GameState gameState;
    void changeDirection();
    int points;
    void birdUpdate();
    void wallChecker();
    void collisions();
    void showSpikes();
   public:
    Board();
   ~Board();
    void gameUpdate();
    void resetClock();
    sf::RectangleShape getBirdSprite() const;
    sf::CircleShape getSpikes(int numberInTable) const;
    int getBirdPositionX() const;
    int getBirdPositionY() const;
    GameState getGameState() const;
    Direction getDirection() const;
    int getPoints() const;
};


#endif //DONT_TOUCH_THE_SPIKES_BOARD_H
