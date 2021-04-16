#include "pch.h"

#include "Config.h"
#include "PacketManager.h"

void PacketManager::board_to_packet(sf::Packet& packet, const Board& board)
{
    packet << PACKET_BOARD_SIZE;
    packet << board.size.x << board.size.y;

    for (int y = 0; y < size.y; ++y)
    {
        for (int x = 0; x < size.x; ++x)
        {
            if (board[y][x].type != PIECE_EMPTY_SQUARE)
            {
                packet << PACKET_BOARD_PIECE;
                board[y][x].to_packet();
            }
        }
    }

    return packet;
}
