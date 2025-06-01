#pragma once
#include "State.hpp"
#include <iostream>
class NoMoneyState;
class HasMoneyState;
class SoldState;

class VendingMachine {
    friend class NoMoneyState;
    friend class HasMoneyState;
    friend class SoldState;
public:
    VendingMachine();
    void insertCoin();
    void pressButton();
    void setState(StatePtr);
    void dispense();
    void printState() const;
private:
    StatePtr state_;
};
