#include <Renderer.hpp>

// ************************************************************************** //
//                            | Canonical Form  |                             //
// ************************************************************************** //

/*Default Destructor*/
Renderer::~Renderer() {}


// ************************************************************************** //
//                        | Constructor Overloading |                         //
// ************************************************************************** //

Renderer::Renderer(int cellSize)
	: _cellSize(cellSize),
	_backgroundColor(sf::Color::White),
	_cellColor(sf::Color::Black) {}


// ************************************************************************** //
//                            | Public Members  |                             //
// ************************************************************************** //

void	Renderer::render(sf::RenderWindow &window, Grid const &grid)
{
	window.clear(_backgroundColor);
	drawCells(window, grid);
	window.display();
}

void Renderer::drawCells(sf::RenderWindow &window, Grid const &grid)
{
	sf::RectangleShape cellShape(sf::Vector2f(
		static_cast<float>(_cellSize),
		static_cast<float>(_cellSize)));
	cellShape.setFillColor(_cellColor);
	
	for (const Cell& cell : grid.getGrid())
	{
		float pixelX = static_cast<float>(cell.getX() * _cellSize);
		float pixelY = static_cast<float>(cell.getY() * _cellSize);
		
		cellShape.setPosition(sf::Vector2f(pixelX, pixelY));
		window.draw(cellShape);
	}
}
