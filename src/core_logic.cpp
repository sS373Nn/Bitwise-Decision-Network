#include "core_logic.hpp"

uint64_t output_value = 0;

const std::unordered_map<OperationType, std::function<void(uint8_t&, const uint8_t&)>> operation_map {
    {OperationType::AND, [](uint8_t &input, const uint8_t &mask) {return input &= mask;}},
    {OperationType::OR, [](uint8_t &input, const uint8_t &mask) {return input |= mask;}},
    {OperationType::XOR, [](uint8_t &input, const uint8_t &mask) {return input ^= mask;}},
    {OperationType::SHIFT_LEFT, [](uint8_t &input, const uint8_t &amount) {return input <<= (amount & 0x07);}},
    {OperationType::SHIFT_RIGHT, [](uint8_t &input, const uint8_t &amount) {return input >>= (amount & 0x07);}}, //Caps our shifts to a max of 7 regardless of input
    {OperationType::NOT, [](uint8_t &input, const uint8_t &unused) {return input = ~input;}},
    {OperationType::NONE, [](uint8_t &input, const uint8_t &unused) {return input;}}
};

//OperationNode::OperationNode(uint8_t offset, uint8_t mask, uint8_t step, OperationType operation, uint8_t shiftAmount) : offset(offset << 3), mask(mask), step(step |= 0b00000001), operation(operation), shiftAmount(shiftAmount & 0x07), retry(true) {
    //Offset * 8 == location in output
    //Offset is right to left I.E. bit #64 for a uint64_t == bit #0
    //Offset set properly in constructor. DO NOT *8, ALREADY DONE

    //step |= 0b00000001
    //Included check to ensure step is odd
    //However, this doesn't let us keep a step of 0

    //shiftAmount & 0x07
    //Caps shift to 7, prevents wiping all bits out of an 8 bit range

//    output = &output_value;
//};

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

//void apply_operation_node(const OperationNode &OpNode, const uint64_t &input){
//    uint8_t input_section = (input >> OpNode.offset) & 0b11111111; //Use | 0?
//    operation_map.at(OpNode.operation)(input_section, OpNode.mask);
//    *OpNode.output |= (static_cast<uint64_t>(input_section) << OpNode.offset);
//}
