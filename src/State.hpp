#pragma once
#include <memory>
class VendingMachine;
struct State {
    virtual ~State() = default;
    virtual void insertCoin(VendingMachine&) = 0;
    virtual void pressButton(VendingMachine&) = 0;
};
using StatePtr = std::unique_ptr<State>;
