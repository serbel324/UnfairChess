#include "pch.h"
#include "Assets.h"
#include "Config.h"

#include <cstddef>
#include <vector>

Assets::Assets()
{
}

void Assets::load_assets(std::string path)
{
    std::vector<Direction> empty_moves;
    std::vector<Direction> white_pawn_moves = { Direction::king_U};
    std::vector<Direction> white_pawn_takes = { Direction::king_UL, Direction::king_UR };

    std::vector<Direction> black_pawn_moves = { Direction::king_D };
    std::vector<Direction> black_pawn_takes = { Direction::king_DL, Direction::king_DR };

    std::vector<Direction> knight_moves = { 
        Direction::knight_DDL, Direction::knight_DLL,
        Direction::knight_DDR, Direction::knight_DRR,
        Direction::knight_UUL, Direction::knight_ULL,
        Direction::knight_UUR, Direction::knight_URR };
    std::vector<Direction> knight_takes = knight_moves;

    std::vector<Direction> bishop_moves = {
        Direction::bishop_DL, Direction::bishop_DR,
        Direction::bishop_UL, Direction::bishop_UR };
    std::vector<Direction> bishop_takes = bishop_moves;

    std::vector<Direction> rook_moves = {
        Direction::rook_U, Direction::rook_D,
        Direction::rook_L, Direction::rook_R };
    std::vector<Direction> rook_takes = rook_moves;

    std::vector<Direction> queen_moves = {
        Direction::rook_U,    Direction::rook_D,
        Direction::rook_L,    Direction::rook_R,
        Direction::bishop_DL, Direction::bishop_DR,
        Direction::bishop_UL, Direction::bishop_UR };
    std::vector<Direction> queen_takes = queen_moves;

    std::vector<Direction> king_moves = {
        Direction::king_U,  Direction::king_D,
        Direction::king_L,  Direction::king_R,
        Direction::king_DL, Direction::king_DR,
        Direction::king_UL, Direction::king_UR };
    std::vector<Direction> king_takes = king_moves;

    std::string textures_path = path + "textures/";

    PieceDescription empty(PIECE_EMPTY_SQUARE, empty_moves, empty_moves, textures_path + "empty", "empty");
    PieceDescription white_pawn(PIECE_WHITE_PAWN, white_pawn_moves, white_pawn_takes, textures_path + "white_pawn", "white_pawn");
    PieceDescription black_pawn(PIECE_BLACK_PAWN, black_pawn_moves, black_pawn_takes, textures_path + "black_pawn", "black_pawn");
    PieceDescription knight(PIECE_KNIGHT, knight_moves, knight_takes, textures_path + "knight", "knight");
    PieceDescription bishop(PIECE_BISHOP, bishop_moves, bishop_takes, textures_path + "bishop", "bishop");
    PieceDescription rook(PIECE_ROOK, rook_moves, rook_takes, textures_path + "rook", "rook");
    PieceDescription queen(PIECE_QUEEN, queen_moves, queen_takes, textures_path + "queen", "queen");
    PieceDescription king(PIECE_KING, king_moves, king_takes, textures_path + "king", "king");
    
    piece_descriptions.push_back(empty);
    piece_descriptions.push_back(white_pawn);
    piece_descriptions.push_back(black_pawn);
    piece_descriptions.push_back(knight);
    piece_descriptions.push_back(bishop);
    piece_descriptions.push_back(rook);
    piece_descriptions.push_back(queen);
    piece_descriptions.push_back(king);
}
