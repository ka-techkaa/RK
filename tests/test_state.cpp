#include <gtest/gtest.h>
#include "VendingMachine.hpp"
#include <sstream>
TEST(VendingMachine, StateTransitions) {
    VendingMachine vm;
    testing::internal::CaptureStdout();
    vm.insertCoin();
    vm.pressButton();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Coin inserted"), std::string::npos);
    EXPECT_NE(output.find("Product sold"), std::string::npos);
    EXPECT_NE(output.find("Dispensing product"), std::string::npos);
    vm.insertCoin();
    testing::internal::CaptureStdout();
    vm.pressButton();
    output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Product sold"), std::string::npos);
}
TEST(VendingMachine, DoubleCoin) {
    VendingMachine vm;
    vm.insertCoin();
    testing::internal::CaptureStdout();
    vm.insertCoin();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Coin already inserted"), std::string::npos);
}
