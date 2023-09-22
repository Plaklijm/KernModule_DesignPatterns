#include "IdleState.h"

void IdleState::EnterState(StateContext& context)
{
    printf("Enter Idle State\n");
}

void IdleState::UpdateState(StateContext& context)
{
    printf("\rUpdate Idle State");
}

void IdleState::ExitState(StateContext& context)
{
    printf("\nExit Idle State");
}
