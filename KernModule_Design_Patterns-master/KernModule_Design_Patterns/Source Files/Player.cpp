#include "Player.h"

#include <SDL_keycode.h>

#include "ICommand.h"
#include "InputHandler.h"
#include "States/StateContext.h"

Player::Player()
{
    inputHandler = new InputHandler();
    stateCtx = new StateContext();
    
    // Create instances of commands
    auto* moveLeftCommand = new MoveLeftCommand();
    auto* moveRightCommand = new  MoveRightCommand();
    auto* jumpCommand = new JumpCommand();
    auto* sprintCommand = new SprintCommand();

    // Bind commands to specific keys
    inputHandler->Bind(SDLK_a, moveLeftCommand);
    inputHandler->Bind(SDLK_d, moveRightCommand);
    inputHandler->Bind(SDLK_SPACE, jumpCommand);
    inputHandler->Bind(SDLK_LSHIFT, sprintCommand);
}

void Player::Update()
{
    stateCtx->Update();
    
    inputHandler->ProcessInput(stateCtx);

    // After a second of no input switch back to the IdleState
    if (!hasInput)
    {
        noInputTimer++;
        if (noInputTimer > 60)
        {
            stateCtx->SwitchState(stateCtx->idleState);
            noInputTimer = 0;
        }
    }
}

void Player::Input(int _key)
{
    inputHandler->EnqueueEvents(_key);
    hasInput = true;
}

void Player::NoInput()
{
    noInputTimer = 0;
    hasInput = false;
}
