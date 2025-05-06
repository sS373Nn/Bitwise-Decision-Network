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

TEST(BitOperations, OROperation){
    uint8_t input = 0b10101010;
    uint8_t mask = 0b01010101;
    OperationType op = OperationType::OR;

    operation_map.at(op)(input, mask);
    
    EXPECT_TRUE(input == 0b11111111);
}

TEST(BitOperations, XOROperation){
    uint8_t input = 0b00101010;
    uint8_t mask = 0b01010101;
    OperationType op = OperationType::XOR;

    operation_map.at(op)(input, mask);
    
    EXPECT_TRUE(input == 0b01111111);
}

TEST(BitOperations, SHIFTLEFTOperation){
    uint8_t input = 0b00101010;
    uint8_t amount = 0b00000010;
    OperationType op = OperationType::SHIFT_LEFT;

    operation_map.at(op)(input, amount);
    
    EXPECT_TRUE(input == 0b10101000);
}

TEST(BitOperations, SHIFTRIGHTOperation){
    uint8_t input = 0b00101010;
    uint8_t amount = 0b00100010;
    OperationType op = OperationType::SHIFT_RIGHT;

    operation_map.at(op)(input, amount);
    
    EXPECT_TRUE(input == 0b00001010);
}

TEST(BitOperations, NOTOperation){
    uint8_t input = 0b00101010;
    uint8_t unused = 0;
    OperationType op = OperationType::NOT;

    operation_map.at(op)(input, unused);
    
    EXPECT_TRUE(input == 0b11010101);
}

TEST(BitOperations, NONEOperation){
    uint8_t input = 0b00101010;
    uint8_t unused = 0;
    OperationType op = OperationType::NONE;

    operation_map.at(op)(input, unused);
    
    EXPECT_TRUE(input == 0b00101010);
}

TEST(BitMaskPool, PoolSizeCheck){
    //Not a good test, rethink
    std::vector<uint64_t> test_mask_pool = create_mask_pool();

    EXPECT_EQ(test_mask_pool.size(), 32);
}

TEST(BitMaskPool, PoolIndex0Check){
    std::vector<uint64_t> test_mask_pool = create_mask_pool();
    uint64_t expected_value_at_index0 = 0x0706050403020100;

    EXPECT_EQ(test_mask_pool[0], expected_value_at_index0);
}

TEST(BitMaskPool, PoolIndex1Check){
    std::vector<uint64_t> test_mask_pool = create_mask_pool();
    uint64_t expected_value_at_index1 = 0x0F0E0D0C0B0A0908;

    EXPECT_EQ(test_mask_pool[1], expected_value_at_index1);
}

TEST(BitMaskPool, PoolIndex31Check){
    std::vector<uint64_t> test_mask_pool = create_mask_pool();
    uint64_t expected_value_at_index31 = 0xFFFEFDFCFBFAF9F8;

    EXPECT_EQ(test_mask_pool[31], expected_value_at_index31);
}
