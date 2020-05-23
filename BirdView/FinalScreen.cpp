//
// Created by irena on 18.05.2020.
//

#include "FinalScreen.h"

FinalScreen::FinalScreen(Board &board) : board(board) {
    this->textCreator();
    this->buttonCreator();
    this->isStateChanged=false;
}

FinalScreen::~FinalScreen() {

}

bool FinalScreen::changeState() {
    return isStateChanged;
}


void FinalScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(gameOverText,states);
    target.draw(scoreText,states);
    target.draw(yourPoints,states);
    target.draw(bestPoints,states);
    target.draw(button,states);
    target.draw(play,states);
}

void FinalScreen::textCreator() {
    if (!font.loadFromFile("../font.ttf"))
    {
        abort();
    }
    gameOverText.setFont(font);
    gameOverText.setPosition(50,50);
    gameOverText.setFillColor(sf::Color(DARK_BLUE));
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(110);

    scoreText.setFont(font);
    scoreText.setPosition(190,210);
    scoreText.setFillColor(sf::Color(DARK_BLUE));
    scoreText.setString("YOUR SCORE\n"
                        "\n"
                        "\n"
                        "BEST SCORE");
    scoreText.setCharacterSize(50);
    bestPoints.setFont(font);
    bestPoints.setPosition(200,280);
    bestPoints.setFillColor(sf::Color(BLUE));
    bestPoints.setCharacterSize(60);
    yourPoints.setFont(font);
    yourPoints.setPosition(200,460);
    yourPoints.setFillColor(sf::Color(BLUE));
    yourPoints.setCharacterSize(60);
    play.setFont(font);
    play.setPosition(230,590);
    play.setFillColor(sf::Color(250,250,250));
    play.setString("PLAY");
    play.setCharacterSize(90);
}

void FinalScreen::setPoints() {
    board.getPoints();
    std::string temp="POINTS: "+(std::to_string(board.getPoints()));
    yourPoints.setString(temp);

}
void FinalScreen::updateState(sf::Event event) {
    this->isStateChanged=false;
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            this->buttonChange(event.mouseButton.x,event.mouseButton.y);
        }
    }

}

void FinalScreen::usingFile() {
    std::ifstream ifStream("../results.txt");
    std::string line;
    if(ifStream)
    {
        getline(ifStream, line);
        bestScore=atoi(line.c_str());
    }
   if(board.getPoints()>bestScore) {
       std::ofstream ofStream;
       ofStream.open("../results.txt");
       if (ofStream) {
           ofStream << board.getPoints() << std::endl;

       }
       ofStream.close();
   }
   std::string temp="POINTS:"+(std::to_string(board.getPoints()));
    bestPoints.setString(temp);
}

void FinalScreen::setPointsText() {
    this->setPoints();
    this->usingFile();

}

void FinalScreen::buttonCreator() {
    button=sf::RectangleShape(sf::Vector2f(280,130));
    button.setFillColor(sf::Color(BLUE));
    button.setPosition(200,580);

}

void FinalScreen::buttonChange(int x,int y) {
   
        this->isStateChanged=x>=button.getPosition().x && x<=(button.getPosition().x+button.getSize().x) && y>=button.getPosition().y && y<=(button.getPosition().y+button.getSize().y);
  


}
