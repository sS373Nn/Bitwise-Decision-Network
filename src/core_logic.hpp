#ifndef CORE_LOGIC_H
#define CORE_LOGIC_H

#include <iostream> //move to test_file if not needed here
#include <cstdint>
#include <unordered_map>
#include <functional>

enum class OperationType{
    AND,
    OR,
    XOR,
    SHIFT_LEFT,
    SHIFT_RIGHT,
    NOT
};

struct Operation_Node{
    uint8_t mask;
    uint8_t pattern;
    OperationType operation;
    uint8_t shiftAmount;
    float weight;

    Operation_Node(uint8_t mask, uint8_t pattern, OperationType operation, uint8_t shiftAmount);
};

//std::unorder_map for lambda operation calls
extern const std::unordered_map<OperationType, std::function<void(uint8_t&, const uint8_t&)>> operation_map;

#endif
