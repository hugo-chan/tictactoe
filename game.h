#ifndef _GAME_
#define _GAME_

#include "board.h"
#include "logic.h"

class Game
{
private:
    Board b;
    int player;
public:
    Game(int size): player{1}, b{Board(size)} {};

    // const functions: reporting the state of the game
    int get_player() const {return player;}
    Board get_board() const {return b;}
    bool is_game_over() const;

    friend Pos prompt_move(const Game& g); // need to know which player

    // functions that change the state of the game
    void next_player();
    void place_move(const Pos& pos);
};

void create_game(); // creates and runs game

#endif