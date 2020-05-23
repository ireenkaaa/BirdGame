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
    MainMenu mainMenu;
    BoardCreator boardCreator(board,mainMenu);
    FinalScreen finalScreen(board);
    Controller controller(board, boardCreator, mainMenu, finalScreen);
    controller.run();

    return 0;
}
