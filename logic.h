#include "board.h"

bool left_diagonal(const Board& b); // checks left diagonal win condition of a board
bool right_diagonal(const Board& b); // checks right diagonal win condition of a board
bool horizontal(const Board& b); // check horizontal win condition of a board
bool vertical(const Board& b); // check vertical win condition of a board