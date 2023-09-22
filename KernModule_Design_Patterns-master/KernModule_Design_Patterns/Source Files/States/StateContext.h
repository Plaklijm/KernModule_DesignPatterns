#pragma once
class State;
class IdleState;
class MoveState;
class JumpState;

struct PlayerData;

class StateContext
{
public:
    State* currentState;

    State* idleState;
    State* moveState;
    State* jumpState;
    
    bool isSprinting = false;
    
    StateContext();
    void Init();
    void Update();
    void SwitchState(State* _newState);
};
