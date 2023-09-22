#include "MoveState.h"
#include "StateContext.h"

void MoveState::EnterState(StateContext& context)
{
    printf("Enter Move State\n");
}

void MoveState::UpdateState(StateContext& context)
{
    printf("\rUpdate Move State");
    if (context.isSprinting)
    {
        printf("Sprinting");
    }
}

void MoveState::ExitState(StateContext& context)
{
    printf("\nExit Move State");
    context.isSprinting = false;
}
