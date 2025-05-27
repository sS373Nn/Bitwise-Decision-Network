#include "NodeSet.hpp"

NodeSet::NodeSet(uint8_t operation_bitwise, uint8_t input_size, uint8_t section_size, uint8_t active_nodes_per_operation) : operation_bitwise(operation_bitwise), input_size(input_size), section_size(section_size), active_nodes_per_operation(active_nodes_per_operation) {
    create_nodes(nodes, operation_bitwise, section_size);
}

std::vector<OperationNode> NodeSet::get_nodes(){
    return nodes;
}

//Create OperationNodes
void create_nodes(std::vector<OperationNode> &nodes, const uint8_t &operation_bitwise, const uint8_t &section_size){
    OperationNode NONENode;
    nodes.push_back(NONENode);

    if(operation_bitwise & 0b00000001){
        OperationNode ANDNode(section_size, OperationType::AND);
        nodes.push_back(ANDNode);
    }
    
    if(operation_bitwise & 0b00000010){
        OperationNode ORNode(section_size, OperationType::OR);
        nodes.push_back(ORNode);
    }
}


//Initialize a uint64_t to create all nodes?
//I.E. all data to create the full list of nodes could be stored as a uint64_t
//Maybe later
