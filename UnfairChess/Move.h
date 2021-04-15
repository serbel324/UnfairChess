#pragma once

#include "Piece.h"
#include "Vector2.h"

struct Move
{
public:
    Move(Vector2<int> start_pos, Vector2<int> end_pos, Piece piece_moved, Piece piece_taken=Piece::empty_square);

    Vector2<int> start_pos;
    Vector2<int> end_pos;

    Piece piece_moved;
    Piece piece_taken;
};

