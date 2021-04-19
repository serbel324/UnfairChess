#include "pch.h"
#include "NetworkClient.h"

#include <iostream>

NetworkClient::NetworkClient(std::string server_ip, uint16_t server_port, uint16_t client_port)
    : server_ip(server_ip)
    , server_port(server_port)
    , client_port(client_port)
{
    socket_sender.setBlocking(false);
    socket_receiver.setBlocking(false);
}

void NetworkClient::connect()
{
    socket_sender.connect(server_ip, server_port);

    listener.listen(client_port);
    listener.accept(socket_receiver);

    std::cout << "Server connected: " << socket_receiver.getRemoteAddress() << std::endl;
}

void NetworkClient::connect(sf::IpAddress ip, uint16_t port, uint16_t client_port)
{
    listener.listen(client_port);
    socket_sender.connect(ip, port);
    listener.accept(socket_receiver);

    std::cout << "Server connected: " << socket_receiver.getRemoteAddress() << std::endl;
}

std::deque<sf::Packet> NetworkClient::get_packets()
{
    return packets_received;
}

void NetworkClient::clear_packets()
{
    packets_received.clear();
}

void NetworkClient::receive()
{
    sf::Packet packet;
    while (socket_receiver.receive(packet) == sf::Socket::Done)
    {
        packets_received.push_back(packet);
    }
}

void NetworkClient::send(std::string message)
{
    sf::Packet packet;
    packet << message;
    send(packet);
}

void NetworkClient::send(sf::Packet packet)
{
    socket_sender.send(packet);
}
