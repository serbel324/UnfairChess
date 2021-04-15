#pragma once
#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include <SFML/Graphics/Texture.hpp>

#include "Vector2.h"

struct Direction;

struct PieceDescription
{
public:
    PieceDescription(uint16_t id, 
        std::vector<Direction> moves,
        std::vector<Direction> takes,
        std::string textures_path,
        std::string name);

    uint16_t id;
    std::vector<Direction> moves;
    std::vector<Direction> takes;
    std::vector<sf::Texture> textures;

    std::string name;

private:
    void load_textures(std::string path);
};

struct Direction
{
public:
    Direction(int delta_x, int delta_y, uint32_t range);
    Direction(Vector2<int> delta, uint32_t range);

    Vector2<int> delta;
    uint32_t range;

    static const uint32_t INF_RANGE = 1000;

    static const Direction bishop_UL;
    static const Direction bishop_DL;
    static const Direction bishop_UR;
    static const Direction bishop_DR;

    static const Direction knight_UUL;
    static const Direction knight_ULL;
    static const Direction knight_UUR;
    static const Direction knight_URR;
    static const Direction knight_DDL;
    static const Direction knight_DLL;
    static const Direction knight_DDR;
    static const Direction knight_DRR;

    static const Direction king_U;
    static const Direction king_UR;
    static const Direction king_R;
    static const Direction king_DR;
    static const Direction king_D;
    static const Direction king_DL;
    static const Direction king_L;
    static const Direction king_UL;

    static const Direction rook_U;
    static const Direction rook_D;
    static const Direction rook_L;
    static const Direction rook_R;
};


