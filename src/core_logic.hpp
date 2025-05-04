#ifndef CORE_LOGIC_H
#define CORE_LOGIC_H

#include <iostream> //move to test_file if not needed here
#include <cstdint>
#include <unordered_map>
#include <functional>
#include <vector>

enum class OperationType{
    AND,
    OR,
    XOR,
    SHIFT_LEFT,
    SHIFT_RIGHT,
    NOT,
    NONE
};

struct Operation_Node{
    //Can use std::unordered_set<uint8_t> to determine if we've already used a mask or not
    uint8_t mask;
    
    //Pick op at random?
    OperationType operation;

    //Should be tied to SHIFT iff op == SHIFT
    uint8_t shiftAmount;

    //Assessment metric
    float weight;

    Operation_Node(uint8_t mask, OperationType operation, uint8_t shiftAmount);
};

//std::unorder_map for lambda operation calls
extern const std::unordered_map<OperationType, std::function<void(uint8_t&, const uint8_t&)>> operation_map;

//Create our mask pool
//For efficiency, we build our pool as a vector of uint64_t
//Each mask is only uint8_t, however building this way should allow us more long term efficiency by sharing cache hits
const std::vector<uint64_t> create_mask_pool();

#endif
