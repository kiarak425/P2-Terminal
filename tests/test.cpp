#define CATCH_CONFIG_MAIN 
#include "catch2/catch.hpp"
#include "include/computron.h"
#include "src/computron.cpp"





TEST_CASE("Testing computron opCodes", "[test1]") {
    REQUIRE(opCodeToCommand(11) == Command::write);
    REQUIRE(opCodeToCommand(10) == Command::read);
    REQUIRE(opCodeToCommand(21) == Command::store);
    REQUIRE(opCodeToCommand(30) == Command::add);
    REQUIRE(opCodeToCommand(31) == Command::subtract);
    REQUIRE(opCodeToCommand(32) == Command::divide);
    REQUIRE(opCodeToCommand(33) == Command::multiply);
    REQUIRE(opCodeToCommand(40) == Command::branch);
    REQUIRE(opCodeToCommand(41) == Command::branchNeg);
    REQUIRE(opCodeToCommand(42) == Command::branchZero);
    REQUIRE(opCodeToCommand(43) == Command::halt);

    
  
}


TEST_CASE("Testing computron excute", "[test2]") {
    REQUIRE(validWord(1001) == true);
    REQUIRE(validWord(1301) == true);
    REQUIRE(validWord(1001) == true);
    REQUIRE(validWord(2001) == true);
    REQUIRE(validWord(4561) == true);
    REQUIRE(validWord(-9091) == true);
    REQUIRE(validWord(22222) == false);
  
}
