#pragma once
#include <vector>

#include <SFML/Network/Packet.hpp>

#include "Piece.h"
#include "Vector2.h"

struct Board
{
public:
    Board();
    Board(size_t x_size, size_t y_size);
    Board(Vector2<size_t> size);

    Vector2<size_t> size() const;

    void remove_piece(Vector2<int> pos);
    void emplace_piece(Piece piece);
    void swap_pieces(Vector2<int> f, Vector2<int> s);
    void resize(Vector2<size_t> new_size);

    const Piece& operator[](Vector2<int> pos) const;
    Piece& operator[](Vector2<int> pos);

private:
    Vector2<size_t> _size;
    std::vector<std::vector<Piece>> _board;
    Piece empty_square;
};

