#include "NodeSet.hpp"

NodeSet::NodeSet(uint8_t operation_bitwise, uint8_t input_size, uint8_t section_size, uint8_t active_nodes_per_input) : operation_bitwise(operation_bitwise), input_size(input_size), section_size(section_size), active_nodes_per_input(active_nodes_per_input) {
    create_nodes(nodes, operation_bitwise, section_size);
}

std::vector<OperationNode> NodeSet::get_nodes(){
    return nodes;
}

void NodeSet::set_node_offset(const int &node, const uint8_t &new_offset){
    nodes[node].offset = new_offset * nodes[node].section_size;
}

void NodeSet::set_node_mask(const int &node, const uint8_t &new_mask){
    nodes[node].mask = new_mask;
}

void NodeSet::apply(const uint64_t &input, const std::vector<uint8_t> &offset_vector){
    //Use offset_vector to set offset for active nodes
    //Apply active nodes to input
    //Apply NONENodes to input
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
