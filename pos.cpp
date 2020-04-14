#include "pos.h"
using namespace std;

void error(const string& msg) { // error function
    cerr << msg << endl;
    exit(1);
}

Pos::Pos(int xx, int yy, int sz) :x{xx}, y{yy}, board_size{sz} { // pos constructor
    if (xx < 0 || yy < 0 || xx >= sz || yy >= sz) { // checks if pos is out of bounds
        throw Exception();
    }
}