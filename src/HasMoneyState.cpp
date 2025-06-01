#include "HasMoneyState.hpp"
#include "SoldState.hpp"
#include "VendingMachine.hpp"
#include <iostream>
void HasMoneyState::insertCoin(VendingMachine&) {
    std::cout << "Coin already inserted\n";
}
void HasMoneyState::pressButton(VendingMachine& vm) {
    std::cout << "Product sold\n";
    vm.setState(std::make_unique<SoldState>());
    vm.dispense();
}
