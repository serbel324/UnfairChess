#include "pch.h"
#include "NetworkServer.h"

NetworkServer::NetworkServer()
{
    socket_sender.setBlocking(false);
    socket_receiver.setBlocking(false);
}

void NetworkServer::connect()
{
    sf::TcpListener listener;
    listener.listen(NETWORK_SERVER_PORT);
    listener.accept(socket_receiver);

    std::cout << "Client connected: " << socket_receiver.getRemoteAddress() << std::endl;

    socket_sender.connect(socket_receiver.getRemoteAddress(), NETWORK_CLIENT_PORT);
}

std::deque<sf::Packet> NetworkServer::get_packets()
{
    return packets_received;
}

void NetworkServer::clear_packets()
{
    packets_received.clear();
}

void NetworkServer::receive()
{
    sf::Packet packet;
    while (socket_receiver.receive(packet) == sf::Socket::Done)
    {
        packets_received.push_back(packet);
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
