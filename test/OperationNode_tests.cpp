#include <gtest/gtest.h>
#include "OperationNode.hpp"

TEST(CanaryTest, YellowBird){
    EXPECT_TRUE(true);
}

TEST(BitOperations, ANDOperation){
    uint64_t input = 0b10101010;
    uint8_t mask = 0b01010101;
    OperationType op = OperationType::AND;

    operation_map.at(op)(input, mask);
    
    EXPECT_TRUE(input == 0b00000000);
}

TEST(BitOperations, OROperation){
    uint64_t input = 0b10101010;
    uint8_t mask = 0b01010101;
    OperationType op = OperationType::OR;

    operation_map.at(op)(input, mask);
    
    EXPECT_TRUE(input == 0b11111111);
}

TEST(OperationNodeConstruction, DefaultConstructor){
    OperationNode OpNode;

    EXPECT_EQ(OpNode.operation, OperationType::NONE);
}

TEST(OperationNodeConstruction, SetShiftAmount){
    OperationNode OpNode(8, OperationType::NONE, 0b00001111, 15);

    EXPECT_EQ(OpNode.shiftAmount, 15);
}

TEST(OperationNodeOperations, ApplyOffset0NodeToInput){
    uint64_t input = 0b01010101;
    uint8_t offset = 0;
    uint64_t output = 0;
    uint64_t expected_output = 0b01011111;
    OperationType op = OperationType::OR;
    OperationNode OpNode(8, op, 0b00001111);

    OpNode.apply_operation_node(input, offset, output);

    EXPECT_EQ(output, expected_output);
}

TEST(OperationNodeOperations, ApplyOffset2NodeToInput){
    uint64_t input = 0b0000000000000000000000000000000000000000010101010000000000000000;
    uint8_t offset = 2;
    uint64_t output = 0b0000000000000000000000000000000000000000000000000000000001011111;
    uint64_t expected_output = 0b0000000000000000000000000000000000000000010111110000000001011111;
    OperationType op = OperationType::OR;
    OperationNode OpNode(8, op, 0b00001111);

    OpNode.apply_operation_node(input, offset, output);

    EXPECT_EQ(output, expected_output);
}

TEST(OperationNodeOperations, ApplyOffset5NodeToInput){
    uint64_t input = 0b0000000000000000010101010000000000000000000000000000000000000000;
    uint8_t offset = 5;
    uint64_t output = 0b0000000000000000000000000000000000000000010111110000000001011111;
    uint64_t expected_output = 0b0000000000000000010111110000000000000000010111110000000001011111;
    OperationType op = OperationType::OR;
    OperationNode OpNode(8, op, 0b00001111);

    OpNode.apply_operation_node(input, offset, output);

    EXPECT_EQ(output, expected_output);
}

TEST(OperationNodeOperations, ApplyOffset7NodeToInput){
    uint64_t input = 0b0101010100000000000000000000000000000000000000000000000000000000;
    uint8_t offset = 7;
    uint64_t output = 0b0000000000000000010111110000000000000000010111110000000001011111;
    uint64_t expected_output = 0b0101111100000000010111110000000000000000010111110000000001011111;
    OperationType op = OperationType::OR;
    OperationNode OpNode(8, op, 0b00001111);

    OpNode.apply_operation_node(input, offset, output);

    EXPECT_EQ(output, expected_output);
}
