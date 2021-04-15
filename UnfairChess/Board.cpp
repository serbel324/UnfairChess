#include "Board.h"

Board::Board(size_t x_size, size_t y_size)
    : size(x_size, y_size)
    , board(y_size, std::vector<Piece>(x_size, Piece::empty_square))
    , empty_square(empty_square)
{ }

Board::Board(Vector2<size_t> size)
    : size(size)
    , board(size.y, std::vector<Piece>(size.x, Piece::empty_square))
    , empty_square(empty_square)
{ }

void Board::remove_piece(Vector2<int> pos)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y)
        board[pos.y][pos.x] = Piece::empty_square;
}

void Board::emplace_piece(Vector2<int> pos, Piece piece)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y)
        board[pos.y][pos.x] = piece;
}

void Board::swap_pieces(Vector2<int> f, Vector2<int> s)
{
    if (f.x < 0 || f.y < 0 || f.x >= size.x || f.y >= size.y ||
        s.x < 0 || s.y < 0 || s.x >= size.x || s.y >= size.y)
        return;
    else
    {
        Piece b = board[f.y][f.x];
        board[f.y][f.x] = board[s.y][s.x];
        board[s.y][s.x] = b;
    }
}

const Piece& Board::operator[](Vector2<int> pos) const
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y)
        return empty_square;
    return board[pos.y][pos.x];
}


Piece& Board::operator[](Vector2<int> pos)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= size.x || pos.y >= size.y)
        return empty_square;
    return board[pos.y][pos.x];
}
