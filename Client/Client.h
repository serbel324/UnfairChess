#pragma once

#include <Engine/NetworkClient.h>
#include <Engine/Board.h>
#include <Engine/Game.h>
#include <Engine/Graphics.h>

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
	void init();

	void tick();
	void render();
	void events();

	void draw_board();

	Vector2<int> window_size;
	Graphics gr;

	sf::RenderWindow* window;
	float tick_time;

	Assets assets;
	Game game;
	Board board;

	Vector2<int> square_size;

    NetworkClient network;
    Game current_game;
};

