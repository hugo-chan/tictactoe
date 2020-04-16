#include "game.h"
#include <sstream>
using namespace std;

int welcome_message() { // wecome message for game
    cout << "Welcome to tic-tac-toe!" << endl;
    cout << "To enter a move, enter two numbers where the first represents the row number and the second represents the column number" << endl;
    cout << "What board size would you like to play: ";
    int size;
    while(!(cin >> size)) {
        cout << "Invalid input. Please try again." << endl;
        cout << "What board size would you like to play: ";
    }
    return size;
}

bool is_game_over(Game& g) { // checks game state by checking win conditions
    Board b = g.get_board(); // default copy constructor is okay, because no pointers
    if (left_diagonal(b) || right_diagonal(b) || horizontal(b) || vertical(b)) return 1;
    return false;
}

Pos prompt_move(Game& g) { // prompts user to enter a position, returns valid position
    int valid_pos = 0;
    Pos p;
    while (!valid_pos) {
        cout << "Player " << g.get_player() << ", please enter your move: ";
        int row, col;
        string input;
        getline(cin, input); // using getline instead of cin to deal with excess numbers provided
        istringstream is {input};
        if (!(is >> row >> col)) {
            if (is.bad()) {
                error("prompt_move: bad input stream.");
            }
            if (is.fail()) {
                cout << "Please enter two integers separated by a space." << endl;
                continue;
            }
        }
        try{
            p = Pos(row, col, g.get_board().get_size()); // see if input corresponds to valid position
        } catch (Pos::Exception) { // position is out of bounds
            cout << "This is an invalid position. Please try again." << endl;
            continue;
        }
        if (g.get_board().get_entry(p) != ' ') {
            cout << "This position has already been filled. Please try again." << endl;
            cin.clear();
            continue;
        } else {
            valid_pos = 1;
        }
    }
    return p;
}

void place_move(Game& g, const Pos& pos) { // assumes position is valid
    if (g.get_player() == 1) {
        g.get_board().set_entry(pos, 'X');
    } else {
        g.get_board().set_entry(pos, '0');
    }
}

void next_player(Game& g) { // update player to next
    int curr = g.get_player();
    if (curr == 1) {
        g.set_player(++curr);
    } else { // player 2
        g.set_player(--curr);    }
}

void game_over_message(Game& g) { // message when game is over
    next_player(g);
    cout << "Player " << g.get_player() << " wins!" << endl;
    cout << "Thanks for playing!" << endl;
}

void create_game() { // creates a game and runs it until it's over
    int size = welcome_message();
    Game g = Game(size);
    cout << g.get_board();
    while (!(is_game_over(g))) {
        //g.place_move(prompt_move(g));
        place_move(g, prompt_move(g));
        cout << g.get_board();
        next_player(g);
    }
    game_over_message(g);
}

int main() {
    create_game();
}