#include "Client.h"

void Client::main_loop()
{
    while (true)
    {
        send_data();

        receive_data();
    }
}

Client::Client()
	: network()
	, assets("")
{
	window_size = Vector2<int>(800, 800);

	config();
	SFML_init();

	gr = Graphics(window, window_size);
	Camera* cam = new Camera(window_size / 2, 0, 1);
	gr.apply_camera(cam);
	gr.set_active(false);

	init();

	sf::Thread render_thread(&Client::render, this);
	render_thread.launch();

	while (window->isOpen())
	{
		events();
	}
}

void Client::join_game(Game* game)
{
	//	current_game = game;
	update_board(current_game->get_board());
}

void Client::update_board(Board new_board)
{
	board = new_board;
}

void Client::SFML_init()
{
	window = new sf::RenderWindow(sf::VideoMode(window_size.x, window_size.y), "Unfair chess", sf::Style::Close);
}


void Client::config()
{
	window_size = Vector2<int>(1600, 900);
	square_size = Vector2<int>(50, 50);
	tick_time = 10;
}


void Client::init()
{
}

void Client::tick()
{
}

void Client::render()
{
	sf::Clock clock;

	while (window->isOpen())
	{
		auto t1 = clock.getElapsedTime().asMilliseconds();

		gr.set_active(true);
		gr.set_fill_color(Color(20));

		gr.fill();
		draw_board();
		gr.present();

		gr.set_active(false);

		auto t2 = clock.getElapsedTime().asMilliseconds();

		float dt = static_cast<float>(t2 - t1);

		if (dt < tick_time)
		{
			sf::sleep(sf::milliseconds(tick_time - dt));
		}
	}
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
	for (int y = 0; y < board.size.y; ++y)
	{
		for (int x = 0; x < board.size.x; ++x)
		{
			Vector2<float> square_pos(x * board.size.x * square_size.x,
				y * board.size.y * square_size.y);
			if ((x + y) % 2 == 0)
				gr.set_fill_color(Color(200, 200, 200));
			else
				gr.set_fill_color(Color(55, 55, 55));


			gr.draw_rect(square_pos, square_size);
		}
	}
}