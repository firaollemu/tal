#include "board.h"



int main() {
    ChessBoard chessBoard;
    initializeBoard(&chessBoard);
    printBoard(&chessBoard);
    return 0;
}