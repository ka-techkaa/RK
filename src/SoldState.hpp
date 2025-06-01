#pragma once
#include "State.hpp"
class SoldState : public State {
public:
    void insertCoin(VendingMachine& vm) override;
    void pressButton(VendingMachine& vm) override;
};
