#include "core_logic.hpp"

template<typename T>
OperationNode<T>::OperationNode(uint8_t offset, uint8_t mask, uint8_t step, OperationType operation, uint8_t shiftAmount) : offset(offset << 3), mask(mask), step(step |= 0b00000001), operation(operation), shiftAmount(shiftAmount & 0x07), retry(true) {
    //Offset * 8 == location in output
    //Offset is right to left I.E. bit #64 for a uint64_t == bit #0
    //Offset set properly in constructor. DO NOT *8, ALREADY DONE

    //step |= 0b00000001
    //Included check to ensure step is odd
    //However, this doesn't let us keep a step of 0

    //shiftAmount & 0x07
    //Caps shift to 7, prevents wiping all bits out of an 8 bit range

    output = &output_value;
};

template<typename T>
//Apply our OperationNode to our input
//Can pass the full uint*_t &input and take the uint8_t input_section using offset
void apply_operation_node(const OperationNode<T> &OpNode, const T &input){
    uint8_t input_section = (input >> OpNode.offset) & 0b11111111; //Use | 0?
    operation_map.at(OpNode.operation)(input_section, OpNode.mask);
    *OpNode.output |= (static_cast<T>(input_section) << OpNode.offset);
}
