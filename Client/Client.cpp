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
}

void Client::receive_data()
{
	network.receive();
	auto packets = network.get_packets();
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
	window_size = Vector2<int>(1600, 900);
	square_size = Vector2<int>(80, 80);
	tick_time = 10;

	assets_path = "assets/";
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
			if (e.type == sf::Keyboard::Escape)
			{
				window->close();
			}
			break;
		}
	}
}

void Client::draw_board()
{
	Board board = game.get_board();
	Vector2<float> board_size = board.size() * square_size;
	for (int y = 0; y < board.size().y; ++y)
	{
		for (int x = 0; x < board.size().x; ++x)
		{
			Vector2<float> square_pos(x * square_size.x, y * square_size.y);
			if ((x + y) % 2 == 0)
				gr.set_fill_color(Color(200, 200, 200));
			else
				gr.set_fill_color(Color(55, 55, 55));


			gr.draw_rect(square_pos - board_size * 0.5, square_size);
		}
	}
}