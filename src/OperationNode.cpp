#include "OperationNode.hpp"

const std::unordered_map<OperationType, std::function<void(uint64_t&, const uint8_t&)>> operation_map = {
    {OperationType::AND, [](uint64_t &input, const uint8_t &mask) {return input &= mask;}},
    {OperationType::OR, [](uint64_t &input, const uint8_t &mask) {return input |= mask;}}
};

OperationNode::OperationNode() : OperationNode(1, OperationType::NONE, 0, 0) {};

OperationNode::OperationNode(uint8_t section_size, OperationType operation, uint8_t mask, uint8_t shiftAmount) : section_size(section_size), operation(operation), mask(mask), shiftAmount(shiftAmount) {};

void OperationNode::apply_operation_node(const uint64_t &input, const uint8_t &offset, uint64_t &output){
    uint8_t offset_by_bits = offset * section_size;
    uint64_t input_section = ((((0b1ULL << section_size) - 1) << offset_by_bits) & input) >> offset_by_bits;
    operation_map.at(operation)(input_section, mask);
    output |= (input_section << offset_by_bits);
}
