#include <inttypes.h> // Used for inutting uintN_t
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define SINGLEPLAYER false
#define MULTIPLAYER !SINGLEPLAYER
#define BOARDSIZE 4
#define PRINTMODE GRID

enum stones { EMPTY, PLAYER1, PLAYER2, STONE_SIZE };
enum printMode { GRID, FANCYGRID, STRING };
char const stoneNames[] = "-XO";
void printBoard(enum stones[BOARDSIZE][BOARDSIZE][BOARDSIZE], enum printMode);
bool setStone(size_t, size_t, size_t, enum stones);
enum stones evalWinner(enum stones[BOARDSIZE][BOARDSIZE][BOARDSIZE]);