#pragma once
#include <cstddef>
#include <cstdint>
#include "Vector2.h"

struct Piece
{
public:
    Piece(uint16_t type, uint16_t player, Vector2<int> pos, bool is_capital=0, uint32_t moves=0, uint64_t cooldown=0);
    Piece(const Piece& other);

    void operator=(const Piece& other);

    static const Piece empty_square;

    uint16_t type;
    uint16_t player;
    Vector2<int> pos;

    uint32_t moves;
    uint64_t cooldown;

    bool is_capital;
};

