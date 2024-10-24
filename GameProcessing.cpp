#include <iostream>
#include "GameProcessing.h"

GameProcessing::GameProcessing() {
board = {
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}

};
currentTurn = 1;
gameState = 0;
}


GameProcessing& GameProcessing::getInstance() {
    static GameProcessing instance;
    return instance;
}


int GameProcessing::getColor(int x, int y) {
    return board[x][y];
}

int GameProcessing::nextMove(int col) {
    if(board[0][col] != 0) {
        std::cout << board[0][col] << std::flush;
        return 1;
    }
    for(auto i = board.size()-1; i >= 0 ; --i){
        if(board[i][col] == 0) {
            board[i][col] = currentTurn;
            currentTurn = (currentTurn == 1) ? 2 : 1;
            return 0;

        }

    }
    return 1;
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
