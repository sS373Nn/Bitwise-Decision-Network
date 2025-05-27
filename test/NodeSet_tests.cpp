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
