#include "GameProcessing.h"

GameProcessing::GameProcessing() {
board = {
        {0,0,0,0,0,0,0},
        {0,0,2,1,2,0,0},
        {0,0,2,2,2,0,0},
        {0,0,2,2,2,0,0},
        {0,2,2,2,2,2,0},
        {0,2,2,0,2,2,0}

};
}


GameProcessing& GameProcessing::getInstance() {
    static GameProcessing instance;
    return instance;
}


int GameProcessing::getColor(int x, int y) {
    return board[x][y];
}

int GameProcessing::nextMove(int col) {
    return 0;
}

int GameProcessing::getState() {
    return 0;
}

int GameProcessing::getTurn() {
    return 0;
}

void GameProcessing::undoMove() {

}

void GameProcessing::setBoard(std::vector<std::vector<int>> &Iboard) {
board = Iboard;
}
