#include "pch.h"
#include "NetworkClient.h"

#include <iostream>

NetworkClient::NetworkClient(std::string server_ip, uint16_t server_port, uint16_t client_port)
    : server_ip(server_ip)
    , server_port(server_port)
    , client_port(client_port)
{
    connect(server_ip, server_port, client_port);
    socket_sender.setBlocking(false);
    socket_receiver.setBlocking(false);
}

void NetworkClient::connect(sf::IpAddress ip, uint16_t port, uint16_t client_port)
{
    socket_sender.connect(ip, port);

    listener.listen(client_port);
    listener.accept(socket_receiver);

    std::cout << "Server connected: " << socket_receiver.getRemoteAddress() << std::endl;
}

std::deque<std::string> NetworkClient::get_messages()
{
    return messages_receieved;
}

void NetworkClient::receive()
{
    sf::Packet packet;
    while (socket_receiver.receive(packet) == sf::Socket::Done)
    {
        std::string message;
        packet >> message;
        messages_receieved.push_back(message);
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
