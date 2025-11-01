#ifndef RENDERER_HPP
# define RENDERER_HPP

# include <SFML/Graphics.hpp>
# include <Grid.hpp>

class Renderer
{
	public:
		/*Canonical Form*/
		Renderer(void) = delete;
		Renderer(Renderer const &src) = delete;
		~Renderer(void);
		Renderer &operator=(Renderer const &rhs) = delete;

		/*Constructor Overloading*/
		Renderer(int cellSize);

		/*Public Members*/
		void	render(sf::RenderWindow &window, Grid const &grid);

	private:
		int			_cellSize;
		
		/*Colors*/
		sf::Color	_backgroundColor;
		sf::Color	_cellColor;

		/*Drawing helpers*/
		void	drawCells(sf::RenderWindow &window, Grid const &grid);
};

#endif // RENDERER_HPP