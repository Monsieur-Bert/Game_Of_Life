#ifndef RENDERER_HPP
# define RENDERER_HPP

# include <Grid.hpp>
# include <SFML/Graphics.hpp>

class Renderer
{
	public:
		/*Canonical Form*/
		Renderer(void);
		Renderer(Renderer const &src) = delete;
		~Renderer(void);
		Renderer &operator=(Renderer const &rhs) = delete;

		/*Constructor Overloading*/
		Renderer(int winWidth, int winHeight, int cellSize);

		/*Public Members*/
		void	render(Grid const &game);

	private:
		sf::RenderWindow	_window;
		int					_cellSize;

};

#endif // RENDERER_HPP