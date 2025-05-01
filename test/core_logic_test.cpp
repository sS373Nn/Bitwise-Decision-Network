#include "../src/core_logic.hpp"

int main(){

    int number_of_tests = 0;
    int number_of_tests_passed = 0;
    int number_of_tests_failed = 0;

    if(true){
        std::cout << "Canary test successful!\n";
        number_of_tests++;
        number_of_tests_passed++;
    }


    //BIT OPERATIONS
    uint8_t input = 0b10101010;
    uint8_t mask = 0b01010101;
    OperationType op = OperationType::AND;

    operation_map.at(op)(input, mask);

    number_of_tests++;
    //Expected output for AND
    if(input == 0b00000000){
        std::cout << "\noperation AND passed\n";
        number_of_tests_passed++;
    }else{
        std::cout << "\noperation AND failed\n";
        number_of_tests_failed++;
    }

    input = 0b10101010;
    op = OperationType::OR;

    operation_map.at(op)(input, mask);

    number_of_tests++;
    //Expected output for OR
    if(input == 0b11111111){
        std::cout << "\noperation OR passed\n";
        number_of_tests_passed++;
    }else{
        std::cout << "\noperation OR failed\n";
        number_of_tests_failed++;
    }

    input = 0b00101010;
    op = OperationType::XOR;

    operation_map.at(op)(input, mask);

    number_of_tests++;
    //Expected output for XOR
    if(input == 0b01111111){
        std::cout << "\noperation XOR passed\n";
        number_of_tests_passed++;
    }else{
        std::cout << "\noperation XOR failed\n";
        number_of_tests_failed++;
    }

    input = 0b00101010;
    op = OperationType::SHIFT_LEFT;
    uint8_t amount = 0b00000010;

    operation_map.at(op)(input, amount);

    number_of_tests++;
    //Expected output for SHIFT_LEFT
    if(input == 0b10101000){
        std::cout << "\noperation SHIFT_LEFT passed\n";
        number_of_tests_passed++;
    }else{
        std::cout << "\noperation SHIFT_LEFT failed\n";
        number_of_tests_failed++;
    }

    input = 0b00101010;
    op = OperationType::SHIFT_RIGHT;
    amount = 0b00100010;

    operation_map.at(op)(input, amount);

    number_of_tests++;
    //Expected output for SHIFT_RIGHT
    if(input == 0b00001010){
        std::cout << "\noperation SHIFT_RIGHT passed\n";
        number_of_tests_passed++;
    }else{
        std::cout << "\noperation SHIFT_RIGHT failed\n";
        number_of_tests_failed++;
    }

    input = 0b00101010;
    op = OperationType::NOT;

    operation_map.at(op)(input, mask);

    number_of_tests++;
    //Expected output for NOT
    if(input == 0b11010101){
        std::cout << "\noperation NOT passed\n";
        number_of_tests_passed++;
    }else{
        std::cout << "\noperation NOT failed\n";
        number_of_tests_failed++;
    }

    std::cout << "\n\nNUMBER OF TESTS: " << number_of_tests << "\nNUMBER OF TESTS PASSED: " << number_of_tests_passed << "\nNUMBER OF TESTS FAILED: " << number_of_tests_failed << std::endl;

    return 0;
}
