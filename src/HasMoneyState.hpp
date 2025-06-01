#pragma once
#include "State.hpp"
class HasMoneyState : public State {
public:
    void insertCoin(VendingMachine& vm) override;
    void pressButton(VendingMachine& vm) override;
};
