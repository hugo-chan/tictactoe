#include "logic.h"

bool left_diagonal(const Board& b) { // check left diagonal win condition
    char start = b.get_entry(Pos(0, 0, b.get_size()));
    for (int i = 1; i < b.get_size(); i++) { 
        char cell = b.get_entry(Pos(i, i, b.get_size())); 
        if (cell == ' ' || cell != start) return false;
    }
    return true; // all elements are the same
}

bool right_diagonal(const Board& b) { // check right diagonal win condition
    char start = b.get_entry(Pos(0, b.get_size()-1, b.get_size()));
    for (int i = 1; i < b.get_size(); i++) { 
        char cell = b.get_entry(Pos(i, b.get_size()-1-i, b.get_size()));
        if (cell = ' ' || cell != start) return false;
    }
    return true; // all elements are the same
}

bool horizontal(const Board& b) { // check horizontal win condition
    bool row_success;
    for (int i = 0; i < b.get_size(); i++) { // go through each row
        row_success = 1;
        char start = b.get_entry(Pos(i, 0, b.get_size()));
        for (int j = 1; j < b.get_size(); j++) { // check within each row
            char cell = b.get_entry(Pos(i, j, b.get_size()));
            if (cell == ' ' || cell != start) {
                row_success = 0; // row failed
                break;
            }
        }
        if (row_success) return true; // row_success was never modified
    } 
    return false; // all rows had row_success = 0, so fail
}

bool vertical(const Board& b) { // check vertical win condition
    bool col_success;
    for (int i = 0; i < b.get_size(); i++) { // go through each col
        col_success = 1;
        char start = b.get_entry(Pos{0, i, b.get_size()});
        for (int j = 1; j < b.get_size(); j++) { // check within each col
            char cell = b.get_entry(Pos(j, i, b.get_size())) != start;
            if (cell == ' ' || cell != start) {
                col_success = 0; // column failed
                break;
            }
        }
        if (col_success) return true; // col_success was never modified
    }
    return false; // all cols had col_success = 0, so fail
}