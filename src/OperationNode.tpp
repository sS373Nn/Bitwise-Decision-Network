#include "core_logic.hpp"

template<typename T>
OperationNode<T>::OperationNode(uint8_t offset, uint8_t mask, uint8_t step, OperationType operation, uint8_t shiftAmount) : offset(offset), mask(mask), step(step), operation(operation), shiftAmount(shiftAmount), retry(true) {
    //Include check to ensure step is odd
    //However, this doesn't let us keep a step of 0
    step |= 0b00000001;

    //Offset * 8 == location in output
    //Offset is right to left I.E. bit #64 for a uint64_t == bit #0
    offset <<= 3;

    output = &output_value;
};

template<typename T>
//Apply our OperationNode to our input
//Can pass the full uint*_t &input and take the uint8_t input_section using offset
void apply_operation_node(const OperationNode<T> &OpNode, const T &input){
    uint8_t input_section = (input >> OpNode.offset) & 0b11111111;
    operation_map.at(OpNode.operation)(input_section, OpNode.mask);
    *(OpNode.output) |= (static_cast<T>(input_section) << OpNode.offset);
}
