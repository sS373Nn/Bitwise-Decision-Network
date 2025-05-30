#ifndef OPERATIONNODE_H
#define OPERATIONNODE_H

#include "OperationType.hpp"

#include <iostream> //move to test_file if not needed here
#include <cstdint>
#include <unordered_map>
#include <functional>

extern const std::unordered_map<OperationType, std::function<void(uint64_t&, const uint8_t&)>> operation_map;

struct OperationNode{
    uint8_t mask;
    uint8_t shiftAmount; //set iff op == shift
    uint8_t section_size; //allow user to modify the chunks of input upon which each node operates.
    OperationType operation;

    bool accept; //Change to 'pass' to disable Node

    OperationNode();
    //OperationNode(uint8_t offset, uint8_t section_size = 1, uint8_t mask = 0, OperationType operation = OperationType::NONE, uint8_t shiftAmount = 0);
    OperationNode(uint8_t section_size, OperationType operation = OperationType::NONE, uint8_t mask = 0, uint8_t shiftAmount = 0);
    void apply_operation_node(const uint64_t &input, const uint8_t &offset, uint64_t &output);
};

#endif
