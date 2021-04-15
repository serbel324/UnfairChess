#include "PieceDescription.h"

PieceDescription::PieceDescription(uint16_t id, 
    std::vector<Direction> moves,
    std::vector<Direction> takes,
    std::string textures_path,
    std::string name)
    : id(id)
    , moves(moves)
    , takes(takes)
{ 
    load_textures(textures_path);
}

void PieceDescription::load_textures(std::string path)
{
}

Direction::Direction(int delta_x, int delta_y, uint32_t range)
    : delta(delta_x, delta_y)
    , range(range)
{ }

Direction::Direction(Vector2<int> delta, uint32_t range)
    : delta(delta)
    , range(range)
{ }

const Direction Direction::bishop_UL    = Direction(-1,  1, Direction::INF_RANGE);
const Direction Direction::bishop_UR    = Direction( 1,  1, Direction::INF_RANGE);
const Direction Direction::bishop_DL    = Direction(-1, -1, Direction::INF_RANGE);
const Direction Direction::bishop_DR    = Direction(-1,  1, Direction::INF_RANGE);

const Direction Direction::knight_UUL   = Direction(-1,  2, 1);
const Direction Direction::knight_ULL   = Direction(-2,  1, 1);
const Direction Direction::knight_UUR   = Direction( 1,  2, 1);
const Direction Direction::knight_URR   = Direction( 2,  1, 1);
const Direction Direction::knight_DDL   = Direction(-1, -2, 1);
const Direction Direction::knight_DLL   = Direction(-2, -1, 1);
const Direction Direction::knight_DDR   = Direction( 1, -2, 1);
const Direction Direction::knight_DRR   = Direction( 2, -1, 1);

const Direction Direction::king_U       = Direction( 0,  1, 1);
const Direction Direction::king_UR      = Direction( 1,  1, 1);
const Direction Direction::king_R       = Direction( 1,  0, 1);
const Direction Direction::king_DR      = Direction( 1, -1, 1);
const Direction Direction::king_D       = Direction( 0, -1, 1);
const Direction Direction::king_DL      = Direction(-1, -1, 1);
const Direction Direction::king_L       = Direction(-1,  0, 1);
const Direction Direction::king_UL      = Direction(-1,  1, 1);

const Direction Direction::rook_U       = Direction( 0,  1, Direction::INF_RANGE);
const Direction Direction::rook_D       = Direction( 0, -1, Direction::INF_RANGE);
const Direction Direction::rook_L       = Direction(-1,  0, Direction::INF_RANGE);
const Direction Direction::rook_R       = Direction( 1,  0, Direction::INF_RANGE);
