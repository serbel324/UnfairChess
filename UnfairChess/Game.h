#pragma once

#include "Assets.h"
#include "Board.h"
#include "Move.h"

#include <SFML/System/Clock.hpp>

class Game
{
public:
    Game(Vector2<size_t> board_size, Assets& assets);

    void propose_move(uint16_t player, Vector2<int> start_pos, Vector2<int> end_pos);
    void decline_move();
    bool check_for_checks();
    std::vector<Vector2<int>> get_possible_moves(Piece piece);
    void commit_move(Move move);
    void undo_last_move(Move move);

    void standard_setup();
    Board get_board();

private:
    Assets& assets;

    Board board;
    std::vector<Move> moves;

    sf::Clock clock;

    uint16_t turn;
};

