#pragma once

#ifndef UTP_PROJECT1_LIB_GAMEPROCESSING_H
#define UTP_PROJECT1_LIB_GAMEPROCESSING_H


#include <vector>

class GameProcessing {
private:
   const int rows = 6;
   const int cols = 7;
    std::vector<std::vector<int>> board;
    int currentTurn;
    std::vector<int> count;
    int gameState;

    GameProcessing();

    GameProcessing(const GameProcessing&) = delete;
    GameProcessing& operator=(const GameProcessing&) = delete;

public:

    static GameProcessing& getInstance();


    auto getColor(const int& x, const int& y) -> int;

    auto nextMove(int col) -> int;

    auto getState() -> int;

    auto getTurn() -> int;

    auto detectVictory(const int& x,const int& y) -> void;

    auto detectDraw() -> void;

    auto scanLine(const int& x, const int& y, const int& dx, const int& dy, const int& player) -> bool;

    auto resetBoard(bool resetCount) -> void;

    auto getCount(int i) -> int;

    auto getBoardSize() -> int;
    auto getBoardSize(int row) -> int;

};


#endif //UTP_PROJECT1_LIB_GAMEPROCESSING_H
