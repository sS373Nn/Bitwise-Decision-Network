#include "core_logic.hpp"

Operation_Node::Operation_Node(uint8_t mask, OperationType operation, uint8_t shiftAmount) : mask(mask), operation(operation), shiftAmount(shiftAmount), retry(true) {};

const std::unordered_map<OperationType, std::function<void(uint8_t&, const uint8_t&)>> operation_map {
    {OperationType::AND, [](uint8_t &input, const uint8_t &mask) {return input &= mask;}},
    {OperationType::OR, [](uint8_t &input, const uint8_t &mask) {return input |= mask;}},
    {OperationType::XOR, [](uint8_t &input, const uint8_t &mask) {return input ^= mask;}},
    {OperationType::SHIFT_LEFT, [](uint8_t &input, const uint8_t &amount) {return input <<= (amount & 0x07);}},
    {OperationType::SHIFT_RIGHT, [](uint8_t &input, const uint8_t &amount) {return input >>= (amount & 0x07);}}, //Caps our shifts to a max of 7 regardless of input
    {OperationType::NOT, [](uint8_t &input, const uint8_t &unused) {return input = ~input;}},
    {OperationType::NONE, [](uint8_t &input, const uint8_t &unused) {return input;}}
};

//Create our mask pool
//For efficiency, we build our pool as a vector of uint64_t
//Each mask is only uint8_t, however building this way should allow us more long term efficiency by sharing cache hits
const std::vector<uint64_t> create_mask_pool(){
    std::vector<uint64_t> mask_vector;
    
    uint8_t mask = 0;

    for(int j = 0; j < 32; j++){
      uint64_t packed_mask = 0;
      
      for(int i = 0; i < 8; i++){
          packed_mask |= static_cast<uint64_t>(mask) << (i * 8);
          mask++;
      }
      
      mask_vector.push_back(packed_mask);
    }
    
    return mask_vector;
}

//Choose our mask and check it off in our applied_masks bitset
void pick_mask(uint8_t &mask, std::bitset<256> &applied_masks, const std::vector<uint64_t> &mask_pool){
    
}
