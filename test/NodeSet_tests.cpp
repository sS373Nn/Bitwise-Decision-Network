#include <gtest/gtest.h>
#include "NodeSet.hpp"

TEST(NodeSetCreation, EmptyNodeSet){
    NodeSet emptyNodeSet;

    EXPECT_EQ(1, emptyNodeSet.get_nodes().size());

    EXPECT_EQ(OperationType::NONE, emptyNodeSet.get_nodes()[0].operation);
}

TEST(NodeSetCreation, ANDNodeSet){
    uint8_t operations_bitwise = 0b00000001;
    NodeSet ANDNodeSet(operations_bitwise);

    EXPECT_EQ(OperationType::AND, ANDNodeSet.get_nodes()[1].operation);
}

TEST(NodeSetCreation, ORNodeSet){
    uint8_t operations_bitwise = 0b00000010;
    NodeSet ORNodeSet(operations_bitwise);

    EXPECT_EQ(OperationType::OR, ORNodeSet.get_nodes()[1].operation);
}

TEST(NodeSetModification, ChangeMaskForANDNode){
    uint8_t operations_bitwise = 0b00000001;
    NodeSet ANDNodeSet(operations_bitwise);
    int node_to_change = 1;
    uint8_t initial_mask = 0;
    uint8_t mask_to_use = 0b00001111;

    EXPECT_EQ(initial_mask, ANDNodeSet.get_nodes()[1].mask);

    ANDNodeSet.set_node_mask(node_to_change, mask_to_use);

    EXPECT_EQ(mask_to_use, ANDNodeSet.get_nodes()[1].mask);
}

TEST(NodeSetModification, ZeroOutputSection){
    uint8_t operations_bitwise = 0b00000001;
    NodeSet ANDNodeSet(operations_bitwise, 1, 1, 1, ~0ULL);
    uint8_t offset = 3;
    uint64_t expected_output = 0b1111111111111111111111111111111111111111111111111111111111110111;

    ANDNodeSet.zero_output_section(offset);

    EXPECT_EQ(expected_output, ANDNodeSet.get_output());
}

TEST(NodeSetApplication, ApplyORNodeSetToInput){
    uint64_t input = 0;
    uint64_t expected_output = 0b00000001;
    uint8_t operations_bitwise = 0b00000010;
    uint64_t section_zero_set_active = 0b1;
    NodeSet ORNodeSet(operations_bitwise, 20, 2);
    ORNodeSet.set_node_mask(1, 0b00000001);

    ORNodeSet.apply(input, section_zero_set_active);

    EXPECT_EQ(expected_output, ORNodeSet.get_output());
}

TEST(NodeSetApplication, ApplyANDNodeSetToInput){
    uint64_t input = 0b1111111111111111111111111111111111111111111111111111111111111111;
    uint64_t expected_output = 0b1111111111111111111111111111111111111111111111111111111111111101;
    uint8_t operations_bitwise = 0b00000001;
    uint64_t section_zero_set_active = 0b1;
    NodeSet ANDNodeSet(operations_bitwise, 20, 2);
    ANDNodeSet.set_node_mask(1, 0b11111101);

    ANDNodeSet.apply(input, section_zero_set_active);

    EXPECT_EQ(expected_output, ANDNodeSet.get_output());
}
