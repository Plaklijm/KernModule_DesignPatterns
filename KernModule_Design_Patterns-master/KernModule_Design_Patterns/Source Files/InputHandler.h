#pragma once
#include <chrono>
#include <map>

class StateContext;
class ICommand;

struct KeyCommand
{
    int key;
    ICommand* command;
    float time;
};

class InputHandler
{
public:
    int head;
    int tail;
    static constexpr int maxPending = 50;
    const float maxAllowedTime = -50;
    int numPending;

    KeyCommand pending[maxPending]{};
    std::map<int, ICommand*> commands;

    InputHandler();
    ~InputHandler();
    
    void Bind(int key, ICommand* _command);
    void EnqueueEvents(int _key);
    void ProcessInput(StateContext* ctx);

    // The inherited class can override this function if you want other key mapping
    // virtual void MapInput() = 0;
};
