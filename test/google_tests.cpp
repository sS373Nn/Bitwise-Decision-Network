#include <gtest/gtest.h>
#include "core_logic.hpp"

TEST(CanaryTest, YellowBird){
    EXPECT_TRUE(true);
}

TEST(BitOperations, ANDOperation){
    uint16_t input = 0b10101010;
    uint8_t mask = 0b01010101;
    auto op = AND_Operation<uint16_t, uint8_t>;

    op(input, mask);
    
    EXPECT_TRUE(input == 0b00000000);
}

TEST(BitOperations, OROperation){
    uint16_t input = 0b10101010;
    uint8_t mask = 0b01010101;
    auto  op = OR_Operation<uint16_t, uint8_t>;

    op(input, mask);
    
    EXPECT_TRUE(input == 0b11111111);
}

TEST(BitOperations, XOROperation){
    uint8_t input = 0b00101010;
    uint8_t mask = 0b01010101;
    auto  op = XOR_Operation<uint8_t, uint8_t>;

    op(input, mask);
    
    EXPECT_TRUE(input == 0b01111111);
}

TEST(BitOperations, SHIFTLEFTOperation){
    uint8_t input = 0b00101010;
    uint8_t amount = 0b00000010;
    auto op = SHIFT_LEFT_Operation<uint8_t, uint8_t>;

    op(input, amount);
    
    EXPECT_TRUE(input == 0b10101000);
}

TEST(BitOperations, SHIFTRIGHTOperation){
    uint8_t input = 0b00101010;
    uint8_t amount = 0b00100010;
    auto op = SHIFT_RIGHT_Operation<uint8_t, uint8_t>;

    op(input, amount);
    
    EXPECT_TRUE(input == 0b00001010);
}

TEST(BitOperations, NOTOperation){
    uint8_t input = 0b00101010;
    uint8_t unused = 0;
    auto op = NOT_Operation<uint8_t, uint8_t>;

    op(input, unused);
    
    EXPECT_TRUE(input == 0b11010101);
}

TEST(BitOperations, NONEOperation){
    uint8_t input = 0b00101010;
    uint8_t unused = 0;
    auto op = NONE_Operation<uint8_t, uint8_t>;

    op(input, unused);
    
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

TEST(OperationNodeConstruction, SetOffset){
    OperationNode<uint64_t, uint8_t> OpNode(2, 8);

    EXPECT_EQ(OpNode.offset, 16);
}

TEST(OperationNodeConstruction, SetShiftAmount){
    auto op = OR_Operation<uint64_t, uint8_t>;
    OperationNode<uint64_t, uint8_t> OpNode(2, 8, 0b00001111, op, 15);

    EXPECT_EQ(OpNode.shiftAmount, 15);
}

TEST(OperationNodeOperations, ApplyOffset0NodeToInput){
    uint64_t input = 0b01010101;
    uint64_t expected_output = 0b01011111;
    auto op = OR_Operation<uint64_t, uint8_t>;
    OperationNode<uint64_t, uint8_t> OpNode(0, 8, 0b00001111, op);

    OpNode.apply_operation_node(input);

    EXPECT_EQ(*OpNode.output, expected_output);
}

TEST(OperationNodeOperations, ApplyOffset2NodeToInput){
    uint64_t input = 0b0000000000000000000000000000000000000000010101010000000000000000;
    uint64_t expected_output = 0b0000000000000000000000000000000000000000010111110000000001011111;
    auto op = OR_Operation<uint64_t, uint8_t>;
    OperationNode<uint64_t, uint8_t> OpNode(2, 8, 0b00001111, op);

    OpNode.apply_operation_node(input);

    EXPECT_EQ(*OpNode.output, expected_output);
}

TEST(OperationNodeOperations, ApplyOffset5NodeToInput){
    uint64_t input = 0b0000000000000000010101010000000000000000000000000000000000000000;
    uint64_t expected_output = 0b0000000000000000010111110000000000000000010111110000000001011111;
    auto op = OR_Operation<uint64_t, uint8_t>;
    OperationNode<uint64_t, uint8_t> OpNode(5, 8, 0b00001111, op);

    OpNode.apply_operation_node(input);

    EXPECT_EQ(*OpNode.output, expected_output);
}

TEST(OperationNodeOperations, ApplyOffset7NodeToInput){
    uint64_t input = 0b0101010100000000000000000000000000000000000000000000000000000000;
    uint64_t expected_output = 0b0101111100000000010111110000000000000000010111110000000001011111;
    auto op = OR_Operation<uint64_t, uint8_t>;
    OperationNode<uint64_t, uint8_t> OpNode(7, 8, 0b00001111, op);

    OpNode.apply_operation_node(input);

    EXPECT_EQ(*OpNode.output, expected_output);
}
