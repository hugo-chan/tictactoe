#include "board.h"
#include <vector>
using namespace std;

Board::Board(int sz) // constructor for board, with size default = 3
:size{sz}
{
    b.resize(size);
    for (unsigned int i = 0; i < b.size(); i++) {
        b[i].resize(size, ' '); // all initial values are ' '
    }
}

ostream& operator<<(ostream& os, const Board& b) { // print function for board
    cout << "   "; // print row numbers
    for(unsigned int i = 0; i < b.size; i++) { 
        cout << i << "   ";
    }

    cout << endl;
    for (unsigned int i = 0; i < b.size; i++) { // rows
        os << i << " "; // print row number
        for (unsigned int j = 0; j < b.size; j++) { // columns
            os << " " << b.b[i][j] << " "; // print cell
            if (j != b.size - 1) { // print column separator
                os << "|";
            } else {
                os << endl;
            }
        }
        if (i != b.size - 1) { // print row separator for all except last row
            cout << " ";
            for (unsigned int i = 0; i < b.size; i++)
                cout << " ---";
            cout << endl;
        }
    }
    return os;
}
