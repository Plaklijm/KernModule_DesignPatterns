#pragma once

class Player;

class Manager
{
private:
    Player* player;
public:
    void Init();
    void Shutdown();
    void Tick();
    
    void KeyDown( int _key );
    void KeyUp();
};
