#pragma once
#include "Vector2.h"

#define PIECE_EMPTY_SQUARE  0
#define PIECE_WHITE_PAWN    1
#define PIECE_BLACK_PAWN    2
#define PIECE_KNIGHT        3
#define PIECE_BISHOP        4
#define PIECE_ROOK          5
#define PIECE_QUEEN         6
#define PIECE_KING          7

#define PLAYER_WHITE 0
#define PLAYER_BLACK 1
#define PLAYER_NEUTRAL 2

#define POSITION_NULL Vector2<int>(-1, -1)

#define NETWORK_SERVER_PORT 1118
#define NETWORK_CLIENT_PORT 1119

constexpr uint16_t PACKET_BOARD_SIZE =        0;
constexpr uint16_t PACKET_BOARD_PIECE =       1;
constexpr uint16_t PACKET_BOARD_END =         3;

constexpr uint16_t PACKET_PIECE_TYPE =          4;
constexpr uint16_t PACKET_PIECE_PLAYER =        5;
constexpr uint16_t PACKET_PIECE_POS =           6;
constexpr uint16_t PACKET_PIECE_IS_CAPITAL =    7;
constexpr uint16_t PACKET_PIECE_MOVES =         8;
constexpr uint16_t PACKET_PIECE_COOLDOWN =      9;
constexpr uint16_t PACKET_PIECE_END =           10;

constexpr uint16_t PACKET_MOVE_PLAYER = 0;
constexpr uint16_t PACKET_MOVE_START_POS = 1;
constexpr uint16_t PACKET_MOVE_END_POS = 2;
constexpr uint16_t PACKET_MOVE_END = 3;