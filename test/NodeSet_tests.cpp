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

TEST(NodeSetModification, ChangeOffsetForANDNode){
    uint8_t operations_bitwise = 0b00000001;
    NodeSet ANDNodeSet(operations_bitwise);
    int node_to_change = 1;
    uint8_t amount_to_change = 5;

    EXPECT_EQ(0, ANDNodeSet.get_nodes()[1].offset);

    ANDNodeSet.set_node_offset(node_to_change, amount_to_change);

    EXPECT_EQ(5, ANDNodeSet.get_nodes()[1].offset);
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

//TEST(NodeSetApplication, ApplyNodeSetToInput){
//    uint64_t input = 0;
//    uint64_t expected_output = 0b00000001;
//    uint8_t operations_bitwise = 0b00000010;
//    NodeSet ORNodeSet(operations_bitwise);
//    ORNodeSet.set_node_mask(1, 0b00000001);
//    std::vector<uint8_t> active_node_offset = {63};
//
//    ORNodeSet.apply(input, active_node_offset);
//
//    EXPECT_EQ(expected_output, ORNodeSet.get_nodes()[0].output);
//}
