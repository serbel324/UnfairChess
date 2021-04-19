#include "pch.h"
#include "Config.h"
#include "Game.h"

#include <iostream>

Game::Game()
    : assets()
    , clock()
    , turn(PLAYER_WHITE)
{}

Game::Game(Assets assets)
    : assets(assets)
    , clock()
    , turn(PLAYER_WHITE)
{}

bool Game::try_move(MoveAttempt move)
{
    if (board[move.start_pos].player != move.player)
    {
        return 0;
    }

    return 1;
}

void Game::propose_move(MoveAttempt move_attempt)
{
    if (!try_move(move_attempt))
    {
        return;
    }
        
    Move move(move_attempt.player, 
        move_attempt.start_pos, 
        move_attempt.end_pos, 
        board[move_attempt.start_pos], 
        board[move_attempt.end_pos]
    );

    commit_move(move);
    return;
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
    Piece piece_moved = board[move.start_pos];

    board.remove_piece(move.start_pos);

    if (move.piece_taken.type != PIECE_EMPTY_SQUARE)
        board.remove_piece(move.piece_taken.pos);

    piece_moved.moves += 1;
    piece_moved.pos = move.end_pos;

    board.emplace_piece(piece_moved);

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
        pos.set(i, 1);
        board.emplace_piece(Piece(PIECE_WHITE_PAWN, PLAYER_WHITE, pos));
    }

    pos.set(0, 0);
    board.emplace_piece(Piece(PIECE_ROOK, PLAYER_WHITE, pos));
    pos.set(7, 0);
    board.emplace_piece(Piece(PIECE_ROOK, PLAYER_WHITE, pos));

    pos.set(1, 0);
    board.emplace_piece(Piece(PIECE_KNIGHT, PLAYER_WHITE, pos));
    pos.set(6, 0);
    board.emplace_piece(Piece(PIECE_KNIGHT, PLAYER_WHITE, pos));

    pos.set(2, 0);
    board.emplace_piece(Piece(PIECE_BISHOP, PLAYER_WHITE, pos));
    pos.set(5, 0);
    board.emplace_piece(Piece(PIECE_BISHOP, PLAYER_WHITE, pos));

    pos.set(3, 0);
    board.emplace_piece(Piece(PIECE_QUEEN, PLAYER_WHITE, pos));
    pos.set(4, 0);
    board.emplace_piece(Piece(PIECE_KING, PLAYER_WHITE, pos, true));


    // ------------------------ BLACK PIECES ------------------------ //

    for (int i = 0; i < 8; ++i)
    {
        pos.set(i, 6);
        board.emplace_piece(Piece(PIECE_WHITE_PAWN, PLAYER_BLACK, pos));
    }

    pos.set(0, 7);
    board.emplace_piece(Piece(PIECE_ROOK, PLAYER_BLACK, pos));
    pos.set(7, 7);
    board.emplace_piece(Piece(PIECE_ROOK, PLAYER_BLACK, pos));

    pos.set(1, 7);
    board.emplace_piece(Piece(PIECE_KNIGHT, PLAYER_BLACK, pos));
    pos.set(6, 7);
    board.emplace_piece(Piece(PIECE_KNIGHT, PLAYER_BLACK, pos));

    pos.set(2, 7);
    board.emplace_piece(Piece(PIECE_BISHOP, PLAYER_BLACK, pos));
    pos.set(5, 7);
    board.emplace_piece(Piece(PIECE_BISHOP, PLAYER_BLACK, pos));

    pos.set(3, 7);
    board.emplace_piece(Piece(PIECE_QUEEN, PLAYER_BLACK, pos));
    pos.set(4, 7);
    board.emplace_piece(Piece(PIECE_KING, PLAYER_BLACK, pos, true));

    turn = PLAYER_WHITE;
}

Board Game::get_board()
{
    return board;
}

void Game::set_board(Board board)
{
    this->board = board;
}

Vector2<size_t> Game::get_board_size()
{
    return board.size();
}
