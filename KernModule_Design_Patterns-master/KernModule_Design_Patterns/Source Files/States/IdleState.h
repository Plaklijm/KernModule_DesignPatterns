#pragma once
#include "State.h"

class IdleState : public State
{
public:
    ~IdleState() override{}
    
    void EnterState(StateContext& context) override;
    void UpdateState(StateContext& context) override;
    void ExitState(StateContext& context) override;
};
