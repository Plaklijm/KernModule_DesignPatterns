#pragma once
#include "States/StateContext.h"

// Command interface
class ICommand
{
public:
    virtual ~ICommand() {}
    
    /// Reference is passed to make it so that you could have it more abstract
    /// When you want to implement AI it uses the same command system, only this time
    /// it executes the command on the referenced object
    virtual void Execute(StateContext* ctx) = 0;
};

//--------------------------------------------------------------------------------------------
// Command definitions
//--------------------------------------------------------------------------------------------

class MoveLeftCommand : public ICommand
{
public:
    ~MoveLeftCommand() override {}

    void Execute(StateContext* ctx) override { ctx->SwitchState(ctx->moveState); }
};

class MoveRightCommand : public ICommand
{
public:
    ~MoveRightCommand() override {}
    
    void Execute(StateContext* ctx) override { ctx->SwitchState(ctx->moveState); }
};

class JumpCommand : public ICommand
{
public:
    ~JumpCommand() override {}
    
    void Execute(StateContext* ctx) override
    {
        if (ctx->currentState != ctx->jumpState)
        {
            ctx->SwitchState(ctx->jumpState);
        }
    }
};

class SprintCommand : public ICommand
{
public:
    ~SprintCommand() override {}
    
    void Execute(StateContext* ctx) override { ctx->isSprinting = true; }
};
