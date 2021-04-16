#pragma once

#include <cstddef>
#include <deque>
#include <string>

#include <SFML/Network.hpp>

#include "Config.h"

class NetworkServer
{
public:
    NetworkServer();

    void connect(uint16_t port);

    std::deque<std::string> get_messages();

    void receive();
    void send(std::string message);
    void send(sf::Packet packet);

private:
    sf::TcpListener listener;

    sf::TcpSocket socket_sender;
    sf::TcpSocket socket_receiver;

    uint16_t client_port;
    uint16_t server_port;

    std::deque<std::string> messages_receieved;
};

