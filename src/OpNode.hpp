#ifndef OPNODE_H
#define OPNODE_H

#include "OperationType.hpp"

#include <iostream> //move to test_file if not needed here
#include <cstdint>
#include <unordered_map>
#include <functional>

//Set to uint64_t for now, can be changed to larger or smaller value as input size varies
extern uint64_t OUTPUT_VALUE;

extern const std::unordered_map<OperationType, std::function<void(uint64_t&, const uint8_t&)>> operation_map;

struct OperationNode{
    uint8_t mask;
    uint8_t shiftAmount; //set iff op == shift
    uint8_t offset;
    uint8_t section_size; //allow user to modify the chunks of input upon which each node operates.
    OperationType operation;
    
    //Place modified bits into the output at offset
    uint64_t *output;
    bool accept; //Change to 'pass' to disable Node

    OperationNode();
    OperationNode(uint8_t offset, uint8_t section_size = 1, uint8_t mask = 0, OperationType operation = OperationType::NONE, uint8_t shiftAmount = 0);
    void apply_operation_node(const uint64_t &input);
};

#endif
