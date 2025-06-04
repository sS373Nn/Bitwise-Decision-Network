#include <gtest/gtest.h>
#include "TicTacToePlugin.hpp"

TEST(TicTacToeNodeInitialization, InitializeTicTacToeNodesWithPlayerOneMask){
    uint8_t expected_mask = 0b1;
    uint8_t player_one = 0b1;
    TicTacToePlugin PlayerOne(player_one);

    EXPECT_EQ(PlayerOne.get_TicTacToeNodes().get_nodes()[1].mask, expected_mask);
}

TEST(TicTacToeNodeInitialization, InitializeTicTacToeNodesWithPlayerTwoMask){
    uint8_t expected_mask = 0b10;
    uint8_t player_two = 0b10;
    TicTacToePlugin PlayerTwo(player_two);

    EXPECT_EQ(PlayerTwo.get_TicTacToeNodes().get_nodes()[1].mask, expected_mask);
}
