#include "pch.h"

#include "Config.h"
#include "PacketManager.h"

void PacketManager::board_to_packet(sf::Packet& packet, const Board& board)
{
    packet << PACKET_BOARD_SIZE;
    packet << board.size().x << board.size().y;

    for (int y = 0; y < board.size().y; ++y)
    {
        for (int x = 0; x < board.size().x; ++x)
        {
            Vector2<int> pos(x, y);
            if (board[pos].type != PIECE_EMPTY_SQUARE)
            {
                packet << PACKET_BOARD_PIECE;
                piece_to_packet(packet, board[pos]);
            }
        }
    }
    packet << PACKET_BOARD_END;
}

void PacketManager::piece_to_packet(sf::Packet& packet, const Piece& piece)
{
    packet << PACKET_PIECE_TYPE << piece.type;
    packet << PACKET_PIECE_PLAYER << piece.player;
    packet << PACKET_PIECE_POS << piece.pos.x << piece.pos.y;
    packet << PACKET_PIECE_IS_CAPITAL << piece.is_capital;
    packet << PACKET_PIECE_MOVES << piece.moves;
    packet << PACKET_PIECE_COOLDOWN << piece.cooldown;
    packet << PACKET_PIECE_END;
}

void PacketManager::move_to_packet(sf::Packet& packet, const MoveAttempt& move)
{
    packet << PACKET_MOVE_PLAYER << move.player;
    packet << PACKET_MOVE_START_POS << move.start_pos.x << move.start_pos.y;
    packet << PACKET_MOVE_END_POS << move.end_pos.x << move.end_pos.y;
    packet << PACKET_MOVE_END;
}

Board PacketManager::board_from_packet(sf::Packet& packet)
{
    Board board;
    Vector2<size_t> board_size;
    uint16_t param;

    bool end_reached = 0;
    while (!end_reached)
    {
        packet >> param;
        switch (param)
        {
        case PACKET_BOARD_SIZE:
            packet >> board_size.x >> board_size.y;
            board.resize(board_size);
            break;
        case PACKET_BOARD_PIECE:
        {
            Piece piece = piece_from_packet(packet);
            board.emplace_piece(piece);
            break;
        }
        case PACKET_BOARD_END:
            end_reached = 1;
            break;
        }
    }
    return board;
}

Piece PacketManager::piece_from_packet(sf::Packet& packet)
{
    uint16_t type = 1;
    uint16_t player = 0;
    Vector2<int> pos(0, 0);

    uint32_t moves = 0;
    uint64_t cooldown = 0;

    bool is_capital = 0;

    uint16_t param;

    bool end_reached = 0;
    while (!end_reached)
    {
        packet >> param;
        switch (param)
        {
        case PACKET_PIECE_TYPE:
            packet >> type;
            break;
        case PACKET_PIECE_PLAYER:
            packet >> player;
            break;
        case PACKET_PIECE_POS:
            packet >> pos.x >> pos.y;
            break;
        case PACKET_PIECE_IS_CAPITAL:
            packet >> is_capital;
            break;
        case PACKET_PIECE_MOVES:
            packet >> moves;
            break;
        case PACKET_PIECE_COOLDOWN:
            packet >> cooldown;
            break;
        case PACKET_PIECE_END:
            end_reached = 1;
            break;
        }
    }
    return Piece(type, player, pos, is_capital, moves, cooldown);
}

MoveAttempt PacketManager::move_from_packet(sf::Packet& packet)
{
    uint16_t player = 0;
    Vector2<int> start_pos(0, 0);
    Vector2<int> end_pos(0, 0);

    uint16_t param;

    bool end_reached = 0;
    while (!end_reached && !packet.endOfPacket())
    {
        packet >> param;
        switch (param)
        {
        case PACKET_MOVE_PLAYER:
            packet >> player;
            break;
        case PACKET_MOVE_START_POS:
            packet >> start_pos.x >> start_pos.y;
            break;
        case PACKET_MOVE_END_POS:
            packet >> end_pos.x >> end_pos.y;
            break;
        case PACKET_MOVE_END:
            end_reached = 1;
            break;
        }
    }
    return MoveAttempt(player, start_pos, end_pos);
}
