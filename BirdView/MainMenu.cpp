//
// Created by irena on 17.05.2020.
//

#include "MainMenu.h"

MainMenu::MainMenu() {
    this->textCreator();
    this->buttonsCreator();
    this->animalsCreator();
    isMenuChanged=false;
    this->characters=0;
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
    characterButtons[0].setFillColor(sf::Color(RED));

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

    if (playButton.getGlobalBounds().contains(x, y)) {
        playButton.setFillColor(sf::Color(RED));
        this->isMenuChanged = true;
    } else {
        this->isMenuChanged = false;
    }
    for (int i = 0; i < 4; i++) {
        if (characterButtons[i].getGlobalBounds().contains(x, y)) {
            characters = i;
            characterButtons[i].setFillColor(sf::Color(RED));
        } else {
            characterButtons[i].setFillColor(sf::Color(ORANGE));
        }
    }
}

void MainMenu::animalsCreator() {
    if (!animalTextures[0].loadFromFile("../graphics/chicken.png"),!animalTextures[1].loadFromFile("../graphics/sheep.png"),!animalTextures[2].loadFromFile("../graphics/elephant.png"),!animalTextures[3].loadFromFile("../graphics/pig.png"))
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

bool MainMenu::changeState() {
    return isMenuChanged;
}

void MainMenu::updateState(sf::Event event) {
    isMenuChanged=false;
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            this->buttonChange(event.mouseButton.x,event.mouseButton.y);
        }
    }
}

int MainMenu::getCharacters() const {
    return characters;
}

