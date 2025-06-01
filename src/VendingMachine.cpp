#include "VendingMachine.hpp"
#include "NoMoneyState.hpp"
#include "HasMoneyState.hpp"
#include "SoldState.hpp"
#include <iostream>
VendingMachine::VendingMachine()
    : state_(std::make_unique<NoMoneyState>()) {}

void VendingMachine::insertCoin() {
    state_->insertCoin(*this);
}
void VendingMachine::pressButton() {
    state_->pressButton(*this);
}
void VendingMachine::setState(StatePtr newState) {
    state_ = std::move(newState);
}
void VendingMachine::dispense() {
    std::cout << "Dispensing product...\n";
    setState(std::make_unique<NoMoneyState>());
}
void VendingMachine::printState() const {
    std::cout << "[VendingMachine State] ";
    if (dynamic_cast<const NoMoneyState*>(state_.get())) std::cout << "NoMoneyState\n";
    else if (dynamic_cast<const HasMoneyState*>(state_.get())) std::cout << "HasMoneyState\n";
    else if (dynamic_cast<const SoldState*>(state_.get())) std::cout << "SoldState\n";
    else std::cout << "Unknown\n";
}
