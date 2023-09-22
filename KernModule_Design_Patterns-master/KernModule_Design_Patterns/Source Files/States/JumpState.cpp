#include "JumpState.h"

void JumpState::EnterState(StateContext& context)
{
    printf("Enter Jump State\n");
}

void JumpState::UpdateState(StateContext& context)
{
    printf("\rUpdate Jump State");
}

void JumpState::ExitState(StateContext& context)
{
    printf("\nExit Jump State");
}
