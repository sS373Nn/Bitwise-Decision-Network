#include "core_logic.hpp"

uint64_t output_value = 0;

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
