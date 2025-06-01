#include "VendingMachine.hpp"
#include <iostream>
int main() {
    VendingMachine vm;
    vm.printState();
    vm.pressButton();
    vm.insertCoin();
    vm.printState();
    vm.insertCoin();
    vm.pressButton();
    vm.printState();
    return 0;
}
