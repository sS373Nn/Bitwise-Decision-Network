#include "core_logic.hpp"

Operation_Node::Operation_Node(uint8_t mask, uint8_t pattern, OperationType operation, uint8_t shiftAmount) : mask(mask), pattern(pattern), operation(operation), shiftAmount(shiftAmount) {};

const std::unordered_map<OperationType, std::function<void(uint8_t&, const uint8_t&)>> operation_map {
    {OperationType::AND, [](uint8_t &input, const uint8_t &mask) {return input &= mask;}},
    {OperationType::OR, [](uint8_t &input, const uint8_t &mask) {return input |= mask;}},
    {OperationType::XOR, [](uint8_t &input, const uint8_t &mask) {return input ^= mask;}},
    {OperationType::SHIFT_LEFT, [](uint8_t &input, const uint8_t &amount) {return input <<= (amount & 0x07);}},
    {OperationType::SHIFT_RIGHT, [](uint8_t &input, const uint8_t &amount) {return input >>= (amount & 0x07);}},
    {OperationType::NOT, [](uint8_t &input, const uint8_t &unused) {return input = ~input;}}
};
