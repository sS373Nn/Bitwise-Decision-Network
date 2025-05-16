#ifndef CORE_LOGIC_H
#define CORE_LOGIC_H

#include <iostream> //move to test_file if not needed here
#include <cstdint>
#include <unordered_map>
#include <functional>
#include <vector> //Unneeded
#include <bitset>

//Set to uint64_t for now, can be changed to larger or smaller value as input size varies
extern uint64_t output_value;

enum class OperationType{
    AND,
    OR,
    XOR,
    SHIFT_LEFT,
    SHIFT_RIGHT,
    NOT,
    NONE
};

template<typename T, typename S>
const auto AND_Operation = [](T &input, const S &mask) {input &= mask;};

template<typename T, typename S>
const auto OR_Operation = [](T &input, const S &mask) {input |= mask;};

template<typename T, typename S>
const auto XOR_Operation = [](T &input, const S &mask) {input ^= mask;};

template<typename T, typename S>
const auto SHIFT_LEFT_Operation = [](T &input, const S &amount) {input <<= amount;};

template<typename T, typename S>
const auto SHIFT_RIGHT_Operation = [](T &input, const S &amount) {input >>= amount;};

template<typename T, typename S>
const auto NOT_Operation = [](T &input, const S &unused) {input = ~input;};

template<typename T, typename S>
const auto NONE_Operation = [](T &input, const S &unused) {return;};

template<typename T, typename S>
struct OperationNode{
    S mask;
    S input_section;
    S shiftAmount; //set iff op == shift

    uint8_t offset;
    int section_size; //allow user to modify the chunks of input upon which each node operates.

    std::function<void(T&, const S&)> operation;
    
    //Place modified bits into the output at offset
    T *output;
    bool accept; //Change to 'pass' to disable Node

    OperationNode(uint8_t offset = 0, int section_size = 1, S mask = 0, std::function<void(T&, const S&)> operation = NONE_Operation<T, S>, S shiftAmount = 0);
    void apply_operation_node(const T &input);
};

//Iterates through all possible masks from 0-255 one step at a time
//Step MUST be an odd int between 1-255 inclusive
void update_mask(uint8_t &mask, const uint8_t &step);

//Check to ensure our mask has not been used
void mark_mask_in_memory(std::bitset<256> &applied_masks_memory, const uint8_t &mask);

#include "OperationNode.tpp"

#endif
