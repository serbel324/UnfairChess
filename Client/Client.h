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

	void mouse_click();
	Vector2<int> get_square(Vector2<float> cursor_pos);

	void draw_board();

	Vector2<int> window_size;
	Graphics gr;

	sf::RenderWindow* window;
	float tick_time;

	std::string assets_path;

	Assets assets;
	Game game;
	uint16_t player;

	Vector2<int> square_size;

    NetworkClient network;
    Game current_game;

	bool move_done;
	MoveAttempt move_attempt;

	Vector2<float> cursor_pos;
	bool is_square_selected;
	Vector2<int> square_selected;
};

