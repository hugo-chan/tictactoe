#ifndef _POS_
#define _POS_

#include <string>
#include <iostream>

void error(const std::string& msg);

struct Pos { // implemenation of position, how to index the board
    class Exception{}; // add an exception so can throw instead of calling error
    int x; // row
    int y; // column
    int board_size;

    Pos() {}; // default constructor
    Pos(int xx, int yy, int sz);
};

#endif