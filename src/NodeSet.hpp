#ifndef NODESET_H
#define NODESET_H

#include "OpNode.hpp"

class NodeSet{
public:
    NodeSet(uint8_t operation_bitwise = 0, uint8_t input_size = 0, uint8_t section_size = 0, uint8_t active_nodes_per_operation = 0);

    std::vector<OperationNode> get_nodes();

private:
    std::vector<OperationNode> nodes;
    uint8_t operation_bitwise;
    uint8_t input_size;
    uint8_t section_size;
    uint8_t active_nodes_per_operation;
};

//Create OperationNodes
void create_nodes(std::vector<OperationNode> &nodes, const uint8_t &operation_bitwise, const uint8_t &section_size);

#endif

//Create a NodeSet that uses each possible operation and only calls the needed nodes on an execution?
//Create custom NodeSet that ONLY uses nodes set by user and OperationType::NONE nodes to take up slack?
