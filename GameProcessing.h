#pragma once

#ifndef UTP_PROJECT1_LIB_GAMEPROCESSING_H
#define UTP_PROJECT1_LIB_GAMEPROCESSING_H


#include <vector>

class GameProcessing {
private:
    int rows = 6;
    int cols = 7;
    std::vector<std::vector<int>> board;
    int currentTurn;
    std::vector<int> moveHistory;
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

    auto undoMove() -> void;

    auto setBoard(std::vector<std::vector<int>>& Iboard) -> void;

    auto detectVictory(const int& x,const int& y) -> void;

    auto scanLine (const int& x, const int& y, const int& dx, const int& dy, const int& player) -> bool;
    //bool isWinningMove(int lastCol, int lastRow);

};


#endif //UTP_PROJECT1_LIB_GAMEPROCESSING_H
