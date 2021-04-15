#include "Config.h"
#include "Piece.h"

Piece::Piece(uint16_t type, uint16_t player, Vector2<int> pos, 
             uint32_t moves, uint64_t cooldown, bool is_capital)
    : type(type)
    , player(player)
    , pos(pos)
    , moves(moves)
    , cooldown(cooldown)
    , is_capital(is_capital)
{ }

Piece::Piece(const Piece& other)
    : type(other.type)
    , player(other.player)
    , pos(other.pos)
    , moves(other.moves)
    , cooldown(other.cooldown)
    , is_capital(other.is_capital)
{ }

void Piece::operator=(const Piece& other)
{
    type = other.type;
    player = other.player;
    pos = other.pos;
    moves = other.moves;
    cooldown = other.cooldown;
    is_capital = other.is_capital;
}

const Piece Piece::empty_square = Piece(PIECE_EMPTY_SQUARE, PLAYER_NEUTRAL, POSITION_NULL);

const Piece Piece::empty_square = Piece(PIECE_EMPTY_SQUARE, PLAYER_NEUTRAL, POSITION_NULL);