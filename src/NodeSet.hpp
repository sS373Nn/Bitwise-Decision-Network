#ifndef NODESET_H
#define NODESET_H

#include "OpNode.hpp"

class NodeSet{
public:
    NodeSet(uint8_t operation_bitwise = 0, uint8_t input_size = 1, uint8_t section_size = 1, uint8_t active_nodes_per_input = 1);

    std::vector<OperationNode> get_nodes();
    void set_node_offset(const int &node, const uint8_t &new_offset);
    void set_node_mask(const int &node, const uint8_t &new_mask);
    void apply(const uint64_t &input, const std::vector<uint8_t> &offset_vector);

private:
    std::vector<OperationNode> nodes;
    uint8_t operation_bitwise;
    uint8_t input_size;
    uint8_t section_size;
    uint8_t active_nodes_per_input;
};

//Create OperationNodes
void create_nodes(std::vector<OperationNode> &nodes, const uint8_t &operation_bitwise, const uint8_t &section_size);

#endif

//Create a NodeSet that uses each possible operation and only calls the needed nodes on an execution?
//Create custom NodeSet that ONLY uses nodes set by user and OperationType::NONE nodes to take up slack?
