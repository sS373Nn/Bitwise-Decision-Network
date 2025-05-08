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

TEST(BitMaskOperations, UpdateMask){
    uint8_t mask = 0b00001010;
    uint8_t step = 5;
    uint8_t expected_update = 0b00001111;

    update_mask(mask, step);

    EXPECT_EQ(mask, expected_update);
}

TEST(BitMaskOperations, UpdateMemory){
    std::bitset<256> mask_memory;
    uint8_t mask = 0b00001010;

    EXPECT_TRUE(!mask_memory[mask]);

    mark_mask_in_memory(mask_memory, mask);

    EXPECT_TRUE(mask_memory[mask]);
}

TEST(OperationNodeOperations, ApplyNodeToInput){
    uint64_t input = 0b01010101;
    uint64_t expected_output = 0b01011111;
    OperationNode<uint64_t> OpNode(0, 0b00001111, 1, OperationType::OR);

    apply_operation_node(OpNode, input);

    EXPECT_EQ(*OpNode.output, expected_output);
}
