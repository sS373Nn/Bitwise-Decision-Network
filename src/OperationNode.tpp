#include "core_logic.hpp"

template<typename T, typename S>
OperationNode<T, S>::OperationNode(uint8_t offset, int section_size, S mask, std::function<void(T&, const S&)> operation, S shiftAmount) : offset(offset * section_size), section_size(section_size), mask(mask), operation(operation), shiftAmount(shiftAmount), accept(false) {
    output = &output_value;
};

//This should allow NONE_Operation to work as well, but it introduces inefficiency by needing to copy each section instead of simply replacing it.
template<typename T, typename S>
void OperationNode<T, S>::apply_operation_node(const T &input){
    T input_section = ((((static_cast<T>(0b1) << section_size) - 1) << offset) & input) >> offset;
    operation(input_section, mask);
    *output |= (input_section << offset);
};
