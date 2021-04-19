#include "pch.h"
#include "Board.h"
#include "Config.h"

#include <iostream>

Board::Board()
    : _size(0, 0)
    , empty_square(empty_square)
{ }


Board::Board(size_t x_size, size_t y_size)
    : _size(x_size, y_size)
    , _board(y_size, std::vector<Piece>(x_size, Piece::empty_square))
    , empty_square(empty_square)
{ }

Board::Board(Vector2<size_t> size)
    : _size(size)
    , _board(size.y, std::vector<Piece>(size.x, Piece::empty_square))
    , empty_square(empty_square)
{ }

Vector2<size_t> Board::size() const
{
    return _size;
}

void Board::remove_piece(Vector2<int> pos)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= _size.x || pos.y >= _size.y)
        return;

    _board[pos.y][pos.x] = Piece::empty_square;
}

void Board::emplace_piece(Piece piece)
{
    auto pos = piece.pos;
    if (pos.x < 0 || pos.y < 0 || pos.x >= _size.x || pos.y >= _size.y)
        return;

    _board[pos.y][pos.x] = piece;
}

void Board::swap_pieces(Vector2<int> f, Vector2<int> s)
{
    if (f.x < 0 || f.y < 0 || f.x >= _size.x || f.y >= _size.y ||
        s.x < 0 || s.y < 0 || s.x >= _size.x || s.y >= _size.y)
        return;
    else
    {
        Piece b = _board[f.y][f.x];
        _board[f.y][f.x] = _board[s.y][s.x];
        _board[s.y][s.x] = b;
    }
}

void Board::resize(Vector2<size_t> new_size)
{
    _size = new_size;
    _board.assign(_size.y, std::vector<Piece>(_size.x, Piece::empty_square));
}

const Piece& Board::operator[](Vector2<int> pos) const
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= _size.x || pos.y >= _size.y)
        return empty_square;
    return _board[pos.y][pos.x];
}


Piece& Board::operator[](Vector2<int> pos)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= _size.x || pos.y >= _size.y)
        return empty_square;
    return _board[pos.y][pos.x];
}