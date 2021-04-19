#include "pch.h"
#include "Config.h"
#include "Move.h"

Move::Move(uint16_t player, Vector2<int> start_pos, Vector2<int> end_pos, Piece piece_moved, Piece piece_taken)
    : player(player)
    , start_pos(start_pos)
    , end_pos(end_pos)
    , piece_moved(piece_moved)
    , piece_taken(piece_taken)
{}

MoveAttempt::MoveAttempt()
    : player(PLAYER_WHITE)
    , start_pos(0, 0)
    , end_pos(0, 0)
{}


MoveAttempt::MoveAttempt(uint16_t player, Vector2<int> start_pos, Vector2<int> end_pos)
    : player(player)
    , start_pos(start_pos)
    , end_pos(end_pos)
{}
