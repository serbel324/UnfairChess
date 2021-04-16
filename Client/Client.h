#pragma once

#include <Engine/NetworkClient.h>
#include <Engine/Move.h>
#include <Engine/Board.h>
#include <Engine/Game.h>
#include <Engine/Graphics.h>

#include <vector>

class Client
{
public:
    Client();

    void main_loop();
    void send_data();
    void receive_data();

private:
	void SFML_init();
	void config();

	void render();
	void events();

	void draw_board();

	Vector2<int> window_size;
	Graphics gr;

	sf::RenderWindow* window;
	float tick_time;

	std::string assets_path;

	Assets assets;
	Game game;

	Vector2<int> square_size;

    NetworkClient network;
    Game current_game;

	std::vector<MoveAttempt> move_attempts;
};

