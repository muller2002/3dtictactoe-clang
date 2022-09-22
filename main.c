#include "main.h"

int main() {
  printf("This is 3d Tic Tac Toe. \n \n Enter Number of Players (1 or 2): \n");
  bool numOfPlayers = false;
  uint8_t inputPlayerNum = 1;
  // scanf("%" SCNu8, &inputPlayerNum);
  if (inputPlayerNum == 1)
    numOfPlayers = SINGLEPLAYER;
  else if (inputPlayerNum == 2)
    numOfPlayers = MULTIPLAYER;
  else {
    printf("Enter a valid Player Number, you entered: %hhu\n", inputPlayerNum);
    exit(EXIT_FAILURE);
  }

  enum stones board[BOARDSIZE][BOARDSIZE][BOARDSIZE] = {
      0}; // Corresponding to x,y,z Coordinates

  printBoard(board, PRINTMODE);

  // simple Game logic:
  enum stones activePlayer = PLAYER1;
  while (evalWinner(board) == EMPTY) {
    bool validInput = false;
    size_t x = SIZE_MAX, y = SIZE_MAX, z = SIZE_MAX;
    printf("Spieler %u ist am Zug. Gib deinen Zug ein (XYZ): ", activePlayer);
    while (!validInput) {
      scanf("%1zu%1zu%1zu", &x, &y, &z);
      if (x >= 0 && x < BOARDSIZE && y >= 0 && y < BOARDSIZE && z >= 0 &&
          z < BOARDSIZE && board[x][y][z] == EMPTY)
        validInput = true;
      else
        printf("Ungülitge Eingabe. Bitte versuche es erneut (XYZ): ");
    }
    printf("X:%zu, Y:%zu, Z:%zu\n\n", x, y, z);

    // Changing Player after Move logic
    activePlayer++;
    if (activePlayer == STONE_SIZE)
      activePlayer = 1;
  }

  return EXIT_SUCCESS;
}

void printBoard(enum stones board[BOARDSIZE][BOARDSIZE][BOARDSIZE],
                enum printMode mode) {
  switch (mode) {
  case GRID:
    for (size_t i = 0; i < BOARDSIZE; i++) {     // X
      for (size_t j = 0; j < BOARDSIZE; j++) {   // Z
        for (size_t k = 0; k < BOARDSIZE; k++) { // Y
          printf("%c ", stoneNames[board[i][k][j]]);
        }
        printf("\t");
      }
      printf("\n");
    }
    break;
  case FANCYGRID:
    break;
  case STRING:
    /*
     * Print in Order
     * X Y Z
     * 0 0 0
     * 1 0 0
     * 2 0 0
     * 3 0 0
     * 0 1 0
     * ....
     * 2 3 3
     * 3 3 3
     * */

    for (size_t i = 0; i < BOARDSIZE; i++) {     // Z
      for (size_t j = 0; j < BOARDSIZE; j++) {   // Y
        for (size_t k = 0; k < BOARDSIZE; k++) { // X
          printf("%c ", stoneNames[board[k][j][i]]);
        }
      }
    }
    printf("\n");
    break;
  default:
    break;
  }
}

enum stones evalWinner(enum stones board[BOARDSIZE][BOARDSIZE][BOARDSIZE]) {

  // check X rows
  for (size_t i = 0; i < BOARDSIZE; i++) {
    for (size_t j = 0; j < BOARDSIZE; j++) {
      if (board[0][i][j] == board[1][i][j] &&
          board[0][i][j] == board[2][i][j] && board[0][i][j] == board[3][i][j])
        return board[0][i][j];
    }
  }

  // check Y rows
  for (size_t i = 0; i < BOARDSIZE; i++) {
    for (size_t j = 0; j < BOARDSIZE; j++) {
      if (board[i][0][j] == board[i][1][j] &&
          board[i][0][j] == board[i][2][j] && board[i][0][j] == board[i][3][j])
        return board[i][0][j];
    }
  }

  // check Z rows
  for (size_t i = 0; i < BOARDSIZE; i++) {
    for (size_t j = 0; j < BOARDSIZE; j++) {
      if (board[i][j][0] == board[i][j][1] &&
          board[i][j][0] == board[i][j][2] && board[i][j][0] == board[i][j][3])
        return board[i][j][0];
    }
  }

  // TODO: Check for Diagonals (both Types)

  return EMPTY;
}