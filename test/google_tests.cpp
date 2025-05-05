#include <gtest/gtest.h>
#include "core_logic.hpp"

TEST(CanaryTest, YellowBird){
    EXPECT_TRUE(true);
}

TEST(BitOperations, ANDOperation){
    uint8_t input = 0b10101010;
    uint8_t mask = 0b01010101;
    OperationType op = OperationType::AND;

    operation_map.at(op)(input, mask);
    
    EXPECT_TRUE(input == 0b00000000);
}
