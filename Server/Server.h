#pragma once
#include <Engine/Assets.h>
#include <Engine/Game.h>
#include <Engine/NetworkServer.h>

class Server
{
public:
    Server();

private:
    void config();

    void send_data();
    void receive_data();
    void main_loop();

    NetworkServer network;
    Assets assets;
    Game game;
};

