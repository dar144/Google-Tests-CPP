#include <gtest/gtest.h>
#include "TicTacToe.hpp"







// Unit Test
TEST(IsMoveValid, TestRangeAndEmptyness)
{
    // Arrange
    char board[3][3] = {
        {'X', '1', '2'},
        {'3', 'O', '5'},
        {'6', '7', 'X'}};
    TicTacToe game(board);
    
    // Act
    // empty

    // Assert
    ASSERT_EQ(game.IsMoveValid(0), false);
    ASSERT_EQ(game.IsMoveValid(1), true);
    ASSERT_EQ(game.IsMoveValid(15), false);
}












// Integration Test
TEST(IsWon, TestWinningSequences)
{
    // Arrange
    char board[3][3] = {
        {'X', 'O', '2'},
        {'O', 'X', '5'},
        {'6', '7', 'X'}};

    // Act
    TicTacToe game(board);

    // Assert
    int currentPlayer = game.player;

    ASSERT_EQ(game.IsWonInt(), currentPlayer);
}









int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}