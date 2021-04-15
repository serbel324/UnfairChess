#include "Game.h"

Game::Game(Vector2<size_t> board_size, Assets& assets)
    : assets(assets)
    , board(board_size)
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
    std::cout << "Ohuel?" << std::endl;
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
    board.emplace_piece(move.end_pos, move.piece_moved);

    board[move.end_pos].moves += 1;
}

Board Game::get_board()
{
    return board;
}
