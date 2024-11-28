#include <iostream>
#include "GameProcessing.h"

GameProcessing::GameProcessing() {
resetBoard(true);
}


GameProcessing& GameProcessing::getInstance() {
    static GameProcessing instance;
    return instance;
}


auto GameProcessing::getColor(const int& x, const int& y) -> int {
    return board[x][y];
}

auto GameProcessing::nextMove(int col) -> int {
    if(board[0][col] != 0) {
        std::cout << board[0][col] << std::flush;
        return 1;
    }
    for(auto i = board.size()-1; i >= 0 ; --i){
        if(board[i][col] == 0) {
            board[i][col] = currentTurn;
            detectVictory(i,col);
            detectDraw();
            currentTurn = (currentTurn == 1) ? 2 : 1;
            return 0;

        }

    }
    return 1;
}

auto GameProcessing::getState() -> int {
    return gameState;
}

auto GameProcessing::getTurn() -> int {
    return currentTurn;
}


auto GameProcessing::detectVictory(const int &x,const int &y) -> void {
  auto player = board[x][y];
    if( scanLine(x, y, 0, 1, player)  // Горизонталь (вправо-влево)
            || scanLine(x, y, 1, 0, player )  // Вертикаль (вверх-вниз)
            || scanLine(x, y, 1, 1,player )  // Диагональ (слева направо)
            || scanLine(x, y, 1, -1,  player)) {
        gameState = player;
        count[player-1] += 1;
    }
}
auto GameProcessing::scanLine (const int& x, const int& y, const int& dx, const int& dy,  const int& player) -> bool {
    auto count = 0;
    auto currX = 0;
    auto currY = 0;
    for (auto i = 0; i <= 3; ++i) {
        currX = x + (dx * i);
        currY = y + (dy * i);
        if (currX >= 0 && currX < board.size() && currY >= 0 && currY < board[0].size()) {
            if (board[currX][currY] == player) count += 1;
            else break;
        }
        else break;
    }
    for (auto i = -1; i >= -3; --i) {
        currX = x + (dx * i);
        currY = y + (dy * i);
        if (currX >= 0 && currX < board.size() && currY >= 0 && currY < board[0].size()) {
            if (board[currX][currY] == player) count += 1;
            else break;
        }
        else break;
    }
    if (count >= 4) return true;
    else return false;
}
auto GameProcessing::resetBoard(bool resetCount) -> void{
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
    if(resetCount) count = {0,0};
}
auto GameProcessing::getCount(int i) -> int {
    return count[i];
}

    auto GameProcessing::detectDraw() -> void {
        if(std::find_if(board.begin(), board.end(), [](const auto& row) {
            return std::find(row.begin(), row.end(), 0) != row.end();
        }) == board.end() && gameState==0) gameState = 3;
    }

auto GameProcessing::getBoardSize() -> int{
    return board.size();
}
auto GameProcessing::getBoardSize(int row) -> int{
    return board[row].size();
}
