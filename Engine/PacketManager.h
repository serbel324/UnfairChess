#pragma once
#include <SFML/Network.hpp>
#include "Board.h"
#include "Move.h"

class PacketManager
{
public:
    static void board_to_packet(sf::Packet& packet, const Board& board);
    static void piece_to_packet(sf::Packet& packet, const Piece& piece);
    static void move_to_packet(sf::Packet& packet, const MoveAttempt& move);

    static Board board_from_packet(sf::Packet& packet);
    static Piece piece_from_packet(sf::Packet& packet);
    static MoveAttempt move_from_packet(sf::Packet& packet);
};

