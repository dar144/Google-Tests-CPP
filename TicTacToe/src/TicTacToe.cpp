#include <iostream>
#include "TicTacToe.hpp"

using namespace std;

int TicTacToe::player = 1;

TicTacToe::TicTacToe()
{
    for (int i = 0; i < 9; i++)
        board[i / 3][i % 3] = '0' + i;
}

TicTacToe::TicTacToe(char newBoard[3][3])
{
    for (int i = 0; i < 9; i++)
        board[i / 3][i % 3] = newBoard[i / 3][i % 3];
}

void TicTacToe::Draw()
{
    system("clear"); // system("cls") for Windows
    cout << "Tic Tac Toe v1.0" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int TicTacToe::TakeMoveFromUser()
{
    int a;
    char currentPlayer = player == 1 ? 'X' : 'O';
    cout << "Player " << currentPlayer << "\n";
    cout << "Enter your move: ";
    cin >> a;

    return a;
}

bool TicTacToe::IsMoveValid(int move)
{
    if (move < 0 || move > 8)
        return false;
    if (board[move / 3][move % 3] != '0' + move)
        return false;
    return true;
}
int TicTacToe::convertXToInt(char player)
{
    if (player == 0)
        return 0;
    return player == 'X' ? 1 : -1;
}

int TicTacToe::IsWonChar()
{
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2])
        return board[0][1];
    if (board[1][0] == board[1][1] && board[1][1] == board[1][2])
        return board[1][1];
    if (board[2][0] == board[2][1] && board[2][1] == board[2][2])
        return board[2][1];
    if (board[0][0] == board[1][0] && board[1][0] == board[2][0])
        return board[1][0];
    if (board[0][1] == board[1][1] && board[1][1] == board[2][1])
        return board[1][1];
    if (board[0][2] == board[1][2] && board[1][2] == board[2][2])
        return board[1][2];
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[1][1];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[1][1];
    return 0;
}
int TicTacToe::IsWonInt()
{
    char c = IsWonChar();
    return convertXToInt(c);
}
bool TicTacToe::IsDraw()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'O' && board[i][j] != 'X')
                return false;
    return true;
}

void TicTacToe::TogglePlayer()
{
    player *= -1;
}

void TicTacToe::MakeMove(int move)
{
    if (IsMoveValid(move))
    {
        board[move / 3][move % 3] = player == 1 ? 'X' : 'O';
    }
}

int TicTacToe::PlayGame()
{
    int move;
    int counter = 0;
    while (IsWonInt() == 0 && !IsDraw())
    {
        Draw();
        move = TakeMoveFromUser();

        MakeMove(move);
        TogglePlayer();
    }
    if (IsDraw())
    {
        return 0;
    }
    return player * -1;
}
int TicTacToe::PlayGame(int moves_table[9])
{
    int move;
    int counter = 0;
    while (IsWonInt() == 0 && !IsDraw())
    {

        move = moves_table[counter++];

        MakeMove(move);
        TogglePlayer();
    }
    if (IsDraw())
    {
        return 0;
    }
    return player * -1;
}