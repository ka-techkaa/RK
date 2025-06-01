#include "SoldState.hpp"
#include "NoMoneyState.hpp"
#include "VendingMachine.hpp"
#include <iostream>
void SoldState::insertCoin(VendingMachine&) {
    std::cout << "Wait, already dispensing\n";
}
void SoldState::pressButton(VendingMachine&) {
    std::cout << "Already pressed, dispensing...\n";
}
