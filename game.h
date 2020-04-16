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
    Board& get_board() {return b;}
    
    // functions that change the state of the game
    void set_player(int p) {player = p;}



    //void place_move(const Pos& pos);
};


#endif