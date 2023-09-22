#include "Manager.h"
#include <iostream>

#include "Player.h"

// Initialize the application (Start)
void Manager::Init()
{
    player = new Player();
}

// Close down the application
void Manager::Shutdown()
{
}

// Main Tick function (Update)
void Manager::Tick()
{
    player->Update();
}

void Manager::KeyDown(int _key)
{
    player->Input(_key);
}

void Manager::KeyUp()
{
    player->NoInput();
}
