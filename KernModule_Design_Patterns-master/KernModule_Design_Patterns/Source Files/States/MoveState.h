#pragma once
#include "State.h"

class MoveState : public State
{
public:
    ~MoveState() override{}
    
    void EnterState(StateContext& context) override;
    void UpdateState(StateContext& context) override;
    void ExitState(StateContext& context) override;
};
