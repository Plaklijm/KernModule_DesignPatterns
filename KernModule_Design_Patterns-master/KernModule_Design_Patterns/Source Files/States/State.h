#pragma once
#include <iostream>
//#include "StateContext.h"
/// Forward declaration of StateContext class so we can reference it from the State class
/// we only need the declaration of this class, not the definition


class StateContext;

class State
{
public:
    virtual ~State() {}

    /// Pure virtual Class (interface in C++)
    /// C++ supports multiple inheritance so you inherent a pure virtual class
    virtual void EnterState(StateContext& context) = 0;
    virtual void UpdateState(StateContext& context) = 0;
    virtual void ExitState(StateContext& context) = 0;
    
    // You can implement other functions you need the state to do here, an example is:
    // virtual void PhysicsUpdate(StateContext& context) = 0;
};
