#include <gtest/gtest.h>
#include "NodeSet.hpp"

TEST(NodeSetCreation, EmptyNodeSet){
    NodeSet emptyNodeSet;

    EXPECT_EQ(1, emptyNodeSet.get_nodes().size());

    EXPECT_EQ(OperationType::NONE, emptyNodeSet.get_nodes()[0].operation);
}
