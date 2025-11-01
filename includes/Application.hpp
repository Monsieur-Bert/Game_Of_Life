#ifndef APPLICATION_HPP
# define APPLICATION_HPP

#include <SFML/Graphics.hpp>
#include <Grid.hpp>
#include <Renderer.hpp>

constexpr float UPDATE_INTERVAL = 0.1f;

class Application
{
	public:
		/*Canonical Form*/
		Application(void) = delete;
		Application(Application const &src) = delete;
		~Application(void);
		Application &operator=(Application const &rhs) = delete;

		/*Constructor Overloading*/
		Application(int windowWidth, int windowHeight, int gridWidth, int gridHeight, int cellSize);

		/*Public Members*/
		void	run();

	private:
		sf::RenderWindow	_window;
		Grid				_game;
		Renderer			_renderer;
		bool				_running;
		
		/* Framerate Management*/
		sf::Clock	_clock;
		float		_updateInterval;

		/* Game Loop */
		void	handleEvents();
		void	update();
		void	render();
};

#endif // APPLICATION_HPP