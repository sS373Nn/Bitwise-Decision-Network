#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <unordered_map>
#include <cstdint>

extern std::unordered_map<uint64_t, uint64_t> long_term_memory;
extern std::unordered_map<uint64_t, uint8_t> short_term_memory;

extern uint64_t LONG_TERM_INITIALIZATION_VALUE;
extern uint8_t SHORT_TERM_INITIALIZATION_VALUE;

void add_positive_outcome(const uint64_t &output);

void deduct_negative_outcome(const uint64_t &output);

#endif
