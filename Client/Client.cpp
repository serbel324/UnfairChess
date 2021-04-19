#include "Client.h"
#include <Engine/PacketManager.h>

Client::Client()
	: network()
	, assets()
{
	window_size = Vector2<int>(800, 800);

	config();
	SFML_init();

	gr = Graphics(window, window_size);
	Camera* cam = new Camera(window_size / 2, 0, 1);
	gr.apply_camera(cam);
	gr.set_active(false);

	network.connect();

	main_loop();
}

void Client::main_loop()
{
	while (window->isOpen())
	{
		receive_data();
		events();
		render();
		send_data();
	}
}

void Client::send_data()
{
	sf::Packet packet;

	if (move_done)
	{ 
		PacketManager::move_to_packet(packet, move_attempt);
		move_done = 0;
		network.send(packet);
	}
}

void Client::receive_data()
{
	network.receive();
	auto packets = network.get_packets();
	network.clear_packets();

	if (packets.size() != 0)
	{
		game.set_board(PacketManager::board_from_packet(packets.back()));
	}
}


void Client::SFML_init()
{
	window = new sf::RenderWindow(sf::VideoMode(window_size.x, window_size.y), "Unfair chess", sf::Style::Close);
}


void Client::config()
{
	window_size = Vector2<int>(640, 640);
	square_size = Vector2<int>(80, 80);
	tick_time = 10;

	assets_path = "assets/";
	assets.load_assets(assets_path);

	cursor_pos.set(0, 0);
	is_square_selected = 0;
	square_selected.set(0, 0);

	move_done = 0;
}


void Client::render()
{
	sf::Clock clock;

	gr.set_fill_color(Color(20));

	gr.fill();
	draw_board();
	gr.present();
}


void Client::events()
{
	sf::Event e;
	while (window->pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			switch (e.key.code)
			{
			case sf::Keyboard::Escape:
				window->close();
				break;
			}
		case sf::Event::MouseButtonPressed:
			if (e.mouseButton.button == sf::Mouse::Left)
			{
				mouse_click();
			}
			else if (e.mouseButton.button == sf::Mouse::Right)
			{

			}
			break;
		case sf::Event::MouseMoved:
			{
				sf::Vector2i mp = sf::Mouse::getPosition(*window);
				cursor_pos = Vector2<float>(mp.x - window_size.x / 2, mp.y - window_size.y / 2);
			}
			break;
		}
	}
}

void Client::mouse_click()
{
	auto bsize = game.get_board_size();
	auto sq = get_square(cursor_pos);

	if (sq.x < 0 || sq.y < 0 || sq.x >= bsize.x || sq.y >= bsize.y)
		return;

	if (!is_square_selected)
	{
		square_selected = sq;
		is_square_selected = 1;
	}
	else
	{
		if (sq == square_selected)
		{
			is_square_selected = 0;
		}
		else
		{
			is_square_selected = 0;
			move_done = 1;
			move_attempt = MoveAttempt(player, square_selected, sq);
		}
	}
}

Vector2<int> Client::get_square(Vector2<float> cursor_pos)
{
	auto bsize = game.get_board_size();
	Vector2<float> board_size = bsize * square_size;
	Vector2<float> v = cursor_pos - window_size * 0.5 + board_size;
	return Vector2<int>(v.x / square_size.x, bsize.y - v.y / square_size.y);
}

void Client::draw_board()
{
	Board board = game.get_board();
	Vector2<int> bsize = board.size();
	Vector2<float> board_size = board.size() * square_size;
	for (int y = 0; y < bsize.y; ++y)
	{
		for (int x = 0; x < bsize.x; ++x)
		{
			Vector2<int> pos(x, y);

			Vector2<int> square(x + 1, bsize.y - y);
			Vector2<float> square_pos = square * square_size - square_size;

			if ((x + y) % 2 == 1)
				gr.set_fill_color(Color(200, 200, 200));
			else
				gr.set_fill_color(Color(100, 100, 100));

			if (is_square_selected && pos == square_selected)
				gr.set_fill_color(Color(255, 100, 100));

			gr.draw_rect(square_pos - board_size * 0.5, square_size);

			if (board[pos].type != PIECE_EMPTY_SQUARE)
			{
				if ((x + y) % 2 == 0)
					gr.set_fill_color(Color(200, 200, 200));
				else
					gr.set_fill_color(Color(55, 55, 55));

				Piece piece = board[pos];
				sf::Texture& tex = assets.piece_descriptions[piece.type].textures[piece.player];
				gr.draw_texture(tex, square_pos - board_size * 0.5 + square_size * 0.5, square_size);
			}
		}
	}
}