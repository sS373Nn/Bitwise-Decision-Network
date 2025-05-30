#include "NodeSet.hpp"

NodeSet::NodeSet(uint8_t operation_bitwise, uint8_t input_size, uint8_t section_size, uint8_t active_nodes_per_input, uint64_t output) : operation_bitwise(operation_bitwise), input_size(input_size), section_size(section_size), active_nodes_per_input(active_nodes_per_input), output(output) {
    create_nodes(nodes, operation_bitwise, section_size);
}

std::vector<OperationNode> NodeSet::get_nodes(){
    return nodes;
}

uint64_t NodeSet::get_output(){
    return output;
}

void NodeSet::set_node_mask(const int &node, const uint8_t &new_mask){
    nodes[node].mask = new_mask;
}

void NodeSet::zero_output_section(const uint8_t &offset){
    uint64_t section_mask = ~((~(((~0ULL) >> section_size) << section_size)) << (offset * section_size));

    output &= section_mask;
}

void NodeSet::apply(const uint64_t &input, const uint64_t &active_node_sections){
    output = input;
    uint8_t active_node_mask = 0b1;
    OperationNode activeNode = nodes[1];

    for(uint8_t offset = 0; offset < (input_size / section_size); offset++){
        if((active_node_sections >> offset) & active_node_mask){
            zero_output_section(offset);
            activeNode.apply_operation_node(input, offset, output);
        }
    }

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
