#pragma once
#include <cstddef>
#include <deque>
#include <string>

#include <SFML/Network.hpp>

#include "Config.h"

class NetworkClient
{
public:
    NetworkClient(std::string server_ip = "localhost", 
        uint16_t server_port = NETWORK_SERVER_PORT,
        uint16_t client_port = NETWORK_CLIENT_PORT);

    void connect();
    void connect(sf::IpAddress ip, uint16_t port, uint16_t client_port);

    std::deque<sf::Packet> get_packets();

    void receive();
    void send(std::string message);
    void send(sf::Packet packet);

private:
    sf::TcpListener listener;

    sf::TcpSocket socket_sender;
    sf::TcpSocket socket_receiver;

    uint16_t client_port;

    uint16_t server_port;
    sf::IpAddress server_ip;

    std::deque<sf::Packet> packets_received;
};

