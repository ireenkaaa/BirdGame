//
// Created by irena on 17.05.2020.
//

#ifndef BIRDGAME_MAINMENU_H
#define BIRDGAME_MAINMENU_H

#include "SFML/Graphics.hpp"
#include "../BirdLogic/DefineVariables.h"

class MainMenu : public sf::Drawable{
public:
    MainMenu();
    ~MainMenu();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    States getStates() const;
    void buttonChange(int x,int y);

private:
    sf::RectangleShape playButton;
    States states;
    Characters characters;
    sf::Font font;
    sf::Text gameName;
    sf::Text chooseCharacter;
    sf::Text playText;
    sf::RectangleShape characterButtons[4];
    sf::Sprite animalSprites[4];
    sf::Texture animalTextures[4];
    void buttonsCreator();
    void textCreator();
    void animalsCreator();

};


#endif //BIRDGAME_MAINMENU_H
