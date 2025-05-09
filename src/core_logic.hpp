#ifndef CORE_LOGIC_H
#define CORE_LOGIC_H

#include <iostream> //move to test_file if not needed here
#include <cstdint>
#include <unordered_map>
#include <functional>
#include <vector> //Unneeded
#include <bitset>

enum class OperationType{
    AND,
    OR,
    XOR,
    SHIFT_LEFT,
    SHIFT_RIGHT,
    NOT,
    NONE
};


template<typename T>
struct OperationNode{
    //Can use std::unordered_set<uint8_t> to determine if we've already used a mask or not
    //std::unoredered_set too clunky for lager number of nodes -> std::bitset instead
    uint8_t mask; //The mask IS the index
    uint8_t step; //MUST be an odd number between 1-255 inclusive
    std::bitset<256> used_mask_memory; //Can keep if necessary later

    //Place modified bits into the output at offset
    T *output; //Change to template?
    uint8_t offset;
    
    //Pick op at random?
    OperationType operation;

    //Should be tied to SHIFT iff op == SHIFT
    //Default shiftAmount == 0
    //If op != shift, then don't input shift value
    uint8_t shiftAmount;

    //Retry operation with new values
    //Initialize to true
    //Set to false on acceptance
    bool retry;

    OperationNode(uint8_t offset = 0, uint8_t mask = 0, uint8_t step = 1, OperationType operation = OperationType::NONE, uint8_t shiftAmount = 0);
};

//std::unorder_map for lambda operation calls
extern const std::unordered_map<OperationType, std::function<void(uint8_t&, const uint8_t&)>> operation_map;

//Set to uint64_t for now, can be changed to larger or smaller value as input size varies
extern uint64_t output_value;

//Iterates through all possible masks from 0-255 one step at a time
//Step MUST be an odd int between 1-255 inclusive
void update_mask(uint8_t &mask, const uint8_t &step);

//Check to ensure our mask has not been used
void mark_mask_in_memory(std::bitset<256> &applied_masks_memory, const uint8_t &mask);

//Apply our OperationNode to our input
template<typename T>
void apply_operation_node(const OperationNode<T> &OpNode, const T &input);

#include "OperationNode.tpp"

#endif
