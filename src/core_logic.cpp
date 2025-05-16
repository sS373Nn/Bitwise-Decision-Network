#include "core_logic.hpp"

uint64_t OUTPUT_VALUE = 0;

const std::unordered_map<OperationType, std::function<void(uint64_t&, const uint8_t&)>> operation_map = {
    {OperationType::AND, [](uint64_t &input, const uint8_t &mask) {return input &= mask;}},
    {OperationType::OR, [](uint64_t &input, const uint8_t &mask) {return input |= mask;}}
};

OperationNode::OperationNode(uint8_t offset, uint8_t section_size, uint8_t mask, OperationType operation, uint8_t shiftAmount) : offset(offset * section_size), section_size(section_size), mask(mask), operation(operation), shiftAmount(shiftAmount) {
    output = &OUTPUT_VALUE;
};

void OperationNode::apply_operation_node(const uint64_t &input){
    uint64_t input_section = ((((0b1ULL << section_size) - 1) << offset) & input) >> offset;
    operation_map.at(operation)(input_section, mask);
    *output |= (input_section << offset);
}
