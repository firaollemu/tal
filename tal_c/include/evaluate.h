#include <stdio.h>
#include "board.h"

void initializeBoard(ChessBoard *chessBoard) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            chessBoard->board[i][j].piece = EMPTY;
            chessBoard->board[i][j].color = NONE;
        }
    }
}


// pawns
for (int i = 0; i < BOARD_SIZE; i++) {
    chessBoard->board[1][i].piece = PAWN;
    chessBoard->board[1][i].color = WHITE;
    chessBoard->board[6][i].piece = PAWN;
    chessBoard->board[6][i].color = BLACK;
}


// rook
chessBoard->board[0][0].piece = chessBoard->board[0][7].piece = ROOK;
chessBoard->board[7][0].piece = chessBoard->board[7][7].piece = ROOK;
// knight
chessBoard->board[0][1].piece = chessBoard->board[0][6].piece = KNIGHT;
chessBoard->board[7][1].piece = chessBoard->board[7][6].piece = KNIGHT;

// bishop
chessBoard->board[0][2].piece = chessBoard->board[0][5].piece = BISHOP;
chessBoard->board[7][2].piece = chessBoard->board[7][5].piece = BISHOP;

// queen
chessBoard->board[0][3].piece = QUEEN;
chessBoard->board[7][3].piece = QUEEN;

// king
chessBoard->board[0][4].piece = KING;
chessBoard->board[7][4].piece = KING;

// set the colors for the white pieces
for (int i = 0; i < BOARD_SIZE; i++) {
    chessBoard->board[0][i].color = WHITE;
}
// set the colors for the black pieces
for (int i = 0; i < BOARD_SIZE; i++) {
    chessBoard->board[7][i].color = BLACK;
}


// print the board

void printBoard(ChessBoard *chessBoard) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (chessBoard->board[i][j].color) {
                case WHITE: 
                    printf("W"); 
                    break;
                case BLACK:
                    printf("B");
                    break;
                default:
                    printf(".");
            }

            switch (chessBoard->board[i][j].piece) {
                case PAWN:
                    printf("P ");
                    break;
                case KNIGHT:
                    printf("N ");
                    break;
                case BISHOP:
                    printf("B ");
                    break;
                case ROOK:
                    printf("R ");
                    break;
                case QUEEN:
                    printf("Q ");
                    break;
                case KING:
                    printf("K ");
                    break;
                default:
                    printf(". ");

                
            }
        }
    }
}




