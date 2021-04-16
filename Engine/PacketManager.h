#pragma once
#include <SFML/Network.hpp>
#include "Board.h"
class PacketManager
{
public:
    static void board_to_packet(sf::Packet& packet, const Board& board);

    static Board board_from_packet(std::string);
};

