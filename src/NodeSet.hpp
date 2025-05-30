#ifndef NODESET_H
#define NODESET_H

#include "OperationNode.hpp"

class NodeSet{
public:
    NodeSet(uint8_t operation_bitwise = 0, uint8_t input_size = 1, uint8_t section_size = 1, uint8_t active_nodes_per_input = 1, uint64_t output = 0ULL);

    std::vector<OperationNode> get_nodes();
    uint64_t get_output();
    void set_node_mask(const int &node, const uint8_t &new_mask);
    void zero_output_section(const uint8_t &offset);
    void apply(const uint64_t &input, const uint64_t &active_node_sections);

private:
    std::vector<OperationNode> nodes;
    uint8_t operation_bitwise;
    uint8_t input_size; //Number of bits used in uint64_t input
    uint8_t section_size; //Divisions of input to be manipulated
    uint8_t active_nodes_per_input;
    uint64_t output;
};

//Create OperationNodes
void create_nodes(std::vector<OperationNode> &nodes, const uint8_t &operation_bitwise, const uint8_t &section_size);

#endif

//Create a NodeSet that uses each possible operation and only calls the needed nodes on an execution?
//Create custom NodeSet that ONLY uses nodes set by user and OperationType::NONE nodes to take up slack?
