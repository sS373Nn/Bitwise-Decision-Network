#include <gtest/gtest.h>
#include "memory.hpp"

TEST(MemoryInitialization, AddPositiveOutputForFirstTimeLongTermMem){
    uint64_t positive_output = 0b11110000ULL;
    uint64_t expected_value = 0x7FFFFFFFFFFFFFFF;

    add_positive_outcome(positive_output);

    EXPECT_EQ(long_term_memory[positive_output], expected_value);
}

TEST(MemoryInitialization, AddPositiveOutputForFirstTimeShortTermMem){
    uint64_t positive_output = 0b11111000ULL;
    uint64_t expected_value = 0b00001000;

    add_positive_outcome(positive_output);

    EXPECT_EQ(short_term_memory[positive_output], expected_value);
}

TEST(MemoryInitialization, DeductNegativeOutputForFirstTimeLongTermMem){
    uint64_t negative_output = 0b01110000ULL;
    uint64_t expected_value = 0x7FFFFFFFFFFFFFFF;

    deduct_negative_outcome(negative_output);

    EXPECT_EQ(long_term_memory[negative_output], expected_value);
}

TEST(MemoryInitialization, DeductNegativeOutputForFirstTimeShortTermMem){
    uint64_t negative_output = 0b01111000ULL;
    uint64_t expected_value = 0b00001000;

    deduct_negative_outcome(negative_output);

    EXPECT_EQ(short_term_memory[negative_output], expected_value);
}

TEST(MemoryUpdate, AddPositiveOutputForSecondTimeLongTermMem){
    uint64_t positive_output = 0b11110000ULL;
    uint64_t expected_value = 0x7FFFFFFFFFFFFFFF;

    add_positive_outcome(positive_output);

    EXPECT_EQ(long_term_memory[positive_output], expected_value);
}

TEST(MemoryUpdate, AddPositiveOutputForSecondTimeShortTermMem){
    uint64_t positive_output = 0b11111000ULL;
    uint64_t expected_value = 0b00010000;

    add_positive_outcome(positive_output);

    EXPECT_EQ(short_term_memory[positive_output], expected_value);
}

TEST(MemoryUpdate, DeductNegativeOutputForSecondTimeLongTermMem){
    uint64_t negative_output = 0b01110000ULL;
    uint64_t expected_value = 0x7FFFFFFFFFFFFFFF;

    deduct_negative_outcome(negative_output);

    EXPECT_EQ(long_term_memory[negative_output], expected_value);
}

TEST(MemoryUpdate, DeductNegativeOutputForSecondTimeShortTermMem){
    uint64_t negative_output = 0b01111000ULL;
    uint64_t expected_value = 0b00000100;

    deduct_negative_outcome(negative_output);

    EXPECT_EQ(short_term_memory[negative_output], expected_value);
}
