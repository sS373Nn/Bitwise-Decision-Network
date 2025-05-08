#include "core_logic.hpp"

OperationNode::OperationNode(uint8_t mask, uint8_t step, OperationType operation, uint8_t shiftAmount) : mask(mask), step(step), operation(operation), shiftAmount(shiftAmount), retry(true) {
    //Include check to ensure step is odd
    //However, this doesn't let us keep a step of 0
    step |= 0b00000001;
};

const std::unordered_map<OperationType, std::function<void(uint8_t&, const uint8_t&)>> operation_map {
    {OperationType::AND, [](uint8_t &input, const uint8_t &mask) {return input &= mask;}},
    {OperationType::OR, [](uint8_t &input, const uint8_t &mask) {return input |= mask;}},
    {OperationType::XOR, [](uint8_t &input, const uint8_t &mask) {return input ^= mask;}},
    {OperationType::SHIFT_LEFT, [](uint8_t &input, const uint8_t &amount) {return input <<= (amount & 0x07);}},
    {OperationType::SHIFT_RIGHT, [](uint8_t &input, const uint8_t &amount) {return input >>= (amount & 0x07);}}, //Caps our shifts to a max of 7 regardless of input
    {OperationType::NOT, [](uint8_t &input, const uint8_t &unused) {return input = ~input;}},
    {OperationType::NONE, [](uint8_t &input, const uint8_t &unused) {return input;}}
};

//Iterates through all possible masks from 0-255 one step at a time
//Step MUST be an odd int between 1-255 inclusive
void update_mask(uint8_t &mask, const uint8_t &step){
    mask += step;
}

//Decouple or remove marking the applied_mask_memory?
//Could return a bool to mark success or failure?
//Use to determine valid mask
//Maybe pbr mask so we can increment until a valid mask is found?
void mark_mask_in_memory(std::bitset<256> &applied_masks_memory, const uint8_t &mask){
    //For now, just set the indicated bit
    //Can also check to see if all masks have been used
    //Can check to see if the current mask has been used
    //If so, can increment mask to an unused mask
    //Can reset the bitset if ALL masks have been used and indicate this as a break; for computation
    applied_masks_memory.set(mask);
}

//Apply our OperationNode to our input
void apply_operation_node(const OperationNode &OpNode, uint8_t &input){
    operation_map.at(OpNode.operation)(input, OpNode.mask);
}
