#pragma once
#include "State.h"

class JumpState : public State
{
public:
    ~JumpState() override{}
    
    void EnterState(StateContext& context) override;
    void UpdateState(StateContext& context) override;
    void ExitState(StateContext& context) override;
};
