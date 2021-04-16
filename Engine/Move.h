#pragma once

#include "Piece.h"
#include "Vector2.h"

struct Move
{
public:
    Move(uint16_t player, Vector2<int> start_pos, Vector2<int> end_pos, Piece piece_moved, Piece piece_taken=Piece::empty_square);
    
    uint16_t player;
    Vector2<int> start_pos;
    Vector2<int> end_pos;

    Piece piece_moved;
    Piece piece_taken;
};


struct MoveAttempt
{
public:
    MoveAttempt(uint16_t player, Vector2<int> start_pos, Vector2<int> end_pos);

    uint16_t player;
    Vector2<int> start_pos;
    Vector2<int> end_pos;
};