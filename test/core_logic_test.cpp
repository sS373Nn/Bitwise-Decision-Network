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
    //Expected output for AND DONE
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
    //Expected output for OR DONE
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
    //Expected output for XOR DONE
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
    //Expected output for SHIFT_LEFT DONE
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
    //Expected output for SHIFT_RIGHT DONE
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
    //Expected output for NOT DONE
    if(input == 0b11010101){
        std::cout << "\noperation NOT passed\n";
        number_of_tests_passed++;
    }else{
        std::cout << "\noperation NOT failed\n";
        number_of_tests_failed++;
    }

    input = 0b00101010;
    op = OperationType::NONE;

    operation_map.at(op)(input, mask);

    number_of_tests++;
    //Expected output for NONE DONE
    if(input == 0b00101010){
        std::cout << "\noperation NONE passed\n";
        number_of_tests_passed++;
    }else{
        std::cout << "\noperation NONE failed\n";
        number_of_tests_failed++;
    }

    //END BIT OPERATIONS


    //BIT MASK POOL DONE

    std::vector<uint64_t> test_mask_pool = create_mask_pool();

    number_of_tests++;
    //Expected size
    if(test_mask_pool.size() == 32){
        std::cout << "\nmask pool size correct\n";
        number_of_tests_passed++;
    }else{
        std::cout << "\nmask pool size incorrect\n";
        number_of_tests_failed++;
    }

    uint64_t index0 = 0x0706050403020100;
    uint64_t index1 = 0x0F0E0D0C0B0A0908;
    uint64_t index31 = 0xFFFEFDFCFBFAF9F8;

    number_of_tests++;
    //Expected value of index 0, 1 and 31
    //Break into three tests
    if(test_mask_pool[0] == index0 && test_mask_pool[1] == index1 && test_mask_pool[31] == index31){
        std::cout << "\nexpected values correct\n";
        number_of_tests_passed++;
    }else{
        std::cout << "\nexpected values incorrect\n";
        number_of_tests_failed++;
    }

    //END BIT MASK POOL

    
    //MASK GENERATION

    //From an unmarked mask_memory location, generate a valid uint8_t mask from test_mask_pool
    
    //Mask_pool already created above as 'test_mask_pool'
    std::bitset<256> marked_mask_memory;
    uint8_t mask;

    

    //END MASK GENERATION

    //FINAL TEST STATEMENT
    std::cout << "\n\nNUMBER OF TESTS: " << number_of_tests << "\nNUMBER OF TESTS PASSED: " << number_of_tests_passed << "\nNUMBER OF TESTS FAILED: " << number_of_tests_failed << std::endl;

    return 0;
}
