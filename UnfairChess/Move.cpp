#include "Move.h"

Move::Move(Vector2<int> start_pos, Vector2<int> end_pos, Piece piece_moved, Piece piece_taken)
    : start_pos(start_pos)
    , end_pos(end_pos)
    , piece_moved(piece_moved)
    , piece_taken(piece_taken)
{}