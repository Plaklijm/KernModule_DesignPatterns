#include "InputHandler.h"

#include <cassert>
#include "ICommand.h"

InputHandler::InputHandler()
{
    numPending = 0;
    head = 0;
    tail = 0;
}

void InputHandler::Bind(int _key, ICommand* _command)
{
    commands[_key] = _command;
}

void InputHandler::EnqueueEvents(int _key)
{
    // check if commands has a valid key otherwise return
    if (!commands.count(_key)) { return; }
    
    assert((tail + 1) % maxPending != head);
    
    pending[tail].key = _key;
    pending[tail].command = commands[_key];
    auto currentTime = std::chrono::duration_cast<std::chrono::milliseconds>(
       std::chrono::steady_clock::now().time_since_epoch());
    pending[tail].time = static_cast<float>(currentTime.count());
    
    tail = (tail + 1) % maxPending;
}

void InputHandler::ProcessInput(StateContext* ctx)
{
    if (head == tail) { return; }

    /// VERY BUGGY AND BAD CODE OVERALL, I THOUGHT THIS WOULD MAKE IT WORK BUT IT DOESNT
    /// I'LL LEAVE IT IN HERE JUST TO SHOW THAT I TRIED
    float oldTime = pending[head].time;
    auto newTime = std::chrono::duration_cast<std::chrono::milliseconds>(
   std::chrono::steady_clock::now().time_since_epoch());
    auto timeDiff = oldTime - static_cast<float>(newTime.count());
    
    // Check if the command's time is smaller than the maximum allowed time
    if (timeDiff < maxAllowedTime)
    {
        // Execute the command
        pending[head].command->Execute(ctx);
    }
    else
    {
        printf("\nCommand with time %f is too old and will be discarded.\n", timeDiff);
    }
    pending[head].command->Execute(ctx);
    head = (head + 1) % maxPending;
}

InputHandler::~InputHandler()
{
    // Delete all command pointers    
    for (auto iter = commands.begin(); iter != commands.end(); iter++)
        delete iter->second;
}
