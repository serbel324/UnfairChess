#pragma once

#include "Assets.h"
#include "Board.h"
#include "Move.h"

#include <SFML/System/Clock.hpp>

class Game
{
public:
    Game();
    Game(Assets assets);

    bool try_move(MoveAttempt move);

    void propose_move(MoveAttempt move);

    bool check_for_checks();
    std::vector<Vector2<int>> get_possible_moves(Piece piece);
    void commit_move(Move move);
    void next_player();
    void undo_last_move(Move move);

    void standard_setup();
    Board get_board();

    void set_board(Board board);

    Vector2<size_t> get_board_size();

private:
    Assets assets;

    Board board;
    std::vector<Move> moves;

    sf::Clock clock;

    uint16_t turn;
};

