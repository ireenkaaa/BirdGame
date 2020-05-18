#include <iostream>
#include "BirdLogic/Board.h"
#include "BirdView/BoardCreator.h"
#include "BirdView/MainMenu.h"
#include "BirdView/FinalScreen.h"
#include "Controller.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>

int main() {
    srand (time(NULL));

    Board board;
    BoardCreator boardCreator(board);
    MainMenu mainMenu;
    FinalScreen finalScreen;
    Controller controller(board, boardCreator, finalScreen, mainMenu);
    controller.run();

    return 0;
}
