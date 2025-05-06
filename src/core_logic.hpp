#ifndef CORE_LOGIC_H
#define CORE_LOGIC_H

#include <iostream> //move to test_file if not needed here
#include <cstdint>
#include <unordered_map>
#include <functional>
#include <vector>
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

struct Operation_Node{
    //Can use std::unordered_set<uint8_t> to determine if we've already used a mask or not
    //std::unoredered_set too clunky for lager number of nodes -> std::bitset instead
    uint8_t mask;
    uint8_t mask_index;
    uint8_t step; //MUST be an odd number between 1-255 inclusive
    std::vector<uint64_t> *mask_vector;
    std::bitset<256> used_mask_memory;
    
    //Pick op at random?
    OperationType operation;

    //Should be tied to SHIFT iff op == SHIFT
    uint8_t shiftAmount;

    //Retry operation with new values
    //Initialize to true
    //Set to false on acceptance
    bool retry;

    Operation_Node(uint8_t mask, OperationType operation, uint8_t shiftAmount);
};

//std::unorder_map for lambda operation calls
extern const std::unordered_map<OperationType, std::function<void(uint8_t&, const uint8_t&)>> operation_map;

//Create our mask pool
//For efficiency, we build our pool as a vector of uint64_t
//Each mask is only uint8_t, however building this way should allow us more long term efficiency by sharing cache hits
const std::vector<uint64_t> create_mask_pool();

//Choose our mask and check it off in our applied_masks bitset
void pick_mask(uint8_t &mask, uint8_t &mask_index, std::bitset<256> &applied_masks_memory, const uint8_t &step, const std::vector<uint64_t> &mask_pool);

#endif
