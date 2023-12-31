#pragma once

/// Player object
/// Can make it more abstract with an Actor/Entity base class but this is out of scope

class StateContext;
class InputHandler;


class Player
{
private:
    bool hasInput = false;
    int noInputTimer = 0;
    
    InputHandler* inputHandler;
    StateContext* stateCtx;
    
public:
    Player();
    void Update();
    void Input(int key);
    void NoInput();
};
