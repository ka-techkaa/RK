#include "NoMoneyState.hpp"
#include "HasMoneyState.hpp"
#include "VendingMachine.hpp"
#include <iostream>
void NoMoneyState::insertCoin(VendingMachine& vm) {
    std::cout << "Coin inserted\n";
    vm.setState(std::make_unique<HasMoneyState>());
}
void NoMoneyState::pressButton(VendingMachine&) {
    std::cout << "Insert a coin first\n";
}
