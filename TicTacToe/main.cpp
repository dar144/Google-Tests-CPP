#include <iostream>
#include "TicTacToe.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    TicTacToe game;

    int x = game.PlayGame();
    cout << "Game over. ";
    if (x == 1)
        cout << "Player 1 wins!";
    else if (x == -1)
        cout << "Player 2 wins!";
    else if (x == 0)
        cout << "Draw!";
    cout << endl;
    return 0;
}
