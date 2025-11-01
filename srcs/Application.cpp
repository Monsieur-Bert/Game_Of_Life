#include <Application.hpp>

// ************************************************************************** //
//                            | Canonical Form  |                             //
// ************************************************************************** //

/*Default Destructor*/
Application::~Application() {}

// ************************************************************************** //
//                        | Constructor Overloading |                         //
// ************************************************************************** //

Application::Application(int windowWidth, int windowHeight, int gridWidth, int gridHeight, int cellSize)
	: _window(sf::VideoMode(sf::Vector2u(windowWidth, windowHeight)), "Game of Life"),
	_game(gridWidth, gridHeight),
	_renderer(cellSize),
	_running(true),
	_updateInterval(UPDATE_INTERVAL)
{
	_window.setFramerateLimit(60);

	// Glide Pattern Example
	_game.addCell(1, 0);
	_game.addCell(2, 1);
	_game.addCell(0, 2);
	_game.addCell(1, 2);
	_game.addCell(2, 2);
}


// ************************************************************************** //
//                            | Public Members  |                             //
// ************************************************************************** //

void	Application::run()
{
	while(_running && _window.isOpen())
	{
		handleEvents();
		update();
		render();
	}
	_window.close();
}

// ************************************************************************** //
//                            | Private Members |                             //
// ************************************************************************** //

void Application::handleEvents()
{
	while (auto eventOpt = _window.pollEvent())
	{
		const sf::Event	&event = *eventOpt;
		
		if (event.is<sf::Event::Closed>())
			_running = false;
		if (auto* keyPress = event.getIf<sf::Event::KeyPressed>())
		{
			if (keyPress->code == sf::Keyboard::Key::Escape)
				_running = false;
		}
	}
}

void	Application::update()
{
	if (_clock.getElapsedTime().asSeconds() >= _updateInterval)
	{
		_game.iteration();
		_clock.restart();
	}
}

void	Application::render()
{
	_renderer.render(_window, _game);
}

