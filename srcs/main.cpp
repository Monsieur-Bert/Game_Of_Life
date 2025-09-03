#include <gameOfLife.hpp>
#include <Grid.hpp>

void	debugPrint(Grid const &game)
{
	for (int y = 0; y < game.getHeight(); ++y)
	{
		for (int x = 0; x < game.getWidth(); ++x)
		{
			if (game.getGrid().count(Cell(x, y)))
				std::cout << "0";
			else
				std::cout << ".";
		}
		std::cout << std::endl;
	}
}


// int main() {
// 	Grid game(40, 20);

// 	// test add blinker
// 	game.addCell(20,10);
// 	game.addCell(21,10);
// 	game.addCell(22,10);

// 	for(int gen = 0; gen < 3; ++gen)
// 	{
// 		std::cout << "Generation " << gen << ":\n";
// 		debugPrint(game);
// 		game.iteration();
// 	}

// 	return 0;
// }


int main() {
    const unsigned int cellSize = 10;
    const unsigned int width = 1920 / cellSize;
    const unsigned int height = 1080 / cellSize;

    Grid game(width, height);
    game.addCell(10, 10);
    game.addCell(11, 10);
    game.addCell(12, 10);

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u{W_WIDTH, W_HEIGHT}), "Game of Life - SFML 3");
    window.setFramerateLimit(10);

    sf::RectangleShape cellShape(sf::Vector2f{float(cellSize), float(cellSize)});
    cellShape.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        while (auto eventOpt = window.pollEvent()) {
            // sf::Event event = *eventOpt;
			// if (event.index() == sf::Event::Closed)
			// 	window.close();
        }

        game.iteration();

        window.clear(sf::Color::Black);
        for (const Cell& c : game.getGrid()) {
            cellShape.setPosition(sf::Vector2f{float(c.getX() * cellSize), float(c.getY() * cellSize)});
            window.draw(cellShape);
        }
        window.display();
    }

    return 0;
}


