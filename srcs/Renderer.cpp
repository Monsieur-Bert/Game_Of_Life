#include <Renderer.hpp>

// ************************************************************************** //
//                            | Canonical Form  |                             //
// ************************************************************************** //

/*Default Constructor*/
Renderer::Renderer() {}

/*Default Destructor*/
Renderer::~Renderer() {}

// ************************************************************************** //
//                        | Constructor Overloading |                         //
// ************************************************************************** //

Renderer::Renderer(int windowWidth, int windowHeight, int cellSize)
	: _window(sf::VideoMode(sf::Vector2u(windowWidth, windowHeight)), "Game of Life"),
	_cellSize(cellSize)
{
	_window.setFramerateLimit(10);
}

// ************************************************************************** //
//                            | Public Members  |                             //
// ************************************************************************** //

void	Renderer::render(Grid const &game)
{
	sf::RectangleShape cellShape(sf::Vector2f{float(_cellSize), float(_cellSize)});
	cellShape.setFillColor(sf::Color::Black);

	_window.clear(sf::Color::White);

	for (const Cell& c : game.getGrid())
	{
		cellShape.setPosition(sf::Vector2f{float(c.getX() * _cellSize), float(c.getY() * _cellSize)}),
		_window.draw(cellShape);
	}
	
	_window.display();
}
