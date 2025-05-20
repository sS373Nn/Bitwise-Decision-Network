#include "NodeSet.hpp"

NodeSet::NodeSet(uint8_t input_size, uint8_t section_size, uint8_t active_nodes_per_operation) : input_size(input_size), section_size(section_size), active_nodes_per_operation(active_nodes_per_operation) {
    OperationNode NONENode;
    nodes.push_back(NONENode);
}

std::vector<OperationNode> NodeSet::get_nodes(){
    return nodes;
}
