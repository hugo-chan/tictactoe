#ifndef _board_
#define _board_

#include "pos.h"
#include <vector>


class Board // implementation of a board
{
private:
    std::vector<std::vector<char>> b;
    int size;
public:
    Board(int size = 3); // default value for size is 3
    
    // const functions that report state of board
    int get_size() const {return size;}
    char get_entry(const Pos& p) const {return b[p.x][p.y];}

    void set_entry(const Pos& p, char c) {b[p.x][p.y] = c;}
    friend std::ostream& operator<<(std::ostream& os, const Board& b);
};

#endif