//
// Created by irena on 17.05.2020.
//

#ifndef BIRDGAME_MAINMENU_H
#define BIRDGAME_MAINMENU_H

#include "SFML/Graphics.hpp"
#include "../BirdLogic/DefineVariables.h"
#include "../State.h"

class MainMenu : public sf::Drawable, public State{
public:
    MainMenu();
    ~MainMenu();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    bool changeState() override;
    void updateState(sf::Event event) override;
    int getCharacters() const;

private:
    sf::RectangleShape playButton;
    int characters;
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
    bool isMenuChanged;
    void buttonChange(int x,int y);

};


#endif //BIRDGAME_MAINMENU_H
