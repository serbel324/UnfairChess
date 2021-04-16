#include "pch.h"
#include "Config.h"
#include "Game.h"

#include <iostream>

Game::Game()
    : assets(assets)
    , clock()
{
    standard_setup();
}

Game::Game(Assets assets)
    : assets(assets)
    , clock()
{
    standard_setup();
}

void Game::propose_move(uint16_t player, Vector2<int> start_pos, Vector2<int> end_pos)
{
    if (player != turn)
    {
        decline_move();
        return;
    }

    if (board[start_pos].player != player)
    {
        decline_move();
        return;
    }
        
    Move move(start_pos, end_pos, board[start_pos], board[end_pos]);
    commit_move(move);
}

void Game::decline_move()
{
    std::cout << "Tak nelzya" << std::endl;
}

bool Game::check_for_checks()
{
    return false;
}

std::vector<Vector2<int>> Game::get_possible_moves(Piece piece)
{
    return std::vector<Vector2<int>>();
}

void Game::commit_move(Move move)
{
    moves.push_back(move);
    board.remove_piece(move.start_pos);
    board.remove_piece(move.piece_taken.pos);
    board.emplace_piece(move.end_pos, move.piece_moved);

    board[move.end_pos].moves += 1;
    board[move.end_pos].pos = move.end_pos;

    turn = !turn;
}

void Game::next_player()
{
    if (turn == PLAYER_WHITE)
        turn = PLAYER_BLACK;
    else
        turn = PLAYER_WHITE;
}

void Game::undo_last_move(Move move)
{
}

void Game::standard_setup()
{
    board.resize(Vector2<size_t>(8, 8));

    Vector2<int> pos(0, 0);

    // ------------------------ WHITE PIECES ------------------------ //

    for (int i = 0; i < 8; ++i) 
    {
        pos.set(1, i);
        board.emplace_piece(pos, Piece(PIECE_WHITE_PAWN, PLAYER_WHITE, pos));
    }

    pos.set(0, 0);
    board.emplace_piece(pos, Piece(PIECE_ROOK, PLAYER_WHITE, pos));
    pos.set(0, 7);
    board.emplace_piece(pos, Piece(PIECE_ROOK, PLAYER_WHITE, pos));

    pos.set(0, 1);
    board.emplace_piece(pos, Piece(PIECE_KNIGHT, PLAYER_WHITE, pos));
    pos.set(0, 6);
    board.emplace_piece(pos, Piece(PIECE_KNIGHT, PLAYER_WHITE, pos));

    pos.set(0, 2);
    board.emplace_piece(pos, Piece(PIECE_BISHOP, PLAYER_WHITE, pos));
    pos.set(0, 5);
    board.emplace_piece(pos, Piece(PIECE_BISHOP, PLAYER_WHITE, pos));

    pos.set(0, 3);
    board.emplace_piece(pos, Piece(PIECE_QUEEN, PLAYER_WHITE, pos));
    pos.set(0, 4);
    board.emplace_piece(pos, Piece(PIECE_KING, PLAYER_WHITE, pos, true));


    // ------------------------ BLACK PIECES ------------------------ //

    for (int i = 0; i < 8; ++i)
    {
        pos.set(6, i);
        board.emplace_piece(pos, Piece(PIECE_WHITE_PAWN, PLAYER_BLACK, pos));
    }

    pos.set(7, 0);
    board.emplace_piece(pos, Piece(PIECE_ROOK, PLAYER_BLACK, pos));
    pos.set(7, 7);
    board.emplace_piece(pos, Piece(PIECE_ROOK, PLAYER_BLACK, pos));

    pos.set(7, 1);
    board.emplace_piece(pos, Piece(PIECE_KNIGHT, PLAYER_BLACK, pos));
    pos.set(7, 6);
    board.emplace_piece(pos, Piece(PIECE_KNIGHT, PLAYER_BLACK, pos));

    pos.set(7, 2);
    board.emplace_piece(pos, Piece(PIECE_BISHOP, PLAYER_BLACK, pos));
    pos.set(7, 5);
    board.emplace_piece(pos, Piece(PIECE_BISHOP, PLAYER_BLACK, pos));

    pos.set(7, 3);
    board.emplace_piece(pos, Piece(PIECE_QUEEN, PLAYER_BLACK, pos));
    pos.set(7, 4);
    board.emplace_piece(pos, Piece(PIECE_KING, PLAYER_BLACK, pos, true));

    turn = PLAYER_WHITE;
}

Board Game::get_board()
{
    return board;
}

void Game::set_board(Board board)
{
    board.set(board);
}
