#include <gtest/gtest.h>
#include "NodeSetDriver.hpp"

TEST(ApplyingNodeSets, ApplySingleORNode){
    uint64_t input = 0;
    uint64_t expected_output = 0b00000001;
    uint8_t operations_bitwise = 0b00000010;
    NodeSet ORNodeSet(operations_bitwise);
    ORNodeSet.set_node_mask(1, 0b00000001);

    
}
