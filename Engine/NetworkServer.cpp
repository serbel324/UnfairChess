#include "pch.h"
#include "NetworkServer.h"

NetworkServer::NetworkServer()
{
    connect(client_port);
    socket_sender.setBlocking(false);
    socket_receiver.setBlocking(false);
}

void NetworkServer::connect(uint16_t port)
{
    sf::TcpListener listener;
    listener.listen(NETWORK_SERVER_PORT);
    listener.accept(socket_receiver);

    std::cout << "Client connected: " << socket_receiver.getRemoteAddress() << std::endl;
}

std::deque<std::string> NetworkServer::get_messages()
{
    return messages_receieved;
}

void NetworkServer::receive()
{
    sf::Packet packet;
    while (socket_receiver.receive(packet) == sf::Socket::Done)
    {
        std::string message;
        packet >> message;
        messages_receieved.push_back(message);
    }
}

void NetworkServer::send(std::string message)
{
    sf::Packet packet;
    packet << message;
    send(packet);
}

void NetworkServer::send(sf::Packet packet)
{
    socket_sender.send(packet);
}
