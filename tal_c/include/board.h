#ifndef BOARD_H
#define BOARD_H

#define BOARD_SIZE 8

enum Piece { EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING };
enum Color { NONE, WHITE, BLACK };


typedef struct {
    enum Piece piece;
    enum Color color;
} Square;

typedef struct {
    Square board[BOARD_SIZE][BOARD_SIZE];
} ChessBoard;


void initializeBoard(ChessBoard *chessBoard);
void printBoard(ChessBoard *chessBoard);


#endif



