//
// Created by irena on 17.05.2020.
//

#include "MainMenu.h"

MainMenu::MainMenu() {
    this->textCreator();
    this->buttonsCreator();
    this->animalsCreator();
    states=MAIN_MENU;
}

MainMenu::~MainMenu() {
}

void MainMenu::buttonsCreator() {
    playButton=sf::RectangleShape(sf::Vector2f(320,100));
    playButton.setFillColor(sf::Color(YELLOW));
    playButton.setPosition(180,230);
    for(int i=0; i<4; i++)
    {
        characterButtons[i]=sf::RectangleShape(sf::Vector2f(130,130));
        characterButtons[i].setFillColor(sf::Color(ORANGE));
        characterButtons[i].setPosition(i*(150),500);
        characterButtons[i].move(70,0);
    }

}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(playButton,states);
    for(int i=0; i<4; i++)
    {
        target.draw(characterButtons[i],states);
        target.draw(animalSprites[i],states);
    }
    target.draw(gameName);
    target.draw(chooseCharacter);
    target.draw(playText);

}

void MainMenu::textCreator() {
    if (!font.loadFromFile("../font.ttf"))
    {
        abort();
    }
    gameName.setFont(font);
    gameName.setPosition(160,50);
    gameName.setFillColor(sf::Color(DARK_BLUE));
    gameName.setString("DON'T TOUCH \n"
                       " THE SPIKES");
    gameName.setCharacterSize(60);
    chooseCharacter=gameName;
    chooseCharacter.setPosition(210,350);
    chooseCharacter.setString("CHOOSE THE\n"
                              " CHARACTER");
    chooseCharacter.setCharacterSize(40);
    playText.setFont(font);
    playText.setFillColor(sf::Color(250,250,250));
    playText.setPosition(250,235);
    playText.setString("PLAY");
    playText.setCharacterSize(70);

}

void MainMenu::buttonChange(int x, int y) {
    if(x>=playButton.getPosition().x && x<=(playButton.getPosition().x+playButton.getSize().x) && y>=playButton.getPosition().y && y<=(playButton.getPosition().y+playButton.getSize().y))
    {
        playButton.setFillColor(sf::Color(RED));
        states=GAME;
    } else{
        states=MAIN_MENU;
    }
    for(int i=0; i<4; i++)
    {
        if(x>=characterButtons[i].getPosition().x && x<=(characterButtons[i].getPosition().x+characterButtons[i].getSize().x) && y>=characterButtons[i].getPosition().y && y<=(characterButtons[i].getPosition().y+characterButtons[i].getSize().y))
        {
            characters = static_cast<Characters>(i);
            characterButtons[i].setFillColor(sf::Color(RED));

        } else{
            characterButtons[i].setFillColor(sf::Color(ORANGE));
        }
    }

}

States MainMenu::getStates() const {
    return states;
}
void MainMenu::animalsCreator() {
    if (!animalTextures[0].loadFromFile("../chicken.png"),!animalTextures[1].loadFromFile("../sheep.png"),!animalTextures[2].loadFromFile("../elephant.png"),!animalTextures[3].loadFromFile("../pig.png"))
    {
        abort();
    }
    for(int i=0;i<4; i++){
        animalSprites[i].setTexture(animalTextures[i]);
        animalSprites[i].setPosition(characterButtons[i].getPosition());
        animalSprites[i].move(15,15);
        animalSprites[i].setScale(0.2,0.2);
    }
}