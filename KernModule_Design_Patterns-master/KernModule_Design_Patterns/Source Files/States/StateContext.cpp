#include "StateContext.h"

#include "IdleState.h"
#include "JumpState.h"
#include "MoveState.h"
#include "State.h"

StateContext::StateContext()
{
    idleState = new IdleState();
    moveState = new MoveState();
    jumpState = new JumpState();
    Init();
}

void StateContext::Init()
{
    currentState = idleState;
    currentState->EnterState(*this);
}

void StateContext::Update()
{
   currentState->UpdateState(*this);
}

void StateContext::SwitchState(State* _newState)
{
    if (currentState != _newState)
    {
        if (currentState)
        {
            currentState->ExitState(*this);
        }
        printf("\nSwitched\n");
        currentState = _newState;
        currentState->EnterState(*this);
    }
}
