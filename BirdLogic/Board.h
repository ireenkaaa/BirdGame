
#ifndef DONT_TOUCH_THE_SPIKES_BOARD_H
#define DONT_TOUCH_THE_SPIKES_BOARD_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <math.h>
#define spikeSideSize 40
#define windowWidth 700
#define windowHeight 800
#define gravity 2.1
#define alpha (70*2*M_PI/360)
#define velocity 0.8

enum Direction{BEAK_RIGHT,BEAK_LEFT};
enum GameState{RUNNING, END};
enum SpikeState{ENABLED,DISABLED};
class Board : public sf::Drawable {
    sf::CircleShape spikes[8];
    SpikeState spikesState[8];
    sf::FloatRect boxesForSpikes[8];
    sf::RectangleShape top;
    sf::RectangleShape down;
    sf::Sprite birdSprite;
    sf::Texture texture;
    sf::Clock clockBird;
    Direction direction;
    sf::FloatRect boundingBoxBird;
    sf::FloatRect boundingBoxTop;
    sf::FloatRect boundingBoxDown;
    void createSpikes();
    void createBird();
    void createTopAndDown();
    GameState gameState;
    void changeDirection();
    int points;
    int maxNumberOfSpikes=8;
   public:
    Board();
    void resetClock();
    void birdUpdate();
    void wallChecker();
    void collisions();
    void showSpikes();
    int getBirdPositionX() const;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual ~Board();

    GameState getGameState() const;
};


#endif //DONT_TOUCH_THE_SPIKES_BOARD_H
