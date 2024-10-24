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


    auto getColor(int x, int y) -> int;

    auto nextMove(int col) -> int;

    auto getState() -> int;

    auto getTurn() -> int;

    auto undoMove() -> void;

    auto setBoard(std::vector<std::vector<int>>& Iboard) -> void;

    //bool isWinningMove(int lastCol, int lastRow);

};


#endif //UTP_PROJECT1_LIB_GAMEPROCESSING_H
