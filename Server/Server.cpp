#include "Server.h"
#include <Engine/PacketManager.h>
#include <iostream>

Server::Server()
    : assets()
    , game()
{
    config();
    network.connect();
    send_data();
    main_loop();
}

void Server::config()
{
    std::string assets_path = "assets/";
    assets.load_assets(assets_path);
    game.standard_setup();
}

void Server::send_data()
{
    sf::Packet packet;
    PacketManager::board_to_packet(packet, game.get_board());
    network.send(packet);
}

void Server::receive_data()
{
    network.receive();
    auto packets = network.get_packets();
    network.clear_packets();

    if (packets.size() != 0)
    {
        MoveAttempt move = PacketManager::move_from_packet(packets.back());

        game.propose_move(move);
        send_data();
    }
}

void Server::main_loop()
{
    while (true)
    {
        receive_data();
    }
}
