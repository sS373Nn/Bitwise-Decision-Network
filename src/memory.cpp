#include "memory.hpp"

std::unordered_map<uint64_t, uint64_t> long_term_memory;
std::unordered_map<uint64_t, uint8_t> short_term_memory;

uint64_t LONG_TERM_INITIALIZATION_VALUE = 0x7FFFFFFFFFFFFFFF;
uint8_t SHORT_TERM_INITIALIZATION_VALUE = 0b00001000;

void add_positive_outcome(const uint64_t &output){
    if(!short_term_memory.count(output)){
        //initialize new output
        short_term_memory[output] = SHORT_TERM_INITIALIZATION_VALUE;
        long_term_memory[output] = LONG_TERM_INITIALIZATION_VALUE;
    } else if(short_term_memory[output] == 0b10000000){
        //increment long_term_memory
        long_term_memory[output] += 1; //Use << 1 if less granularity needed
        short_term_memory[output] = SHORT_TERM_INITIALIZATION_VALUE;
    } else{
        short_term_memory[output] <<= 1;
    }
}

void deduct_negative_outcome(const uint64_t &output){
    if(!short_term_memory.count(output)){
        short_term_memory[output] = SHORT_TERM_INITIALIZATION_VALUE;
        long_term_memory[output] = LONG_TERM_INITIALIZATION_VALUE;
    } else if(short_term_memory[output]  == 0b00000001){
        long_term_memory[output] -= 1;
        short_term_memory[output] = SHORT_TERM_INITIALIZATION_VALUE;
    } else{
        short_term_memory[output] >>= 1;
    }
}
