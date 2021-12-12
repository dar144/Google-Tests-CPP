#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
public:
    static int player;

    TicTacToe();
    TicTacToe(char newBoard[3][3]);
    void Draw();
    int TakeMoveFromUser();
    bool IsMoveValid(int move);
    void TogglePlayer();
    int IsWonChar();
    int IsWonInt();
    int convertXToInt(char player);
    void MakeMove(int move);
    bool IsDraw();
    int PlayGame();
    int PlayGame(int moves_table[9]);

private:
    char board[3][3];
};

#endif